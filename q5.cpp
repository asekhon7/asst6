#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool isCircular(Node* head) {
    if (head == nullptr) return false;
    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
    return temp == head;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    if (isCircular(head))
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular Linked List" << endl;


    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;

    if (isCircular(head))
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular Linked List" << endl;

    return 0;
}
