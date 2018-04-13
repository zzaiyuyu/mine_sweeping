#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col, char set){
	memset(board,set,row*col*sizeof(char));
}
void Display(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;

	for(i=1; i<row; i++){
		if(i == 1){
			for(j=1; j<col;j++){
				if(1 == j){
					printf("   ");
				}
				printf("|%2d|",j);
			}
			printf("\n");
			for(j=1; j<col;j++){
				if(1 == j){
					printf("   ");
				}
				printf(" ---");
			}
			printf("\n");
		}
		for(j=1; j<col;j++){
			if(1 == j){
				printf("%2d|",i);
			}
			printf("| %c ",board[i][j]);
		}
		printf("|\n");
		for(j=1; j<col;j++){
			if(1 == j){
				printf("   ");
			}
			printf(" ---");
		}
		printf("\n");
	}
		printf("\n");
}
void SetMine(char board[ROW][COL], int row, int col, int mine){
	int x = 0;
	int y = 0;
	int i = 0;
	for(i=0; i<mine; i++){
		x = rand()%(row-1)+1;  //因为传的row是8 如果7X7生成1~7的随机数
		y = rand()%(col-1)+1;
		while(board[x][y] == '1'){               //该位置已经有雷，重新选位置。
			x = rand()%(row-1)+1;  
			y = rand()%(col-1)+1;
		}
		board[x][y] = '1';
	}

}
int FindMine(char board[ROW][COL],char show[ROW][COL], int row, int col){
	//正常展开返回0，没有可扫的雷了返回1
	int flag = 0;
	int i = 0, j = 0;

	for(i=1; i<row; i++){
		for(j=1; j<col;j++){
			if(show[i][j]=='*' && board[i][j]=='0'){  //还有没扫出来的雷
				flag = 1;
				break;
			}
		}
	}
	if(!flag){
		return 1;
	}

	
	return 0;
}
void SpreadMine(char board[ROW][COL],char show[ROW][COL],int used[ROW][COL], int row, int col, int x, int y){
	int tmp = 0;
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	int tmpx = 0, tmpy = 0;
	int i;
	if(x<1||y<1||x>=row||y>=col||used[x][y]== -1){        //row是8，到下标为8就到边界了
		return;
	}
	used[x][y] = -1;     //访问过了
	if(board[x][y]=='0'){
		show[x][y]= ' ';
	}
	tmp = board[x-1][y-1]+board[x-1][y+0]+board[x-1][y+1]+board[x+0][y-1]+board[x+0][y+1]+board[x+1][y-1]+board[x+1][y+0]+board[x+1][y+1]- 8*'0';
	if(tmp > 0 ){
		show[x][y] = tmp + '0';
		return;
	}
	for(i=0; i<4; i++){
		tmpx = x +dir[i][0];
		tmpy = y +dir[i][1];
		SpreadMine(board, show, used, row, col, tmpx, tmpy);
	}
	
}
int PlayerMove(char board[ROW][COL], char show[ROW][COL], int row, int col,int mine, int step){     
	int x = 0;
	int y = 0;
	int i = 0, j = 0;
	int used[ROW][COL]= {0};
	while(1){
		printf("请输入你要排雷的坐标（x,y）->\n");
		scanf("%d%d",&x,&y);
		if(0 == step && board[x][y] == '1'){
									 //第一步是雷则把雷移开
			for(i=1; i<row; i++){
				for(j=1; j<col; j++){
					if(board[i][j]=='0'){
						board[i][j]='1';
						board[x][y]='0';
						break;
					}
				}
			}
			
		}
		if(x>=row|| y>=col|| x<=0|| y<=0){
			printf("输入非法的位置！\n");
			continue;
		}

		else if(show[x][y] != '*'){
			printf("这个位置你已经知道啦！\n");
			continue;
		}
		else if(board[x][y]=='1'){
			
			Display(board, row, col);
			printf("************你炸了**********\n");
			return 1;                               
		}


		break;	 //合法输入

	}

	SpreadMine(board, show, used, row, col, x, y);
	return 0;
}