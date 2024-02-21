#include <iostream>
#include "array_list.h"
#include "linked_list.h"

using namespace std;

int main() {
    // Test array-based list
    cout << "Array-based List:" << endl;
    ArrayList arrayList;

    arrayList.insert(3);
    arrayList.insert(2);
    arrayList.insert(1);
    arrayList.display();

    cout << "Search 2: " << (arrayList.search(2) ? "Found" : "Not found") << endl;
    cout << "Search 10: " << (arrayList.search(5) ? "Found" : "Not found") << endl;

    arrayList.remove(2);
    arrayList.display();

    cout << endl;

    // Test linked list
    cout << "Linked List:" << endl;
    LinkedList linkedList;

    linkedList.insert(400);
    linkedList.insert(11);
    linkedList.insert(33);
    linkedList.display();

    cout << "Search 111: " << (linkedList.search(111) ? "Found" : "Not found") << endl;
    cout << "Search 11: " << (linkedList.search(11) ? "Found" : "Not found") << endl;

    linkedList.remove(11);
    linkedList.display();

    return 0;
}
