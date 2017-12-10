//Zachary Teutsch
//
//CSCI 1300
//Recitation: 209 - G. Byrandurga Gopinath
//Conway's Game of Life
//Dish Implementation

#include "dish.h"
#include "cell.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

//base constructor for dish objcect
//iniatilizes a 20 by 20 2d array with cell objects
//sets those to default false
//iniatilizes members
dish::dish(){


	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 20; j++){

			cell c;
			dishState[i][j] = c;		
		}
	}

	currGeneration = 0;

	liveChar = 'o';
	deadChar = ' ';

}

//constructor for randomized start
//seeds pseudo random number generator
//sets true and false values of the cells accordingly
dish::dish(int n){

	srand(n);
	int count = 0;
	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 20; j++){

			int curr = rand() % 2;

			if(curr == 0){

				cell c(false);
				dishState[i][j] = c;

			}else{
				cell c(true);
				count++;
				dishState[i][j] = c;
			}		
		}
	}
	currGeneration = 0;
	liveCells = count;

	liveChar = 'o';
	deadChar = ' ';

}

dish::~dish(){
	//destructor
}

//prints a visual representation of the dish to the console
void dish::printDish(){

	cout << "Generation " << currGeneration << " - " << liveCells << " live cells" << endl;
	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 20; j++){

			if(dishState[i][j].getCurrState()){
				cout << liveChar << " ";
			}else{
				cout << deadChar << " ";
			}
		}

		cout << endl;
	}

	for(int i = 0; i < 40; i++){
		cout << "~";
	}

	cout << endl;

	
}

//determines next generation values for cells in dish
//uses Conway's algorithm to determine death, survival, or reproduction
//sets values of each cell for their NextState
void dish::nextGeneration(){

	int count1 = 0;

	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 20; j++){

			int count = 0;

			/*
				Cell Rules:

				1. Fewer than 2 alive neighbors, cell dies

				2. 2 alive neighbors, cell survives

				3. 3 alive neighbors, cell either a) survives b) comes alive

				4. More than 3 alive neighbors, cell dies

			*/

			if(dishState[i-1][j].getCurrState() && i != 0)
					count++;
			if(dishState[i+1][j].getCurrState() && i != 19)
					count++;
			if(dishState[i][j-1].getCurrState() && j != 0)
					count++;
			if(dishState[i][j+1].getCurrState() && j !=  19)
					count++;
			if(dishState[i+1][j+1].getCurrState() && (j != 19 && i != 19))
					count++;
			if(dishState[i-1][j-1].getCurrState() && (j != 0 && i != 0))
					count++;
			if(dishState[i+1][j-1].getCurrState() && (j != 0 && i != 19))
					count++;
			if(dishState[i-1][j+1].getCurrState() && (j != 19 && i != 0))
					count++;

			if(count < 2){
				dishState[i][j].setNext(false);
			}else if(count == 2 && dishState[i][j].getCurrState()){
				dishState[i][j].setNext(true);
				count1++;
			}else if(count == 3){
				dishState[i][j].setNext(true);
				count1++;
			}else{
				dishState[i][j].setNext(false);
			}
		}

	}

	liveCells = count1;

}

//switches all cells in dish from currentState to their next state
//increments the generation value
void dish::advance(){

	nextGeneration();

	for(int i = 0; i < 20; i++){

		for(int j = 0; j < 20; j++){

			dishState[i][j].next();
		}
	}

	currGeneration++;
	
}

//calls the parameter free advance function n amount of times
//calls to printDish() after each call to advance();
void dish::advance(int n){

	for(int i = 0; i < n; i++){
		advance();
	}

	printDish();

}

//automatically advances the dish on a time interval
//advances the dish and prints
//calls sleep for n seconds, pausing execution
//calls to autoAdvance for recursive loop
void dish::autoAdvance(int n){
	
		advance();
		printDish();
		sleep(n);
		autoAdvance(n);
			
}

//sets the live representaiton character for the dish
void dish::setLiveChar(char a){
	liveChar = a;
}

//sets the dead representaiton character for the dish
void dish::setDeadChar(char a){
	deadChar = a;
}

//returns the live representaiton character for the dish
char dish::getLiveChar(){
	return liveChar;
}

//returns the dead representaiton character for the dish
char dish::getDeadChar(){
	return deadChar;
}

//returns the current generation
int dish::getCurrGeneration(){
	return currGeneration;
}

//returns the number of cells
int dish::getNumCells(){
	return numCells;
}

//takes a filename input and saves the current dish to that file
//formats with 'f' for a dead cell and 't' for live cell
bool dish::saveDishState(string filename){

	string curr = "/Users/zacharyteutsch/Desktop/GOL/Saves/" + filename;
	ofstream outfile;

	outfile.open(curr);

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){

			if(dishState[i][j].getCurrState()){
				outfile << "t";
			}else{
				outfile << "f";
			}			
		}

		outfile << endl;
	}

	outfile.close();
	return true;

}

//loads a saved dish state into the simulator
//parses t/f format with getline and string[]
//sets dish values based on parsed data
//returns false if file was properly accessed
bool dish::loadDishState(string filename){

	string curr = "/Users/zacharyteutsch/Desktop/GOL/" + filename;

	ifstream infile;

	infile.open(curr);

	if(infile.fail()){
		cout << "Failed to open save file." << endl;
		return false;
	}

	string line;
	int index = 0;

	while(getline(infile, line)){

		for(int i = 0; i < 20; i++){

			if(line[i] == 't')
				dishState[index][i].setCurrState(true);
			else
				dishState[index][i].setCurrState(false);
		}

		index++;
	}
}
