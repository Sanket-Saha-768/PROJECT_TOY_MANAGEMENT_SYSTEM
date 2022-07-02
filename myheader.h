#include <bits/stdc++.h>
using namespace std;

class Toy
{
    int quantity;
    string name;
    int price;
    bool out_of_stock_flag;
};

class Admin : public Toy
{
    string id,password;bool login_status;
    public:
        void create_admin(string id_p,string password_p);
        bool login(string id_p,string password_p);
        void delete_toy(Toy T);
        void update_toy();
        void create_toy();
};

class Customer : private Toy
{
    string username,password;bool login_status;
    public :
        void create_user(string user,string pass);
        bool login(string id_p,string password_p);
        void purchase();
        void view_toys_list();
        void search_toy();
        void display_balance(int cash,Toy t);
        
};
