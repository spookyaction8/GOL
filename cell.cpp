//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Cell Implementation

#include "cell.h"
#include <string>
#include <iostream>

using namespace std;

cell::cell(){

	currentState = false;

}

cell::cell(bool a){

	currentState = a;

}

cell::~cell(){
	//destructor
}

bool cell::getCurrState(){

	return currentState;
}



/*
	Cell Rules:

	1. Fewer than 2 alive neighbors, cell dies

	2. 2 alive neighbors, cell survives

	3. 3 alive neighbors, cell either a) survives b) comes alive

	4. More than 3 alive neighbors, cell dies

*/