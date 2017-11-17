//Zachary Teutsch
//
//CSCI 1300
//
//Conway's Game of Life
//Main

#include "dish.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

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

			cout << "Enter a psuedo-random seeding value: ";
			cin >> input;

			dish d(input);
			d.printDish();

			while(true){

				cout << endl << "Enter an integer over 0 to advance n generations, enter 0 to quit: ";
				cin >> input;
				

				if(input > 0){
					d.advance(input);
				}else{
					break;
				}
			}
			cout << endl;
			menu();

		}else{
			cout << endl << "Invalid menu choice selected. Returning to the main menu." << endl << endl;
			menu();
		}
	}else if(input == 2){

		cout << "Which example state would you like to load?" << endl;
		cout << "1) Fixed state examples." << endl;
		cout << "2) Sample small oscillators." << endl;
		cout << "3) Pentadecathlon oscillator." << endl;
		cout << "4) Pulsar oscillator." << endl;
		cout << "5) Lightweight spaceship." << endl;
		cout << "Enter the number of your choice: ";
		cin >> input;

		if(input == 1){

		}else if(input == 2){

		}else if(input == 3){
			
		}else if(input == 4){
			
		}else if(input == 5){
			
		}else{

		}

	}else if(input == 3){

		string filename;
		cout << "Enter the name of the file you would like to load: ";
		cin >> filename;

		filename = "Saves/" + filename;

		dish d(3);
		d.loadDishState(filename);

		cout << "1) Auto-advance or 2) controlled progression?" << endl;
		cout << "Enter the number of your choice: ";
		cin >> input;

		if(input == 1){

			d.printDish();
			sleep(2);
			d.autoAdvance(2);

		}else if(input == 2){


			d.printDish();

			while(true){

				cout << endl << "Enter an integer over 0 to advance n generations, enter 0 to quit: ";
				cin >> input;
				

				if(input > 0){
					d.advance(input);
				}else{
					break;
				}
			}
			cout << endl;
			menu();

		}else{
			cout << endl << "Invalid menu choice selected. Returning to the main menu." << endl << endl;
			menu();
		}


	}else{
		cout << endl << "Invalid menu choice selected. Returning to the main menu." << endl << endl;
		menu();
	}

}
int main(void){

	
	


	menu();


	cout << endl;


}