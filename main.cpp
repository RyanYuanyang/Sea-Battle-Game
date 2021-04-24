#include <iostream>
#include "instruction.h"
#include "challenge.h"
#include "AI.h"

using namespace std;

int main(){
	char opt;
	cout << "Welcome to the Seabattle game (Author: Tu Yuanyang & He Jiachuan)\n\n";
	cout << "    1: Play!\n    2: Instruction" << endl;
	cin >> opt;
	system("cls");
	
	while(opt != '1')
	{
		if(opt != '2')
			cout << "Please input again\n\n    1: Play!\n    2: Instruction"<< endl;
		else if(opt == '2')
		{
			instruction();
			cout << "    1: Play!\n    2: Instruction" << endl;
		}
		cin>>opt;
		system("cls");
	}
	
	cout << "Choosing Mode:\n" << endl;
	cout << "    1: Fight Against AI" << endl;
	cout << "    2: Challenge Mode" << endl;
	cin >> opt;
	system("cls");
	
	if (opt == '2'){
		challenge();
	}
	else if (opt == '1'){
		int dif = 0;
		while(dif > 4 || dif <1)
		{
			cout << "Choosing Difficulty:\n" << endl;
			cout << "    1: EASY" << endl;
			cout << "    2: NORMAL" << endl;
			cout << "    3: HARD" << endl;
			cout << "    4: IMPOSSIBLE" << endl;
			cin >> dif;
			system("cls");
		}
		AI(dif);
	}

	return 0;
}
