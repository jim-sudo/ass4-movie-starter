#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H
#include "customer.h"

using namespace std;

class CustomerHashTable {
private:
    static const int TABLE_SIZE = 101; // A prime number size for better distribution
    Customer* table;                        // Array to store keys
    bool* occupied;                    // Array to track occupied slots

    static int hashFunction(int key);   // Hash function to compute index
    static int probe(int key, int i);   // Quadratic probing function

public:
    CustomerHashTable();                       // Constructor
    ~CustomerHashTable();                      // Destructor
    bool insert(Customer customer);              // Insert key into the hash table
    bool search(int id) const;        // Search key in the hash table
    Customer* getCustomer(int id);
    bool remove(Customer customer);              // Remove key from the hash table
    void print() const;
};

#endif
