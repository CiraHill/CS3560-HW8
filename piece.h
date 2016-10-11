//***************************************\
//	Favour Ogundare			  \
//					   \
//	Othello Phase 3		 	    O	
//					   /
//	11/20/15			  /
//***************************************/

#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
#include "colors.h"


using namespace std;

class piece{
  public:
	piece(){
        choice = "empty";
        relevant_piece = ' ';}

        void flip();
        bool is_black()const{
                if(choice == "black") return true;}
        bool is_white()const{
                if(choice == "white") return true;}
        bool is_empty()const{
                if(choice == "empty")return true;}

        void black(){
                choice = "black";}
        void white(){
                choice = "white";}
        void empty(){
                choice = "empty";}

        void set_relevant_piece(char input){
                relevant_piece = input;}
                
        char flip_piece()const;
                       

  private:
    string choice;
    char relevant_piece;
};
