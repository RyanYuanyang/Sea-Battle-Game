#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int B[11][11]; //board
int S[10]; //the number of each type of ship
//0 == nothing    1 == ship   2 == destroyed
int rd() // rand
{
	int rr;
	rr = rand();
	rr = rr*rr%19260817;
	return rr;
}

int chki(int a[11][11], int len, int B_size, int st1, int st2)//check i lines to place ship 
{
	int p;
	for(int i = 0; i<B_size; ++i)
	{
		for(int j = 0; j<B_size; ++j)
		{
			p=0;
		//	printf("i %d ia %d     j %d    ja %d\n",i,(i+st1)%B_size,j,(j+st2)%B_size);
			for(int k = 0; k+(i+st1)%B_size<B_size; ++k)
			{
				if(!a[ k+(i+st1)%B_size ][ (j+st2)%B_size ]) p++;
				if(p == len) return ( (i+st1)%B_size )*100+( (j+st2)%B_size );
					// There is a place for the ship
				if(a[ k+(i+st1)%B_size ][ (j+st2)%B_size ]) p = 0;
			}
		}
	}
	return -1;// not available
}
int chkj(int a[11][11], int len, int B_size, int st1, int st2)//check j lines to place ship 
{
	int p;
	for(int i = 0; i<B_size; ++i)
	{
		for(int j = 0; j<B_size; ++j)
		{
			p=0;
			for(int k = 0; k+(i+st1)%B_size<B_size; ++k)
			{
				if(!a[ (i+st1)%B_size ][ k+(j+st2)%B_size ]) p++;
				if(p == len) return ( (i+st1)%B_size )*100+( (j+st2)%B_size );
				// There is a for the ship
				if(a[ (i+st1)%B_size ][ k+(j+st2)%B_size ]) p = 0;
			}

		}
	}
	return -1;// nott available
}
int PLACE_SHIP(int a[11][11], int n, int len)
{
	int r1,r2,r3,siz,ci,cj;
	r1 = rd();
	r2 = rd();
	r3 = rd()%2;
	int ii,jj;
	ii = r1 % (n-len);
	jj = r2 % (n-len);
//ii = 0; jj = 0; r3 = 1;
	ci = chki(a,len,n,ii,jj);
	cj = chkj(a,len,n,ii,jj);
//	printf("ii%d jj%d ci%d cj%d   r3=%d (1->shu  0->heng)\n",ii,jj,ci,cj,r3);
	if(ci<0 && cj<0) return 0; // no available place
	// len == ship lenth
	if(r3) // i向 
	{
		if(ci >= 0)
			for(int k = 0; k<len; ++k)	a[ci/100 + k][ci%100] = len;
		else if(cj >= 0)
			for(int k = 0; k<len; ++k)	a[cj/100][cj%100 + k] = len;
	}
	else //j向 
	{
		if(cj >= 0)
			for(int k = 0; k<len; ++k)	a[cj/100][cj%100 + k] = len;
		else if(ci >= 0)
			for(int k = 0; k<len; ++k)	a[ci/100 + k][ci%100] = len;
	}
	return 1; // success
}
int GEN(int a[11][11], int n, int S_num[])//ship number
{
	//n * n == board size
	srand( (time(NULL)%19260817) );
	int tot = 0;
	for(int i = 0; i<5; ++i)
		for(int j = 1; j<=S_num[i]; ++j) tot+= S_num[i]*j;
	
	if( tot > (n*n/2) ) return 1; // too many ships
	if( tot == 0 ) return 2; // no ships
	
	for(int i = 0; i<5; ++i)
		for(int j = 1; j<=S_num[i]; ++j)
			if(PLACE_SHIP(a,n,i+2) == 0) //i+2 == length of ship
				printf("FAILED TO PLACE %d\n",i+2);

	printf("    ");
	for(int j = 0; j<n; ++j)
		printf("%c ",'A'+j);
	printf("\n");
	for(int i = 0; i<n; ++i)
	{
		printf("I%d  ",i);
		for(int j = 0; j<n; ++j)
		{
			if(a[i][j])
				printf("%d ",a[i][j]);
			else
				printf(". ");
		}
		
		printf("\n");
	}

	
	
	
	return 0;
}


int main()
{
	for(int i = 0; i<10; ++i)
		for(int j = 0; j<10; ++j) B[i][j] = 0;
	
	//S[]  array is used to record the number of each type of ship
	for(int i = 0; i<5; ++i) S[i] = 2;
	
	GEN(B,10,S);
		
	return 0;
}
