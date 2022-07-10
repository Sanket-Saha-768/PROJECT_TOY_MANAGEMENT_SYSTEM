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
                    return;
                }
            }
            if(!flag) cout<<name<<" was not found in the database. Contact admin for the details"<<endl;
        }

        void converter()
        {
            ifstream file;
            file.open("toy_information.txt");
            vector<> dataMatrix;
        }

        
};
