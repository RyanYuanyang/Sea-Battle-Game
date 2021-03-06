// The program to generate randomly the game board with ships

#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int S[10]; //the number of each type of ship
//0 == nothing   2 == Submarine  3 == Destoryer  4 == Cruiser  5 == Battleship  6 == Carrier

int rd() // generate a random number
{
	int rr;
	rr = rand();
	rr = rr%19260817;  //to make the random number more diffuse
	// mod by a big prime to avoid random numbers concenrate on some values
	return rr;
}
//check whether the i lines could place this ship
//a[][] stores the board, len means the length of ship, n is 10 (n*n board)
//len == length of the ship   n -->  Board Size (n*n)
//(st1,st2) is the starter position to check is there is a place for the ship
int CHKi(int a[11][11], int len, int n, int st1, int st2)
{
	int p;
	for(int i = 0; i<n; ++i)
		for(int j = 0; j<n; ++j)
		{
			p=0;
			if( (i+st1)%n +len < n )
			for(int k = 0; k < len; ++k)
			{
				if(!a[ k + (i+st1)%n ][ (j+st2) % n ]) p++;
				if(p == len)
					return ( (i+st1) % n )*100+( (j+st2) % n );
				// There is a place for the ship
		// [ (i+st1) % n , (j+st2) % n ] represents the starter position of a ship
				if(a[ k + (i+st1)%n ][ (j+st2) % n ] > 1) break;
			}
		}
	return -1;// not available
}
//check whether the j lines could place this ship
//a[][] stores the board, len means the length of ship, n is 10 (n*n board)
//len == length of the ship   n -->  Board Size (n*n)
//(st1,st2) is the starter position to check is there is a place for the ship
int CHKj(int a[11][11], int len, int n, int st1, int st2)
{
	int p;
	for(int i = 0; i<n; ++i)
		for(int j = 0; j<n; ++j)
		{
			p=0;
			if( (j+st2)%n +len < n )
			for(int k = 0; k < len; ++k)
			{
				if(!a[ (i+st1) % n ][ k + (j+st2)%n ]) p++;
				if(p == len)
					return ( (i+st1) % n )*100+( (j+st2) % n );
				// There is a for the ship
				if(a[ (i+st1) % n ][ k + (j+st2)%n ] > 1) break;
			}
		}
	return -1;// not available
}
// place the ship on the board
// n*n == Board Size  & len == ship lenth
int PLACE_SHIP(int a[11][11], int n, int tp)
{

	int r1,r2,r3,siz,ci,cj,ships_num,len;
	len = tp%10;
	r1 = rd();
	r2 = rd();
	r3 = rd()%2;
	int ii,jj;
	ii = r1 % n;
	jj = r2 % n;
	//  ii,jj  is the starter position to check
	//  r3  is the direction ( r3 = 0 means row  &  r3 = 1 means colum )
	ci = CHKi(a,len,n,ii,jj);
	cj = CHKj(a,len,n,ii,jj);// to check whether the ship could be placed horizontially or vertically

	if(ci<0 && cj<0) return 0; // no available place

	if(r3) // ship on an i line (row)
	{
		if(ci >= 0)
			for(int k = 0; k<len; ++k)	a[ci/100 + k][ci%100] = tp;
		else if(cj >= 0)
			for(int k = 0; k<len; ++k)	a[cj/100][cj%100 + k] = tp;
	}
	else // ship on a j line (colum)
	{
		if(cj >= 0)
			for(int k = 0; k<len; ++k)	a[cj/100][cj%100 + k] = tp;
		else if(ci >= 0)
			for(int k = 0; k<len; ++k)	a[ci/100 + k][ci%100] = tp;
	}
	return 1; // success
}
//this function is used to intiallize the random function and place the ships stored in S_num[] array
//a[][] stores the board, n is 10 (the board is n*n size)
//S_num[] stores number of ships
int GEN(int a[11][11], int n, int S_num[])
{
	//n * n == board size
	srand( (unsigned) (time(0)%19260817) );

	for(int i = 4; i>=0; --i)
		for(int j = 1; j<=S_num[i]; ++j)
			if(PLACE_SHIP(a,n,(i+2) + j*10) == 0) //i+2 == length of ship
				printf("FAILED TO PLACE %d\n",i+2);

	return 0;
}

//this function is to output the board generated here
//it is used to check whether the board is generated correctly
/*
void PRINT_BOARD(int a[11][11],int n)
{
	printf("    ");
	for(int j = 0; j<n; ++j)
		printf("%c ",'A'+j);
	printf("\n");

	for(int i = 0; i<n; ++i)
	{
		printf("I%d  ",i);
//0 == nothing   2 == Submarine  3 == Destoryer  4 == Cruiser  5 == Battleship  6 == Carrier
		for(int j = 0; j<n; ++j)
		{
			if(a[i][j])
				printf("%d ",a[i][j]);
			else
				printf(". ");
		}
		printf("\n");
	}
}*/

//genboard is the body function of this part, it will initialize first
//and is used to generate the board randomly with specified number of ships
//B[]  array is used to record the board
//S[]  array is used to record the number of each type of ship
void genBoard(int B[][11],int S[])
{
	for(int i = 0; i<10; ++i)
		for(int j = 0; j<10; ++j)
			B[i][j] = 0;

	GEN(B,10,S);
	//PRINT_BOARD(B,10)
}
