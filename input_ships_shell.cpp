#include<iostream>
#include<cstdio>

using namespace std;

// this function is used to print the number of each type of ships
// ships[]  stors the number of each type of ships
void print_current_ships(int ships[])
{
	cout<<"Current ships:"<< endl << endl;
	cout<<"    Submarine: "<< ships[0] << endl;
	cout<<"    Destoryer: "<< ships[1] << endl;
	cout<<"    Cruiser: "<< ships[2] << endl;
	cout<<"    Battleship: "<< ships[3] << endl;
	cout<<"    Carrier: "<< ships[4] << endl << endl;
}

// this function is used to store the number of each type of ships and shells from player's input
// and return the number of total grids of ships
// ships[]  stors the number of each type of ships, shell stores the number of shells
int input_ships_shell(int ships[], int &shell)
{
	int num = -1;
	while(num < 0 || num > 5)
	{
		print_current_ships(ships);
		cout<<"Input the number of Submarine (0~5)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[0] = num;
	num = -1;
	while(num < 0 || num > 5)
	{
		print_current_ships(ships);
		cout<<"Input the number of Destoryer (0~5)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[1] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Cruiser (0~3)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[2] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Battleship (0~3)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[3] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Carrier (0~3)"<<endl;
		cin>>num;
		system("clear");
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
		system("clear");
		if(num < tot)
			cout<<"    Not enough shells!"<< endl;
		else if(num > 99)
			cout<<"    Too many shells!"<< endl << endl;
		else chk = 1;
	}
	shell = num;
	return tot;
}
//this function is similar with the function above
//it stores the number of each type of ships but not the shells
//ships[]  stors the number of each type of ships
int input_ships(int ships[])
{
	int num = -1;
	while(num < 0 || num > 5)
	{
		print_current_ships(ships);
		cout<<"Input the number of Submarine (0~5)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[0] = num;
	num = -1;
	while(num < 0 || num > 5)
	{
		print_current_ships(ships);
		cout<<"Input the number of Destoryer (0~5)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[1] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Cruiser (0~3)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[2] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Battleship (0~3)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[3] = num;
	num = -1;
	while(num < 0 || num > 3)
	{
		print_current_ships(ships);
		cout<<"Input the number of Carrier (0~3)"<<endl;
		cin>>num;
		system("clear");
	}
	ships[4] = num;
	num = -1;
	int chk = 0, tot = 0;
	for(int i = 0; i<5; ++i) //count the total grid of ships
		tot+= ships[i] * (i+2);
	return tot;
}
