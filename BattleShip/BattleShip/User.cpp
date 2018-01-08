//Sharvita Paithankar
#include <iostream>
using namespace std;
#include "User.h"
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>

User::User() {
	
}

//get information from the user 
void User::getShipsInfo() {

	string fileName;
	ifstream infile;
	string ship, position, orient;
	int row, column;
	char charOrient;
	getline(cin, fileName);
	infile.open(fileName);

	if (!infile)
	{
		cout << "File not found. Try entering again: " << endl;
		getShipsInfo();
	}
	else
	{	//Reads unnecessary headers
		getline(infile, ship, ',');
		getline(infile, ship, ',');
		getline(infile, ship);
        cout << endl << endl;
		while (!infile.eof()) {
			
			getline(infile, ship, ',');
			getline(infile, position, ',');
			getline(infile, orient);

			for (int i = 0; i < ship.length(); i++)
			{
				ship[i] = tolower(ship[i]);
			}
			
			if (ship == "submarine")
			{
				getShipInfoHelper(infile, position, orient, charOrient, row, column); //calls this to get information from file
				WaterVehicle sub(charOrient, row, column+1, 3, 3);
				submarine = sub;
				setShips(sub, 3);

			}
			if (ship == "cruiser")
			{
				getShipInfoHelper(infile, position, orient, charOrient, row, column);
				WaterVehicle cruis(charOrient, row, column+1, 3, 4);
				cruiser = cruis;
				setShips(cruis, 4);
			}
			if (ship == "destroyer")
			{
				getShipInfoHelper(infile, position, orient, charOrient, row, column);
				WaterVehicle dest(charOrient, row, column+1, 2, 5);
				destroyer = dest;
				setShips(dest, 5);
			}
			if (ship == "carrier")
			{
				getShipInfoHelper(infile, position, orient, charOrient, row, column);
				WaterVehicle carr(charOrient, row, column+1, 5, 6);
				carrier = carr;
				setShips(carr, 6);
			}
			if (ship == "battleship")
			{
				getShipInfoHelper(infile, position, orient, charOrient, row, column);
				WaterVehicle battle(charOrient, row, column+1, 4, 7);
				battleship = battle;
				setShips(battle, 7);
			}

		}

	}
}

//This sets the ship
void User :: setShips(WaterVehicle& ship, int shipNum) {

	if (vec.setShipPosition(ship, shipNum, ship.printShipName(shipNum))) { //checks if it's placable on grid
		
		cout << ship.printShipName(shipNum) << " has been placed on the grid" << endl;
	}
	else {
		cout << ship.printShipName(shipNum) << " cannot be placed" << endl;
	}
}
void User :: attackShips(Grid& computer) { //allows user to attack 

	
	bool isValid = true; //checks if inputs are valid
	char col;
	    int row, column;

			cout << "Enter the letter of the column you want to shoot:  " << endl;
			cin >> col;

			cout << "Enter the number of the row that you want to shoot:  " << endl;
			cin >> row;
			
			column = changeCharToInt(col);
			try {
				while (row < 1 && row > 11) {
					isValid = false;
					cout << "Row is invalid. It is not a number between 1-10 " << endl;
					cin >> row;


				}
				while (column == 11) {
					isValid = false;
					cout << "Column is invalid. It's not a letter between A-J." << endl;
					cin >> col;
					break;

				}
				if (cin.fail())
				{
					isValid = false;
					cin.clear();
					cout << "Please enter valid inputs\n";
				}


				if (isValid) {
					cout << endl << endl;
					cout << "_________________________________" << endl << endl;
					cout << "An O will be printed if you miss" << endl;
					cout << "A X will be printed if you hit " << endl;
					cout << "_________________________________" << endl;


					if (computer.isHit(row - 1, column - 1)) {//checks if ship is hit
					    computer.getVector()[row-1][col-1] = 1;
						cout << "Computer's ";
						int n = computer.whichShip(row - 1, column - 1);
						hit(computer, n);
					}
				}
			}
			catch (const out_of_range& e) {
				cout << "cannot shoot at that spot" << endl;
			}
}
void User :: getShipInfoHelper(ifstream& infile,string& position, string& orient, char& charOrient, int& row, int& column) {//this breaks down the position and direction that has been taken from file using string stream and allows to make objects
	
	stringstream ss;
	char letter = 'A';
	ss << position;
	ss >> letter;
	ss >> row;
	ss.clear();
	ss << position;
	column = letter - 'A';

	if (orient.size() != 0)
		charOrient = orient[0];
}

int User :: changeCharToInt(char letter) { //changes the columns from letters to numbers 

	if (letter == 'A' || letter == 'a') 
		return 1;
	if (letter == 'B' || letter == 'b')
		return 2;
	if (letter == 'C' || letter == 'c')
		return 3;
	if (letter == 'D' || letter == 'd')
		return 4;
	if (letter == 'E' || letter == 'e')
		return 5;
	if (letter == 'F' || letter == 'f')
		return 6;
	if (letter == 'G' || letter == 'g')
		return 7;
	if (letter == 'H' || letter == 'h')
		return 8;
	if (letter == 'I' || letter == 'i')
		return 9;
	if (letter == 'J' || letter == 'j')
		return 10;
	else
		return 11;
}

