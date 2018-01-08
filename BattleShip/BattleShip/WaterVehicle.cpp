//Sharvita Paithankar
#include <iostream>
using namespace std;
#include "WaterVehicle.h"


WaterVehicle :: WaterVehicle() {
  // intentionally left blank 
	hits = 0;
}

WaterVehicle::WaterVehicle(char orient, int _x, int _y, int _shipLength, int shipNum)
{
	x = _x;
	y = _y;
	orientation = orient;
	shipLength = _shipLength;
	shipNumber = shipNum;
	hits = 0;
}

void WaterVehicle::setOrientation(char input)
{
	if (input == 'H' || input == 'h')
		orientation = 'h';
	else if (input == 'V' || input == 'v')
		orientation = 'v';
	else
		orientation = 'h';
}

char WaterVehicle :: getOrientation() const
{
	return orientation;
}

void WaterVehicle::increaseHits()
{
	hits++;
}

bool WaterVehicle::isSunk()  //checks if ship is Sunk 
{
	if (hits == shipLength)
		return true;
	else
		return false;
}

int WaterVehicle :: getShipLength() const
{
	return shipLength;
}

string  WaterVehicle :: printShipName(int shipNum) //returns ship name, each ship is definied by a specific num in the vector 
{
	if (shipNum == 3)
		return "Submarine";
	if (shipNum == 4)
		return "Cruiser";
	if (shipNum == 5)
		return "Destroyer";
	if (shipNum == 6)
		return "Carrier";
	if (shipNum == 7)
		return "Battleship";
}

int WaterVehicle::getX() 
{
	return x;
}

int WaterVehicle::getY() 
{
	return y;
}

void WaterVehicle::setX(int _x) 
{
	x = _x;
}

void WaterVehicle::setY(int _y) 
{
	y = _y;
}