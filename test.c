#include <stdio.h>
#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

void menu(){
	printf("**************************************\n");
	printf("********��һ�̾��մ̼���ɨ�װ�********\n");
	printf("********1.���ż���********************\n");
	printf("********2.���׼���********************\n");
	printf("********0.�˳���Ϸ********************\n");
	printf("**************************************\n");
}
void game(int choice){
	char board[ROW][COL];
	char show[ROW][COL];
	int ret = 0;          //�����һ��֮�����Ӯ���
	int row = 0;
	int col = 0;
	int step = 0;         //���߲���
	int mine = 0;         //����
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
	InitBoard(board, ROW, COL, '0');		//��ʼ������
	InitBoard(show, ROW, COL, '*');			//��ʼ����ʾ����
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
			printf("**************�����ɹ��ˣ�*******\n");

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
		printf("������->");
		scanf("%d",&choice);
		switch(choice){
			case PLAY:game(choice);
				continue;
			case PLAY2:game(choice);
				continue;
			case EXIT:printf("�˳���Ϸ");
				break;
			default:printf("û�����ѡ�����������\n");
				continue;
		}

	}while(choice);
}