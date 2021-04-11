#include <iostream>
#include "instruction.h"
#include "challenge.h"

using namespace std;

int main(){
  char opt;
  cout << "Welcome to the Seabattle game (Author: Tu Yuanyang & He Jiachuan)\n" << endl;
  cout << "1: Play!\n2: Instruction" << endl;
  cin >> opt;

  while (opt != '1' && opt != '2'){
    cout << "Please input again" << endl;
    cin >> opt;
  }

  system("cls");

  if (opt == '2'){
    instruction();
    cin >> opt;
  }

  system("cls");

  cout << "Choosing Mode:\n" << endl;
  cout << "1: Fight Against AI" << endl;
  cout << "2: Challenge Mode" << endl;
  cin >> opt;

  while (opt != '1' && opt != '2'){
    cout << "Please input again" << endl;
    cin >> opt;
  }

  system("cls");

  if (opt == '2'){
    challenge();
    cout << "Gameover";
  }
  else if (opt == '1'){

  }


}
