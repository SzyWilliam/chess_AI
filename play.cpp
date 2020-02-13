#include "play.h"

struct pos{
	int x;
	int y;
};

// return 0 if success, return FAILURE if fail
int play_chess(int chess_category);
struct pos * play_BLACK_chess();
struct pos * play_WHITE_chess();

int play_chess(int chess_category){
	struct pos * pointer;
	if(chess_category == BLACK){
		pointer = play_BLACK_chess();
	}else if(chess_category == WHITE){
		pointer = play_WHITE_chess();
	}else{
		return FAILURE;
	}

	if(pointer != NULL && pointer->x >= 0 && pointer->y >= 0 && pointer->x < LEN && pointer->y < LEN && chessBoard[pointer->x][pointer->y] == EMPTY){
		chessBoard[pointer->x][pointer->y] = chess_category;
		return 0;
	}
	return FAILURE;
}

// return the pointer of the pos
struct pos * play_BLACK_chess(){
	return NULL;
}

struct pos * play_WHITE_chess(){
	return NULL;
}
