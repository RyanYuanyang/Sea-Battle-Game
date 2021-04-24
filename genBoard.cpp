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
	rr = rr*rr%19260817;  //to make the random number more diffuse
	// mod by a big prime to avoid random numbers concenrate on some values
	return rr;
}

int CHKi(int a[11][11], int len, int n, int st1, int st2)//check i lines to place ship
{
	//len == length of the ship    B_size  ==  Board Size
	//(st1,st2) is the starter position to check is there is a place for the ship
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
int CHKj(int a[11][11], int len, int n, int st1, int st2)//check j lines to place ship
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
int PLACE_SHIP(int a[11][11], int n, int tp)
{
	// n*n == Board Size  & len == ship lenth
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
	cj = CHKj(a,len,n,ii,jj);

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
int GEN(int a[11][11], int n, int S_num[])//ship number
{
	//n * n == board size
	srand( (time(NULL)%19260817) );

	for(int i = 4; i>=0; --i)
		for(int j = 1; j<=S_num[i]; ++j)
			if(PLACE_SHIP(a,n,(i+2) + j*10) == 0) //i+2 == length of ship
				printf("FAILED TO PLACE %d\n",i+2);

	return 0;
}

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
}

void genBoard(int B[][11],int S[])
{
	for(int i = 0; i<10; ++i)
		for(int j = 0; j<10; ++j) B[i][j] = 0;

	//S[]  array is used to record the number of each type of ship
	//for(int i = 0; i<5; ++i) S[i] = 1;
	GEN(B,10,S);

//	PRINT_BOARD(B,10);

}
