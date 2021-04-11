#include <iostream>
#include "instruction.h"
#include "challenge.h"

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
		cout << "    Gameover";
	}
	else if (opt == '1'){
	
	}

	return 0;
}
