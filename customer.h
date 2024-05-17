#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Customer {

    private:
        int id_;
        string last_name_;
        string first_name_;
        std::vector<string> history;

    public:
        int ID();
        string LastName();
        string FirstName();


};
