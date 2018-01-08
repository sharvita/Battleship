//Sharvita Paithankar
#ifndef Computer_h
#define Computer_h
#include <iostream>
using namespace std;
#include "Grid.h"
#include "Player.h"
#pragma once

class Computer : public Player {

	public:
		Computer();
		void getShipsInfo();
		void setShips(WaterVehicle&,int);
		void attackShips(Grid&);
		int generateRandomNumbers();
		char generateRandomOrient();
		void makePlacable(WaterVehicle&,int);
		void setVector(int x, int y, int hit);
};
#endif
