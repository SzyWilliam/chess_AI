#include <stdlib.h>
//#include "chess.h"
#include "play.h"

int main(int argc, char *argv[]){

	// initialize
	for(int i = 0; i < LEN; i++){
		for(int j = 0; j < LEN; j++){
			chessBoard[i][j] = EMPTY;
		}
	}

	// start game
	int status;
	int currTurn = BLACK;
	while((status = test_win()) == 0){
		if(play_chess(currTurn) == FAILURE){
			fprintf(stderr, "play failed when currTurn is %d\n", currTurn);
			exit(3);
		}
		currTurn = -currTurn;
	}

	print_board();	

	if(status == FAILURE){
		printf("nobody wins!\n");
	}else if(status == BLACK){
		printf("BLACK wins!\n");
	}else if(status == WHITE){
		printf("WHITE wins!\n");
	}

}
