//Zachary Teutsch
//
//CSCI 1300
//Recitation: 209 - G. Byrandurga Gopinath
//Conway's Game of Life
//Main

#include "dish.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

//menu function
//takes user input to navigate options for Game of Life
//1)Random state
//2)Example state
//3)Saved State
// Users have the option to auto-advance or to control generation advance
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
		cout << "2) Control pacing. (Includes save option)" << endl;
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

				cout << endl << "Enter a positive integer to advance n generations, 0 to save, or a negative int to quit: ";
				cin >> input;
				

				if(input > 0){
					d.advance(input);
				}else if(input == 0){
					string filename;
					cout << endl << "Please enter a filename to save as: ";
					cin >> filename;

					d.saveDishState(filename);

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
			dish d(0);
			d.loadDishState("Examples/fixed.txt");
			d.printDish();
			sleep(2);
			d.autoAdvance(2);

		}else if(input == 2){
			dish d(0);
			d.loadDishState("Examples/small.txt");
			d.printDish();
			sleep(2);
			d.autoAdvance(2);
		}else if(input == 3){
			dish d(0);
			d.loadDishState("Examples/pentadecathlon.txt");
			d.printDish();
			sleep(2);
			d.autoAdvance(2);
		}else if(input == 4){
			dish d(0);
			d.loadDishState("Examples/pulsar.txt");
			d.printDish();
			sleep(2);
			d.autoAdvance(2);
		}else if(input == 5){
			dish d(0);
			d.loadDishState("Examples/lwss.txt");
			d.printDish();
			sleep(2);
			d.autoAdvance(2);
		}else{
			cout << endl << "Invalid menu choice selected. Returning to the main menu." << endl << endl;
			menu();
		}

	}else if(input == 3){

		string filename;
		cout << "Enter the name of the file you would like to load: ";
		cin >> filename;

		filename = "Saves/" + filename;

		dish d(0);
		d.loadDishState(filename);

		cout << "1) Auto-advance or 2) controlled progression (Includes save option)?" << endl;
		cout << "Enter the number of your choice: ";
		cin >> input;

		if(input == 1){

			d.printDish();
			sleep(2);
			d.autoAdvance(2);

		}else if(input == 2){


			d.printDish();

			while(true){

				cout << endl << "Enter a positive integer to advance n generations, 0 to save, or a negative int to quit: ";
				cin >> input;
				

				if(input > 0){
					d.advance(input);
				}else if(input == 0){
					string filename;
					cout << endl << "Please enter a filename to save as: ";
					cin >> filename;

					d.saveDishState(filename);

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


}