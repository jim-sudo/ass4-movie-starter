#include <iostream>
#include <string>
using namespace std;
class Customer {

    private:
        int id_;
        string last_name_;
        string first_name_;
        std::vector<Action> history;

    public:
        int ID();
        string LastName();
        string FirstName();


};
