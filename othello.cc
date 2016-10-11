//***************************************\
//	Favour Ogundare			  \
//					   \
//	othello Phase 3			    O	
//					   /
//	11/20/15			  /
//***************************************/

#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "game.h"
#include "colors.h"
#include "othello.h"

using namespace std;

void othello :: display_status( )const{
  cout << "  A  B  C  D  E  F  G  H " << endl;
		for (int i = 0; i < 8; i++)
		{
	 		cout << endl << (i+1);
	 		for(int j=0; j<8; j++)
			{ 
	  			if ((i+j)%2 == 0)
				{
					if (board[i][j].is_empty())
					{
						cout << B_RED << "   " << RESET;
					}
					
					if (board[i][j].is_white())
					{
						cout << B_RED << WHITE << " 0 " << RESET;
					}
			
					if (board[i][j].is_black())
					{
						cout << B_RED << BLACK << " 0 " << RESET;
					}
				}

				else
				{
					if (board[i][j].is_empty())
					{
						cout << B_CYAN << "   " << RESET;
					}
	
					if (board[i][j].is_black())
					{
						cout << B_CYAN << BLACK << " 0 " << RESET;
					}
	
					if (board[i][j].is_white())
					{
						cout << B_CYAN << WHITE << " 0 " << RESET;
					}
				}
			}
		}

  cout << RESET;
  cout << endl;

  cin.sync();
  cout << " - Turn - " << moves_completed() + 1;
  cout << "\n";
  if(moves_completed() % 2 == 0){
    cout << "Black" << endl;
  }else if(moves_completed() % 2 == 1){
    cout << "White" << endl;
  }

}

void othello :: restart(){

        for(int i = 0; i < 7; ++i){
                for(int j = 0; j < 7; ++j){
                        board[i][j].empty();
                        board[i][j].set_relevant_piece(' ');
                }
        }
                       
                board[3][3].white();
                board[4][4].white();
                board[3][4].black();
                board[4][3].black();

                board[3][3].set_relevant_piece('0');
                board[4][4].set_relevant_piece('0');
                board[3][4].set_relevant_piece('0');
                board[4][3].set_relevant_piece('0');

                skip = 0;
                cout << endl << endl;
}

int othello :: black_count()const{
int mic = 0;
        for(int i = 0; i <= 7; ++i){
                for(int j = 0; j <= 7; ++j){
                        if(board[i][j].is_black()){
                          ++ mic;
                        }
                }
        }
return mic;
}

int othello :: white_count()const{
int mic = 0;
        for(int i = 0; i <= 7; ++i){
                for(int j = 0; j <= 7; ++j){
                        if(board[i][j].is_white()){
                          ++ mic;
                        }
                }
        }
return mic;
}

bool othello :: is_legal(const std::string& move)const{

if(move == "s" || move == "skip" || move == "Skip" ||
   move == "S" || move == "SKIP"){
  return true;
}else{


int row, column;
row = (move[1] - '0' - 1);
if(isupper(move[0])){
  column = (int)((move[0] - 'A'));
}else{
    column = (int)((move[0] - 'a'));
}





if(row < 0 || column < 0 || row > 7 || column > 7){
  return false;
}
if(board[row][column].is_empty() != true){
  return false;
}




if(next_mover() == HUMAN){

if((row - 1) < 8 && (column) > -1 && (row - 1) > -1 && (column) < 8){
  if(board[row - 1][column].is_white() == true && (row - 1)> -1){
    int trow = row-1;
    while(trow <=7 && trow >= 0 && !board[trow][column].is_empty()){

        if(board[trow][column].is_black() == true){
          return true;
        }
        trow--;
    }
  }
}

if((row + 1) < 8 && (column) > -1 && (row + 1) > -1 && (column) < 8){

  if(board[row + 1][column].is_white() == true && (row + 1) < 8){
    int trow = row+1;
    while(trow <=7 && trow >= 0 && !board[trow][column].is_empty()){
        if(board[trow][column].is_black() == true){
          return true;
        }
        trow++;
    }
  }
}


if((row) < 8 && (column - 1) > -1 && (row) > -1 && (column - 1) < 8){
  if(board[row][column - 1].is_white() == true && (column - 1) > -1){
    int tcol = column-1;
    while(tcol <=7 && tcol >= 0 && !board[row][tcol].is_empty()){
        if(board[row][tcol].is_black() == true){
          return true;
        }
        tcol--;
    }
  }
}


if((row + 1) < 8 && (column) > -1 && (row + 1) > -1 && (column) < 8){
  if(board[row][column + 1].is_white() == true && (column + 1) < 8){
    int tcol = column+1;
    while(tcol <=7 && tcol >= 0 && !board[row][tcol].is_empty()){
        if(board[row][tcol].is_black() == true){
          return true;
        }
        tcol++;
    }
  }
}

if((row - 1) < 8 && (column - 1) > -1 && (row - 1) > -1 && (column - 1) < 8){
  if(board[row - 1][column - 1].is_white() == true && (row - 1)> -1 && (column - 1) > -1){
    int trow = row-1;
    int tcol= column-1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_black() == true){
          return true;
        }
        trow--;
        tcol--;
    }
  }
}


if((row - 1) < 8 && (column + 1) > -1 && (row - 1) > -1 && (column + 1) < 8){
  if(board[row - 1][column + 1].is_white() == true && (row - 1)> -1 && (column + 1) < 8){
    int trow = row-1;
    int tcol= column+1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_black() == true){
          return true;
        }
        trow--;
        tcol++;
    }
  }
}


if((row + 1) < 8 && (column + 1) > -1 && (row + 1) > -1 && (column + 1) < 8){
  if(board[row + 1][column + 1].is_white() == true && (row + 1) < 8 && (column + 1) < 8){
    int trow = row+1;
    int tcol= column+1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_black() == true){
          return true;
        }
        trow++;
        tcol++;
    }
  }
}


 if((row + 1) < 8 && (column - 1) > -1 && (row + 1) > -1 && (column - 1) < 8){
  if(board[row + 1][column - 1].is_white() == true && (row + 1) < 8 && (column - 1) > -1){
    int trow = row+1;
    int tcol= column-1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_black() == true){
          return true;
        }
        trow++;
        tcol--;
    }
  }

 }else{
   return false;
 }        


}else if(next_mover() == COMPUTER){


if((row - 1) < 8 && (column ) > -1 && (row - 1) > -1 && (column) < 8){
  if(board[row - 1][column].is_black() == true && (row - 1) > -1){
    int trow = row -1;
    while(trow <=7 && trow >= 0&& !board[trow][column].is_empty()){
        if(board[trow][column].is_white() == true){
          return true;
        }
        trow--;
    }
  }
}


if((row + 1) < 8 && (column) > -1 && (row + 1) > -1 && (column) < 8){
  if(board[row + 1][column].is_black() == true && (row + 1) < 8){
    int trow = row+1;
    while(trow <=7 && trow >= 0&& !board[trow][column].is_empty()){
        if(board[trow][column].is_white() == true){
          return true;
        }
        trow++;
    }
  }
}


if((row) < 8 && (column - 1) > -1 && (row) > -1 && (column - 1) < 8){
  if(board[row][column - 1].is_black() == true && (column - 1) > -1){
    int tcol = column-1;
    while(tcol <=7 && tcol >= 0&& !board[row][tcol].is_empty()){
        if(board[row][tcol].is_white() == true){
          return true;
        }
        tcol--;
    }
  }
}


if((row) < 8 && (column + 1) > -1 && (row) > -1 && (column + 1) < 8){
  if(board[row][column + 1].is_black() == true && (column + 1) < 8){
    int tcol =column+1;
    while(tcol <=7 && tcol >= 0&& !board[row][tcol].is_empty()){
        if(board[row][tcol].is_white() == true){
          return true;
        }
        tcol++;
    }
  }
}


if((row - 1) < 8 && (column - 1) > -1 && (row - 1) > -1 && (column - 1) < 8){
  if(board[row - 1][column - 1].is_black() == true && (row - 1) > -1 && (column - 1) > -1){
    int trow = row-1;
    int tcol= column-1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_white() == true){
          return true;
        }
        trow--;
        tcol--;
    }
  }
}


if((row - 1) < 8 && (column + 1) > -1 && (row - 1) > -1 && (column + 1) < 8){
  if(board[row - 1][column + 1].is_black() == true && (row - 1) > -1 && (column + 1) < 8){
    int trow = row-1;
    int tcol= column+1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_white() == true){
          return true;
        }
        trow--;
        tcol++;
    }
  }
}


if((row + 1) < 8 && (column + 1) > -1 && (row + 1) > -1 && (column + 1) < 8){
  if(board[row + 1][column + 1].is_black() == true && (row + 1) < 8 && (column + 1) < 8){
    int trow = row+1;
    int tcol= column+1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_white() == true){
          return true;
        }
        trow++;
        tcol++;
    }
  }
}


 if((row + 1) < 8 && (column - 1) > -1 && (row + 1) > -1 && (column - 1) < 8){
  if(board[row + 1][column - 1].is_black() == true && (row + 1) < 8 && (column - 1) > -1){
    int trow = row+1;
    int tcol= column-1;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && !board[trow][tcol].is_empty()){
        if(board[trow][tcol].is_white() == true){
          return true;
        }
        trow++;
        tcol--;
    }
  }

 }else{
   return false;
 }        

}
}

}

void othello :: make_move(const std::string& move){
if(move == "s" || move == "skip" || move == "Skip" ||
   move == "S" || move == "SKIP"){
  game::make_move(move);
  ++skip;
}else{

int row, column;
row = (move[1] - '0' - 1);
if(isupper(move[0])){
  column = (int)((move[0] - 'A'));
}else{
    column = (int)((move[0] - 'a'));
}


if(next_mover() == HUMAN){

  board[row][column].black();
  board[row][column].set_relevant_piece('0');


if((row - 1) < 8 && (column) > -1 && (row - 1) > -1 && (column) < 8){
  if(board[row - 1][column].is_white() == true && (row - 1)> -1){
    for(int i = row - 2; i >= 0; i--){
        if(board[i][column].is_black() == true){
          for(int j = i+1;j < row; j++){
            board[j][column].flip();
          }
        break;
        }
    }
  }
}

if((row + 1) < 8 && (column) > -1 && (row+1) > -1 && (column) < 8){
  if(board[row + 1][column].is_white() == true && (row + 1) < 8){
    for(int i = (row + 2); i <= 7; i++){
        if(board[i][column].is_black() == true){
          for(int j = i-1;j > row; j--){
            board[j][column].flip();
          }
        break;
        }
    }
  }
}

if((row) < 8 && (column - 1) > -1 && (row) > -1 && (column - 1) < 8){
  if(board[row][column - 1].is_white() == true && (column - 1) > -1){
    for(int i = column - 2; i > 0; i--){
        if(board[row][i].is_black() == true){
          for(int j = i+1;j < column; j++){
            board[row][j].flip();
          }
        break;
        }
    }
  }
}

if((row) < 8 && (column + 1) > -1 && (row) > -1 && (column + 1) < 8){
  if(board[row][column + 1].is_white() == true && (column + 1) < 8){
    for(int i = (column + 2); i <= 7; i++){
        if(board[row][i].is_black() == true){
          for(int j = i-1;j > column; j--){
            board[row][j].flip();
          }
        break;
        }
    }
  }
}

if((row - 1) < 8 && (column - 1) > -1 && (row-1) > -1 && (column - 1) < 8){
  if(board[row - 1][column - 1].is_white() == true && (row - 1) > -1 && (column - 1) > -1){
    int trow = row-2;
    int tcol = column-2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_black() == true){
          trow++;
          tcol++;
          while(trow < row && tcol < column){
            board[trow][tcol].flip();
             trow++;
            tcol++;
          }
        break;
        }else{
          trow--;
          tcol--;
        }
    }
  }
}
 
if((row - 1) < 8 && (column + 1) > -1 && (row-1) > -1 && (column + 1) < 8){
  if(board[row - 1][column + 1].is_white() == true && (row - 1) > -1 && (column + 1) < 8){
    int trow = row-2;
    int tcol = column+2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_black() == true){
          trow++;
          tcol--;
          while(trow < row && tcol > column){
            board[trow][tcol].flip();
             trow++;
            tcol--;
          }
        break;
        }else{
          trow--;
          tcol++;
        }
    }
  }
}

if((row + 1) < 8 && (column + 1) > -1 && (row+1) > -1 && (column + 1) < 8){
  if(board[row + 1][column + 1].is_white() == true && (row + 1) < 8 && (column + 1) < 8){
    int trow = row+2;
    int tcol = column+2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_black() == true){
          trow--;
          tcol--;
          while(trow > row && tcol > column){
            board[trow][tcol].flip();
             trow--;
            tcol--;
          }
        break;
        }else{
          trow++;
          tcol++;
        }
    }
  }
}

if((row + 1) < 8 && (column - 1) > -1 && (row+1) > -1 && (column - 1) < 8){
  if(board[row + 1][column - 1].is_white() == true && (row + 1) < 8 && (column - 1) > -1){
    int trow = row+2;
    int tcol = column-2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_black() == true){
          trow--;
          tcol++;
          while(trow > row && tcol < column){
            board[trow][tcol].flip();
             trow--;
            tcol++;
          }
        break;
        }else{
          trow++;
          tcol--;
        }
    }
  }
}
}

 
if(next_mover() == COMPUTER){

  board[row][column].white();
  board[row][column].set_relevant_piece('0');


if( (row - 1) < 8 && (column) > -1 && (row-1) > -1 && (column) < 8){
  if(board[row - 1][column].is_black() == true){
    for(int i = row - 2; i >= 0; i--){
        if(board[i][column].is_white() == true){
          for(int j = i+1;j < row; j++){
            board[j][column].flip();
          }
        break;
        }
    }
  }
}

if((row + 1) < 8 && (column) > -1 && (row+1) > -1 && (column) < 8){
  if(board[row + 1][column].is_black() == true && (row + 1) < 8){
    for(int i = (row + 2); i <= 7; i++){
        if(board[i][column].is_white() == true){
          for(int j = i-1;j > row; j--){
            board[j][column].flip();
          }
        break;
        }
    }
  }
}

if((row) < 8 && (column - 1) > -1 && (row) > -1 && (column - 1) < 8){
  if(board[row][column - 1].is_black() == true && (column - 1) > -1){
    for(int i = column - 2; i >= 0; i--){
        if(board[row][i].is_white() == true){
          for(int j = i+1;j < column; j++){
            board[row][j].flip();
          }
        break;
        }
    }
  }
}

if((row) < 8 && (column + 1) > -1 && (row) > -1 && (column + 1) < 8){
  if(board[row][column + 1].is_black() == true && (column + 1) < 8){
    for(int i = (column + 2); i <= 7; i++){
        if(board[row][i].is_white() == true){
          for(int j = i-1;j > column; j--){
            board[row][j].flip();
          }
        break;
        }
    }
  }
}

if((row - 1) < 8 && (column - 1) > -1 && (row-1) > -1 && (column - 1) < 8){
    int trow = row-2;
  if(board[row - 1][column - 1].is_black() == true && (row - 1) > -1 && (column - 1) > -1){
    int trow = row-2;
    int tcol = column-2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_white() == true){
          trow++;
          tcol++;
          while(trow < row && tcol < column){
            board[trow][tcol].flip();
             trow++;
            tcol++;
          }
        break;
        }else{
          trow--;
          tcol--;
        }
    }
  }
}

if((row - 1) < 8 && (column + 1) > -1 && (row-1) > -1 && (column + 1) < 8){
  if(board[row - 1][column + 1].is_black() == true && (row - 1) > -1 && (column + 1) < 8){
    int trow = row-2;
    int tcol = column+2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_white() == true){
          trow++;
          tcol--;
          while(trow < row && tcol > column){
            board[trow][tcol].flip();
             trow++;
            tcol--;
          }
        break;
        }else{
          trow--;
          tcol++;
        }
    }
  }
}

if((row + 1) < 8 && (column + 1) > -1 && (row+1) > -1 && (column + 1) < 8){
  if(board[row + 1][column + 1].is_black() == true && (row + 1) < 8 && (column + 1) < 8){
    int trow = row+2;
    int tcol = column+2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0){
        if(board[trow][tcol].is_white() == true){
          trow--;
          tcol--;
          while(trow > row && tcol > column){
            board[trow][tcol].flip();
             trow--;
            tcol--;
          }
        break;
        }else{
          trow++;
          tcol++;
        }
    }
  }
}

if((row + 1) < 8 && (column - 1) > -1 && (row+1) > -1 && (column - 1) < 8){
  if(board[row + 1][column - 1].is_black() == true){
    int trow = row+2;
    int tcol = column-2;
    while(trow <=7 && trow >= 0 && tcol <=7 && tcol >= 0 && (row + 1) < 8 && (column - 1) > -1){
        if(board[trow][tcol].is_white() == true){
          trow--;
          tcol++;
          while(trow > row && tcol < column){
            board[trow][tcol].flip();
             trow--;
            tcol++;
          }
        break;
        }else{
          trow++;
          tcol--;
        }
    }
  }
}
}

skip = 0;
game::make_move(move);
}


 }


bool othello :: is_game_over() const{

 if(black_count() + white_count() == 64){
        return true;
 }
 if(white_count() == 0 || black_count() == 0){
   return true;
 }
 if(skip == 2){
   return true;
 }

return false;

}


game :: who othello :: winning( ) const{

  if (black_count() > white_count()){
        return HUMAN;
  }else if(black_count() < white_count()){
        return COMPUTER;
  }else{
        return NEUTRAL;
  }

}



void othello :: compute_moves(std::queue<std::string>& moves) const{



string row, column, input;

        for(int i = 0; i < 7; ++i){
                for(int j = 0; j < 7; ++j){
                  row = (i + 'A');
                  column = (j + '1');
                  input = row + column;
                        if(is_legal(input) == true){
                          moves.push(input);
                        }
                }
        }

        if(moves.size() == 0){
          moves.push("s");
        }
}

int othello :: evaluate() const{

int human_cost = 0;
int computer_cost = 0;

if(board[0][0].is_white() || board[0][7].is_white() ||
   board[7][0].is_white() || board[7][7].is_white()){
  computer_cost = computer_cost + 2;
}

if(board[0][0].is_black() || board[0][7].is_black() ||
   board[7][0].is_black() || board[7][7].is_black()){
  human_cost = human_cost + 2;
}

  for(int i = 0; i < 8; ++i){

    for(int j = 0; j < 8; ++j){
        if(board[i][j].is_black()){
          human_cost = human_cost + 1;
        }
        if(board[i][j].is_white()){
          computer_cost = computer_cost + 1;
         }

        if(board[0][j].is_black()){
          human_cost = human_cost + 1;
        }
        if(board[0][j].is_white()){
          computer_cost = computer_cost + 1;
         }
        if(board[7][j].is_black()){
          human_cost = human_cost + 1;
        }
        if(board[7][j].is_white()){
          computer_cost = computer_cost + 1;
         }
    }
    if(board[i][0].is_black()){
      human_cost = human_cost + 1;
    }
    if(board[i][0].is_white()){
      computer_cost = computer_cost + 1;
    }
    if(board[i][7].is_black()){
      human_cost = human_cost + 1;
    }
    if(board[i][7].is_white()){
      computer_cost = computer_cost + 1;
    }
   
  }

  int eval = computer_cost - human_cost;
  return eval;
}
