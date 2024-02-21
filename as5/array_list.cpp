#include "array_list.h"
#include <iostream>

using namespace std;

ArrayList::ArrayList() {
    size = 0;
}

void ArrayList::insert(int value) {
    if (size == MAX_SIZE) {
        cout << "List is full" << endl;
        return;
    }

    int i = size - 1;
    while (i >= 0 && elements[i] > value) {
        elements[i + 1] = elements[i];
        i--;
    }

    elements[i + 1] = value;
    size++;
}

bool ArrayList::search(int value) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return true;
        }
    }
    return false;
}

void ArrayList::remove(int value) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Element not found" << endl;
        return;
    }

    for (int i = pos; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}

void ArrayList::display() {
    cout << "List: ";
    for (int i = 0; i < size; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}
