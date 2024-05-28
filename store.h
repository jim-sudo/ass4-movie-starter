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
    
    CustomerHashTable customer_table_;
    
    ComedyFactory *com = nullptr;
    DramaFactory *dram = nullptr;
    ClassicFactory *classic = nullptr;
   
public: 
    Store();    
    void ReadMovies(ifstream& file);
    void ReadCustomers(ifstream& file);
    void ReadAndExecuteActions(ifstream& in);
    Inventory& inventory();
    void PrintCustomers() const;
    ~Store(); 
};

#endif



