//Zachary Teutsch
//
//CSCI 1300
//Recitation: 209 - G. Byrandurga Gopinath
//Conway's Game of Life
//Cell Implementation

#include "cell.h"
#include <string>
#include <iostream>

using namespace std;

//constructs cell with default value of false (dead)
cell::cell(){

	currentState = false;

}

//paramter constructs
//takes bool parameter and initializes cell to that value
cell::cell(bool a){

	currentState = a;

}

cell::~cell(){
	//destructor
}

//returns the current state of the cell
bool cell::getCurrState(){

	return currentState;
}

//sets the current state of the cell
void cell::setCurrState(bool a){
	currentState = a;
}

//sets the next state of the cell
void cell::setNext(bool a){

	nextState = a;
}

//advances the cell to its next state
void cell::next(){
	currentState = nextState;
}
