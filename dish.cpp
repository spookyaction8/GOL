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


	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 40; j++){

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

	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 40; j++){

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

	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 40; j++){

			if(dishState[i][j].getCurrState()){
				cout << liveChar << " ";
			}else{
				cout << deadChar << " ";
			}
		}

		cout << endl;
	}
}

void dish::nextGeneration(){

	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 40; j++){

			int count = 0;

			/*
				Cell Rules:

				1. Fewer than 2 alive neighbors, cell dies

				2. 2 alive neighbors, cell survives

				3. 3 alive neighbors, cell either a) survives b) comes alive

				4. More than 3 alive neighbors, cell dies

			*/

			try{
				if(dishState[i-1][j].getCurrState())
					count++;
			}catch(...){}
			try{
				if(dishState[i+1][j].getCurrState())
					count++;
			}catch(...){}
			try{
				if(dishState[i][j-1].getCurrState())
					count++;
			}catch(...){}
			try{
				if(dishState[i][j+1].getCurrState())
					count++;
			}catch(...){}
			try{
				if(dishState[i+1][j+1].getCurrState())
					count++;
			}catch(...){}
			try{	
				if(dishState[i-1][j-1].getCurrState())
					count++;
			}catch(...){}
			try{
				if(dishState[i+1][j-1].getCurrState())
					count++;
			}catch(...){}
			try{
				if(dishState[i-1][j+1].getCurrState())
					count++;
			}catch(...){}

			if(count < 2){
				dishState[i][j].setNext(false);
			}else if(count == 2 && dishState[i][j].getCurrState()){
				dishState[i][j].setNext(true);
			}else if(count == 3){
				dishState[i][j].setNext(true);
			}else{
				dishState[i][j].setNext(false);
			}
		}

	}

}

void dish::advance(){

	nextGeneration();

	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 40; j++){

			dishState[i][j].next();
		}
	}
}

void dish::advance(int n){

	for(int i = 0; i < n; i++){
		advance();
	}
}
