// s_hash.hpp

#ifndef S_HASH_HPP
#define S_HASH_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class SmarterHashTable {
public:
    SmarterHashTable(int initialCapacity);
    int hash(string key);
    int add(string key);
    bool remove(string key);
    bool search(string key);

    string toString();
    int getSize();
    int getCollisionCount();

private:
    int capacity = 10;
    int size = 0;
    int collisionCount = 0;

    vector<vector<string>> storage; // Use a vector of vectors for chaining

    bool resize();
};

#endif // S_HASH_HPP
