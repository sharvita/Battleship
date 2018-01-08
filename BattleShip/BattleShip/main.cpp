//Sharvita Paithankar 

#include <iostream>
using namespace std;
#include "Grid.h"
#include "WaterVehicle.h"
#include "User.h"
#include "Computer.h"
#include <time.h>

int main()
{

	Grid example;
	cout << "Hi! Let's play Battleship!" << endl;
	cout << "If you want to quit the game, click 1 . If you want to continute playing, click 2" << endl << endl;
	cout << "Instructions: " << endl;
	cout << "The board looks something like this: " << endl;
	example.printGrid();
	
    srand(time(NULL));
	int input = 1;

	User use;
	Computer compute;
	cout << "Enter a file name to place your ships and begin playing." << endl;
	use.getShipsInfo();
	cout << endl;
	cout << "The following is what your grid looks like : " << endl;
	use.getGrid().printGrid(); //prints user grid
	cout << "Computer's grid: " << endl;

	cout << endl;
		compute.getShipsInfo(); //computer generates random numbers 
		cout << endl;
		Grid computerGrid = compute.getGrid();
		Grid userGrid = use.getGrid();

	do {
	   
		cout << "It's your turn to shoot torperdo! " << endl;
		use.attackShips(compute.getGrid());

	    compute.getGrid().printUserHitsOnGrid(compute.getGrid());
		
		//computer shoots
		cout << "Computer has shot it's torpedo " << endl;
		compute.attackShips(use.getGrid());
		compute.getGrid().printGrid();
		if (compute.hasWon()) {
			cout << "The computer has won the game" << endl;
			input = 2;
		}
		else 
			if (use.hasWon()) {
			cout << "You won the game! Good job! " << endl;
			input = 2;
		}

		cout << "Do you wish to continue? Enter 1 for yes, Enter 2 for no" << endl;
		cin.ignore();//1000,'/n');
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cout << "Please enter a number!\n(1 for yes, 2 for no)";
		}
		else if (input != 1 && input != 2) {
			cout << "Input a valid number, Please." << endl;
		}
		else if (input == 2) {
			cout << "Byeeeee! " << endl;
		}

	} while (input == 1);
	system("pause");
	return 0;
	system("pause");
}
