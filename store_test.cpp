/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "inventory.h"
#include "movie.h"
#include "store.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char command_type;
  string discard;
  while (fs >> command_type) {
    out << command_type;
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
  ifstream movie_file("data4movies.txt");
  store.ReadMovies(movie_file);
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
  ifstream movie_file("data4movies.txt");
  store.ReadMovies(movie_file);
  ifstream customerfile("data4customers.txt");
  store.ReadCustomers(customerfile);
  ifstream commandfile("testCommandtext.txt");
  store.ReadAndExecuteActions(commandfile);
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store store;
  ifstream movie_file("data4movies.txt");
  store.ReadMovies(movie_file);
  ifstream customerfile("data4customers.txt");
  store.ReadCustomers(customerfile);
  ifstream commandfile("data4commands.txt");
  store.ReadAndExecuteActions(commandfile);
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  // testStore1();
  // testStore2();
  // testStore3();
  // testStore4();
  testStoreFinal();
}