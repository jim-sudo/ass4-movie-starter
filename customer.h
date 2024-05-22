#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Customer {

    private:
        int id_;
        string last_name_;
        string first_name_;
        std::vector<string> history_;

    public:
        Customer();
        Customer(int id, string last_name, string first_name);
        int ID() const;
        string LastName() const;
        string FirstName() const;
        void SetID(int id);
        void SetLastName(string last_name);
        void SetFirstName(string first_name);
        bool Add(string history);
        vector<string> History();
        bool operator==(const Customer &customer) const;


};
#endif
