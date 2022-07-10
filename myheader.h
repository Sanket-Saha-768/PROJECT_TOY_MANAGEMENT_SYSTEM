#include <bits/stdc++.h>
using namespace std;

class Toy
{
    public :
        int quantity;
        int price;
        bool out_of_stock_flag;
        void display()
        {
            cout<<" "<<quantity<<" "<<price<<" "<<out_of_stock_flag<<endl;
        }
};

class Admin
{
    string id,password;bool login_status;
    public:
        void create_admin(string id_p,string password_p);
        bool login(string id_p,string password_p);
        void delete_toy(string toy_name);
        void update_toy();
        void create_toy();
};

class Customer
{
    string username,password;bool login_status;
    public :
        void create_user(string user,string pass);
        bool login(string id_p,string password_p);
        void purchase();
        void view_toys_list();
        void search_toy();
        void display_balance(int cash,string toy_name);        
};
