#include "myheader.h"

Admin ::Admin()
{
    id = "Admin1";
    password = "pass985";
}

void menu()
{
    int choice;
    cout << "\n-------------------------------------------" << endl;
    cout << "1 -> Login as Admin" << endl;
    cout << "2 -> Login as Customer" << endl;
    cout << "0 -> Exit Toy Shop Management Interface" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    if (choice == 0)
        return;
    string id, password;
    cout << "\n-------------------------------------------" << endl;
    cout << "\nEnter Login id : ";
    cin >> id;
    cout << "Enter Password : ";
    cin >> password;
    cout << "-------------------------------------------" << endl;
    if (choice == 1)
    {
        Admin admin;
        admin.login(id, password);
    }
    else if (choice == 2)
    {
        Customer customer;
        customer.login(id, password);
    }
    else
        menu();
}

void CSV_FILE_ITERATOR ::inputData(string name, int quantity, int price, bool oos)
{
    fstream file;
    file.open("toy_information.csv", ios ::out | ios ::app);
    file << name << "," << quantity << "," << price << "," << oos << "\n";
    file.close();
}

void CSV_FILE_ITERATOR ::create_customer(string customer_id, string password, int balance)
{
    ofstream file("customer_details.csv", ios ::app | ios ::out);
    file << customer_id << "," << password << "," << balance << endl;
    file.close();
}

void CSV_FILE_ITERATOR ::update_purchase_record(string customer_id, string toy_name, int purchase_quantity, int toy_price, time_t date_and_time)
{
    ofstream file("purchase_record.csv", ios ::app);
    file << customer_id << "," << toy_name << "," << purchase_quantity << "," << toy_price << "," << date_and_time << endl;
    file.close();
}

Toy *CSV_FILE_ITERATOR ::search(string name) // send the toy object to the purchase function
{
    fstream file;
    string s, word, token, temp;
    bool flag = false;
    Toy *data_loader = new Toy();
    file.open("toy_information.csv", ios ::in);
    while (getline(file, s))
    {
        stringstream word(s);
        getline(word, s, ',');
        if (s == name)
        {
            flag = true;
            cout << s << " was found in the database." << endl;
            getline(word, temp, ',');
            data_loader->quantity = stoi(temp);
            getline(word, temp, ',');
            data_loader->price = stoi(temp);
            getline(word, temp, ',');
            data_loader->out_of_stock_flag = stoi(temp);
            return data_loader;
        }
    }
    if (!flag)
        cout << name << " was not found in the database. Contact admin for the details" << endl;
    return NULL;

    /*
        search function is returning a null pointer in  case the searched toy is not in the list. so in ur function please do check for this null pointer before u use it to avoid null pointer reference

        @dasosis
    */
}

map<string, Toy *> CSV_FILE_ITERATOR ::converter()
{
    ifstream file;
    string toy_name, token, temp;
    Toy *data_loader = new Toy();
    file.open("toy_information.csv");
    map<string, Toy *> dataMatrix;
    getline(file, toy_name);
    while (getline(file, toy_name))
    {
        stringstream token(toy_name);
        getline(token, toy_name, ','); // toy name is the key of the map
        getline(token, temp, ',');
        data_loader->quantity = stoi(temp);
        getline(token, temp, ',');
        data_loader->price = stoi(temp);
        getline(token, temp, ',');
        data_loader->out_of_stock_flag = stoi(temp);
        dataMatrix.insert(make_pair(toy_name, data_loader));
        for (auto it : dataMatrix)
        {
            cout << it.first << " ";
            (it.second)->display();
        }
        cout << endl;
    }
    return dataMatrix;
}

void CSV_FILE_ITERATOR ::delete_toy(string name)
{
    fstream source_file("toy_information.csv", ios ::in | ios ::app);
    string line, word, toy_name;
    fstream dest_file("new_toy.csv", ios ::out);
    while (1)
    {
        if (!getline(source_file, line))
            break;
        stringstream word(line);
        getline(word, toy_name, ',');
        if (toy_name != name)
            dest_file << line << "\n";
    }
    dest_file.close();
    source_file.close();
    remove("toy_information.csv");
    rename("new_toy.csv", "toy_information.csv");
}

void CSV_FILE_ITERATOR ::update_toy(string name, int quantity, int price, bool oos)
{
    fstream source_file("toy_information.csv", ios ::in | ios ::app);
    string line, word, toy_name;
    bool isPresent = false;
    fstream dest_file("new_toy.csv", ios ::out);
    while (1)
    {
        if (!getline(source_file, line))
            break;
        stringstream word(line);
        getline(word, toy_name, ',');
        if (toy_name == name)
        {
            isPresent = true;
            line = "";
            line += toy_name + "," + to_string(quantity) + "," + to_string(price) + "," + to_string(oos);
        }
        dest_file << line << "\n";
    }
    if (!isPresent)
        inputData(name, quantity, price, oos);
    dest_file.close();
    source_file.close();
    remove("toy_information.csv");
    rename("new_toy.csv", "toy_information.csv");
}

void CSV_FILE_ITERATOR ::view_list()
{
    ifstream file("toy_information.csv");
    string row;
    while (1)
    {
        if (!getline(file, row))
            return;
        cout << row << endl;
    }
    file.close();
}

void CSV_FILE_ITERATOR ::View_List_Customer()
{
    ifstream file("toy_information.csv");
    string row, word;
    while (1)
    {
        if (!getline(file, row))
            return;
        stringstream word(row);
        getline(word, row, ',');
        cout << row << " ";
        getline(word, row, ',');
        getline(word, row, ',');
        cout << row << endl;
    }
    file.close();
}

void CSV_FILE_ITERATOR ::write_back(map<string, Toy *> data_matrix)
{
    ofstream file("toy_information.csv", ios ::out);
    for (auto it : data_matrix)
        file << it.first << "," << (it.second)->quantity << "," << (it.second)->price << "," << (it.second)->out_of_stock_flag << "\n";
    file.close();
}

int CSV_FILE_ITERATOR ::getBalance(string id)
{
    ifstream file("customer_details.csv");
    string row, word;
    while (1)
    {
        if (!getline(file, row))
            return -1;
        stringstream word(row);
        getline(word, row, ',');
        if (row == id)
        {
            getline(word, row, ',');
            getline(word, row, ',');
            return stoi(row);
        }
    }
    file.close();
    return stoi(row);
}

void CSV_FILE_ITERATOR :: update_customer_details(string id, string password, int balance)
{
    // ifstream file("customer_details.csv");
    // char file1name[] = "customer_details.csv";
    // fstream file1;file1.open("customer_details_copy.csv", ios ::out | ios :: app);
    // char file2name[] = "customer_details_copy.csv";
    // string row, word, cell;
    // int renamed,removed;
    // while (1)
    // {
    //     if (!getline(file, row)) return;
    //     stringstream word(row);
    //     getline(word, cell, ',');
    //     if (cell != id)
    //         file1 << row << endl;
    //     else
    //         file1 << id << "," << password << "," << balance << endl;
    // }
    // file.close();
    // file1.close();
    // // remove("customer_details.csv");
    // // rename("customer_details_copy.csv", "customer_details.csv");    
    // //rename(file2name, file1name);
    // removed = remove(file1name);
    // renamed = rename(file2name, file1name);
    fstream source_file("customer_details.csv",ios :: in | ios :: app);
    string line,word,name;
    fstream dest_file("new_customer.csv",ios :: out);
    while(1)
    {
        if(!getline(source_file,line)) break;
        stringstream word(line);
        getline(word,name,',');
        if(id == name)
        {
            line="";
            line+=id+","+password+","+to_string(balance);
        }
        dest_file<<line<<"\n";
    }
    dest_file.close();
    source_file.close();
    remove("customer_details.csv");
    rename("new_customer.csv","customer_details.csv");
}

// void Admin ::create_admin(string id_p, string password_p)
// {
//     id = id_p;
//     password = password_p;
//     login_status = false;
//     fstream file;
//     file.open("admin_details.txt", ios::app);
//     file << id << " " << password << endl;
//     file.close();
// }

bool Admin ::login(string id_p, string password_p)
{
    if (id != id_p)
    {
        cout << "XXXXXXXX  INVALID ADMIN ID. TRY AGAIN!! XXXXXXXXX" << endl;
        menu();
    }
    if (password != password_p)
    {
        cout << "XXXXXXXX  INVALID ADMIN PASSWORD. TRY AGAIN!! XXXXXXXXX" << endl;
        menu();
    }
    cout << "\n-------------------------------------------" << endl;
    cout << "\nWELCOME Admin : " << id << endl;
    interface_admin();
    login_status = true;
    return true;
}

void Admin ::delete_toy()
{
    string toy_name;

    cout << "\n-------------------------------------------" << endl;
    cout << "Enter the name of the toy to be DELETED : ";
    cin >> toy_name;
    cout << "-------------------------------------------" << endl;

    CSV_FILE_ITERATOR ::delete_toy(toy_name);
    interface_admin();
}

void Admin ::create_toy()
{
    string toy_name;
    int quantity;
    int price;

    cout << "\n-------------------------------------------" << endl;
    cout << "Enter the name of the NEW toy : ";
    cin >> toy_name;
    cout << "Enter the quantity of the NEW toy : ";
    cin >> quantity;
    cout << "Enter the price of the NEW toy : ";
    cin >> price;
    cout << "-------------------------------------------" << endl;

    inputData(toy_name, quantity, price, false);
    interface_admin();
}

void Admin ::update_toy()
{
    string toy_name;
    int quantity;
    int price;
    bool oos;
    cout << "\n-------------------------------------------" << endl;
    cout << "Enter the name of the toy to be UPDATED : ";
    cin >> toy_name;
    cout << "Enter the quantity of the UPDATED toy : ";
    cin >> quantity;
    cout << "Enter the price of the UPDATED toy : ";
    cin >> price;
    cout << "If toy is out of stock? : ";
    cin >> oos;
    cout << "-------------------------------------------" << endl;

    CSV_FILE_ITERATOR ::update_toy(toy_name, quantity, price, oos);
    interface_admin();
}

void Admin ::create_user()
{
    // username = user;
    // password = pass;
    // login_status = false;
    // fstream file;
    // file.open("customer_details.csv", ios::app);
    // file << username << " " << password << endl;
    // file.close();
    string username, user_password;
    int balance;
    cout << "-------------------------------------------" << endl;
    cout << "\nEnter the name of the user : ";
    cin >> username;
    cout << "\nEnter the password for the user " << username << " : ";
    cin >> user_password;
    cout << "\nEnter the user " << username << "'s account balance : ";
    cin >> balance;
    cout << "-------------------------------------------" << endl;
    create_customer(username, user_password, balance);
    interface_admin();
}

bool Customer ::purchase(string toy_name)
{
    Toy *item = search(toy_name);
    time_t timesec = time(0);
    if (item)
    {
        int balance = getBalance(username);
        // int price = get_price(toy_name);
        if (balance >= item->price)
        {
            update_customer_details(username, password, (balance - item->price));
            // update purchase record
            update_purchase_record(username, toy_name, 1, item->price, timesec);
            update_toy(toy_name, item->quantity - 1, item->price, ((item->quantity - 1 == 0) ? true : false));
            // update purchase reciept
            // call function to open purchase reciept
            print_reciept(toy_name, item->quantity - 1, item->price, timesec, balance - item->price);
            interface();
            return true;
        }
        else
        {
            cout << "Not enough balance" << endl;
            interface();
            return true;
        }
    }
    else
    {
        cout << "Toy Out of Stock" << endl;
        interface();
        return false;
    }
}

void Admin ::view_toy_list()
{
    View_List_Customer();
    interface_admin();
}

void Admin ::interface_admin()
{
    int choice;
    cout << "\n-------------------------------------------" << endl;
    cout << "1 - Create a Toy" << endl;
    cout << "2 - Update Toy" << endl;
    cout << "3 - Delete a Toy" << endl;
    cout << "4 - View Toy List" << endl;
    cout << "5 - Create NEW User" << endl;
    cout << "0 - Exit" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        create_toy();
        break;
    case 2:
        update_toy();
        break;
    case 3:
        delete_toy();
        break;
    case 4:
        view_toy_list();
        break;
    case 5:
        create_user();
        break;
    case 0:
        menu();
        break;
    default:
    {
        cout << "Invalid Choice!!" << endl;
        interface_admin();
    }
    break;
    }
}

bool Customer ::login(string id_p, string password_p)
{
    int tries = 0;
    bool assignment = false;
    ifstream file("customer_details.csv");
    string row, word, line;
    getline(file, row);
    while (1)
    {
        if (!getline(file, row))
            return false;
        stringstream word(row);
        getline(word, row, ',');
        if (row == id_p)
        {
            username = row;
            getline(word, row, ',');
            password = row;
            assignment = true;
            break;
        }
    }
    if (!assignment)
    {
        cout << "XXXXXXXX  INVALID USER ID. TRY AGAIN!! XXXXXXXXX" << endl;
        cout << endl
             << endl;
        menu();
    }
    while (1)
    {
        if (password_p != password_p)
        {
            cout << "XXXXXXXX  INVALID USER PASSWORD. TRY AGAIN!! XXXXXXXXX" << endl;
            cout << endl
                 << endl;
            menu();
        }
        else
            break;
    }
    cout << "\n-------------------------------------------" << endl;
    cout << "\nWelcome Customer : " << username << endl;
    interface();
    login_status = true;
    return true;
}

void Customer ::view_toys_list()
{
    View_List_Customer();
    interface();
}

void Customer ::interface()
{
    int choice;
    cout << "\n-------------------------------------------" << endl;
    cout << "1 - Purchase a Toy" << endl;
    cout << "2 - View Toy List" << endl;
    cout << "3 - Search a Toy" << endl;
    cout << "4 - Display Balance" << endl;
    cout << "0 - Exit" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string toy_name;
        cout << "What toy do you want to purchase? ";
        cin >> toy_name;
        if (purchase(toy_name))
        {
            cout << "\nPurchase successfull!!!" << endl;
        }
        else
            cout << "\nPurchase unsuccessfull!!!" << endl;
    }
    break;
    case 2:
        view_toys_list();
        break;
    case 3:
    {
        string toy_name;
        cout << "\nWhat toy do you want to search? ";
        cin >> toy_name;
        if (search(toy_name))
        {
            cout << "\nThe Toy is available in the store" << endl;
        }
        else
            cout << "\nThe toy is not available in the store" << endl;
        interface();
    }
    break;
    case 4:
    {
        cout << "\nRemaining Balance - " << getBalance(username) << endl;
        interface();
    }
    break;
    case 0:
        menu();
        break;
    default:
    {
        cout << "Invalid Choice!";
        interface();
    }
    break;
    }
    /*
        switch (choice)
        {
            case 1 : purchase();
                    break;
            case 2 : view_toys_list();
            break;
            case 3 : search_toy(toyname);
            case 4 : display_balance();
            break;
            case 0 : break;
            default :
        }*/
}
/*
void Customer ::display_balance(int cash, string toy_name)
{
}
*/
/*
void Customer ::view_toys_list()
{
    ifstream file;
    string s;
    int c = 0;
    file.open("toy_list.txt");
    while (1)
    {
        getline(file, s);
        if (!file)
            break;
        cout << s << endl;
    }
    file.close();
}
*/
/*
bool Customer ::search_toy(string toy_name)
{
    string toy_name_from_list, prompt_response;
    ifstream file;
    file.open("toy_list.txt");
    while (1)
    {
        getline(file, toy_name_from_list);
        if (toy_name == toy_name_from_list)
            return 1;
        else
            return 0;
    }
}
*/
/*
    void Customer ::search_toy()
    {
        string toy_name, toy_name_from_list, prompt_response;
        cout << "Enter the name of the toy that you want to search : ";
        cin >> toy_name;
        ifstream file;
        file.open("toy_list.txt");
        while (1)
        {
            getline(file, toy_name_from_list);
            if (toy_name == toy_name_from_list)
            {
                cout << toy_name << " is available in the store. Type yes to purchase when prompted or type no to exit Search Module!!" << endl;
                cout << "Do you want to purchase " << toy_name << " ?" << endl;
                cin >> prompt_response;
                if (prompt_response == "yes")
                {
                    Customer ::purchase();
                    break;
                }
                else
                {
                    interface();
                    break;
                }
            }
            else if (!file)
            {
                cout << toy_name << " is not available in the store at the moment. Contact the admin to add this toy to the list. Thanks!!!" << endl;
                break;
            }
        }
        file.close();
    }
*/

int generalMenu()
{
    int choice;
    cout << "\nWelcome to Toy Shop Management Interface" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1 -> Login as an Admin" << endl;
    cout << "2 -> Login as a Customer" << endl;
    cout << "0 -> Exit Toy Shop Management Interface" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter your choice :";
    cin >> choice;
    return choice;
}

void print_reciept(string toy_name, int quantity, int price, time_t pur_id, int balance)
{
    cout << "\n-------------------------------------------" << endl;
    cout << "Thank you for purchasing with us!" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Your Bill : " << endl
         << endl;
    cout << toy_name << " x "
         << "1" << endl;
    cout << "Total Price : " << price << endl;
    cout << "Your Current Balance : " << balance << endl;
    cout << "Your Purchase ID : " << pur_id << endl
         << endl;
    cout << "-------------------------------------------" << endl;
}
