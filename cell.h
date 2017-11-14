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
		void setNext(bool);
		void next();

	private:

		bool currentState;
		bool nextState;
	

};



#endif CELL_H