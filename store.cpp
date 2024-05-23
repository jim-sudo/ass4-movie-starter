#include "store.h"
#include <iostream>
#include <sstream>
using namespace std;

void Store::ReadCustomers(ifstream& file) {
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


Store::Store() {
    Movie::RegisterType('F', new ComedyFactory());
    Movie::RegisterType('D', new DramaFactory());
    Movie::RegisterType('C', new ClassicFactory());
}

void Store::ReadMovies() {
  const string filename = "data4movies.txt";
  ifstream file(filename);
  if (!file) {
    std::cerr << "Could not open the file!" << std::endl;
    return;
  }

  std::string line;
  while (getline(file, line)) {
    if (line.empty()) continue; 

    char type = line[0];
    if (type != 'F' && type != 'D' && type != 'C') {
      std::cerr << "Invalid movie type: " << type << std::endl;
      continue; 
    }

    try {
      auto movie = Movie::Create(type, line.substr(3)); 
      if (movie != nullptr) {
        inventory_.AddMovie(*movie, movie->getStock());
      }
    } catch (const exception& e) {
        cerr << "Error parsing line: " << line << "\n" << e.what() << std::endl;
    }
  }
  cout << endl;
}
 
void Store::PrintCustomers() const{
  customer_table_.print();
}