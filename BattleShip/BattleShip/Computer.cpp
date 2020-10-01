//Sharvita Paithankar
#include <iostream>
using namespace std;
#include "Computer.h"
#include <stdlib.h>

Computer::Computer() {

}
void Computer :: getShipsInfo()  //generates random nums for ships to be placed
{

		int x = generateRandomNumbers();
		int y = generateRandomNumbers();


		//Submarine
		WaterVehicle sub(generateRandomOrient(), x,y, 3, 3);
		submarine = sub;
		setShips(sub, 3);

		x = generateRandomNumbers();
		y = generateRandomNumbers();

		//Cruiser
		WaterVehicle cru(generateRandomOrient(), x,y, 3, 4);
		cruiser = cru;
		setShips(cru, 4);

		x = generateRandomNumbers();
		y = generateRandomNumbers();

		//Destroyer
		WaterVehicle dest(generateRandomOrient(), x,y, 2, 5);
		destroyer = dest;
		setShips(dest, 5);

		x = generateRandomNumbers();
		y = generateRandomNumbers();

		//Carrier
		WaterVehicle carr(generateRandomOrient(), x,y, 5, 6);
		carrier = carr;
		setShips(carr, 6);

		x = generateRandomNumbers();
		y = generateRandomNumbers();
	
		//BattleShip
		WaterVehicle battle(generateRandomOrient(),x,y, 4, 7);
		battleship = battle;
		setShips(battle, 7);
		
	
	cout << "Computer has placed its ships" << endl << endl;


}
void Computer :: setShips(WaterVehicle& ship, int num)  //checks if ships are placed, if not then generates other random numbers
{
	if (!vec.setShipPosition(ship, num, ship.printShipName(num)))
	{
		makePlacable(ship,num);
	}
		
}
void Computer :: attackShips(Grid& user) //randomly attacks ships
{

	int shipNum = 0;
	int randomRow = rand() % (10); //randomly chooses a row 
	int randomCol = rand() % (10); //randomly chooses a column

	if (user.isHit(randomRow, randomCol)) {
		user.getVector()[randomRow][randomCol] = 1;
		cout << "Your ";
		int n = user.whichShip(randomRow, randomCol);
		hit(user, n);
	}
	else
	{
		user.getVector()[randomRow][randomCol] = 2;
	}
	user.printGrid();
}
int Computer :: generateRandomNumbers() {
	return rand() % 10 + 1;
	
}
char Computer :: generateRandomOrient() {

	int randomOrient = rand() % 2;
	char orient;

	if (randomOrient == 0)
	    orient = 'h';
	else
		orient = 'v';
	return orient;
}
void Computer :: makePlacable(WaterVehicle& ship, int shipNum) {
	ship.setX(generateRandomNumbers());
	ship.setY(generateRandomNumbers());
		if (!vec.setShipPosition(ship, shipNum, ship.printShipName(shipNum))) {
			makePlacable(ship, shipNum);
	}
}
//sets vector
void Computer::setVector(int x, int y, int hit)
{
	Grid vector = this->getGrid();
	vector.getVector()[x][y] = hit;
}
