//Sharvita Paithankar
#ifndef Player_h
#define Player_h
#include <iostream>
using namespace std;
#include "Grid.h"
#include "WaterVehicle.h"

class Player {

protected:
	Grid vec;
	WaterVehicle submarine;
	WaterVehicle cruiser;
	WaterVehicle destroyer;
	WaterVehicle carrier;
	WaterVehicle battleship;
	
public:
	
	Grid& getGrid();
	void hit(Grid& grid, int n);
	bool hasWon();

	virtual void getShipsInfo() = 0;//gets information for ships
	virtual void setShips(WaterVehicle&, int) = 0;//sets ships on grid for player
	virtual void attackShips(Grid&) = 0;//attacks ships
	void setVector(int x, int y, int hit);//sets vector at position x and y to 1(hit)

};
#endif