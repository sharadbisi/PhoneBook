#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;

public:
    Contact(string name, string phoneNumber, string email) : name(name), phoneNumber(phoneNumber), email(email) {}

    string getName() {
        return name;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    string getEmail() {
        return email;
    }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    void setEmail(string email) {
        this->email = email;
    }

    void displayContact() {
        cout << "Name: " << name << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }
};

class Phonebook {
private:
    vector<Contact> contacts;

public:
    void addContact(Contact contact) {
        contacts.push_back(contact);
    }

    Contact* findContactByName(string name) {
        for (auto& contact : contacts) {
            if (contact.getName() == name) {
                return &contact;
            }
        }
        return nullptr;
    }

    bool updateContact(string name, string newPhoneNumber, string newEmail) {
        Contact* contact = findContactByName(name);
        if (contact != nullptr) {
            contact->setPhoneNumber(newPhoneNumber);
            contact->setEmail(newEmail);
            return true;
        }
        return false;
    }

    bool deleteContact(string name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getName() == name) {
                contacts.erase(it);
                return true;
            }
        }
        return false;
    }

    void listAllContacts() {
        for (auto& contact : contacts) {
            contact.displayContact();
            cout << "---------------" << endl;
        }
    }
};

int main() {
    Phonebook phonebook;

    while (true) {
        cout << "Phonebook Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. List All Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1: {
                cout << "Enter name: ";
                string name;
                getline(cin, name);
                cout << "Enter phone number: ";
                string phoneNumber;
                getline(cin, phoneNumber);
                cout << "Enter email: ";
                string email;
                getline(cin, email);
                Contact newContact(name, phoneNumber, email);
                phonebook.addContact(newContact);
                cout << "Contact added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter name to search: ";
                string searchName;
                getline(cin, searchName);
                Contact* foundContact = phonebook.findContactByName(searchName);
                if (foundContact != nullptr) {
                    cout << "Contact found:" << endl;
                    foundContact->displayContact();
                } else {
                    cout << "Contact not found." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter name to update: ";
                string updateName;
                getline(cin, updateName);
                cout << "Enter new phone number: ";
                string newPhone;
                getline(cin, newPhone);
                cout << "Enter new email: ";
                string newEmail;
                getline(cin, newEmail);
                bool updated = phonebook.updateContact(updateName, newPhone, newEmail);
                if (updated) {
                    cout << "Contact updated successfully!" << endl;
                } else {
                    cout << "Contact not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter name to delete: ";
                string deleteName;
                getline(cin, deleteName);
                bool deleted = phonebook.deleteContact(deleteName);
                if (deleted) {
                    cout << "Contact deleted successfully!" << endl;
                } else {
                    cout << "Contact not found." << endl;
                }
                break;
            }
            case 5:
                phonebook.listAllContacts();
                break;
            case 6:
                cout << "Exiting Phonebook. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
