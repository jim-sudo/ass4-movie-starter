#include <iostream>
#include <vector>
#include "customer.h"
using namespace std;


Customer::Customer() {

}

Customer::Customer(int id, string last_name, string first_name) 
: id_(id), last_name_(last_name), first_name_(first_name) { }

int Customer::ID() const {
    return id_;
}

string Customer::LastName() const {
    return last_name_;
}

string Customer::FirstName() const {
    return first_name_;
}

void Customer::SetID(int id) {
    id_ = id;
}

void Customer::SetLastName(string last_name) {
    last_name_ = last_name;
}

void Customer::SetFirstName(string first_name) {
    first_name_ = first_name;
}

bool Customer::Add(string history) {
    history_.push_back(history);
    return true;
}

void Customer::History() const {
    if (history_.empty()) {
        std::cout << "** No transactions found **" << std::endl;
    } else {
        for (const auto& transaction : history_) {
            std::cout << transaction << std::endl;
        }
    }
}

bool Customer::operator==(const Customer &customer) const {
    return id_ == customer.id_ && last_name_ == customer.last_name_ && first_name_ == customer.first_name_;
}

ostream& operator<<(ostream& os, const Customer& customer) {
  os << "Customer ID: " << customer.ID()
     << ", Name: " << customer.FirstName() << " " << customer.LastName();
  return os;
}