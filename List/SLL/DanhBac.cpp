#include <iostream>
#include <string>
using namespace std;

#pragma region Contact
class Contact
{   
    string fax;
    string name;
    string address;
public:
    friend istream& operator>>(istream &is, Contact &contact)
    {
        cout << "Enter your number phone\n";
        getline(is, contact.fax);
        cout << "Enter your name\n";
        getline(is, contact.name);
        cout << "Enter your address\n";
        getline(is, contact.address);
        return is;
    }
    friend ostream& operator<<(ostream &os, const Contact contact)
    {
        os << contact.fax << ' ' << contact.name << ' ' << contact.address << '\n' << '\n';
        return os;
    }
    Contact() {}
    // Contact(string fax, string name, string address) {
    //     this->fax = fax;
    //     this->name = name;
    //     this->address = address;
    // }
    Contact(string sdt, string ten, string diaChi) : fax(sdt), name(ten), address(diaChi) {}
    string getName() {
        return name;
    }
};
#pragma endregion

#pragma region Node
class Node{
    public:
        Contact data;
        Node *next = NULL;
};
#pragma endregion

#pragma region DanhBa
class danhBa{
    private:
        Node *head;
    public:
        danhBa() : head(nullptr) {}
        void addContact(const Contact& contact) {
            Node* newNode = new Node(); 
            newNode->data = contact;
            newNode->next = head; // cho nó trỏ tới nút đầu
            head = newNode; // cập nhật để nút mới trở thành nút đầu
        }
        void deleteContact(const string& name) {
            Node* current = head;
            Node* previous = nullptr;

            while(current != nullptr && current->data.getName() != name) {
                previous = current; 
                current = current->next;
            }

            if (current != nullptr) {
                if (previous != nullptr) {
                    previous->next = current->next; // xóa nút giữa hoặc cuối
                }
                else {
                    head = current->next; // nút cần xóa là nút đầu
                }
                delete current;
                cout << "contact having name: " << name << "has been deleted!\n";
            }
            else {
                cout  << "contact having name: " << name << "does not exist!\n";
            }
        }
        void editContact(const string& name) {
            Node* current = head;

            while(current != nullptr) {
                if (current->data.getName() == name) {
                    cout << "Pls type your info again!\n";
                    cin >> current->data;
                    cout << "The info ontact has been changed\n";
                    break;
                }
                current = current->next;
                if (current == nullptr) {
                    cout << "The contact does not exsit!\n";
                    break;
                }
            }

            // while (current != nullptr &&  current->data.getName() != name) {
            //     current = current->next;
            // }
            
            // if (current != nullptr) {
            //     cout << "Pls fill in your info again1:\n";
            //     cin >> current->data;
            //     cout << "The info contact has been changed\n";
            // }
            // else {
            //     cout << "not found\n";
            // }

        }
        void searchContact(const string& name) {
            Node* current = head;
            // while (current != nullptr)
            // {
            //     if (current->data.setName() == name) {
            //         cout << "The contact has been found\n";
            //         cout << current->data;
            //         break;
            //     }
            //     current = current->next;
            //     if (current == nullptr) {
            //         cout << "The contact does not exsit!\n";
            //         break;
            //     }
            // }

            while (current != nullptr &&  current->data.getName() != name) {
                current = current->next;
            }
            if (current != nullptr) {
                cout << "The contact has been found\n";
            }
            else {
                cout << "The contact does not exsit\n";
            }
        }

        friend ostream& operator<<(ostream &os, const danhBa &danhba) {
            Node* current = danhba.head;
            while (current != nullptr) {
                os << current->data;
                current = current->next;
            }
            return os;
        }
};
#pragma endregion

#pragma region MENU
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int choice;
    danhBa danhba;
    Contact contact;
    string name;

    do {
        cout << "\033[1m====================================\033[0m\n";
        cout << "\033[1m          CONTACT MANAGER           \033[0m\n";
        cout << "\033[1m====================================\033[0m\n";
        cout << "\033[1m1. ADD A CONTACT\033[0m\n";
        cout << "\033[1m2. DELETE A CONTACT\033[0m\n";
        cout << "\033[1m3. MODIFY A CONTACT\033[0m\n";
        cout << "\033[1m4. SEARCH A CONTACT\033[0m\n";
        cout << "\033[1m5. PRINT CONTACT LIST\033[0m\n";
        cout << "\033[1m6. EXIT\033[0m\n";
        cout << "\033[1m====================================\033[0m\n";
        cout << "\033[1mEnter your choice: \033[0m";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cin >> contact;
            danhba.addContact(contact);
            break;
        case 2:
            getline(cin, name);
            danhba.deleteContact(name);
            break;
        case 3:
            getline(cin, name);
            danhba.editContact(name);
            break;
        case 4:
            cin.ignore();
            getline(cin, name);
            danhba.searchContact(name);
            break;
        case 5:
            cout << "The list of information contacts\n";
            cout << danhba << '\n';
            break;
        case 6:
            cout << "You've alreadly exited\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }while(choice != 6);

    return 0;
}
#pragma endregion