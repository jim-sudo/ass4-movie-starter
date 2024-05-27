#include "store.h"
#include <iostream>
#include <sstream>


ComedyFactory* com = nullptr;
DramaFactory* dram = nullptr;
ClassicFactory* classic = nullptr;

void Store::ReadCustomers(ifstream& file) {
    string line;
    int id;
    string last_name;
    string first_name;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (getline(file, line)) {
        istringstream iss(line);
        if (!(iss >> id >> last_name >> first_name)) {
            cerr << "Error reading line: " << line << endl;
            continue; // Handles lines that do not have exactly three words
        }
        Customer customer(id, last_name, first_name);
        customer_table_.insert(customer);
    }
    file.close();

}

Inventory& Store::inventory(){
  return inventory_;
}


// Store::Store() {
//     Movie::RegisterType('F', new ComedyFactory());
//     Movie::RegisterType('D', new DramaFactory());
//     Movie::RegisterType('C', new ClassicFactory());
// // }

Store::Store() {
    com = new ComedyFactory();
    dram = new DramaFactory();
    classic = new ClassicFactory();
    Movie::RegisterType('F', com);
    Movie::RegisterType('D', dram);
    Movie::RegisterType('C', classic);
}

Store::~Store() {
    delete com;
    delete dram;
    delete classic;
}

void Store::ReadMovies(ifstream& file) {
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
            auto* movie = Movie::Create(type, line.substr(3));
            if (movie != nullptr) {
                inventory_.AddMovie(*movie, movie->getStock());
            }
            delete movie;
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
            case 'I': {
                inventory().PrintInventory();
                break;
            }
            case 'H': {
                int cusomter_id;
                iss >> cusomter_id;
                if (customer_table_.search(cusomter_id)) {
                    Customer* customer = customer_table_.getCustomer(cusomter_id);
                    cout << endl;
                    std::cout << "History for customer " << cusomter_id << ":" << std::endl;
                    cout << endl;
                    customer->History();
                } else {
                    std::cerr << "Invalid customer ID: " << cusomter_id << std::endl;
                }
                break;
                }
            case 'B':
            case 'R': {
                int cusomter_id;
                char media_type;
                iss >> cusomter_id >> media_type;

                std::string movie_type;
                std::string movie_info;
                std::getline(iss >> std::ws, movie_info);

                if (customer_table_.search(cusomter_id)) {
                    Customer* customer = customer_table_.getCustomer(cusomter_id);
                    bool success;
                    if (command == 'B') {
                        success = inventory_.BorrowMovie(movie_info);
                    } else {
                        success = inventory_.ReturnMovie(movie_info);
                    }

                    if (success) {
                        std::string action = (command == 'B') ? "Borrowed" : "Returned";
                        std::string combined = action;
                        combined.append(": ").append(movie_info);
                        customer->Add(combined);
                    } else {
                        std::cerr << "Error: Could not " << (command == 'B' ? "borrow" : "return") << " movie: " << movie_info << std::endl;
                    }
                } else {
                    std::cerr << "Error: Customer ID " << cusomter_id << " not found." << std::endl;
                }
                break;
            }
            default:
                std::cerr << "Invalid command: " << command << std::endl;
                break;
        }
    }
}
