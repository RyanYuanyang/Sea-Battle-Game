#include <iostream>
#include <fstream>
#include <ctime>

#include "genBoard.h"
#include "printBoard.h"
#include "printRecord.h"


using namespace std;

bool ships_left[6][7];
int ships_current[6];

// a function that record the current ships on the board and retuen the sinked ship.
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

// the body function of challenge mode
char challenge(){

  int count = 0;
  int shell = 50;
  int board[11][11];
  int ships[11];
  int x, y;
	int sink_ship;
	int chk_ships = 0, tot;


	// use fileio to manipulate user record
	ofstream fout;
	fout.open("record.txt", ios::app);

	// check wheter the fileio is successful
	if (fout.fail()){
		cout << "Error in file opening!" << endl;
		exit(1);
	}



  //initialize the board
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      board[i][j] = 0;
    }
  }
  for(int i = 0; i<5; ++i) ships[i] = 0;

	char opt = ' ';

	// print the instructions
	cout << "\n\n";
	cout << "  Challenge mode is an alternative game play of Seabattle game we came up\n" << endl;
	cout << "  In challenge mode, you only have limited amount of shells (60) to defeat the enemy fleet" << endl;
	cout << "  You don't have a fleet, instead, you are defending your base from enemy's attack" << endl;
	cout << "  The enemy fleet contains only one of the each type of ship\n" << endl;
	cout << "  They are: " << endl;
	cout << "      1 Submarine: 2 units " << endl;
	cout << "      1 Destoryer: 3 units" << endl;
	cout << "      1 Cruiser: 4 units" << endl;
	cout << "      1 Battleship: 5 units" << endl;
	cout << "      1 Carrier: 6 units\n" << endl;
	cout << "  If you defeat the enemy fleet within the limited shells, you win!" << endl;
	cout << "  Otherwise, if you are ran out of shells and there are still enemy ships left, the game failed :(\n" << endl;
	cout << "  Each of the winning game play will be recorded, and your record will be ranked by the amount of shells you use." << endl;
	cout << "  The record will be stored in a txt file and you can call/read it in the game. \n\n\n";

	// options to show the record or start game.
	while(opt != '1')
	{
		cout << "\n  Choose an option: " << endl;
		cout << "    1. Enter 1 to start" << endl;
		cout << "    2. Enter anything else to see your local record" << endl;
		cin >> opt;
		if (opt != '1'){
			system("cls");
			// print the record
			printRecord();
		}
	}

	system("cls");

	for(int i = 0; i<5; ++i)
		ships[i] = 1;

	shell = 60;
	tot = 20;
	cout << "Destroy The Enemy Fleet and Protect Our Base! " << endl;

	// auto-generate the enemy fleet
	genBoard(board,ships);
	cout << endl;


  while (count != tot && shell != 0){
		// report when the player have sinked an ship
  	sink_ship = Count_ships_left(board,ships);
  	if(sink_ship)
  	{
  		cout << "    Good job capitan, you have sank an ";
  		if(sink_ship == 2) cout << "Submarine !" << endl;
  		if(sink_ship == 3) cout << "Destoryer !" << endl;
  		if(sink_ship == 4) cout << "Cruiser !" << endl;
  		if(sink_ship == 5) cout << "Battleship !" << endl;
  		if(sink_ship == 6) cout << "Carrier !" << endl;
	  }

  	cout << endl;
    printBoard(board);
    cout << endl;
		// report the ships left on the board
    cout << "    Enemy fleet:  Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1] << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl;
		cout << "    " << shell << " shells left,   " << count << " hit." << endl << endl;
    cout << "    Choose position to attack (x y): ";
    cin >> x >> y;

		// input again when the input is invalid
    while (x > 10 || x < 1 || y > 10 || y < 1 || !cin){
			system("cls");
			cout << "    Denied, out of range! \n\n\n";
	    printBoard(board);
	    cout << endl;
	    cout << "    Enemy fleet:  Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1] << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl;
			cout << "    " << shell << " shells left,   " << count << " hit." << endl << endl;
    	cout << "    Choose position to attack (x y): " << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> x >> y;
    }

    x = x - 1;
    y = y - 1;

    cout << endl;
    system("cls");
		// report missed when the position is empty
    if (board[y][x] == 0){
      cout << "    Missed!" << endl << endl;
      board[y][x] = -1;
    }
		// input again when the input is invalid
    else if (board[y][x] == 1 || board[y][x] == -1){
      cout << "    Denied, The Position Has been Shot." << endl << endl;
      shell++;
    }
		// report hit when the position has a ship
    else{
      cout << "    Right on Target!"<< endl << endl;
      board[y][x] = 1;
      count++;
    }
    shell--;
  }

  if(count == tot){ //win
		// get the current time
		time_t now = time(0);
		// convert now to string form
		char* dt = ctime(&now);
		// update the record with the shell used and the current time
		fout << 60 - shell << "                        " << dt;

		cout << "    You Have Sanked Enemy Fleet! \n    The Victory is Yours! \n" << endl << endl;
		fout.close();
	}
	else // fail
		cout << "    Ahhhh! The Enemy Fleet Has Destroyed Our Base, Gameover :(" << endl << endl;


  // options when finish a round
	cout << "    Choose an option: " << endl;
	cout << "    1. Play Against the AI\n    2. Play Challenge Mode Again!\n    3. Quit\n    4. Enter Anything Else to See the Local Record";
	cin >> opt;

	// when user wants to see the record
	while (opt != '1' && opt != '2' && opt != '3'){
		printRecord();
		cout << "    Choose an option: " << endl;
		cout << "    1. Play Against the AI\n    2. Play Challenge Mode Again!\n    3. Quit\n    4. Enter Anything Else to See the Local Record";
		cin >> opt;
	}

	return opt;
}
