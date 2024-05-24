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

Inventory& Store::inventory(){
  return inventory_;
}


Store::Store() {
    Movie::RegisterType('F', new ComedyFactory());
    Movie::RegisterType('D', new DramaFactory());
    Movie::RegisterType('C', new ClassicFactory());
}

void Store::ReadMovies() {
  const string filename = "../data4movies.txt";
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

void Store::ReadAndExecuteActions(std::ifstream& in) {
  std::string line;
  while (std::getline(in, line)) {
    std::istringstream iss(line);
    char command;
    iss >> command;

    switch (command) {
    case 'I':
      inventory().PrintInventory();
      break;

    case 'H': {
      int customerID;
      iss >> customerID;
      if (!customer_table_.search(customerID)) {
        std::cerr << "Invalid customer ID: " << customerID << std::endl;
      } else {
        Customer* customer = customer_table_.getCustomer(customerID);
        customer->History();
      }
      break;
    }

    case 'B': {
        int customerID;
        char mediaType, movieType;
        iss >> customerID >> mediaType >> movieType;
        std::string movieInfo;
        std::getline(iss, movieInfo);
        if (customer_table_.search(customerID)) {
          if (inventory_.BorrowMovie(movieType + movieInfo)) {
            Customer* customer = customer_table_.getCustomer(customerID);
            if (customer) {
              customer->Add("Borrowed: " + movieInfo);
            }
          } else {
            std::cerr << "Error: Could not borrow movie: " << movieInfo << std::endl;
          }
        } else {
          std::cerr << "Error: Customer ID " << customerID << " not found." << std::endl;
        }
        break;
      }
    case 'R': {
      int customerID;
      char mediaType, movieType;
      iss >> customerID >> mediaType >> movieType;
      std::string movieInfo;
      std::getline(iss, movieInfo);
      if (customer_table_.search(customerID)) {
        if (inventory_.ReturnMovie(movieType + movieInfo)) {
          Customer* customer = customer_table_.getCustomer(customerID);
          if (customer) {
            customer->Add("Returned: " + movieInfo);
          }
        } else {
          std::cerr << "Error: Could not return movie: " << movieInfo << std::endl;
        }
      } else {
        std::cerr << "Error: Customer ID " << customerID << " not found." << std::endl;
      }
      break;
    }

    default:
      std::cerr << "Invalid command: " << command << std::endl;
      break;
    }
  }
}
