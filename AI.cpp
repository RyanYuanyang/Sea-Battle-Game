// The program which implement mode 3 of the game.
// player VS AI(with different difficulty)

#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include "genBoard.h"
#include "printBoard.h"
#include "input_ships_shell.h"
#include "printRecord.h"

using namespace std;

//This structure is used to store the result of AI's shot.
struct AI_result{
	int pos; // shot position
	int st;  // position_status
};

//a[][11] stores the board(and ships) , n is 10(n*n board) , pos is the shooting position
AI_result SHOOT(int a[][11], int n, int pos)
{
	AI_result result_current;
	int i,j;	//(i,j) is the postion
	
	result_current.pos = pos;
	result_current.st = 0;
	
	if(pos > n*n) return result_current;
	i = pos/n;
	j = pos%n;
	if(a[i][j] >= 2)
	{
		a[i][j] = 1; // shoot the ship
		result_current.pos = i*10 + j;
		result_current.st = 1;
		return result_current;
	}
	else if(a[i][j] == 0)
	{
		a[i][j] = -1; //shoot nothing
		result_current.pos = i*10 + j;
		result_current.st = -1;
		return result_current;
	}
	result_current.st = -2;
	return result_current; //the position has been shot
}
//IMPOSSIBLE mode AI will shoot with unfailing accuracy
//a[][11] stores the board(and ships) , n is 10(n*n board)
AI_result IMPOSSIBLE(int a[][11], int n)
{
	AI_result result_current;
	int ri,rj,s,cnt;
	ri = rand();
	ri = ri % (n);
	rj = rand();
	rj = rj % (n);
	for(int i = 0; i<n; ++i)
		for(int j = 0; j<n; ++j)
			if(a[ (i+ri)%n ][ (j+rj)%n ] >= 2) // there is a ship
			{
				a[ (i+ri)%n ][ (j+rj)%n ] = 1; // shoot the ship
				result_current.pos = i*10 + j;
				result_current.st = 1;
				return result_current;
			}
	result_current.pos = 0;	
	result_current.st = 0;
	return result_current; // your fleet has been destroyed
}
//EASY mode AI will shoot randomly :D
//a[][11] stores the board(and ships) , n is 10(n*n board)
AI_result EASY(int a[][11], int n)
{
	AI_result result_current;
	int rr,s,cnt;
	rr = rand();
	rr = rr*rr%19260817;
	rr = rr % (n*n);
	cnt = 0;
	while(1)
	{
		result_current = SHOOT(a, n, rr);
		if( result_current.st == 1 || result_current.st == -1 ) return result_current;
		//1 == shoot the ship
		//-1 == shoot nothing
		//else, the position has been shot
		rr = (rr+1) % n;
		cnt++;
		if(cnt == n)
		{
			result_current.pos = 0;
			result_current.st = 0;
			return result_current; //no places to shoot
		}
	}
	result_current.pos = 0;
	result_current.st = 0;
	return result_current; //return 0,0 means there are some errors
}
//NORMAL mode AI will shoot with relatively low accuracy
//a[][11] stores the board(and ships) , n is 10(n*n board)
AI_result NORMAL(int a[][11], int n)
{
	AI_result result_current;
	int rr,s,cnt;
	rr = rand();
	rr%= 100;
	if(rr < 20) result_current = IMPOSSIBLE(a,n);
	else result_current = EASY(a,n);
	return result_current;
}
//HARD mode AI will shoot with relatively high accuracy
//a[][11] stores the board(and ships) , n is 10(n*n board)
AI_result HARD(int a[][11], int n)
{
	AI_result result_current;
	int rr,s,cnt;
	rr = rand();
	if(rr & 1) result_current = IMPOSSIBLE(a,n);
	else result_current = EASY(a,n);
	return result_current;
}
bool ships_left_AI[6][7];
int ships_current_AI[6]; //this array is used to store the ships that not been sunk currently

//this function is used to count the ships left on the board in AI mode
//board[][11]is used to store the board, ships[] stores the number of each type of ships
int Count_ships_left_AI(int board[][11], int ships[])
{
	for(int i = 0; i<5; ++i)
	{
		ships_current_AI[i] = 0;
		for(int j = 0; j<6; ++j)
			ships_left_AI[i][j] = 0; // i -->type of ship   j --> ID of ships  1->not sunk  0->sunk
	}

	for(int i = 0; i<10; ++i)
		for(int j = 0; j<10; ++j)
			if(board[i][j] > 1)
				if(ships_left_AI[ board[i][j]%10 -2 ][ board[i][j]/10 ] == 0)
				{
					ships_left_AI[ board[i][j]%10 -2 ][ board[i][j]/10 ] = 1;
					ships_current_AI[ board[i][j]%10 -2 ]++;
				}
	for(int i = 0; i<5; ++i)
		if(ships_current_AI[i] < ships[i])
		{
			ships[i] = ships_current_AI[i];
			return (i+2);
		}

	return 0;
}

//diff means the difficulty
//This is the body function of AI mode
int AI(int diff)
{
	if(diff == 1)
		cout << "    YOU CHOOSE 1: EASY MODE" << endl;
	else if(diff == 2)
		cout << "    YOU CHOOSE 2: NORMAL MODE" << endl;
	else if(diff == 3)
		cout << "    YOU CHOOSE 3: HARD MODE" << endl;
	else if(diff == 4)
		cout << "    YOU CHOOSE 4: IMPOSSIBLE MODE" << endl;

	int count = 0, count2 = 0; //count & count2 means hit counts of player and AI respectively
	int board[11][11]; //player's board
	int b2[11][11];  //AI's board
	int ships[11]; //player's ships
	int s2[11];  //AI's ships
	int chk_ships = 0; //check whether a ship is sunk last turn
	int tot, tot2, x, y; //tot, tot2 represents the total grids of player's and AI's ships respectively
	AI_result chk_AI; //to store position and the position's status that AI shot last turn
	chk_AI.st = 0;
	chk_AI.pos = 0;
	//initialize the board
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = 0;
			b2[i][j] = 0;
		}

	for(int i = 0; i<5; ++i)
	{
		ships[i] = 0; s2[i] = 0;
	}

	char opt = '0';
	while(opt != '1' && opt != '2')
	{
		cout <<"\n    Please choose the number of ships ( both yours and AI's )"<< endl;
		cout <<"    1.Default ( 1 for each type of ship )"<< endl;
		cout <<"    2.Customize"<<endl;
		cin >> opt;
		system("clear");
	}


	if(opt == '1')
	{
		for(int i = 0; i<5; ++i)
			ships[i] = 1;
		tot = 20;
		cout <<"Default mode"<< endl;
	}
	else if(opt == '2')
	while(!chk_ships) //chk_ships == 1 -> proper
	{
		tot = input_ships(ships);//unlimited shells in this mode

		if( tot > 60 ) cout <<"    Too many ships!"<< endl;
		else if( tot == 0 ) cout <<"    No ships!"<< endl;
		else chk_ships = 1;
	}
	for(int i = 0; i<5; ++i)
		s2[i] = ships[i];
	tot2 = tot;

	cout << "The enemy fleet was found! Destroy them or we will die!";

	genBoard(board,ships);
	genBoard(b2,s2); //generate player's and AI's board randomly with specified ship number
	cout << endl;

	int sink_ship,sink_ship2;
	int chk_denied = 0; //check whether player shoot a position that has been shot

	while (count != tot && count2 != tot2)
	{
	  sink_ship = Count_ships_left_AI(board,ships);
	  sink_ship = Count_ships_left_AI(b2,s2);
	  if(sink_ship)
	  {
	  	cout << "\n    You sank an enemy ";
	  	if(sink_ship == 2) cout << "Submarine !" << endl;
	  	if(sink_ship == 3) cout << "Destoryer !" << endl;
	 	if(sink_ship == 4) cout << "Cruiser !" << endl;
	 	if(sink_ship == 5) cout << "Battleship !" << endl;
  		if(sink_ship == 6) cout << "Carrier !" << endl;
	  }
	cout << endl;
	printBoard2(board,b2);
	cout << endl;
	cout << "    Your  fleet:  Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1];
	cout << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl << endl;

	cout << "    Enemy fleet:  Submarine(2) = " << s2[0] << " Destoryer(3) = " << s2[1];
	cout << " Cruiser(4) = " << s2[2] << " Battleship(5) = " << s2[3] << " Carrier(6) = " << s2[4] << endl << endl << endl;

	cout << "    Choose position to attack (x y): ";
	cin >> x >> y;

	while (x > 10 || x < 1 || y > 10 || y < 1 || !cin)
	{
		system("clear");
		cout << "    Denied, Not an Available Position.\n\n\n";
		printBoard2(board,b2);
		cout << endl;
		cout << "    Enemy fleet:  Submarine(2) = " << ships[0] << " Destoryer(3) = " << ships[1] << " Cruiser(4) = " << ships[2] << " Battleship(5) = " << ships[3] << " Carrier(6) = " << ships[4] << endl << endl;
		cout << "    Choose position to attack: x y" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> x >> y;
	}

	  x = x - 1;
	  y = y - 1;

	  cout << endl;
	  system("clear");
	  chk_denied = 0;
	  if (b2[y][x] == 0){
		  cout << "    Missed!" << " ( " << x + 1 << " , " << y + 1 << " )" << endl << endl;
		  b2[y][x] = -1;
	   }
	  else if (b2[y][x] == 1 || b2[y][x] == -1){
		  cout << "    Denied, The Position Has been Shot." << endl << endl;
		  chk_denied = 1;
	  }
	  else{
		  cout << "    Right on Target!"<< " ( " << x + 1 << " , " << y + 1 << " )" << endl << endl;
		  b2[y][x] = 1;
		  count++;
	  }

	  if(chk_denied == 1)
		  continue; //player has not shot an available place

  	  if(diff == 1) //EASY
		  chk_AI = EASY(board,10);
	  else if(diff == 2) //NORMAL
		  chk_AI = NORMAL(board,10);
	  else if(diff == 3) //HARD
		  chk_AI = HARD(board,10);
	  else if(diff == 4) //IMPOSSIBLE
		  chk_AI = IMPOSSIBLE(board,10);

	  	// chk_AI = 1 --> AI shoot on your ships
	  	// chk_AI = -1 --> AI shoot nothing
		if(chk_AI.st == 1)
		{
			count2++;
			cout << "    Your ship has been shot!" << " ( " << chk_AI.pos/10 + 1 << " , " << chk_AI.pos%10 + 1 << " )" << endl;
		}
		else
			cout << "    Enemy missed!" << " ( " << chk_AI.pos/10 + 1 << " , " << chk_AI.pos%10 + 1 << " )" << endl;
	}
	cout << endl;
	printBoard2(board,b2); // print the final status of board
	cout << endl;

	if(count == tot)
  		cout <<"    You Have Sanked Enemy Fleet!\n    The Victory is Yours!\n" << endl << endl;
	else
		cout << "    Your Fleet is Defeated  \n    You lost." << endl << endl;
	
	cout << endl << endl;

	// options when finish a round
	cout << "    Choose an option: " << endl;
	cout << "    1. Play Against the AI\n    2. Play Challenge Mode Again!\n    3. Quit\n    4. Enter Anything Else to See the Local Record\n";
	cin >> opt;

	// when user wants to see the record
	while (opt != '1' && opt != '2' && opt != '3'){
		printRecord();
		cout << "    Choose an option: " << endl;
		cout << "    1. Play Against the AI\n    2. Play Challenge Mode Again!\n    3. Quit\n    4. Enter Anything Else to See the Local Record\n";
		cin >> opt;
	}

	return opt;
}
