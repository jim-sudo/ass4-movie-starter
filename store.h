#ifndef STORE_H_
#define STORE_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "movie.h"
#include "customerHashTable.h"
#include "movieInventory.h"

using namespace std;
class Store {
    private:
        MovieInventory movies_;
        CustomerHashTable customer_table_;
    public: 
        void ReadMovies(ifstream in);
        void ReadCustomers(ifstream in);
        void ReadAndExecuteActions(ifstream in);
};
#endif
