//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Cell Header

#ifndef CELL_H
#define CELL_H

using namespace std;

class cell{

	public:
		
		//constructors
		cell();
		cell(bool);
		~cell();

		//functions

		//currState set and getters
		bool getCurrState();
		void next();

		bool nextGeneration();
		//determines the state of cell in next stage

		void setLocation(int, int);


	private:

		bool currentState;
		bool nextState;
		int xpos = -1;
		int ypos = -1;


};



#endif CELL_H

/*
	Cell Rules:

	1. Fewer than 2 alive neighbors, cell dies

	2. 2 alive neighbors, cell survives

	3. 3 alive neighbors, cell either a) survives b) comes alive

	4. More than 3 alive neighbors, cell dies

*/