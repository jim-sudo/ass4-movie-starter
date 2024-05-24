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
  cout << "Start MovieRead" << endl;
  Store store;
  store.ReadMovies();

  cout << "Inventory: " << endl;
  cout << endl;
  store.inventory().PrintInventory();

  cout << "End MovieRead" << endl;
}

void testStore3() {
  Store store;
  ifstream stream("../data4customers.txt");
  store.ReadCustomers(stream);
  store.PrintCustomers();

  store.ReadMovies();


  ifstream cstream("../data4commands.txt");
  store.ReadAndExecuteActions(cstream);
}
void testStore4() {
  Store store;
  ifstream stream("../data4commands.txt");
  store.ReadAndExecuteActions(stream);
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  // testStore1();
  // testStore2();
  testStore3();
  //testStore4();
  // testStoreFinal();
}
