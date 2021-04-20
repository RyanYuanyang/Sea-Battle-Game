#include <iostream>
#include "genBoard.h"
#include "printBoard.h"
#include "genBoard.h"

using namespace std;

void print_current_ships(int ships[])
{
	cout<<"Current ships:"<< endl << endl;
	cout<<"    Submarine: "<< ships[0] << endl;
	cout<<"    Destoryer: "<< ships[1] << endl;
	cout<<"    Cruiser: "<< ships[2] << endl;
	cout<<"    Battleship: "<< ships[3] << endl;
	cout<<"    Carrier: "<< ships[4] << endl << endl;
}
int input_ships_shell(int ships[], int &shell)
{
	int num = -1;
	while(num < 0 || num > 5)
	{
		print_current_ships(ships);
		cout<<"Input the number of Submarine (0~5)"<<endl;
		cin>>num;
		system("cls");
	}
	ships[0] = num;
	num = -1;
	while(num < 0 || num > 5)
	{
		print_current_ships(ships);
		cout<<"Input the number of Destoryer (0~5)"<<endl;
		cin>>num;
		system("cls");
	}
	ships[1] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Cruiser (0~3)"<<endl;
		cin>>num;
		system("cls");
	}
	ships[2] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Battleship (0~3)"<<endl;
		cin>>num;
		system("cls");
	}
	ships[3] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Carrier (0~3)"<<endl;
		cin>>num;
		system("cls");
	}
	ships[4] = num;
	num = -1;
	int chk = 0, tot = 0;
	for(int i = 0; i<5; ++i) //count the total grid of ships
		tot+= ships[i] * (i+2);
	while(!chk)
	{
		print_current_ships(ships);
		cout<<"Input the number of shells (0~99)"<< endl;
		cin>>num;
		system("cls");
		if(num < tot)
			cout<<"    Not enough shells!"<< endl;
		else if(num > 99)
			cout<<"    Too many shells!"<< endl << endl;
		else chk = 1;
	}
	shell = num;
	return tot;
}
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
    cout << "    Enemy fleet: " << "Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1] << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl;
    
	cout << "    " << shell << " shells left,   " << count << " hit." << endl << endl;
    
    cout << "    Choose position to attack: x y" << endl;
    cin >> x >> y;

    while (x > 10 || x < 1 || y > 10 || y < 1 || !cin){
      cout << "    Denied!" << endl;
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
      cout << "    Denied!" << endl << endl;
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
