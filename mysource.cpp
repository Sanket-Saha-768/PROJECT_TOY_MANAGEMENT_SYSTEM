#include "myheader.h"

void Admin :: create_admin(string id_p,string password_p)
{
    id=id_p;
    password=password_p;
}

bool Admin :: login(string id_p,string password_p)
{
    int tries=0;
    while(id_p!=id and tries!=3)
    {
        // if()
        // {
            cout<<"XXXXXXXX  INVALID ADMIN ID. TRY AGAIN!! XXXXXXXXX"<<endl; 
            tries+=1;
            if(tries==3)
            {
                cout<<"You have entered the incorrect id 3 times in a row. Exiting admin interface"<<endl;
                return false;
            }
            
        // }
    }
    tries=0;
    while(tries!=3 and password_p!=password)
    {
        // if()
        // {
            cout<<"XXXXXXXX  INVALID ADMIN PASSWORD. TRY AGAIN!! XXXXXXXXX"<<endl;
            tries+=1;
            if(tries==3)
            {
                cout<<"You have entered the incorrect password 3 times in a row. Exiting admin interface"<<endl;
                return false;
            }
        // }
    }
    return true;
}

void Customer :: set_credentials(string user,string pass)
{
    username=user;
    password=pass;
}

bool Customer :: login(string id_p,string password_p)
{
    int tries=0;
    while(id_p!=username and tries!=3)
    {
        // if()
        // {
            cout<<"XXXXXXXX  INVALID USER ID. TRY AGAIN!! XXXXXXXXX"<<endl; 
            tries+=1;
            if(tries==3)
            {
                cout<<"You have entered the incorrect id 3 times in a row. Exiting user interface"<<endl;
                return false;
            }
            
        // }
    }
    tries=0;
    while(tries!=3 and password_p!=password)
    {
        // if()
        // {
            cout<<"XXXXXXXX  INVALID USER PASSWORD. TRY AGAIN!! XXXXXXXXX"<<endl;
            tries+=1;
            if(tries==3)
            {
                cout<<"You have entered the incorrect password 3 times in a row. Exiting user interface"<<endl;
                return false;
            }
        // }
    }
    return true;
}
