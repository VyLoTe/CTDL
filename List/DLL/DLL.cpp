#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node *prev;
    Node *next;

    // Constructor should be public
    Node(T dulieu) : data(dulieu), next(nullptr), prev(nullptr) {}
};

int main() {
    Node<int> A(12);
    Node<int>* head = &A;  
    Node<int> B(14);
    Node<int> C(16);
    A.next = &B;
    B.prev = &A;
    B.next = &C;
    C.prev = &B;
    // while(head != nullptr) {
    //     cout << head->data << " ";
    //     head = head->next;
    // }

    // Node<int>* temp = head;
    // while(temp->next != nullptr) {
    //     temp = temp->next; 
    // } 
    
    // while(temp != nullptr) {
    //     cout << temp->data << " ";
    //     temp = temp->prev;
    // }
    // chen vao dang trc
    Node<int> D(29);
    D.next = head;
    head->prev = &D;
    head = &D;
    // while(head != nullptr) {
    //     cout << head->data << " ";
    //     head = head->next;
    // }

    Node<int> E(26);
    Node<int>* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next; 
    } 
    temp->next = &E;
    E.prev = temp;
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
