#include<bits/stdc++.h>
using namespace std;
class Admin
{
    string id,password;
    public:
        void create_admin(string id_p,string password_p);
        bool login(string id_p,string password_p);
        void delete_toy();
        void update_toy();
        void create_toy();
};

class Customer
{
    string username,password;
    public :
        bool login();
        void purchase();
};

class Toy
{
    
};