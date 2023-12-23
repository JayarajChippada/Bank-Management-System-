#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;

class Bank {
    private:
        int pin;
        float balance;
        string id, pass, name, fname, address, phone;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void already_user();
};

void Bank :: already_user() {
    system("cls");
    fstream file;

    cout << "\n\n Already User Account";
    file.open("bank.txt", ios::in);
    if(!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> id;
    }
}

void Bank :: new_user() {
    p:
    system("cls");
    fstream file;
    int p;
    float b;
    string n, f, pa, a, ph, i;

    cout << "\n\n\t\t\tAdd New User";
    cout << "\n\n User ID : ";
    cin >> id;
    cout << "\n\n Name : ";
    cin >> name;
    cout << "\n\n Father Name : ";
    cin >> fname;
    cout << "\n\n Address : ";
    cin >> address;
    cout << "\n\n Pin Code (5 digit) : ";
    cin >> pin;
    cout << "\n\n Password : ";
    cin >> pass;
    cout << "\n\n Phone No. : ";
    cin >> phone;
    cout << "\n\n Current Balance : ";
    cin >> balance;
    file.open("bank.txt, ios::in");
    if(!file) {
        file.open("bank.txt", ios::app|ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    } else {
        file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        while(!file.eof()) {
            if(i == id) {
                cout << "\n\n User Id Already Exists!";
                getch();
                goto p;
            }
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    }
    cout << "\n\n New User Account Created Successfully!";
}

void Bank :: menu() {
    p:
    system("cls");
    int choice;
    char ch1;
    string email, pin, pass;

    cout << "\n\n\t\t\tControl Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n 2. ATM Management";
    cout << "\n 3. Exit";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            system("cls");
            cout << "\n\n\t\tLogin Account";
            cout << "\n\n Email : ";
            cin >> email;
            cout << "\n\n Pin Code : ";
            for(int i=0; i<=5; i++) {
                ch1 = getch();
                pin += ch1;
                cout << "*";    
            }
            cout << "\n\n Password : ";
            for (int i = 0; i <= 5; i++)
            {
                ch1 = getch();
                pass += ch1;
                cout << "*";
            }
            if(email == "jayaraj@gmail.com" && pin == "123456" && pass == "123456") {
                bank_management();
            }
            else {
                cout << "\n\n Your Email, Pin & Password is Wrong..";
            }
            break;

        case 2:
            atm_management();
            break;

        case 3:
            exit(0);

        default:
            cout << "\n\n Invalid value... Please Try Again...";
            break;
    }
    getch();
    goto p;
}

void Bank :: bank_management() {
    p:
    system("cls");
    int choice;

    cout << "\n\n\t\t\t Bank Management System";
    cout << "\n\n 1.  New User";
    cout << "\n 2.  Already User";
    cout << "\n 3.  Deposit Option";
    cout << "\n 3.  Deposit Option";
    cout << "\n 4.  Withdraw Option";
    cout << "\n 5.  Transfer Option";
    cout << "\n 6.  Payment Option";
    cout << "\n 7.  Search User Record";
    cout << "\n 8.  Edit User Record";
    cout << "\n 9.  Delete User Record";
    cout << "\n 10. Show All Records";
    cout << "\n 11. Payment All Records";
    cout << "\n 12. Go Back";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            new_user();
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:
            
            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            break;

        case 11:

            break;

        case 12:
            menu();

        default:
            cout << "\n\n Invalid value... Please Try Again...";
            break;
    }
    getch();
    goto p; 
}

void Bank :: atm_management() {
    p:
    system("cls");
    int choice;

    cout << "\n\n\t\t\t ATM Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:
            menu();

        default:
            cout << "\n\n Invalid value... Please Try Again...";
            break;
    }
    getch();
    goto p;
}

main() {
    Bank bank;
    bank.menu();
}