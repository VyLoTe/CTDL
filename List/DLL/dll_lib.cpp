#include <bits/stdc++.h>
using namespace std;

template<class T>
class DLL{
    class Node{
        public:
        T data;
        Node *prev;
        Node *next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
        T& getData() {return data;}
    };
    Node* head;
    int num = 0;
    public:
        DLL() : head(nullptr) {}
        void pushFront(T value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            num++;
        }
        void pushBack(T value) {
            Node *newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            num++;
        }
        int getSize() {return num;}
        void insertNode(T value, int pos) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            if (pos <= 0) {
                pushFront(value);
            }
            else if (pos < num-1) {
                Node* temp = head;
                for (int i = 0; i < num-1; ++i) {
                    if (i == pos) {
                       Node* current = temp;
                       newNode->next = current;
                       newNode->prev = current->prev; 
                       current = temp;
                       return;
                    }
                    temp = temp->next;
                }
            }
            else pushBack(value);
        }
        void popFront() {

        }
        void popBack() {

        }
        void eraseNode(int pos) {
            Node *temp = head;
            if (pos <= 0) popFront();
            else if (pos < num-1) {
                for (int i = 0; i < num-1; ++i) {
                    if (i == pos) {
                        temp->prev->next = temp->next;
                        num--;
                        break;
                    }
                    temp = temp->next;
                }    
            }
            else popBack();
        }
        void clearList() {

        }
        void inTrc() {
            Node* temp = head;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void inSau() {
            Node *temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
};

int main() {
    DLL<int> a;
    a.pushBack(4);
    a.pushFront(3);
    a.insertNode(5, 0);
    a.insertNode(7, 4);
    a.pushBack(9);
    a.inTrc();
    a.inSau();
    a.eraseNode(3);
    a.inTrc();

    return 0;
}