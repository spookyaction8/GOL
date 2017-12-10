//Zachary Teutsch
//
//CSCI 1300
//Recitation: 209 - G. Byrandurga Gopinath
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
		void setCurrState(bool);

		//next state related functions
		void setNext(bool);
		void next();

	private:

		//state data members
		bool currentState;
		bool nextState;
	
};



#endif CELL_H