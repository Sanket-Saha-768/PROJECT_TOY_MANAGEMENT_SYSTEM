#include <bits/stdc++.h>
#include <ctime>
#include <cstdio>
using namespace std;

class Toy
{
public:
    int quantity;
    int price;
    bool out_of_stock_flag;
    void display()
    {
        cout << " " << quantity << " " << price << " " << out_of_stock_flag << endl;
    }
};

class CSV_FILE_ITERATOR
{
    // separate function for searching each individual field taking the name of the toy as input
    // return a vector or as per requirement
public:
    void inputData(string name, int quantity, int price, bool oos = false);
    Toy *search(string name); // send the toy object to the purchase function
    map<string, Toy *> converter();
    void delete_toy(string name);
    void update_toy(string name, int quantity, int price, bool oos);
    void view_list();
    void View_List_Customer();
    void write_back(map<string, Toy *> data_matrix);
    int getBalance(string id);
    void update_customer_details(string id, string password, int balance);
    void update_purchase_record(string customer_id, string toy_name, int purchase_quantity, int toy_price, time_t date_and_time);
    void create_customer(string customer_id, string password, int balance);
};

class Admin : public CSV_FILE_ITERATOR
{
    string id, password;
    bool login_status;

public:
    Admin();
    void interface_admin();
    void login_menu();
    bool login(string id_p, string password_p);
    void delete_toy();
    void update_toy();
    void view_toy_list();
    void create_toy();
    void create_user();
};

class Customer : public CSV_FILE_ITERATOR
{
    string username, password;
    bool login_status;

public:
    // bool login_menu();
    bool login(string id_p, string password_p);
    void interface();
    bool purchase(string toy_name);
    void view_toys_list();
    // bool search_toy();
    // void display_balance(int cash,string toy_name);
};

int generalMenu();
void print_reciept(string toy_name, int quantity, int price, time_t pur_id, int balance);
