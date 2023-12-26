#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

int r;
int chkacc(string a);

COORD coord = {0, 0};

void gotoxy(int a, int b)
{
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void design(int x, int y)
{
    for (int i = 0; i <= x; i++)
        cout << (char)y;
}

class ZzeenPay
{
protected: // data hiding
    char userName[20], password[15];

private:
    int val;

public:
    ZzeenPay()
    {
        system("color 01");
        gotoxy(26, 4);
        design(15, 177);
        cout << "\tWELCOME TO ZZEENPAY BANKING SYSTEM\t";
        design(15, 177);
        gotoxy(50, 8);
        cout << "ACCOUNT TYPE";
        gotoxy(44, 10);
        cout << "[1] . ADMINISTRATOR ";
        gotoxy(44, 11);
        cout << "[2] . USER ";
        gotoxy(44, 14);
        cout << "Enter Your Choice .... ";
        cin >> val;
        if (val != 1 && val != 2)
        {
            system("cls");
            ZzeenPay();
        }
        system("cls");
        authenticate();
    }

    void authenticate();
    void login();
    int verify();
    void menu();
    void option();
    void view();
    void add();
    void edit();
    void del();
    void srch();
    void transactions();
    void about();
    void search_acc();
    void search_name();
    void chkblnc();
    void deposit();
    void withdrawl();
    void menuexit();
};

void ZzeenPay ::authenticate()
{
    system("color 01");
    gotoxy(26, 4);
    design(15, 177);
    cout << "\tWELCOME TO ZZEENPAY BANKING SYSTEM\t";
    design(15, 177);
    login();
    if (verify() == 1)
    {
        if (val == 1)
            menu();
        else
            transactions();
    }
    else if (verify() == 0)
    {
        system("cls");
        gotoxy(35, 17);
        design(48, 45);
        gotoxy(43, 16);
        cout << "Incorrect Username / Password !!!!";
        authenticate();
    }
}

void ZzeenPay ::login()
{
    gotoxy(44, 10);
    cout << "Enter The Username : ";
    cin >> userName;
    gotoxy(44, 12);
    cout << "Enter The Password : ";
    cin >> password;
}

int ZzeenPay ::verify()
{
    if (val == 1)
    {
        if ((strcmp(userName, "jayaraj") == 0 && strcmp(password, "jayaraj") == 0))
        {
            gotoxy(35, 17);
            design(48, 45);
            gotoxy(38, 16);
            cout << "You Have Successfully Logged In : " << '"' << userName << '"' << endl;
            time_t t;
            time(&t);
            gotoxy(39, 18);
            cout << "Logged In Time : " << ctime(&t);
            gotoxy(44, 22);
            cout << "Press any key to continue .... ";
            getch();
            return 1;
        }
        else
            return 0;
    }
    else if (val == 2)
    {
        if (strcmp(userName, "user") == 0 && strcmp(password, "user") == 0)
        {
            gotoxy(35, 17);
            design(48, 45);
            gotoxy(38, 16);
            cout << "You Have Successfully Logged In : " << '"' << userName << '"' << endl;
            time_t t;
            time(&t);
            gotoxy(39, 18);
            cout << "Logged In Time : " << ctime(&t);
            gotoxy(44, 22);
            cout << "Press any key to continue .... ";
            getch();
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

void ZzeenPay ::menu()
{
    system("cls");
    gotoxy(28, 4);
    design(20, 177);
    cout << "\tWELCOME TO MAIN MENU\t";
    design(20, 177);
    gotoxy(44, 8);
    cout << "[1] . View Customer Accounts";
    gotoxy(44, 9);
    cout << "[2] . Customer Account Registration";
    gotoxy(44, 10);
    cout << "[3] . Edit Customer Account";
    gotoxy(44, 11);
    cout << "[4] . Delete Customer Account";
    gotoxy(44, 12);
    cout << "[5] . Search Customer Account";
    gotoxy(44, 13);
    cout << "[6] . Transaction";
    gotoxy(44, 14);
    cout << "[7] . Log Out !!! ";
    gotoxy(44, 15);
    cout << "[8] . About US ";
    gotoxy(43, 20);
    cout << "Please Enter Your Choice [1-8] : ";
    option();
}

void ZzeenPay ::option()
{
    int i;
    cin >> i;
    system("cls");
    switch (i)
    {
    case 1:
        view();
        break;
    case 2:
        add();
        break;
    case 3:
        edit();
        break;
    case 4:
        del();
        break;
    case 5:
        srch();
        break;
    case 6:
        transactions();
        break;
    case 7:
        menuexit();
        break;
    case 8:
        about();
        break;
    default:
        menu();
    }
}

void ZzeenPay ::srch()
{
    system("cls");
    int a;
    gotoxy(28, 4);
    design(25, 177);
    cout << " SEARCH MENU ";
    design(25, 177);
    gotoxy(49, 10);
    cout << "[1] . Search By Account Number";
    gotoxy(49, 12);
    cout << "[2] . Search By Name ";
    gotoxy(47, 17);
    cout << "Enter Your Choice [1-2] : ";
    scanf("%d", &a);
    system("cls");
    if (a == 1)
    {
        search_acc();
    }
    else if (a == 2)
    {
        search_name();
    }
    else
        menu();
}

void ZzeenPay ::transactions()
{
    system("CLS");
    gotoxy(25, 4);
    design(25, 177);
    cout << "\tTRANSACTION MENU\t";
    design(25, 177);
    gotoxy(49, 9);
    cout << "[1] . Balance Inquiry";
    gotoxy(49, 10);
    cout << "[2] . Cash Deposit";
    gotoxy(49, 11);
    cout << "[3] . Cash Withdrawal";
    gotoxy(49, 12);
    cout << "[4] . Fund Transfer";
    if (val == 1)
    {
        gotoxy(49, 13);
        cout << "[5] . Main Menu";
    }
    else
    {
        gotoxy(49, 13);
        cout << "[5] . Exit";
    }
    gotoxy(45, 17);
    cout << "Please Enter Your Choice [1-5] : ";
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        system("cls");
        chkblnc();
        break;
    case 2:
        system("cls");
        deposit();
        break;
    case 3:
        system("cls");
        withdrawl();
        break;
    case 4:
        if (val == 1)
            menu();
        else
            menuexit();
        break;
    default:
        transactions();
    }
}

void ZzeenPay ::about()
{
    gotoxy(30, 4);
    design(25, 177);
    cout << " ABOUT US ";
    design(25, 177);
    gotoxy(14, 9);
    cout << "It is a Simple Bank Management System.";
    gotoxy(45, 12);
    cout << "Members of Team Zzeen: ";
    gotoxy(28, 13);
    design(65, 205);
    gotoxy(48, 15);
    cout << "[1] . Ashraf";
    gotoxy(48, 16);
    cout << "[2] . Jayaraj";
    gotoxy(48, 17);
    cout << "[3] . Eswar";
    gotoxy(48, 18);
    cout << "[4] . Srisurya";
    gotoxy(41, 20);
    design(42, 196);
    gotoxy(42, 22);
    cout << "Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13)
    {
        menu();
    }
}

class Contact
{
public:
    string phone;
    string email;
};

class EmploymentInfo
{
public:
    string employmentStatus;
    string employerName;
    string jobTitle;
    int monthlyIncome;
};

class FinancialInfo
{
public:
    int annualIncome;
    string sourceOfIncome;
};

class AccountDetails
{
public:
    string accountNumber;
    string accountType;
    string accountOpeningDate;
    int accountBalance;
};

class PersonalInfo
{
public:
    string fullName;
    string dateOfBirth;
    string gender;
    string nationality;
    string address;
    Contact contact;
};

class Transaction
{
public:
    string type;
    int amount;
    string timestamp;
    string payeeInfo;
    string payerInfo;
};

class BankAccount
{
public:
    PersonalInfo personalInfo;
    EmploymentInfo employmentInfo;
    FinancialInfo financialInfo;
    AccountDetails accountDetails;
    vector<Transaction> transactionHistory;
};

void ZzeenPay ::add()
{
    char c;
    BankAccount acc;
    ofstream f;
    f.open("bank.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
    do
    {
        system("cls");
        gotoxy(24, 4);
        design(20, 177);
        cout << "\tCREATE A NEW ACCOUNT\t";
        design(20, 177);

        // Personal Info
        gotoxy(30, 6);
        cout << "Personal Info:";
        gotoxy(36, 8);
        cout << "[1] . Enter Your FullName : ";
        cin >> acc.personalInfo.fullName;
        gotoxy(36, 9);
        cout << "[2] . Enter Your Date-of-Birth : ";
        cin >> acc.personalInfo.dateOfBirth;
        gotoxy(36, 10);
        cout << "[3] . Enter Your Gender   : ";
        cin >> acc.personalInfo.gender;
        gotoxy(36, 11);
        cout << "[4] . Enter Your Nationality   : ";
        cin >> acc.personalInfo.nationality;
        gotoxy(36, 12);
        cout << "[5] . Enter Your Address        : ";
        cin >> acc.personalInfo.address;

        // Contact Info
        gotoxy(36, 14);
        cout << "Contact Info:";
        gotoxy(40, 16);
        cout << "[1] . Enter Your Phone Number : ";
        cin >> acc.personalInfo.contact.phone;
        gotoxy(40, 17);
        cout << "[2] . Enter Your Email : ";
        cin >> acc.personalInfo.contact.email;

        // Employment Info
        gotoxy(30, 21);
        cout << "Employment Info:";
        gotoxy(36, 23);
        cout << "[1] . Enter Your Employment Status : ";
        cin >> acc.employmentInfo.employmentStatus;
        gotoxy(36, 24);
        cout << "[2] . Enter Your Employer Name : ";
        cin >> acc.employmentInfo.employerName;
        gotoxy(36, 25);
        cout << "[3] . Enter Your Job Title : ";
        cin >> acc.employmentInfo.jobTitle;
        gotoxy(36, 26);
        cout << "[4] . Enter Your Monthly Income : ";
        cin >> acc.employmentInfo.monthlyIncome;

        // Financial Info
        gotoxy(30, 41);
        cout << "Financial Info:";
        gotoxy(36, 43);
        cout << "[1] . Enter Your Annual Income : ";
        cin >> acc.financialInfo.annualIncome;
        gotoxy(36, 45);
        cout << "[2] . Enter Your Source of Income : ";
        cin >> acc.financialInfo.sourceOfIncome;

        // Account Details
        gotoxy(30, 50);
        cout << "Account Details:";
        gotoxy(36, 52);
        cout << "[1] . Enter AccountNumber : ";
        cin >> acc.accountDetails.accountNumber;
        gotoxy(36, 54);
        cout << "[2] . Enter AccountType : ";
        cin >> acc.accountDetails.accountType;
        gotoxy(36, 56);
        cout << "[3] . Enter Account Opening Date : ";
        cin >> acc.accountDetails.accountOpeningDate;
        gotoxy(36, 58);
        cout << "[4] . Enter Account Balance : ";
        cin >> acc.accountDetails.accountBalance;

        // Transaction History
        Transaction transaction;
        transaction.type = "Deposit";
        transaction.amount = 1000;
        transaction.timestamp = "2023-01-15T10:30:00Z";
        transaction.payeeInfo = "John Doe (Deposit)";
        transaction.payerInfo = "Mathew (Deposit)";
        acc.transactionHistory.push_back(transaction);

        f.write(reinterpret_cast<char *>(&acc), sizeof(acc)); // whatever &rec is treat it as char *

        gotoxy(38, 64);
        cout << "CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL";
        i++;
        gotoxy(36, 66);
        cout << "Do You Want To Add Another Record ? (Y/N) : ";
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
    f.close();
    gotoxy(40, 70);
    cout << "Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13)
    {
        menu();
    }
    else
        view();
}

void ZzeenPay ::view()
{
    int i = 7;
    BankAccount acc;
    // read from the file
    ifstream f;
    f.open("bank.bin", ios::in | ios::binary); // open file for read only
    gotoxy(25, 3);
    design(25, 177);
    cout << "\tACCOUNTS LIST\t";
    design(25, 177);
    gotoxy(5, 5);
    cout << "A/C No.";
    gotoxy(13, 5);
    cout << "Accountant Name";
    gotoxy(34, 5);
    cout << "Account Type";
    gotoxy(49, 5);
    cout << "Email Address";
    gotoxy(85, 5);
    cout << "Phone No.";
    gotoxy(99, 5);
    cout << "Balance";
    gotoxy(5, 6);
    design(109, 205);

    while (f.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        gotoxy(7, i);
        cout << acc.accountDetails.accountNumber;
        gotoxy(13, i);
        cout << acc.personalInfo.fullName;
        gotoxy(34, i);
        cout << acc.accountDetails.accountType;
        gotoxy(49, i);
        cout << acc.personalInfo.contact.email;
        gotoxy(85, i);
        cout << acc.personalInfo.contact.phone;
        gotoxy(99, i);
        cout << acc.accountDetails.accountBalance << "/-";
        i++;
    }
    f.close();
    int x;
    gotoxy(42, i + 5);
    cout << "Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13)
    { // 13 = '\r' i.e carriage return
        menu();
    }
    else
        view();
}

int chkacc(string a)
{
    BankAccount acc;
    // read binary
    ifstream f;
    f.open("bank.bin", ios::in | ios::binary);
    while (!f.eof())
    {
        f.read(reinterpret_cast<char *>(&acc), sizeof(acc)); // whatever &rec is treat it as char *
        // char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

        if (a == acc.accountDetails.accountNumber)
        {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}

void ZzeenPay ::edit()
{
    BankAccount acc;
    ifstream f1;
    ofstream f2;
    string a;
re: // label for goto
    gotoxy(23, 4);
    design(25, 177);
    cout << "\tEDIT ACCOUNT DETAILS\t";
    design(25, 177);
    gotoxy(43, 7);
    cout << "Enter Your Account Number To Edit : ";
    cin >> a;
    if (chkacc(a) == 1)
    {
        f1.open("bank.bin", ios::in | ios::binary); // read
        f2.open("new.bin", ios::app | ios::binary); // write
        while (f1.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.accountDetails.accountNumber != a)
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            else if (acc.accountDetails.accountNumber == a)
            {
                gotoxy(41, 20);
                design(42, 45);
                gotoxy(52, 21);
                cout << "Account Number Matched";
                gotoxy(41, 22);
                design(42, 45);
                gotoxy(51, 10);
                cout << "Enter Your Details";
                gotoxy(28, 11);
                design(65, 205);
                gotoxy(31, 12);
                cout << "[1] . Enter Your Name           : ";
                cin >> acc.personalInfo.fullName;
                gotoxy(31, 13);
                cout << "[2] . Enter Your Account Number : ";
                cin >> acc.accountDetails.accountNumber;
                gotoxy(31, 14);
                cout << "[3] . Enter Your Phone Number   : ";
                cin >> acc.personalInfo.contact.phone;
                gotoxy(31, 15);
                cout << "[4] . Enter Your Address        : ";
                cin >> acc.personalInfo.address;
                gotoxy(31, 16);
                cout << "[5] . Enter Your E-mail         : ";
                cin >> acc.personalInfo.contact.email;
                gotoxy(31, 17);
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            }
        }
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(41, 20);
        design(42, 45);
        gotoxy(52, 21);
        cout << "Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 45);
        goto re; // unconditional jump statement goto <label>
    }
    remove("bank.bin");
    rename("new.bin", "bank.bin");
    gotoxy(45, 21);
    cout << "ACCOUNT DETAILS UPDATED SUCCESSFULLY";
    gotoxy(42, 24);
    cout << "Press any key to return back to main menu . ";
    getch();
    menu();
}

void ZzeenPay ::del()
{
    BankAccount acc;
    ifstream f1;
    ofstream f2;
    string a;
re:
    gotoxy(23, 4);
    design(25, 177);
    cout << "\tDELETE CUSTOMER ACCOUNT\t";
    design(25, 177);
    gotoxy(41, 9);
    cout << "Enter Your Account Number To Delete : ";
    cin >> a;
    if (chkacc(a) == 1)
    {
        f1.open("bank.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.accountDetails.accountNumber != a)
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
        }
        f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("bank.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
            f1.write(reinterpret_cast<char *>(&acc), sizeof(acc));
        f1.close();
        f2.close();
    }
    else if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(51, 15);
        cout << "Account Doesn't Exist";
        gotoxy(41, 16);
        design(42, 196);
        goto re;
    }
    gotoxy(41, 14);
    design(42, 196);
    gotoxy(44, 15);
    cout << "CUSTOMER ACCOUNT DELETED SUCCESSFULLY";
    gotoxy(41, 16);
    design(42, 196);
    gotoxy(42, 18);
    cout << "Press any key to return back to main menu. ";
    getch();
    menu();
}

void ZzeenPay ::search_acc()
{
    BankAccount acc;
    ifstream f;
    int b = 0;
    string a;
    int x, interestRate = 0.06;
re:
    gotoxy(23, 4);
    design(25, 177);
    cout << "\tSEARCH CUSTOMER ACCOUNT\t";
    design(25, 177);
    gotoxy(43, 6);
    cout << "Enter Your Account Number To Search : ";
    cin >> a;
    if (chkacc(a) == 1)
    {
        f.open("bank.bin", ios::in | ios::binary);
        while (f.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.accountDetails.accountNumber == a)
            {
                gotoxy(41, 21);
                design(42, 196);
                gotoxy(52, 22);
                cout << "Account Number Matched";
                gotoxy(41, 23);
                design(42, 196);
                gotoxy(45, 9);
                cout << "Detail Information of " << acc.personalInfo.fullName;
                gotoxy(28, 10);
                design(65, 205);
                gotoxy(37, 11);
                cout << "[1] . Account Number : " << acc.accountDetails.accountNumber;
                gotoxy(37, 12);
                cout << "[2] . Name           : " << acc.personalInfo.fullName;
                gotoxy(37, 13);
                cout << "[3] . Gender         : " << acc.personalInfo.gender;
                gotoxy(37, 14);
                cout << "[4] . Phone Number   : " << acc.personalInfo.contact.phone;
                gotoxy(37, 15);
                cout << "[5] . Address        : " << acc.personalInfo.address;
                gotoxy(37, 16);
                cout << "[6] . E-mail         : " << acc.personalInfo.contact.email;
                gotoxy(37, 17);
                cout << "[7] . Citizenship    : " << acc.personalInfo.nationality;
                gotoxy(37, 18);
                cout << "[8] . Current Balance: " << acc.accountDetails.accountBalance;
                gotoxy(37, 19);
                cout << "[9] . Status         : ";
                if (acc.accountDetails.accountBalance > 25)
                {
                    cout << "Active";
                }
                else
                {
                    cout << "Inactive";
                }
                gotoxy(37, 20);
                cout << "[10] . Acquired Interest: ";
                double monthlyInterestRate = interestRate / 12;
                double monthlyInterest = acc.accountDetails.accountBalance * monthlyInterestRate;
                acc.accountDetails.accountBalance += monthlyInterest;
                cout << acc.accountDetails.accountBalance << "/-";
                break;
            }
            else
                b = 1;
        }
        f.close();
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout << "Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        goto re;
    }
    gotoxy(42, 24);
    cout << "Press [ENTER] to return back to main menu. ";
    char z = getch();
    if (z == 13)
        menu();
    else
        srch();
}

void ZzeenPay ::search_name()
{
    int i = 0, b, x, interestRate = 0.06;
    string name;
    gotoxy(23, 4);
    design(25, 177);
    cout << "\tSEARCH CUSTOMER ACCOUNT\t";
    design(25, 177);
    gotoxy(43, 6);
    cout << "Enter Your Full Name To Search : ";
    cin >> name;
    BankAccount acc;
    ifstream f;
    f.open("bank.bin", ios::in | ios::binary);
    while (f.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        b = 0;
        if (acc.personalInfo.fullName == name)
        {
            gotoxy(41, 21);
            design(42, 196);
            gotoxy(52, 22);
            cout << "Account Number Matched";
            gotoxy(41, 23);
            design(42, 196);
            gotoxy(45, 9);
            cout << "Detail Information of " << acc.personalInfo.fullName;
            gotoxy(28, 10);
            design(65, 205);
            gotoxy(37, 11);
            cout << "[1] . Account Number : " << acc.accountDetails.accountNumber;
            gotoxy(37, 12);
            cout << "[2] . Name           : " << acc.personalInfo.fullName;
            gotoxy(37, 13);
            cout << "[3] . Gender         : " << acc.personalInfo.gender;
            gotoxy(37, 14);
            cout << "[4] . Phone Number   : " << acc.personalInfo.contact.phone;
            gotoxy(37, 15);
            cout << "[5] . Address        : " << acc.personalInfo.address;
            gotoxy(37, 16);
            cout << "[6] . E-mail         : " << acc.personalInfo.contact.email;
            gotoxy(37, 17);
            cout << "[7] . Citizenship    : " << acc.personalInfo.nationality;
            gotoxy(37, 18);
            cout << "[8] . Current Balance: " << acc.accountDetails.accountBalance;
            gotoxy(37, 19);
            cout << "[9] . Status         : ";
            if (acc.accountDetails.accountBalance > 25)
            {
                cout << "Active";
            }
            else
            {
                cout << "Inactive";
            }
            gotoxy(37, 20);
            cout << "[10] . Acquired Interest: ";
            double monthlyInterestRate = interestRate / 12;
            double monthlyInterest = acc.accountDetails.accountBalance * monthlyInterestRate;
            acc.accountDetails.accountBalance += monthlyInterest;
            cout << acc.accountDetails.accountBalance << "/-";
            break;
        }
        else
            b = 1;
    }
    f.close();
    if (b == 1)
    {
        system("cls");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout << "Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        search_name();
    }
    gotoxy(42, 24);
    cout << "Press [ENTER] to return back to main menu. ";
    char z = getch();
    if (z == 13)
        menu();
    else
        srch();
}

void ZzeenPay ::chkblnc()
{
    BankAccount acc;
    ifstream f;
    string a;
    gotoxy(27, 4);
    design(25, 177);
    cout << "\tBALANCE INQUIRY\t";
    design(25, 177);
    gotoxy(47, 12);
    cout << "Enter Your Account Number : ";
    cin >> a;
    if (chkacc(a) == 1)
    {
        f.open("bank.bin", ios::in | ios::binary);
        while (f.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.accountDetails.accountNumber == a)
            {
                gotoxy(41, 14);
                design(42, 196);
                gotoxy(41, 16);
                design(42, 196);
                gotoxy(50, 15);
                cout << "Your Balance is : $" << acc.accountDetails.accountBalance;
            }
        }
        f.close();
    }
    if (chkacc(a) == 0)
    {
        system("cls");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(41, 16);
        design(42, 196);
        gotoxy(52, 15);
        cout << "Account Doesn't Exist.";
        chkblnc();
    }
    gotoxy(46, 21);
    cout << "Press any key to return back to main menu. ";
    getch();
    transactions();
}

void ZzeenPay ::deposit()
{
    string a;
    double b;
    BankAccount acc;
    ifstream f1;
    ofstream f2;
    gotoxy(29, 4);
    design(25, 177);
    cout << "\tCASH DEPOSIT\t";
    design(25, 177);
    gotoxy(47, 10);
    cout << "Enter Your Account Number : ";
    cin >> a;
    if (chkacc(a) == 1)
    {
        f1.open("bank.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.accountDetails.accountNumber != a)
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            else if (acc.accountDetails.accountNumber == a)
            {
                acc.personalInfo.fullName;
                acc.accountDetails.accountNumber;
                acc.personalInfo.contact.phone;
                acc.personalInfo.address;
                acc.personalInfo.contact.email;
                acc.personalInfo.nationality;
                gotoxy(45, 13);
                cout << "Enter The Amount To Deposit : $ ";
                scanf("%lf", &b);
                acc.accountDetails.accountBalance += b;
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            }
        }
        f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("bank.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
            f1.write(reinterpret_cast<char *>(&acc), sizeof(acc));
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout << "Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        deposit();
    }
    gotoxy(41, 20);
    design(42, 196);
    gotoxy(41, 22);
    design(42, 196);
    gotoxy(52, 15);
    gotoxy(52, 21);
    cout << "CASH DEPOSIT SUCCESSFULL";
    gotoxy(50, 24);
    cout << "Press any key to return back...";
    getch();
    transactions();
}

void ZzeenPay ::withdrawl()
{
    BankAccount acc;
    ifstream f1;
    ofstream f2;
    string a;
    double b, z;
    gotoxy(25, 4);
    design(25, 177);
    cout << "\tCASH WITHDRAWAL\t";
    design(25, 177);
    gotoxy(45, 10);
    cout << "Enter Your Account Number : ";
    cin >> a;
    if (chkacc(a) == 1)
    {
        f1.open("bank.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        gotoxy(42, 13);
        cout << "Enter The Amount To Withdraw : $ ";
        scanf("%lf", &b);
        while (f1.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
        {
            if (acc.accountDetails.accountNumber != a)
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            else if (acc.accountDetails.accountNumber == a)
            {
                acc.personalInfo.fullName;
                acc.accountDetails.accountNumber;
                acc.personalInfo.contact.phone;
                acc.personalInfo.address;
                acc.personalInfo.contact.email;
                acc.personalInfo.nationality;
                z = acc.accountDetails.accountBalance;
                if (b <= acc.accountDetails.accountBalance)
                {
                    acc.accountDetails.accountBalance -= b;
                    gotoxy(39, 20);
                    design(42, 196);
                    gotoxy(39, 22);
                    design(42, 196);
                    gotoxy(44, 21);
                    cout << "    CASH WITHDRAWAL SUCCESSFULL     ";
                }
                if (acc.accountDetails.accountBalance > 100)
                {
                    acc.accountDetails.accountBalance -= 1;
                    gotoxy(46, 16);
                    cout << " 1$ withdrawn charge taken ";
                }
                f2.write(reinterpret_cast<char *>(&acc), sizeof(acc));
            }
        }
        f1.close();
        f2.close();
        remove("bank.bin");
        rename("new.bin", "bank.bin");
        if (z < b)
        {
            system("CLS");
            gotoxy(39, 20);
            design(42, 196);
            gotoxy(39, 22);
            design(42, 196);
            gotoxy(48, 21);
            cout << "Current Balance is " << z;
            gotoxy(42, 24);
            cout << "Entered amount exceeds current balance";
            withdrawl();
        }
    }
    if (chkacc(a) == 0)
    {
        system("CLS");
        gotoxy(39, 20);
        design(42, 196);
        gotoxy(50, 21);
        cout << "Account Doesn't Exist.";
        gotoxy(39, 22);
        design(42, 196);
        withdrawl();
    }
    gotoxy(42, 24);
    cout << "     Press Any Key To Continue ....   ";
    getch();
    transactions();
}

void ZzeenPay ::menuexit()
{
    system("cls");
    gotoxy(30, 4);
    design(25, 177);
    cout << "\tTHANK YOU\t";
    design(25, 177);
    gotoxy(42, 12);
    cout << "USER            :: " << userName;
    time_t t;
    time(&t);
    gotoxy(42, 14);
    cout << "Logged Out Time :: " << ctime(&t);
    fflush(stdin);
    getch();
    gotoxy(0, 26);
    exit(0);
}

int main()
{
    system("cls");
    ZzeenPay zzeen;
    return 0;
}