//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Main

#include "dish.h"
#include <iostream>

using namespace std;
void menu(){

	int input;
	cout << "Welcome to Conway's Game of Life!" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1) Start with a psuedo-random state." << endl;
	cout << "2) Load an example state." << endl;
	cout << "3) Load a saved state." << endl;
	cout << "Enter a number here: ";
	cin >> input;

	if(input == 1){
		cout << "Would like to auto-advance through generations or enter generation values?" << endl;
		cout << "1) Auto-advance." << endl;
		cout << "2) Control pacing." << endl;
		cout << "Enter a number here: ";
		cin >> input;

		if(input == 1){

			cout << "Enter a psuedo-random seeding value: ";
			cin >> input;

			dish d(input);
			d.autoAdvance(2);

		}else if(input == 2){

		}else{
			cout << endl << "Invalid menu choice selected. Returning to the main menu." << endl << endl;
			menu();
		}
	}else if(input == 2){

	}else if(input == 3){

	}else{
		cout << endl << "Invalid menu choice selected. Returning to the main menu." << endl << endl;
		menu();
	}

}
int main(void){

	



	menu();


	cout << endl;


}