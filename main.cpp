//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Main

#include "dish.h"
#include <iostream>

using namespace std;

int main(void){

	int n;

	cin >> n;

	dish d1(n);

	d1.autoAdvance(2);


	cout << endl;


}