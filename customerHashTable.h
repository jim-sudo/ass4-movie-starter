#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H
#include "customer.h"

using namespace std;

// class CustomerHashTable {
//     private:
//         vector<Customer> customers;
    
//         int hash(int customerID);
//         int probing(int numCollisions);

//     public:
//         bool insertCustomer(Customer customer);
//         Customer getCustomer(Customer customer);
// };


class CustomerHashTable {
private:
    static const int TABLE_SIZE = 101; // A prime number size for better distribution
    Customer* table;                        // Array to store keys
    bool* occupied;                    // Array to track occupied slots

    int hashFunction(int key) const;   // Hash function to compute index
    int probe(int key, int i) const;   // Quadratic probing function

public:
    CustomerHashTable();                       // Constructor
    ~CustomerHashTable();                      // Destructor
    bool insert(Customer customer);              // Insert key into the hash table
    bool search(Customer customer) const;        // Search key in the hash table
    bool remove(Customer customer);              // Remove key from the hash table
    void print() const;
};



#endif
