#include "ws_chess_AI.h"
using namespace WS;


std::pair<bool, int> chess_AI_eval_v1::__check_direction
(int board[LEN][LEN], int sx, int sy, int dx, int dy){
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

        if(not this->__bound_check(pos_x, pos_y)){ // out of bound, is a dead one
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
    pos_x = sx;
    pos_y = sy;
    while(true){
        pos_x -= dx;
        pos_y -= dy;

        if(not this->__bound_check(pos_x, pos_y)){ // out of bound, is a dead one
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

    std::cout << is_live << ", " << number << std::endl;
    return std::pair<bool, int>(is_live, number);
}





int chess_AI_eval_v1::__count_all(std::vector<std::pair<bool, int> > rules){
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
chess_AI_eval_v1::detect_positive(int board[LEN][LEN], int sx, int sy, int chess_category){

    if(board[sx][sy] == EMPTY){
        std::cerr << "ERROR: WS::_chess_AI_eval_v1::detect\n NOT EMPTY in " << sx << ", " << sy << std::endl;
        exit(0);
    }

    std::vector<std::pair<bool, int> > result;

    result.push_back(this->__check_direction(board, sx, sy, _DIR_UP));
    //result.push_back(this->__check_direction(board, sx, sy, _DIR_DOWN));
    result.push_back(this->__check_direction(board, sx, sy, _DIR_LEFT));
    //result.push_back(this->__check_direction(board, sx, sy, _DIR_RIGHT));
    result.push_back(this->__check_direction(board, sx, sy, _DIR_LEFT_UP));
    result.push_back(this->__check_direction(board, sx, sy, _DIR_LEFT_DOWN));
    //result.push_back(this->__check_direction(board, sx, sy, _DIR_RIGHT_UP));
    //result.push_back(this->__check_direction(board, sx, sy, _DIR_RIGHT_DOWN));
    
    
    return result;
}

void chess_AI_eval_v1::__debug_test() {
    this->init_eval_weight();

    chessBoard[0][0] = EMPTY;
    chessBoard[0][1] = BLACK;
    chessBoard[0][2] = BLACK;
    chessBoard[0][3] = BLACK;
    chessBoard[0][4] = BLACK;

    chessBoard[1][2] = BLACK;
    std::cout << "what is" << this->__count_all(detect(chessBoard, 0, 2, WHITE)) << std::endl;
    
}