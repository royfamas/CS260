#pragma once

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(int value);
    bool search(int value);
    void remove(int value);
    void display();
};
