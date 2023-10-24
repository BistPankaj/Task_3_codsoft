#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ofstream file;
string f_name;
string f_data;
void creat()
{
    cout << "Enter the list name to create: ";
    cin >> f_name;
    f_name = f_name + ".txt";
    file.open(f_name.c_str());
    file.close();
    cout << endl;
}
void add()
{
    cout << "Enter the file name: ";
    cin >> f_name;
    f_name = f_name + ".txt";
    cout << "\nPress exit after you inserted the data in list! " << endl;
    cout << "Insert the data in the list:\n";
    file.open(f_name.c_str(), ios::app);
    while (getline(cin, f_data))
    {
        if (f_data == "exit")
        {
            break;
        }
        file << f_data << endl;
    }
    file.close();
    cout << endl;
}
void view()
{
    fstream file;
    file.open(f_name.c_str());
    if (file.is_open())
    {
        string line;
        cout << "Data in the file:";
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open the list.\n";
        cout << "Please insert the data again.\n";
    }
    cout << "\n";
}
void del()
{
    ifstream file;
    cout << "Enter the list name: ";
    cin >> f_name;
    f_name = f_name + ".txt";
    file.open(f_name.c_str());
    cout << "Enter the data to delete: ";
    cin >> f_data;
    ofstream temp;
    temp.open("temp.txt");
    string line;
    while (getline(file, line))
    {
        if (line != f_data)
        {
            temp << line << endl;
        }
    }
    file.close();
    temp.close();
    remove(f_name.c_str());
    rename("temp.txt", f_name.c_str());
    cout << endl;
}
int main()
{
    cout << "\t\t*********************\n";
    cout << "\t\t*     TO DO LIST    *\n";
    cout << "\t\t*********************\n";
    cout << "Choose for 1: CREATE LIST\n";
    cout << "Choose for 2: ADD DATA LIST\n";
    cout << "Choose for 3: VIEW DATA LIST\n";
    cout << "Choose for 4: DELETE DATA\n\n";
    int choice;
    while (true)
    {
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            creat();
            break;
        case 2:
            add();
            break;
        case 3:
            view();
            break;
        case 4:
            del();
            break;
        default:
            cout << "You have entered the wrong input!\n\n";
        }
    }
}