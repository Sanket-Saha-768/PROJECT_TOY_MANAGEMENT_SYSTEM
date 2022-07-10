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
            file<<name<<","<<quantity<<","<<price<<","<<false<<"\n";
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
                    cout<<s<<endl;
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
                getline(token,temp,',');data_loader->quantity=stoi(temp);
                getline(token,temp,',');data_loader->price=stoi(temp);
                getline(token,temp,',');data_loader->out_of_stock_flag=stoi(temp);
                dataMatrix.insert(make_pair(toy_name,data_loader));
            }
            return dataMatrix;
        } 

        void delete_toy(string name)
        {
            fstream file("toy_information.csv",ios :: in | ios :: app);string s;
            getline(file,s);
            cout<<s<<endl;
            file<<"abdssfsfaf"<<endl;
            file.close();
        }    
};

int main()
{
    CSV_FILE_ITERATOR c;
    map<string, Toy*> m=c.converter();
    return 0;
}


/*

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