// s_hash.cpp

#include <sstream>

#include "s_hash.hpp"

using std::stringstream;

SmarterHashTable::SmarterHashTable(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    collisionCount = 0;

    storage.resize(capacity); // Resize the vector of vectors
}

int SmarterHashTable::hash(string value) {
    int result = 0;
    for (char c : value) {
        result += (int)c;
    }

    result %= capacity;

    return result;
}

int SmarterHashTable::add(string value) {
    int bucket = hash(value);
    storage[bucket].push_back(value);
    ++size;

    if (storage[bucket].size() > 1) {
        ++collisionCount;
    }

    return bucket;
}

bool SmarterHashTable::remove(string value) {
    int bucket = hash(value);
    for (auto it = storage[bucket].begin(); it != storage[bucket].end(); ++it) {
        if (*it == value) {
            storage[bucket].erase(it);
            --size;
            return true;
        }
    }
    return false;
}

bool SmarterHashTable::search(string value) {
    int bucket = hash(value);
    for (const string& str : storage[bucket]) {
        if (str == value) {
            return true;
        }
    }
    return false;
}

bool SmarterHashTable::resize() {
    // Implementation of resize function
    // ...

    return true;
}

string SmarterHashTable::toString() {
    stringstream result;
    for (int i = 0; i < capacity; ++i) {
        result << "Bucket " << i << ": ";
        for (const string& str : storage[i]) {
            result << str << ", ";
        }
        result << "\n";
    }

    return result.str();
}

int SmarterHashTable::getSize() {
    return size;
}

int SmarterHashTable::getCollisionCount() {
    return collisionCount;
}
