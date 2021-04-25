// a program to print player's record in mode 2 (challenge mode) on screen

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

// this function is used to print player's record in mode 2 (challenge mode)
// the record is stored in record.txt
void printRecord(){

  int count = 0;

  ifstream fin;
  fin.open("record.txt");

  // prevent the fail calling
  if (fin.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  vector <string> record;
  string x;

  while (getline(fin, x)){
    record.push_back(x);
  }

  // the record is sorted by the number of shells player used in each round
  // the lowest the best
  sort(record.begin(), record.end());
  cout << "Ranking (shells consumed)" << "    " << "Date" << endl;
  vector<string>::iterator itr;

  for (itr = record.begin(); itr != record.begin() + 10; itr++){
    count++;
    if (count == 10){
      cout << count << "." << *itr << endl;
    }
    else
      cout << count << ". " << *itr << endl;
  }

}
