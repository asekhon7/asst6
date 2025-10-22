#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

void insertEnd(Node*& head, char value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node* head) {
    if (head == nullptr) return true;
    Node* left = head;
    Node* right = head;
    while (right->next != nullptr) {
        right = right->next;
    }
    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 'r');
    insertEnd(head, 'a');
    insertEnd(head, 'c');
    insertEnd(head, 'e');
    insertEnd(head, 'c');
    insertEnd(head, 'a');
    insertEnd(head, 'r');

    if (isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
