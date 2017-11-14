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

void cell::setNext(bool a){

	nextState = a;
}

void cell::next(){
	currentState = nextState;
}
