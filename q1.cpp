//student id 1024030287
// q1 asst6
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

class CircularLinkedList {
private:
    CNode* last;
public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtBeginning(int data) {
        CNode* newNode = new CNode{data, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void insertAtEnd(int data) {
        CNode* newNode = new CNode{data, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void insertAfter(int target, int data) {
        if (last == nullptr) return;
        CNode* current = last->next;
        do {
            if (current->data == target) {
                CNode* newNode = new CNode{data, current->next};
                current->next = newNode;
                if (current == last) last = newNode;
                return;
            }
            current = current->next;
        } while (current != last->next);
        cout << "Node " << target << " not found.\n";
    }

    void deleteNode(int key) {
        if (last == nullptr) return;
        CNode* curr = last->next;
        CNode* prev = last;
        do {
            if (curr->data == key) {
                if (curr == last && curr->next == last) {
                    delete curr;
                    last = nullptr;
                    return;
                }
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void search(int key) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CNode* current = last->next;
        do {
            if (current->data == key) {
                cout << "Node " << key << " found.\n";
                return;
            }
            current = current->next;
        } while (current != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CNode* current = last->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != last->next);
        cout << "\n";
    }
};

class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        DNode* newNode = new DNode{data, head, nullptr};
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        DNode* newNode = new DNode{data, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int target, int data) {
        DNode* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        DNode* newNode = new DNode{data, temp->next, temp};
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int target, int data) {
        if (head == nullptr) return;
        DNode* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        DNode* newNode = new DNode{data, temp, temp->prev};
        if (temp->prev != nullptr)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        DNode* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        DNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Node " << key << " found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        DNode* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;
    int choice, listType;
    
    while (true) {
        cout << "\nSelect List Type:\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "\nOperations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        if (listType == 2) cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "8. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int data, key;

        if (choice == 1) {
            cout << "Enter data to insert at beginning: ";
            cin >> data;
            if (listType == 1) cll.insertAtBeginning(data);
            else dll.insertAtBeginning(data);
        }
        else if (choice == 2) {
            cout << "Enter data to insert at end: ";
            cin >> data;
            if (listType == 1) cll.insertAtEnd(data);
            else dll.insertAtEnd(data);
        }
        else if (choice == 3) {
            cout << "Enter target node value: ";
            cin >> key;
            cout << "Enter data to insert after " << key << ": ";
            cin >> data;
            if (listType == 1) cll.insertAfter(key, data);
            else dll.insertAfter(key, data);
        }
        else if (choice == 4 && listType == 2) {
            cout << "Enter target node value: ";
            cin >> key;
            cout << "Enter data to insert before " << key << ": ";
            cin >> data;
            dll.insertBefore(key, data);
        }
        else if (choice == 5) {
            cout << "Enter value to delete: ";
            cin >> key;
            if (listType == 1) cll.deleteNode(key);
            else dll.deleteNode(key);
        }
        else if (choice == 6) {
            cout << "Enter value to search: ";
            cin >> key;
            if (listType == 1) cll.search(key);
            else dll.search(key);
        }
        else if (choice == 7) {
            if (listType == 1) cll.display();
            else dll.display();
        }
    }
    return 0;
}
