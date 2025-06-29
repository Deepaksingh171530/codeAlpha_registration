#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forget();
int main()

{
    int c;
    cout << "\n                MENU                     \n";
    cout << "                                        ";
    cout << " press 1 to LOGIN                          " << endl;
    cout << " press 2 to REGISTRATION                   " << endl;
    cout << " press 3 if you forget your PASSWORD       " << endl;
    cout << " press 4 to EXIT                           " << endl;
    cout << "\nplease enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;
    case 3:
        forget();
        break;
    case 4:
        cout << "\t\t\t thank you! \n\n";
        break;
    default:
        // system("c1s");
        cout << "\t please select from the options given above \n"
             << endl;
        main();
    }
}
void login()
{
    int count;
    string userid, password, id, pass;
    // system("c1s");
    cout << "please enter the username & password  " << endl;
    cout << "\tUSERNAME ";
    cin >> userid;
    cout << "\tPASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userid && pass == password)
        {
            count = 1;
            // system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userid << "\n your LOGIN is. successfull \n thanks for logging in ! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n please cheack your username and password\n";
        main();
    }
}
void registration()
{
    string ruserid, rpassword, rid, rpass;
    // system("cls");
    cout << "\t enter the username : ";
    cin >> ruserid;
    cout << "\t enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserid << ' ' << rpassword << endl;
    // system("cls");
    cout << "\n\tregistration is successfull! \n";
    main();
}
void forget()
{
    int option;
    // system("cls");
    cout << "\t you forget the password? no worries \n";
    cout << "press 1 to search your id by username " << endl;
    cout << "press 2 to go back to the main menu " << endl;
    cout << "\t\tenter your choice :";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass;
        cout << "\n\t enter the username which you remembered :";
        cin >> suserid;

        ifstream f2("records.txt");
        while (sid == spass)
        {
            if (sid == suserid)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n your account is found! \n";
            cout << "\n\n your password is :" << spass;
            main();
        }
        else
        {
            cout << "\n\t sorry! your account is not found! \n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "\t worng choice ! please try again " << endl;
        forget();
}
}