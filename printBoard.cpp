#include <iostream>

using namespace std;

void printBoard(int board[][11]){
  cout << "         1   2   3   4   5   6   7   8   9  10 (x)\n" << endl;
  for (int i = 0; i < 10; i++){
    if (i == 9)
      cout << "    " << (i + 1) << " |";
    else
      cout << "    " << (i + 1) << "  |";
    for (int j = 0; j < 10; j++){
      if (board[i][j] == 1)
        cout << " X |"; // destroyed position
      else if (board[i][j] == -1)
        cout << " O |"; // empty
      else
        cout << " ~ |"; // unknown
    }
    cout << endl;
  }
  cout<<"    (y)"<<endl;
}

void printBoard2(int board[][11],int b2[][11])
{
  cout << "         1   2   3   4   5   6   7   8   9  10 (x)                  1   2   3   4   5   6   7   8   9  10 (x)\n" << endl;
  //players's board
  for (int i = 0; i < 10; i++){
    if (i == 9)
      cout << "    " << (i + 1) << " |";
    else
      cout << "    " << (i + 1) << "  |";
    for (int j = 0; j < 10; j++){
      if (board[i][j] == 1)
        cout << " X |"; // destroyed position
      else if (board[i][j] == -1)
        cout << " O |"; // empty
      else if (board[i][j] == 0)
        cout << " ~ |"; // unknown
      else
        cout << ' ' << board[i][j]%10<<" |"; // player's ships
    }
    //AI's board
    if (i == 9)
      cout << "                " << (i + 1) << ' ';
    else
      cout << "                " << (i + 1) << "  ";
    for (int j = 0; j < 10; j++){
      if (b2[i][j] == 1)
        cout << " X |"; // destroyed position
      else if (b2[i][j] == -1)
        cout << " O |"; // empty
      else
        cout << " ~ |"; // unknown
    }
    cout << endl;
  }
  cout << "    (y)                                                         (y)"<<endl;
}
