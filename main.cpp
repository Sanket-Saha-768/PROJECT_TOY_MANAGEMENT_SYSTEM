#include "mysource.cpp"

int main()
{
    Admin a1;
    Customer c1;
    fstream file;
    file.open("admin_details.txt",ios::in);
    string s;
    getline(file,s);
    // getline(file,s,' ');cout<<s<<endl;
    // getline(file,s,' ');cout<<s<<endl;
    c1.view_toys_list();
    c1.search_toy();
    a1.create_toy();
    return 0;
}