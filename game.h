#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


enum OPTION
{
	EXIT,
	PLAY,
	PLAY2,

};

#define EASY_COUNT 5      //7x7
#define MIDDLE_COUNT 90      //10x10


#define ROW 30
#define COL 30

void InitBoard(char board[ROW][COL], int row, int col, char set);
void Display(char board[ROW][COL], int row, int col);
void SetMine(char board[ROW][COL], int row, int col, int mine);
void SpreadMine(char board[ROW][COL],char show[ROW][COL],int used[ROW][COL], int row, int col, int x, int y);
int FindMine(char board[ROW][COL],char show[ROW][COL], int row, int col);
int PlayerMove(char board[ROW][COL], char show[ROW][COL], int row, int col,int mine, int step);
#endif //__GAME_H__


