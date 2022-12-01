#include "serial.h"

#include <iostream>
#include <thread>
#include <vector>
#include <unordered_map>

using namespace std;


void hello() {
  cout << "Hello from thread " << this_thread::get_id() << endl;
}

int main() {
  unordered_map<string, vector<int>>table;

  unordered_map<string, string>New_map;

  return 0;
}
