#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void insertDoubly(DNode*& head, int value) {
    DNode* newNode = new DNode{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int sizeDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

struct CNode {
    int data;
    CNode* next;
};

void insertCircular(CNode*& head, int value) {
    CNode* newNode = new CNode{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

int sizeCircular(CNode* head) {
    if (head == nullptr) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    DNode* dHead = nullptr;
    insertDoubly(dHead, 10);
    insertDoubly(dHead, 20);
    insertDoubly(dHead, 30);
    cout << "Size of Doubly Linked List: " << sizeDoubly(dHead) << endl;

    CNode* cHead = nullptr;
    insertCircular(cHead, 5);
    insertCircular(cHead, 15);
    insertCircular(cHead, 25);
    insertCircular(cHead, 35);
    cout << "Size of Circular Linked List: " << sizeCircular(cHead) << endl;

    return 0;
}
