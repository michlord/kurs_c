/*
Lista:3
Zadanie:2
Indeks:258375
Michal Zimniak
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int version;
int chessboard_size;
int start_x,start_y;
int **chessboard;
int result=0;
#define MOVES_AMT 8
int moves_x[MOVES_AMT] = {1,2,2,1,-1,-2,-2,-1};
int moves_y[MOVES_AMT] = {-2,-1,1,2,2,1,-1,-2};
int *list_moves_x;
int *list_moves_y;
int mpt=0;
void init(int size,int corner)
{	
	chessboard_size=size;
	switch(corner)
	{
		case 1:
			start_x=0;
			start_y=0;
			break;
		case 2:
			start_x=size-1;
			start_y=0;
			break;
		case 3:
			start_x=0;
			start_y=size-1;
			break;
		case 4:
			start_x=size-1;
			start_y=size-1;
			break;
		default:
			start_x=0;
			start_y=0;
			break;
	}
	
	chessboard=(int**)malloc(sizeof(int*)*size);
	for(int i=0;i<size;++i)
	{
		chessboard[i]=(int*)malloc(sizeof(int)*size);
		/*memset(chessboard[i],0,sizeof(int)*size);*/
		for(int j=0;j<size;++j)
			chessboard[i][j]=-1;
	}
	list_moves_x=(int*)malloc(sizeof(int)*size*size);
	list_moves_y=(int*)malloc(sizeof(int)*size*size);
}

int checkBounds(int x,int y)
{
	if((x<0)||(y<0)||(x>chessboard_size-1)||(y>chessboard_size-1))
		return 0;
	return 1;
}

void cleanup()
{
	for(int i=0;i<chessboard_size;++i)
		free(chessboard[i]);
	free(chessboard);
	free(list_moves_x);
	free(list_moves_y);
}

void printBoard()
{
	printf("Stan szachownicy:\n");
	for(int i=0;i<chessboard_size;++i)
	{
		for(int j=0;j<chessboard_size;++j)
		{
			printf("%d ",chessboard[j][i]);
		}
		putchar('\n');
	}
}
void printMoves()
{
	printf("Ruchy skoczka (x,y):\n");
	for(int i=0;i<mpt;++i)
	{
		printf("(%d,%d) ",list_moves_x[i],list_moves_y[i]);
	}
	putchar('\n');
}

void simulate(int x,int y,int depth)
{
	list_moves_x[mpt]=x;
	list_moves_y[mpt]=y;
	++mpt;
	chessboard[y][x]=depth;
	
	/*this version solves open tour*/
	if(version==1)
	{
		if(depth==chessboard_size*chessboard_size)
		{
			result=1;
			return;
		}
	}
	else
		if(depth==chessboard_size*chessboard_size && x==start_x && y==start_y)
		{
			result=1;
			return;
		}
	for(int i=0;i<MOVES_AMT;++i)
	{
		int tx=x+moves_x[i];
		int ty=y+moves_y[i];
		if(checkBounds(tx,ty)&&chessboard[ty][tx]==-1)
		{
			simulate(tx,ty,depth+1);
			if(result==1)
				return;
		}
	}
	chessboard[y][x]=-1;
	--mpt;
}

int main()
{
	printf("Program zaklada, ze skoczek znajduje sie w lewym gornym rogu\n"
			"bo to nie robi roznicy. Dla rozmiaru tablicy 1 zakladam, ze\n"
			"skoczek przebyl zamknieta sciezke. Program dziala dla rozmiaru <=5.\n"
			"Wieksze rozmiary zajmuja bardzo duzo czasu. Wersja dla otwartej\n"
			"sciezki dziala szybko dla rozmiaru <=7.\n");
	printf("Wersja 1-otwarta 2-zamknieta:");
	scanf("%d",&version);
	printf("Rozmiar szachownicy: ");
	int size;scanf("%d",&size);
	init(size,1);
	simulate(start_x,start_y,1);
	putchar('\n');
	printBoard();
	printMoves();
	cleanup();
	
	if(result==0)
		printf("Skoczek nie wrocil!\n");
	else
		printf("Skoczek wrocil!\n");
	return 0;
}