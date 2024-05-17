#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H
#include <customer.h>

using namespace std;

class CustomerHashTable {
    private:
        vector<Customer> customers;
    
        int hash(int customerID);
        int probing(int numCollisions);

    public:
        bool insertCustomer(Customer customer);
        Customer getCustomer(Customer customer);
};

#endif