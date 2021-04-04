#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
int SHOOT(int a[11][11], int n, int pos) 
{
	int i,j;	//(i,j) is the postion
	if(pos>n) return 0;
	i = pos/n;
	j = pos%n;
	if(a[i][j] >= 2)
	{
		a[i][j] = -1; // shoot the ship
		return -1;
	}
	else if(a[i][j] == 0)
	{
		a[i][j] = -2; //shoot nothing
		return -2;
	}
	return 1; //the position has been shot
}
int IMPOSSIBLE(int a[11][11], int n)
{
	//IMPOSSIBLE mode AI will shoot with unfailing accuracy
	for(int i = 0; i<n; ++i)
		for(int j = 0; j<n; ++j)
			if(a[i][j] >= 2) // there is a ship
			{
				a[i][j] = -1; // shoot the ship
				return -1;
			}
	return 0; // your fleet has been destroyed
}
int EASY(int a[11][11], int n) //EASY mode AI will shoot randomly :D
{
	int rr,s,cnt;
	rr = rand();
	rr = rr*rr%19260817;
	rr = rr % (n*n);
	cnt = 0;
	while(1)
	{
		s = SHOOT(rr)
		if( s < 0 ) return s;
		//-1 == shoot the ship
		//-2 == shoot nothing
		rr = (rr+1) % n;
		cnt++;
		if(cnt = n) return 0;
	}
	return 0; //return 0 means there are some errors
}
int HARD(int a[11][11], int n)
{
	int rr,s,cnt;
	
}
int NORMAL(int a[11][11], int n)
{
	
}
int main()
{
	
	
	
	
	
	return 0;	
} 
