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
#include "othello.h"
#include "game.h"
#include "colors.h"


using namespace main_savitch_14;

void wait();
int main(){

wait();

cin.sync();


othello new_game;

int winner = new_game.play();
  if(winner == 0){
    cout << endl;
    cout << "Player 1 wins! \n";
  }else if(winner == 1){
    cout << endl;
    cout << "It's a draw!\n";
  }else if(winner == 2){
    cout << endl;
    cout << "You Lost!\n";
}
return 0;
}

void wait(){
  cout << "\n";
  cout << "\nEnter any key to start:";

  char msg;                                    // show message until user enters
  cin >> msg;                                  // any key to continue
}

