//Sharvita Paithankar
#include <iostream>
using namespace std;
#include "Grid.h"

const int GRID_MAX = 10;

Grid::Grid()
{
	vec.resize(GRID_MAX, vector < int >(GRID_MAX, 0));//creates grid with 0's in it
}

void Grid::printGrid() //prints grid
{
	cout << "--------------------------------------------" << endl;
	cout << "    A   B   C   D   E   F   G   H   I   J   |" << endl;
	for (int i = 0; i < GRID_MAX; i++) { //goes through rows
		if (i + 1 == 10)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << "   ";
		for (int j = 0; j < GRID_MAX; j++) { //goes through columns

			if (vec[i][j] == 0)
				cout << " " << "   "; //prints the number in this position
			if (vec[i][j] == 1)
				cout << "X " << "  ";
			if (vec[i][j] == 2)
				cout << "O " << "  ";
			if (vec[i][j] == 3)
				cout << "S " << "  ";
			if (vec[i][j] == 4)
				cout << "C " << "  ";
			if (vec[i][j] == 5)
				cout << "D " << "  ";
			if (vec[i][j] == 6)
				cout << "K " << "  ";
			if (vec[i][j] == 7)
				cout << "B " << "  ";

		}
		cout << "|" << endl;
	}
	cout << "--------------------------------------------" << endl;
}


bool Grid :: setShipPosition(WaterVehicle& ship, int shipNum, string name)//sees if ships are placable
{
	
	bool isPlaced = false;
	bool enter = false;
	int shipLength = ship.getShipLength();
	int x = ship.getX()-1;
	int y = ship.getY()-1;
	int endX = x + shipLength;//end of ship
	int endY = y + shipLength;
	

	if (endX <= 10 && endY <= 10)
	{
	
		if (ship.getOrientation() == 'h' || ship.getOrientation() == 'H')
		{
			
			if (isPlacable(ship, x, y, shipNum))
			{

				while (shipLength > 0)
				{
					vec[x][y] = shipNum;
					y++;
					shipLength--;
				}
				isPlaced = true;
				
			}

		}
		else if (ship.getOrientation() == 'v' || ship.getOrientation() == 'V')
		{
		
			if (isPlacable(ship, x, y, shipNum))
			{
		
				while (shipLength > 0)
				{
					vec[x][y] = shipNum; //places it with the ship number
					x++;
					shipLength--;
				}
				isPlaced = true;
			}
		}	
	}
	return isPlaced;
}

bool Grid :: isPlacable(WaterVehicle& object, int x, int y, int shipNum)
{

	bool canPlace = false; //checks if another ship is present

	
	if (object.getOrientation() == 'h' || object.getOrientation() == 'H')
	{

		for (int i = 0; i < object.getShipLength(); i++)
		{

			if (x >= 0 && x < 10 && y >= 0 && y < 10) {

				if (vec[x][y] != 0)
				{
					canPlace = false;
					return canPlace;
				}
				else {
					canPlace = true;
					y++;
				}
			}
		}
	}
	else if (object.getOrientation() == 'v' || object.getOrientation() == 'V')
	{
		for (int i = 0; i < object.getShipLength(); i++)
		{
			if (x >= 0 && x <= 9 && y >= 0 && y <= 9) {
				if (vec[x][y] != 0)
				{		
					canPlace = false;
					return canPlace;			
				}
				else 
				{
					canPlace = true;
					x++;
				}
			}
		}
	}
	return canPlace;
}

bool Grid :: isHit(int x, int y) {

	if (vec[x][y] != 0 && vec[x][y] != 1 && vec[x][y] != 2)
	{
		return true;
	}
	else
	{
		vec[x][y] = 2;// 2 is put in that position if its is a miss 
		return false;
	}
}

int Grid :: whichShip(int x, int y)//returns number of ship
{

	int shipNum = 0 ;

		shipNum = vec[x][y];
		vec[x][y] = 1;

	return shipNum;
}

void Grid :: printUserHitsOnGrid(Grid& computer) ///prints where the user has hit and missed
{
	vector<vector<int>> printVec = computer.getVector();
	cout << "--------------------------------------------" << endl;
	cout << "    A   B   C   D   E   F   G   H   I   J   |" << endl;
	for (int i = 0; i < GRID_MAX; i++) { //goes through rows
		if (i + 1 == 10)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << "   ";
		for (int j = 0; j < GRID_MAX; j++) { //goes through columns

			if (printVec[i][j] == 0)
				cout << " " << "   "; //prints the number in this position
			if (printVec[i][j] == 1)
				cout << "X " << "  ";
			if (printVec[i][j] == 2)
				cout << "O " << "  ";
			if (printVec[i][j] == 3)
				cout << "  " << "  ";
			if (printVec[i][j] == 4)
				cout << "  " << "  ";
			if (printVec[i][j] == 5)
				cout << "  " << "  ";
			if (printVec[i][j] == 6)
				cout << "  " << "  ";
			if (printVec[i][j] == 7)
				cout << "  " << "  ";

		}
		cout  << endl;
	}
	cout << "--------------------------------------------" << endl;
}
	
