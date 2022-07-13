#include "myheader.h"

class CSV_FILE_ITERATOR
{
    //separate function for searching each individual field taking the name of the toy as input
    //return a vector or as per requirement
    public : 
        void inputData(string name,int quantity,int price,bool oos)
        {
            fstream file;
            file.open("toy_information.csv",ios :: out | ios :: app);
            file<<name<<","<<quantity<<","<<price<<","<<oos<<"\n";
            file.close();
        }

        void search(string name)
        {
            fstream file;string s,word;bool flag=false;
            file.open("toy_information.csv",ios :: in);
            while(getline(file,s))
            {
                stringstream word(s);
                getline(word,s,',');
                if(s==name) 
                {
                    flag=true;
                    cout<<s<<" was found in the database."<<endl;
                    return;
                }
            }
            if(!flag) cout<<name<<" was not found in the database. Contact admin for the details"<<endl;
        }

        map<string,Toy*> converter()
        {
            ifstream file;string toy_name,token,temp; Toy *data_loader=new Toy();
            file.open("toy_information.csv");
            map <string,Toy*> dataMatrix;
            getline(file,toy_name);
            while(getline(file,toy_name))
            {
                stringstream token(toy_name);
                getline(token,toy_name,',');
                getline(token,temp,',');
                data_loader->quantity=stoi(temp);
                getline(token,temp,',');
                data_loader->price=stoi(temp);
                getline(token,temp,',');
                data_loader->out_of_stock_flag=stoi(temp);
                dataMatrix.insert(make_pair(toy_name,data_loader));
                for(auto it : dataMatrix)
                {
                    cout<<it.first<<" ";
                    (it.second)->display();
                }
                cout<<endl;
            }
            return dataMatrix;
        } 

        void delete_toy(string name)
        {
            fstream source_file("toy_information.csv",ios :: in | ios :: app);
            string line,word,toy_name;
            fstream dest_file("new_toy.csv",ios :: out);
            while(1)
            {
                if(!getline(source_file,line)) break;
                stringstream word(line);
                getline(word,toy_name,',');
                if(toy_name!=name) dest_file<<line<<"\n";
            }
            dest_file.close();
            source_file.close();
            remove("toy_information.csv");
            rename("new_toy.csv","toy_information.csv");            
        }    

        void update(string name,int quantity,int price, bool oos)
        {
            fstream source_file("toy_information.csv",ios :: in | ios :: app);
            string line,word,toy_name;bool isPresent=false;
            fstream dest_file("new_toy.csv",ios :: out);
            while(1)
            {
                if(!getline(source_file,line)) break;
                stringstream word(line);
                getline(word,toy_name,',');
                if(toy_name == name)
                {
                   isPresent=true;
                   line="";
                   line+=toy_name+","+to_string(quantity)+","+to_string(price)+","+to_string(oos);
                }
                dest_file<<line<<"\n";
            }
            if(!isPresent) inputData(name,quantity,price,oos);
            dest_file.close();
            source_file.close();
            remove("toy_information.csv");
            rename("new_toy.csv","toy_information.csv");
        }

        void wiew_list()
        {
            ifstream file("toy_information.csv");
            string row;
            while(1)
            {
                if(!getline(file,row)) return;
                cout<<row<<endl;
            }
            file.close();
        }

        void write_back(map <string,Toy *> data_matrix)
        {
            ofstream file("toy_information.csv",ios :: out);
            for(auto it : data_matrix) file<<it.first<<","<<(it.second)->quantity<<","<<(it.second)->price<<","<<(it.second)->out_of_stock_flag<<"\n";
            file.close();
        }
};

int main()
{
    CSV_FILE_ITERATOR c;
    map<string, Toy*> m=c.converter();
    for(auto it : m) {cout<<it.first<<" ";(it.second)->display();}
    cout<<endl;
    m["carrom"]->price=99;
    for(auto it : m) {cout<<it.first<<" ";(it.second)->display();}
    return 0;
}


/*
toy_name,quantity,price,is_out_of_stock
ludo,10,70,false
uno,10,70,false
carrom,10,70,false
chess,10,70,false
robots,10,70,false
cricket_set,10,70,false
snake_and_ladder,10,70,false
trading_cards,10,70,false
toy_gun,10,70,false
hotWheels,10,70,falseabdssfsfaf


*/