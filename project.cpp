
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


void cover_page();
void main_page(string);
string fileNameCreate(string);

void login();
void user_register();
void exit();

void add_story(string);
void view_story(string);
void add_password(string);
void view_password(string);
void add_address(string);
void view_address(string);
void log_out();

string fileNameCreate(string name, string type)
{
    string userPath = name + "/" + name + "_" + type + ".txt";
    return userPath;
}
void cover_page()
{
    cout << "\t\t\t..............Personal Diary.............." << endl
         << endl;
    cout << "\t\t\t1.Log in" << endl;
    cout << "\t\t\t2.Register" << endl;
    cout << "\t\t\t3.Exit" << endl;
    cout << "\t\t\tSelect your option:";

    int num1;
    cin >> num1;
    // system("cls");
    switch (num1)
    {
    case 1:
    {
        system("cls");
        login();
        break;
    }

    case 2:
    {
        system("cls");
        user_register();
        break;
    }
    case 3:
    {
        system("cls");
        exit();
        break;
    }
    }
}

void main_page(string username)
{
    cout << "\t\t\t\t.........Welcome to personal Diary ..........." << endl
         << endl;
    cout << "\t\t\t\t\t\tMain Menu" << endl;
    cout << "\t\t\t\t----------------------------------------------" << endl;
    cout << "\t\t\t\t1.Add story" << endl;
    cout << "\t\t\t\t2.View story" << endl;
    cout << "\t\t\t\t3.Add password" << endl;
    cout << "\t\t\t\t4.View password" << endl;
    cout << "\t\t\t\t5.Add address" << endl;
    cout << "\t\t\t\t6.View address" << endl;
    cout << "\t\t\t\t7.Log Out" << endl;
    cout << "\t\t\t\tSelect your option:";
    int num2, num1;
    cin >> num1;

    switch (num1)
    {
    case 1:
    {
        system("cls");
        add_story(username);
        break;
    }

    case 2:
    {
        system("cls");
        view_story(username);
        break;
    }
    case 3:
    {
        system("cls");
        add_password(username);
        break;
    }
    case 4:
    {
        system("cls");
        view_password(username);
        break;
    }

    case 5:
    {
        system("cls");
        add_address(username);
        break;
    }
    case 6:
    {
        system("cls");
        view_address(username);
        break;
    }
    case 7:
    {
        system("cls");
        log_out();
        break;
    }
    }
}

void user_register()
{
    cout << "\t\t\t\t.........Register........" << endl;
    string ruser_name, rpassword, rid, rpass;
    cout << "\t\t\t\tEnter the User Name:";
    cin >> ruser_name;
    cout << "\t\t\t\tEnter the Password:";
    cin >> rpassword;
    ofstream f1("records.txt", ios::out | ios::app);
    f1 << ruser_name << "\t" << rpassword << endl;
    cout << "\t\t\t\tRegister is Successfully!" << endl;
    string createUserPath = "md " + ruser_name;
    char *path;
    path = &createUserPath[0];
    system(path);
    system("cls");
    cover_page();
}

void login()
{
    cout << "\t\t\t\tplease enter the use name and password" << endl;
    int count;
    int count1 = 0;
    string luser_name, password, id, pass;
    cout << "\t\t\t\tUser Name:";
    cin >> luser_name;
    cout << "\t\t\t\tPassword:";
    cin >> password;
    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == luser_name && pass == password)
        {
            count = 1;
        }
    }
    input.close();

    if (count == 1)
    {
        system("cls");
        main_page(luser_name);
    }
    else
    {
        count1++;
        if (count1 < 4)
        {
            cout << endl
                 << "\t\t\t\tLogin ERROR please check your username and password" << endl
                 << endl;
            login();
        }
        else
        {
            system("cls");
            main_page(luser_name);
        }
    }
}
void exit()
{
    cout << endl
         << endl
         << "\t\t\t\t***********************" << endl;
    cout << "\t\t\t\t*                     *" << endl;
    cout << "\t\t\t\t*"
         << "      THANK YOU      *" << endl;
    cout << "\t\t\t\t*                     *" << endl;
    cout << "\t\t\t\t***********************" << endl;
}

void add_story(string username)
{

    int n;
    string name, title;
    ofstream file(fileNameCreate(username, "story"), ios::out | ios::app);
    cout << endl
         << "\t\t\t\tStory length:";
    cin >> n;
    cin.ignore();
    cout << "\t\t\t\tStory Title:";
    getline(cin, title);
    file << endl
         << endl
         << "\t\t\t\t"
         << "***** " << title << " *****" << endl
         << endl;
    system("cls");

    cout << endl
         << "\t\t\t\tEnter your story" << endl;
    cout << "\t\t\t................................" << endl
         << endl;

    for (int i = 0; i < n; i = i + name.size())
    {
        getline(cin, name);
        file << "\t" << name << endl;
    }
    file.close();
    system("cls");
    main_page(username);
}
void view_story(string username)
{
    int n;
    string view;
    ifstream file(fileNameCreate(username, "story"));
    while (getline(file, view))
    {
        cout << view << endl;
    }
    file.close();

    system("pause");
    system("cls");
    main_page(username);
}
void add_password(string username)
{
    string name, password;
    cin.ignore();
    ofstream file(fileNameCreate(username, "password"), ios::out | ios::app);
    cout << "ID Name:";
    getline(cin, name);
    cout << "Password:";
    getline(cin, password);
    file << "\t" << name << "\t\t" << password << endl;
    file.close();
    system("pause");
    system("cls");
    main_page(username);
}
void view_password(string username)
{
    int n;
    string view;
    ifstream file(fileNameCreate(username, "password"));
    while (getline(file, view))
    {
        cout << view << endl;
    }
    file.close();

    system("pause");
    system("cls");
    main_page(username);
}
void add_address(string username)
{
    string name, phone, email, district;
    ofstream file(fileNameCreate(username, "address"), ios::out | ios::app);
    cin.ignore();
    cout << "\t\t\t\tName         :";
    getline(cin, name);
    cout << "\t\t\t\tPhone Number :";
    getline(cin, phone);
    cout << "\t\t\t\tEmail        :";
    getline(cin, email);
    cout << "\t\t\t\tDistrict     :";
    getline(cin, district);
    file << endl
         << name << "\t" << phone << "\t" << email << "\t" << district << endl;
    file.close();

    system("cls");
    main_page(username);
}
void view_address(string username)
{
    int n;
    string view;
    ifstream file(fileNameCreate(username, "address"));
    while (getline(file, view))
    {
        cout << view << endl;
    }
    file.close();

    system("pause");
    system("cls");
    main_page(username);
}

void log_out()
{
    cover_page();
}

int main()
{
    system("cls");
    system("color F0");
    cover_page();

    // main_page();

    getch();
}
