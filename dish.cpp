//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Dish Implementation

#include "dish.h"
#include "cell.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>



dish::dish(){


	for(int i = 0; i < 10; i++){

		for(int j = 0; j < 20; j++){

			cell c;
			dishState[i][j] = c;
			
		}
	}


	currGeneration = 0;

	liveChar = 'o';
	deadChar = ' ';

}

dish::dish(int n){

	srand(n);

	for(int i = 0; i < 10; i++){

		for(int j = 0; j < 20; j++){

			int curr = rand() % 2;

			if(curr == 0){

				cell c(false);
				dishState[i][j] = c;

			}else{
				cell c(true);
				dishState[i][j] = c;
			}
			
		}
	}


	currGeneration = 0;

	liveChar = 'o';
	deadChar = ' ';

}

dish::~dish(){
	//destructor
}

void dish::printDish(){

	for(int i = 0; i < 10; i++){

		for(int j = 0; j < 20; j++){

			if(dishState[i][j].getCurrState()){
				cout << liveChar << " ";
			}else{
				cout << deadChar << " ";
			}
		}

		cout << endl;
	}
}




