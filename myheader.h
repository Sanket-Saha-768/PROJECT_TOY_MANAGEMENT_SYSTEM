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
    string id, password;

public:
    void create_admin(string id_p, string password_p);
    bool login(string id_p, string password_p);
    void delete_toy();
    void update_toy();
    void create_toy();
};

class Customer : public Toy
{
    string username, password;

public:
    void create_user(string user, string pass);
    bool login(string id_p, string password_p);
    void purchase();
    void view_toys_list();
    void search_toy(string name);
    void display_balance(int cash, Toy t);
};
