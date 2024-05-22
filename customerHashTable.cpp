#include "CustomerHashTable.h"

CustomerHashTable::CustomerHashTable() {
    table = new int[TABLE_SIZE];
    occupied = new bool[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        occupied[i] = false;
    }
}

CustomerHashTable::~CustomerHashTable() {
    delete[] table;
    delete[] occupied;
}

int CustomerHashTable::hashFunction(int key) const {
    return key % TABLE_SIZE;
}

int CustomerHashTable::probe(int key, int i) const {
    return (hashFunction(key) + i * i) % TABLE_SIZE;
}

bool CustomerHashTable::insert(int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = probe(key, i);
        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            return true;
        }
    }
    return false; // table is full
}

bool CustomerHashTable::search(int key) const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = probe(key, i);
        if (occupied[idx] && table[idx] == key) {
            return true;
        } else if (!occupied[idx]) {
            return false; // key not found
        }
    }
    return false; // full cycle and not found
}

bool CustomerHashTable::remove(int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = probe(key, i);
        if (occupied[idx] && table[idx] == key) {
            occupied[idx] = false;
            return true; // key removed
        } else if (!occupied[idx]) {
            return false; // key not found
        }
    }
    return false; // key not found after full probing
}
