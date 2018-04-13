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
		x = rand()%(row-1)+1;  //��Ϊ����row��8 ���7X7����1~7�������
		y = rand()%(col-1)+1;
		while(board[x][y] == '1'){               //��λ���Ѿ����ף�����ѡλ�á�
			x = rand()%(row-1)+1;  
			y = rand()%(col-1)+1;
		}
		board[x][y] = '1';
	}

}
int FindMine(char board[ROW][COL],char show[ROW][COL], int row, int col){
	//����չ������0��û�п�ɨ�����˷���1
	int flag = 0;
	int i = 0, j = 0;

	for(i=1; i<row; i++){
		for(j=1; j<col;j++){
			if(show[i][j]=='*' && board[i][j]=='0'){  //����ûɨ��������
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
	if(x<1||y<1||x>=row||y>=col||used[x][y]== -1){        //row��8�����±�Ϊ8�͵��߽���
		return;
	}
	used[x][y] = -1;     //���ʹ���
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
		printf("��������Ҫ���׵����꣨x,y��->\n");
		scanf("%d%d",&x,&y);
		if(0 == step && board[x][y] == '1'){
									 //��һ������������ƿ�
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
			printf("����Ƿ���λ�ã�\n");
			continue;
		}

		else if(show[x][y] != '*'){
			printf("���λ�����Ѿ�֪������\n");
			continue;
		}
		else if(board[x][y]=='1'){
			
			Display(board, row, col);
			printf("************��ը��**********\n");
			return 1;                               
		}


		break;	 //�Ϸ�����

	}

	SpreadMine(board, show, used, row, col, x, y);
	return 0;
}