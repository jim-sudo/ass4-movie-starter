/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include "store.h"
#include "movie.h"
#include "inventory.h"

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
    // this test function tests movie being
    // inserted into inventory and sorted per the requirement.
    Store store;
    ifstream movieFile("data4movies.txt");
    store.ReadMovies(movieFile);
    cout << "Inventory: " << endl;
    cout << endl;
    store.inventory().PrintInventory();
}

void testStore3() {
  // this test function tests customer being
  // inserted into customer Hashtable.
  Store store;
  ifstream stream("data4customers.txt");
  store.ReadCustomers(stream);
  store.PrintCustomers();

}
void testStore4() {
  // this test function tests command are read and executesd. 
  Store store;
  ifstream moviefile("data4movies.txt");
  store.ReadMovies(moviefile);
  ifstream customerfile("data4customers.txt");
  store.ReadCustomers(customerfile);
  ifstream commandfile("testCommandtext.txt");
  store.ReadAndExecuteActions(commandfile);
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  // testStore1();
  //testStore2();
  //testStore3();
  testStore4();
  // testStoreFinal();
}
