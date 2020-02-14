#include <stdlib.h>
#include "ws_chess_AI.h"
#include "play.h"

// get "BLACK" from BLACK and get "WHITE" from WHITE
char * getName(int currTurn){
	if(currTurn == BLACK){
		return "BLACK";
	}
	if(currTurn == WHITE){
		return "WHITE";
	}
	return NULL;
}

int main(int argc, char *argv[]){

	// initialize
	for(int i = 0; i < LEN; i++){
		for(int j = 0; j < LEN; j++){
			chessBoard[i][j] = EMPTY;
		}
	}

	WS::chess_AI_eval_v1 WSAI;
	WSAI.__debug_test();


	// start game
	int status;
	// BLACK is the first hand
	int currTurn = BLACK;
	// if nobody wins and the board still has empty positions, keep the game going on 
	while((status = test_win()) == 0){
		// somebody's AI go wrong
		if(play_chess(currTurn) == FAILURE){
			// print the board and exit
			print_board();
			fprintf(stderr, "play failed when currTurn is %s\n", getName(currTurn));
			exit(3);
		}
		// change the turn
		currTurn = -currTurn;
	}

	print_board();	

	if(status == FAILURE){
		// the board is full but nobody wins
		printf("nobody wins!\n");
	}else if(status == BLACK){
		// BLACK wins
		printf("BLACK wins!\n");
	}else if(status == WHITE){
		// WHITE wins
		printf("WHITE wins!\n");
	}

}
