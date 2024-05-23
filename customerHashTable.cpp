#include "customer.h"
#include "customerHashTable.h"

using namespace std;


CustomerHashTable::CustomerHashTable() {
    table = new Customer[TABLE_SIZE];
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

bool CustomerHashTable::insert(Customer customer) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = probe(customer.ID(), i);
        if (!occupied[idx]) {
            table[idx] = customer;
            occupied[idx] = true;
            return true;
        }
    }
    return false; // table is full
}

bool CustomerHashTable::search(Customer customer) const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = probe(customer.ID(), i);
        if (occupied[idx] && table[idx] == customer) {
            return true;
        } else if (!occupied[idx]) {
            return false; // key not found
        }
    }
    return false; // full cycle and not found
}

void CustomerHashTable::print() const{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i].FirstName().empty()) {
            cout << "at index " << i << ": " << table[i] << endl;;
        }
        
    }
    cout << endl;
}

bool CustomerHashTable::remove(Customer customer) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = probe(customer.ID(), i);
        if (occupied[idx] && table[idx] == customer) {
            occupied[idx] = false;
            return true; // key removed
        } else if (!occupied[idx]) {
            return false; // key not found
        }
    }
    return false; // key not found after full probing
}



