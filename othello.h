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
#include "piece.h"

#ifndef OTHELLO_H
#define OTHELLO_H

using namespace main_savitch_14;
using namespace std;

	class othello:public game
	{
		public:
		
		    int white_count()const;
        	int black_count()const;
			void restart();
			void display_status() const;
			void make_move(const std::string& move);
			bool is_legal(const std::string& move) const;
			void compute_moves(std::queue<std::string>& moves) const;
			bool is_game_over() const;
			int evaluate() const;
			game *clone() const{return new othello(*this);}
			game:: who winning( ) const;
		

		private:
		
				piece board[8][8];
        		int skip;
        		int black_win;
        		int white_win;
	};
	
#endif
