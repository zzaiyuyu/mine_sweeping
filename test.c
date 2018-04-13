#include <stdio.h>
#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

void menu(){
	printf("**************************************\n");
	printf("********来一盘惊险刺激的扫雷吧********\n");
	printf("********1.入门级别********************\n");
	printf("********2.进阶级别********************\n");
	printf("********0.退出游戏********************\n");
	printf("**************************************\n");
}
void game(int choice){
	char board[ROW][COL];
	char show[ROW][COL];
	int ret = 0;          //玩家走一步之后的输赢结果
	int row = 0;
	int col = 0;
	int step = 0;         //已走步数
	int mine = 0;         //雷数
	if(choice == 1){
		row = 8;
		col = 8;
		mine = EASY_COUNT;
	}
	else {
		row = 11;
		col = 11;
		mine = MIDDLE_COUNT;
	}
	InitBoard(board, ROW, COL, '0');		//初始化雷阵
	InitBoard(show, ROW, COL, '*');			//初始化显示矩阵
	srand((unsigned int)time(NULL));
	SetMine(board, row, col, mine);
//	Display(board, row, col);
	Display(show, row, col);
	while(1){
		ret = PlayerMove(board,show, row, col, mine, step);
		if(1 == ret){                        
			break;
		}
		ret = FindMine(board, show, row, col);
		if(1 == ret){   
			Display(show, row, col);
			Display(board, row, col);
			printf("**************革命成功了！*******\n");

			break;
		}
		//Display(board, row, col);
		Display(show, row, col);
		step ++;
	}
}
int main(){
	int choice = 0;

	do{
		menu();
		printf("请输入->");
		scanf("%d",&choice);
		switch(choice){
			case PLAY:game(choice);
				continue;
			case PLAY2:game(choice);
				continue;
			case EXIT:printf("退出游戏");
				break;
			default:printf("没有这个选项，请重新输入\n");
				continue;
		}

	}while(choice);
}