// UID: 24BCS12643
// Linked List Implementation

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = nullptr;
    }
};

class linkedlist {
public:
    node* head = nullptr;

    // Insert at beginning
    void insertAtBeginning(int x) {
        node* newnode = new node(x);
        newnode->next = head;
        head = newnode;
    }

    // Insert at end
    void insertAtEnd(int x) {
        node* newnode = new node(x);

        if (head == nullptr) {
            head = newnode;
            return;
        }

        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    // Insert at given position (1-based)
    void insertInMiddle(int x, int pos) {
        if (pos <= 1) {
            insertAtBeginning(x);
            return;
        }

        node* newnode = new node(x);
        node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Delete node at given position (1-based)
    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            node* del = head;
            head = head->next;
            delete del;
            return;
        }

        node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search element and return position
    int search(int x) {
        node* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (temp->data == x)
                return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    // Display list
    void display() {
        node* temp = head;

        if (temp == nullptr) {
            cout << "NULL\n";
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    linkedlist ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtBeginning(5);
    ll.insertInMiddle(15, 3);

    ll.display();   // 5->10->15->20->NULL

    ll.deleteAtPosition(2);
    ll.display();   // 5->15->20->NULL

    int pos = ll.search(15);
    if (pos != -1)
        cout << "Element found at position: " << pos << endl;
    else
        cout << "Element not found\n";

    return 0;
}
