#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Contact
{
    int id;
    string name;
    string surname;
    string phoneNumber;
    string mailAddress;
    string address;

};
vector <Contact> readDataFromFile();
void convertContactBook(string, vector <Contact>);

int main()
{
    string fileName;
    vector <Contact> allContacts;
    fstream file;

    do
    {
        system("cls");
        cout << "Please type filename (without extension .txt): ";
        cin >> fileName;
        file.open(fileName+".txt", ios::in);
    }
    while (!file.good());

    allContacts = readDataFromFile();
    convertContactBook(fileName, allContacts);
    return 0;
}

vector <Contact> readDataFromFile()
{
    fstream contactBook;
    contactBook.open("contactBook.txt", ios::in);

    vector <Contact> contactsFromFile;
    Contact contactInfo;
    string contactId;
    while (getline(contactBook, contactId))
    {
        contactInfo.id = atoi(contactId.c_str());
        getline(contactBook, contactInfo.name);
        getline(contactBook, contactInfo.surname);
        getline(contactBook, contactInfo.phoneNumber);
        getline(contactBook, contactInfo.mailAddress);
        getline(contactBook, contactInfo.address);

        contactsFromFile.push_back(contactInfo);
    }
    return contactsFromFile;

}

void convertContactBook(string fileName, vector <Contact> allContacts)
{
    fstream contactBook;
    contactBook.open(fileName+"_new_format.txt", ios::out | ios::trunc);

    for (int i = 0; i < allContacts.size(); i++)
        contactBook << allContacts[i].id << "|"
                    << allContacts[i].name << "|"
                    << allContacts[i].surname << "|"
                    << allContacts[i].phoneNumber << "|"
                    << allContacts[i].mailAddress << "|"
                    << allContacts[i].address << "|" << endl;

    contactBook.close();
    cout << endl << "File has been converted!" << endl;
}
