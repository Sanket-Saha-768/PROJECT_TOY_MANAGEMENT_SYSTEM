#include "mysource.cpp"

int main()
{
    Admin a1;
    Customer c1;

    switch (generalMenu())
    {
    case 1:
    {
        cout << "\n-------------------\nFor admin :" << endl;
        // a1.login_menu();
    }
    break;
    case 2:
        // c1.login_menu();
        break;
    case 0:
        exit(0);
        break;
    default:
        cout << "\nIncorrect Input!\n";
        break;
    }
    return 0;
}