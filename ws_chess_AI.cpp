#include "ws_chess_AI.h"
using namespace WS;


std::pair<bool, int> _chess_AI_eval_v1::__check_direction
(board_pointer board, int sx, int sy, int dx, int dy){
    int number = 0;
    int pos_x = sx;
    int pos_y = sy;

    int num_one_side = 0;
    int num_other_side = 0;

    int chess_category = board[sx][sy];

    bool is_live = true;

    // calculate the one side
    while(true) {
        pos_x += dx;
        pos_y += dy;

        if(not this->__bound_check(dx, dy)){ // out of bound, is a dead one
            is_live = false;
            break;
        }

        //inside the bound, available
        if(board[pos_x][pos_y] == chess_category){
            num_one_side++;
        }else if(board[pos_x][pos_y] == EMPTY){
            break;
        }else if(board[pos_x][pos_y] == (-chess_category)){
            is_live = false;
            break;
        }
    }

    // calculate the other side
    while(true){
        pos_x -= dx;
        pos_y -= dy;

        if(not this->__bound_check(dx, dy)){ // out of bound, is a dead one
            is_live = false;
            break;
        }

        //inside the bound, available
        if(board[pos_x][pos_y] == chess_category){
            num_one_side++;
        }else if(board[pos_x][pos_y] == EMPTY){
            break;
        }else if(board[pos_x][pos_y] == (-chess_category)){
            is_live = false;
            break;
        }
    }

    number = num_one_side + num_other_side + 1; // the 1 for (sx, sy)
    return std::pair<bool, int>(is_live, number);
}





int _chess_AI_eval_v1::__count_all(std::vector<std::pair<bool, int> > rules){
    int result = 0;
    typedef std::vector<std::pair<bool, int> >::iterator v_iter;

    for(v_iter iter = rules.begin(); iter != rules.end(); ++iter){
        int *rule_array;
        rule_array = (iter->first == true) ? dead : live;
        result += rule_array[iter->second];
    }

    return result;
}

std::vector<std::pair<bool, int> > 
_chess_AI_eval_v1::detect(board_pointer board, int sx, int sy, int chess_category){

    if(board[sx][sy] != EMPTY){
        std::cerr << "ERROR: WS::_chess_AI_eval_v1::detect\n NOT EMPTY in " << sx << ", " << sy << std::endl;
        exit(0);
    }

    std::vector<std::pair<bool, int> > result;
    bool depress = false;
    for(int round = 0; round < 2; round++, depress = false){
        
    }
    return result;
    

}