//***************************************\
//	Favour Ogundare			  \
//					   \
//	Othello Phase 3			    O	
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
#include "piece.h"

using namespace std;


        void piece :: flip(){
                if(is_black() == true){
                  white();

                }else if(is_white() == true){
                  black();

                }else{

                }
        }


        char piece :: flip_piece()const{
                if(is_white() == true){
                  cout << WHITE;
                  cout << relevant_piece;

                }else if(is_black() == true){
                  cout << BLACK;
                  cout << relevant_piece;
                }else{
                  cout << relevant_piece;
                }
        }
