#include "linked_list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

bool LinkedList::search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::remove(int value) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Element not found" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void LinkedList::display() {
    cout << "List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
