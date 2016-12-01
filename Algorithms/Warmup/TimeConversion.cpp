#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <sstream>

using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

string toMilitaryTime(int hh, int mm, int ss, string period, char delimiter) {
  string new_time;
  
  if(hh != 12 && period == "PM") {
    hh += 12;
  }
  else if(hh == 12 && period == "AM"){
    hh -= 12;
  }
  if(hh == 24) {
    hh = 0;
  }
  
  stringstream ss_out;
  ss_out << std::setfill('0') 
         << std::setw(2) << hh << delimiter
         << std::setw(2) << mm << delimiter
         << std::setw(2) << ss;
  ss_out >> new_time;
  
  return new_time;
}

int main() {
  string time;
  cin >> time;
  
  int hh, mm, ss;
  char separator;
  string period;
  stringstream ss_in;
  ss_in << time;
  ss_in >> hh >> separator >> mm >> separator >> ss >> period;
  clog << hh << separator << mm << separator << ss << ' ' << period << endl;
  
  cout << toMilitaryTime(hh, mm, ss, period, separator) << endl;
  return 0;
}
