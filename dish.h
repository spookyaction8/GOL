//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Dish Header

#ifndef DISH_H
#define DISH_H

#include "cell.h"
#include <string>

using namespace std;

class dish{

	public:

		//constructors

		dish();
		dish(int);
		~dish();

		//functions

		void printDish();
		//prints representation of the dish to console

		void nextGeneration();

		void advance();
		//advances to the next stage
		void advance(int);

		void autoAdvance(int);
		//advances an integer number of stages

		//bool autoAdvance();

		void setLiveChar(char);
		void setDeadChar(char);

		//getters
		char getLiveChar();
		char getDeadChar();
		int getCurrGeneration();
		int getNumCells();

		//writes and loads state data to a file
		
		bool saveDishState(string);
		bool loadDishState(string);


	private:

		cell dishState[10][20];

		int numCells = 200;

		int currGeneration;

		char liveChar;
		char deadChar;


};

#endif DISH_H