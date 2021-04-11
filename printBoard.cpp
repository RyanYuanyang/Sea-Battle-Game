#include <iostream>

using namespace std;

void printBoard(int board[][11]){
  cout << "   1 2 3 4 5 6 7 8 9 10 " << endl;
  for (int i = 0; i < 10; i++){
    if (i == 9)
      cout << (i + 1) << ' ';
    else
      cout << (i + 1) << "  ";
    for (int j = 0; j < 10; j++){
      if (board[i][j] == 1)
        cout << "X ";
      else if (board[i][j] == -1)
        cout << "O ";
      else
        cout << ". ";
    }
    cout << endl;
  }
}
