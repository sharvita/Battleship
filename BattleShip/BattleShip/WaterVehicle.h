//Sharvita Paithankar
#ifndef WaterVehicle_h
#define WaterVehicle_h
#include <iostream>
using namespace std;

class WaterVehicle {

	protected:
		int x, y; //starting position
		char orientation;
		int hits = 0;
		int shipLength;
		int shipNumber;

	public:

		WaterVehicle::WaterVehicle();
		WaterVehicle(char, int, int, int, int);

		//setters
		void setOrientation(char);
		void setX(int);
		void setY(int);
		void setShipLength(int);

		//getters
		int getShipLength() const;
		int getX();
		int getY();
		char getOrientation() const;
		int getNum() const { return shipLength; }
		int getHits() { return hits; }


		//other functions
		void  increaseHits();
		bool isSunk();
		string printShipName(int);
		

};
#endif
