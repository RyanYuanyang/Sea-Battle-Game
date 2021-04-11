#include <iostream>
#include "genBoard.h"
#include "printBoard.h"
#include "genBoard.h"

using namespace std;

void challenge(){

  int count = 0;
  int shell = 50;
  int board[11][11];
  int x, y;
  int sub, des, cru, bat, car;

  //initialize the board
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      board[i][j] = 0;
    }
  }

  genBoard(board);
  cout << endl;

  while (count != 20 && shell != 0){
    printBoard(board);

    sub = 0;
    des = 0;
    cru = 0;
    bat = 0;
    car = 0;
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        if (board[i][j] == 2)
          sub = 1;
        if (board[i][j] == 3)
          des = 1;
        if (board[i][j] == 4)
          cru = 1;
        if (board[i][j] == 5)
          bat = 1;
        if (board[i][j] == 6)
          car = 1;
      }
    }
    cout << endl;
    cout << "Enemy fleet: " << "Submarine(2) = " << sub << " Destoryer(3) = " << des << " Cruiser(4) = " << cru << " Battleship(5) = " << bat << " Carrier(6) = " << car << endl;
    cout << endl;
    cout <<  shell << " shells left." << endl;
    cout << endl;
    cout << "Choose position to attack: x y" << endl;
    cin >> x >> y;

    while (x > 10 || x < 1 || y > 10 || y < 1 || !cin){
      cout << "Denied!" << endl;
      cout << "Choose position to attack: x y" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> x >> y;
    }

    x = x - 1;
    y = y - 1;

    cout << endl;
    system("cls");
    if (board[y][x] == 0){
      cout << "Missed!" << endl;
      board[y][x] = -1;
    }
    else if (board[y][x] == 1 || board[y][x] == -1){
      cout << "Denied!" << endl;
      shell++;
    }
    else{
      cout << "Right on Target!"<< endl;
      board[y][x] = 1;
      count++;
    }
    shell--;
  }
}
