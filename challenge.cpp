#include <iostream>
#include "genBoard.h"
#include "printBoard.h"
#include "input_ships_shell.h"

using namespace std;

bool ships_left[6][7];
int ships_current[6];
int Count_ships_left(int board[][11], int ships[])
{
	for(int i = 0; i<5; ++i)
	{
		ships_current[i] = 0;
		for(int j = 0; j<6; ++j)
			ships_left[i][j] = 0; // i -->type of ship   j --> number of ships		
	}

	for(int i = 0; i<10; ++i)
		for(int j = 0; j<10; ++j)
			if(board[i][j] > 1)
				if(ships_left[ board[i][j]%10 -2 ][ board[i][j]/10 ] == 0)
				{
					ships_left[ board[i][j]%10 -2 ][ board[i][j]/10 ] = 1;
					ships_current[ board[i][j]%10 -2 ]++;
				}
	for(int i = 0; i<5; ++i)
		if(ships_current[i] < ships[i])
		{
			ships[i] = ships_current[i];
			return (i+2);
		}
	
	return 0;
}
void challenge(){

  int count = 0;
  int shell = 60;
  int board[11][11];
  int ships[11];
  int x, y;

  //initialize the board
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      board[i][j] = 0;
    }
  }
  for(int i = 0; i<5; ++i) ships[i] = 0;
  
	char opt = '0';
	while(opt != '1' && opt != '2')
	{
		cout<<"Please choose the number of ships"<<endl;
		cout<<"    1.Default ( 2 for each type of ship and 60 shells)"<<endl;
		cout<<"    2.Customize"<<endl;
		cin>>opt;
		system("cls");
	}
	int chk_ships = 0, tot;
	
	if(opt == '1')
	{
		for(int i = 0; i<5; ++i) ships[i] = 2;
		shell = 60;
		tot = 40;
		cout<<"Default mode"<<endl;
	}
	else if(opt == '2')
	while(!chk_ships) //chk_ships == 1 -> proper
	{
		tot = input_ships_shell(ships,shell);
		
		if( tot > 60 ) cout<<"    Too many ships!"<<endl;
		else if( tot == 0 ) cout<<"    No ships!"<<endl;
		else chk_ships = 1;
	}
	
	genBoard(board,ships);
	cout << endl;
	
	int sink_ship;
  while (count != tot && shell != 0){
  	sink_ship = Count_ships_left(board,ships);
  	if(sink_ship)
  	{
  		cout << "    You sank an enemy ";
  		if(sink_ship == 2) cout << "Submarine !" << endl;
  		if(sink_ship == 3) cout << "Destoryer !" << endl;
  		if(sink_ship == 4) cout << "Cruiser !" << endl;
  		if(sink_ship == 5) cout << "Battleship !" << endl;
  		if(sink_ship == 6) cout << "Carrier !" << endl;
	}
  	cout << endl;
    printBoard(board);
    cout << endl;
    cout << "    Enemy fleet:  Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1] << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl;
    
	cout << "    " << shell << " shells left,   " << count << " hit." << endl << endl;
    
    cout << "    Choose position to attack: x y" << endl;
    cin >> x >> y;

    while (x > 10 || x < 1 || y > 10 || y < 1 || !cin){
		system("cls");
		cout << "    Denied, Not an Available Position.\n\n\n";
	    printBoard(board);
	    cout << endl;
	    cout << "    Enemy fleet:  Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1] << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl;
		cout << "    " << shell << " shells left,   " << count << " hit." << endl << endl;
    	cout << "    Choose position to attack: x y" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> x >> y;
    }

    x = x - 1;
    y = y - 1;

    cout << endl;
    system("cls");
    if (board[y][x] == 0){
      cout << "    Missed!" << endl << endl;
      board[y][x] = -1;
    }
    else if (board[y][x] == 1 || board[y][x] == -1){
      cout << "    Denied, The Position Has been Shot." << endl << endl;
      shell++;
    }
    else{
      cout << "    Right on Target!"<< endl << endl;
      board[y][x] = 1;
      count++;
    }
    shell--;
  }
  	if(count == tot)
  		cout<<"    You Have Sanked Enemy Fleet!\n    You Win!\n";
	else	
		cout << "    Gameover";
}
