//Zachary Teutsch
//
//CSCI 1300
//Recitation: 209 - G. Byrandurga Gopinath
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

		//prints representation of the dish to console
		void printDish();
		
		//determines next generation
		void nextGeneration();

		//advances the dish 1 stage or int amount of stages
		void advance();
		void advance(int);

		//advances an integer number of stages
		void autoAdvance(int);
		
		//setters
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

		//array that stores cells
		cell dishState[20][20];

		//cell count data members
		int numCells = 400;
		int liveCells = 0;

		//generation
		int currGeneration;

		//characters for cell representation
		char liveChar;
		char deadChar;


};

#endif DISH_H