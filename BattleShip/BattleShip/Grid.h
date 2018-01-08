//Sharvita Paithankar
#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include "WaterVehicle.h"

class Grid
{
	private:
		vector<vector<int>> vec;

	public:

		Grid();

		//functions
		void printGrid();//prints grid
		int shootTorpedoRandomly(vector<vector<int>>&);//randomly shoots torperdos, returns ship num; used for computer 
        bool setShipPosition(WaterVehicle&, int, string);//sets ships and return true if it's set 
		bool isPlacable(WaterVehicle&, int, int, int);//checks if ship is placable
		bool isHit(int, int);
		int whichShip(int, int);
		void printUserHitsOnGrid(Grid&);
		vector<vector<int>>& getVector() { return vec; }
};
#endif