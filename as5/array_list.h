#pragma once

const int MAX_SIZE = 100;

class ArrayList {
private:
    int elements[MAX_SIZE];
    int size;

public:
    ArrayList();
    void insert(int value);
    bool search(int value);
    void remove(int value);
    void display();
};
