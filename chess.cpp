#include <stdio.h>
#include "chess.h"

int chessBoard[LEN][LEN];

char* getStyle(int i,int j);

void print_board(){
	for(int i = -1; i <= LEN; i++){
		for(int j = -1; j <= LEN; j++){
			if(i != -1 && j != -1 && i != LEN && j != LEN && chessBoard[i][j] != EMPTY){
				printf("%s", getStyle(i ,j));
			}else{
				printf("%s", getStyle(i, j));
			}
		}
		printf("\n");
	}
}

//获得棋盘中指定坐标交点位置的字符，通过制表符拼成棋盘
char* getStyle(int i,int j){
	if(i >= 0 && j >= 0 && i < LEN && j < LEN){
		if(chessBoard[i][j] == BLACK)//1为黑子
			return "●";
		else if(chessBoard[i][j] == WHITE)//2为白子
			return "○";
	}
	else if(i == -1 && j == -1)//以下为边缘棋盘样式
		return "┏";
	else if(j == LEN && i == -1)
		return "┓";
	else if(i == LEN && j == LEN)
		return "┛";
	else if(j == -1 && i == LEN)
		return "┗";
	else if(j == -1)
		return "┠";
	else if(j == LEN)
		return "┨";
	else if(i == -1)
		return "┯";
	else if(i == LEN)
		return "┷";
	return "┼";//中间的空位
}

int make_move(int pos_x, int pos_y, int chess_category){
	if(pos_x < 0 || pos_y < 0 || pos_x >= LEN || pos_y >= LEN || (chess_category != WHITE && chess_category != BLACK)){
		return FAILURE;
	}
	if(chessBoard[pos_x][pos_y] != EMPTY){
		return chessBoard[pos_x][pos_y];
	}
	chessBoard[pos_x][pos_y] = chess_category;
	return 0;
}

int test_win(){
	int currChess;
	for(int i = 0; i <= LEN - 5; i++){
		for(int j = 0; j < LEN; j++){
			if((currChess = chessBoard[i][j]) != EMPTY){
				if(chessBoard[i + 1][j] == currChess && chessBoard[i + 2][j] == currChess && 
					chessBoard[i + 3][j] == currChess && chessBoard[i + 4][j] == currChess){
					return currChess;
				}
			}
		}
	}
	for(int i = 0; i <= LEN - 5; i++){
		for(int j = 0; j < LEN; j++){
			if((currChess = chessBoard[i][j]) != EMPTY){
				if(chessBoard[j][i + 1] == currChess && chessBoard[j][i + 2] == currChess && 
					chessBoard[j][i + 3] == currChess && chessBoard[j][i + 4] == currChess){
					return currChess;
				}
			}
		}
	}
	for(int i = 0; i <= LEN - 5; i++){
		for(int j = 0; j <= LEN - 5; j++){
			if((currChess = chessBoard[i][j]) != EMPTY){
				if(chessBoard[i + 1][j + 1] == currChess && chessBoard[i + 2][j + 2] == currChess && 
					chessBoard[i + 3][j + 3] == currChess && chessBoard[i + 4][j + 4] == currChess){
					return currChess;
				}
			}
		}
	}
	for(int i = 4; i < LEN; i++){
		for(int j = 4; j <LEN; j++){
			if((currChess = chessBoard[i][j]) != EMPTY){
				if(chessBoard[i - 1][j - 1] == currChess && chessBoard[i - 2][j - 2] == currChess && 
					chessBoard[i - 3][j - 3] == currChess && chessBoard[i - 4][j - 4] == currChess){
					return currChess;
				}
			}
		}
	}

	bool isFull = 1;
	for(int i = 0; i < LEN; i++){
		for(int j = 0; j < LEN; j++){
			if(chessBoard[i][j] == EMPTY){
				isFull = 0;
			}
		}
	}
	
	if(isFull){
		return FAILURE;
	}

	return 0;
}


