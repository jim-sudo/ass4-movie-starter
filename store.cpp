#include "store.h"
#include <iostream>
#include <sstream>
using namespace std;

void Store::ReadCustomers(ifstream file) {
    string line;
    int id;
    string lastName, firstName;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (getline(file, line)) {
        istringstream iss(line);
        if (!(iss >> id >> lastName >> firstName)) {
            cerr << "Error reading line: " << line << endl;
            continue; // Handles lines that do not have exactly three words
        }
        Customer customer(id, lastName, firstName);
        customer_table_.insert(customer);
    }



    file.close();

}
