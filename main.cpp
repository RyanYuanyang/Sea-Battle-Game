// main program of the game

#include <iostream>
#include "instruction.h"
#include "challenge.h"
#include "AI.h"

using namespace std;

int main(){
	// the main menu
	char opt;
	cout << endl;
	cout << endl;
	cout << endl;
  cout << "  Welcome to the Seabattle game (Author: Tu Yuanyang & He Jiachuan)\n" << endl;
  cout << "    1: Play!\n    2: Instruction" << endl;
  cin >> opt;

  while (opt != '1' && opt != '2'){
    cout << "Please input again" << endl;
    cin >> opt;
  }

  system("clear");

  if (opt == '2'){
    instruction();
    cin >> opt;
  }

  system("clear");

	// the choosing mode menu

	while (opt != '3'){
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "  Choosing Mode:\n" << endl;
		cout << "    1: Fight Against AI" << endl;
		cout << "    2: Challenge Mode" << endl;
		cout << "    3: Quit" << endl;
		cin >> opt;
		system("clear");

		// calling the 2 mode
		while (opt == '2')
		{
			opt = challenge();
			system("clear");
		}

		// calling the 1 mode
		if (opt == '1'){
			int dif = 0;

			// calling the instruction
			cout << endl;
			cout << "  This is the typical game play of Battleship game.\n" << endl;
			cout << "  In this mode, player's opponent is a computer, with difficulty **Easy, Normal, Hard, Impossible.**\n" << endl;
			cout << "  Player randomly generate (either horizontally or vertically and at random spots) his ships on a 10 x 10 board\n" << endl;
			cout << "  Types of ships avaliable for the player (with allowed amount): " << endl;
			cout << "    - Aircraft Carrier, 6 units  (0~3)" << endl;
			cout << "    - Battleship, 5 units        (0~3)" << endl;
			cout << "    - Cruiser, 4 units           (0~5)" << endl;
			cout << "    - Destroyer, 3 units         (0~5)" << endl;
			cout << "    - Submarine, 2 units         (0~5)" << endl;

			cout << endl;
			cout << "  Your win goal is to defeat the enemy fleet, otherwise you lose.\n" << endl;

			// choosing the difficulty
			while(!dif || dif > 4 || dif <1)
			{
				cout << "  Choosing Difficulty:\n" << endl;
				cout << "    1: EASY" << endl;
				cout << "    2: NORMAL" << endl;
				cout << "    3: HARD" << endl;
				cout << "    4: IMPOSSIBLE" << endl;
				cin >> dif;
				system("clear");
			}
			AI(dif);

		}
	}

	// when user input 3 and the program end
	cout << "Have a Nice Day :)" << endl;

	return 0;
}
