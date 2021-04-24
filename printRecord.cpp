// a program to print player's record in mode 2 on screen

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

void printRecord(){

  int count = 0;

  ifstream fin;
  fin.open("record.txt");

  if (fin.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  vector <string> record;
  string x;

  while (getline(fin, x)){
    record.push_back(x);
  }

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
