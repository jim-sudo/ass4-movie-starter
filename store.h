#ifndef STORE_H_
#define STORE_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "movie.h"
#include "customerHashTable.h"
#include "inventory.h"

using namespace std;
class Store {
private:
    Inventory inventory_;
    
//    CustomerHashTable customer_table_;
public: 
    Store();    
    void ReadMovies();
    void ReadCustomers(ifstream in);
    void ReadAndExecuteActions(ifstream in);
    Inventory& inventory() { return inventory_; }
};
#endif



