#include <iostream>

#include "hash.hpp"
#include "s_hash.hpp"

using std::cout;
using std::endl;

int main() {
    // Simple Hash Table Tests
    HashTable ht(10);
    cout << "Simple Hash Table Tests:" << endl;
    cout << "Create table." << endl;
    cout << "table contents (empty table): " << ht.toString() << endl;
    cout << "size of empty table: " << ht.getSize() << endl;
    cout << "============================" << endl;

    int result = ht.add("Joseph");
    cout << "Add Joseph (" << result << ")." << endl;
    cout << "table contents (one entry): " << ht.toString() << endl;
    cout << "size of table after 1 add: " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;
    cout << "============================" << endl;

    result = ht.add("Josepi");
    cout << "Add Josepi (" << result << ")." << endl;
    cout << "table contents (non-collision second entry): " << ht.toString() << endl;
    cout << "size of table after 2 add (non-collision): " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;
    cout << "============================" << endl;

    result = ht.add("cats");
    cout << "Add cats (" << result << ")." << endl;
    cout << "table contents (collision third entry): " << ht.toString() << endl;
    cout << "size of table after 3 add (1 collision): " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;
    cout << "============================" << endl;

    result = ht.remove("cats");
    cout << "Remove cats (success: " << result << ")." << endl;
    cout << "table contents (remove cats): " << ht.toString() << endl;
    cout << "size of table after 3 add and one remove (1 collision): " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;
    cout << "============================" << endl << endl;

    // Smarter Hash Table Tests
    SmarterHashTable sht(10);
    cout << "Smarter Hash Table Tests:" << endl;
    cout << "Create table." << endl;
    cout << "table contents (empty table): " << sht.toString() << endl;
    cout << "size of empty table: " << sht.getSize() << endl;
    cout << "============================" << endl;

    result = sht.add("Joseph");
    cout << "Add Joseph (" << result << ")." << endl;
    cout << "table contents (one entry): " << sht.toString() << endl;
    cout << "size of table after 1 add: " << sht.getSize() << endl;
    cout << "collision count: " << sht.getCollisionCount() << endl;
    cout << "============================" << endl;

    result = sht.add("Josepi");
    cout << "Add Josepi (" << result << ")." << endl;
    cout << "table contents (non-collision second entry): " << sht.toString() << endl;
    cout << "size of table after 2 add (non-collision): " << sht.getSize() << endl;
    cout << "collision count: " << sht.getCollisionCount() << endl;
    cout << "============================" << endl;

    result = sht.add("cats");
    cout << "Add cats (" << result << ")." << endl;
    cout << "table contents (collision third entry): " << sht.toString() << endl;
    cout << "size of table after 3 add (1 collision): " << sht.getSize() << endl;
    cout << "collision count: " << sht.getCollisionCount() << endl;
    cout << "============================" << endl;

    result = sht.remove("cats");
    cout << "Remove cats (success: " << result << ")." << endl;
    cout << "table contents (remove cats): " << sht.toString() << endl;
    cout << "size of table after 3 add and one remove (1 collision): " << sht.getSize() << endl;
    cout << "collision count: " << sht.getCollisionCount() << endl;
    cout << "============================" << endl;

    return 0;
}
