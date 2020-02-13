#ifndef __CHESS_H__
#define __CHESS_H__
#include <stdio.h>

#define WHITE 1
#define BLACK -1
#define EMPTY 0
#define FAILURE -2
#define LEN 19

extern int chessBoard[LEN][LEN];

/* return 0 if success, return WHITE if there is already a WHITE chess , the same as BLACK,
   return FAILURE if out of border or chess_category is wrong
*/
int make_move(int pos_x, int pos_y, int chess_category);

// return 0 if nobody wins, otherwise return WHITE or BLACK
int test_win();

void print_board();
#endif
