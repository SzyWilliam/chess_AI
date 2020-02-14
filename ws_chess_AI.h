#ifndef __WS_CHESS_AI_H_
#define __WS_CHESS_AI_H_

//the _DIR_XX definitions are only used in func parameters
#define _DIR_UP         0, -1
#define _DIR_DOWN       0,  1
#define _DIR_LEFT      -1,  0
#define _DIR_RIGHT      1,  0
#define _DIR_LEFT_UP   -1, -1
#define _DIR_LEFT_DOWN -1,  1
#define _DIR_RIGHT_UP   1, -1
#define _DIR_RIGHT_DOWN 1,  1

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include "chess.h"

namespace WS
{
    class _base_chess_AI {
    public:
        typedef int** board_pointer;

        int evaluate(board_pointer board, int pos_x, int pos_y, int chess_category){
            return 0;
        }    

    };

    class chess_AI_eval_v1 : public _base_chess_AI
    {
        int live[5];
        int dead[5];

    private:
        void init_eval_weight() {
            live[0] = -1;  //place holder
            live[1] = 1;
            live[2] = 25;  // this value is some what arbritary, and need revise
            live[3] = 50;  // two or more live_3s will win
            live[4] = 100; // wins, so it is the Compare Criteria

            dead[0] = -1;  // place holder
            dead[1] = -2;  // meaningless (except to compress a live 4/ live 3)
            dead[2] = 15;  // this value is some what arbritary, and need revise
            dead[3] = 30;  // similar to live_2, but potentially to have dead_4s
            dead[4] = 50;  // doule dead_4s or one dead_4 + dead_3 win
        }

        /* 
           ASSUME the (sx, sy) is the SAME as the @chess_category
           
           currently not supporting the SUPRESS
           todo add the supress function from the other side 
        */
        std::vector<std::pair<bool, int> > 
        detect_positive(int board[LEN][LEN], int sx, int sy, int chess_category);

        /* 
           ASSUME the (sx, sy) is the OPPOSITE as the @chess_category and already set
           
           calculate the negetive effects it put to the other side
        */
        std::vector<std::pair<bool, int> >
        detrct_negetive(int board[LEN][LEN], int sx, int sy, int chess_category);

    private:/* the helper functions inside-only*/

        /* the chess is SUPPOSED to be set at (sx, sy) (NOT already)
           ASSUME the (sx, sy) is the SAME as the @chess_category
           this function will KEEP board the same
           
           check the situation for CHESS @chess_category at position (@sx, @sy)
           return pair<@bool = true if is live, false if is dead, @int level)
        */
        std::pair<bool, int>
        __check_direction(int board[LEN][LEN], int sx, int sy, int dx, int dy);

        /* count the final score of all rules */
        int __count_all(std::vector<std::pair<bool, int> > rules);

        /* check if (x,y) is still inside the boundery */
        inline bool __bound_check(int x, int y, int bound = LEN){
            return (0 <= x) && (x < bound) && (0 <= y) && (y < bound);
        }

        


    public:
        chess_AI_eval_v1(){};
        void __debug_test();


    };
}


#endif/*__WS_CHESS_AI_H_*/
