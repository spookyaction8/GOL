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
#include <unistd.h>

using namespace std;

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

	for(int i = 0; i < 40; i++){
		cout << "~";
	}

	cout << endl;
}

void dish::nextGeneration(){

	for(int i = 0; i < 10; i++){

		for(int j = 0; j < 20; j++){

			int count = 0;

			/*
				Cell Rules:

				1. Fewer than 2 alive neighbors, cell dies

				2. 2 alive neighbors, cell survives

				3. 3 alive neighbors, cell either a) survives b) comes alive

				4. More than 3 alive neighbors, cell dies

			*/

			/*try{
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
			}catch(...){} */

			if(dishState[i-1][j].getCurrState() && i != 0)
					count++;
			if(dishState[i+1][j].getCurrState() && i != 9)
					count++;
			if(dishState[i][j-1].getCurrState() && j != 0)
					count++;
			if(dishState[i][j+1].getCurrState() && j !=  19)
					count++;
			if(dishState[i+1][j+1].getCurrState() && (j != 19 && i != 9))
					count++;
			if(dishState[i-1][j-1].getCurrState() && (j != 0 && i != 0))
					count++;
			if(dishState[i+1][j-1].getCurrState() && (j != 0 && i != 9))
					count++;
			if(dishState[i-1][j+1].getCurrState() && (j != 19 && i != 0))
					count++;

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

	for(int i = 0; i < 10; i++){

		for(int j = 0; j < 20; j++){

			dishState[i][j].next();
		}
	}

	currGeneration++;
	cout << endl;
}

void dish::advance(int n){

	for(int i = 0; i < n; i++){
		advance();
	}
}

void dish::autoAdvance(int n){

	advance();
	printDish();
	sleep(n);
	autoAdvance(n);
}

void dish::setLiveChar(char a){
	liveChar = a;
}

void dish::setDeadChar(char a){
	deadChar = a;
}

char dish::getLiveChar(){
	return liveChar;
}

char dish::getDeadChar(){
	return deadChar;
}

int dish::getCurrGeneration(){
	return currGeneration;
}

int dish::getNumCells(){
	return numCells;
}

bool dish::saveDishState(string filename){

	string curr = "/Users/zacharyteutsch/Desktop/GOL/" + filename;
	ofstream outfile;

	outfile.open(curr);

	for(int i = 0; i < 10; i++){
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

bool dish::loadDishState(string filename){

	string curr = "/Users/zacharyteutsch/Desktop/GOL/" + filename;

	ifstream infile;

	infile.open(curr);

	if(infile.fail()){
		cout << "Failed to open save file.";
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



