//Sharvita Paithankar
#include "Player.h"
#include "Grid.h"
#include <iostream>
using namespace std;


Grid& Player::getGrid() { //returns grid by refrence(I figured that not 
	//returning by refrence was making it lose my data after banging my head against the wlls for 3 whole days )
	return vec;
}

void Player :: hit(Grid& grid, int n)  //checks which ship has been hit and writes the name of that ship
{
	if (n == 3) {
		cout << "submarine" << endl;
		submarine.increaseHits();
	}
	else if (n == 4) {
		cout << "cruiser ";
		cruiser.increaseHits();
	}
	else if (n == 5) {
		cout << "destroyer ";
		destroyer.increaseHits();
	}
	else if (n == 6) {
		cout << "carrier ";
		carrier.increaseHits();
	}
	else if (n == 7) {
		cout << "battleship ";
		battleship.increaseHits();
	}
	else {
		cout << "One of your ships ";
	}
	cout << "has been hit." << endl;

}

bool Player:: hasWon() { //is supposed to check if the player won the game

	if (submarine.getHits() == submarine.getShipLength() && cruiser.getHits() == cruiser.getShipLength() && 
		destroyer.getHits() == destroyer.getShipLength() && carrier.getHits() == carrier.getShipLength() && 
		battleship.getHits() == battleship.getShipLength()) {
		return true; 
	}
	else
	{
		return false;
	}
	
}
void Player::setVector(int x, int y, int hit) //sets vector position to 1 if its a miss
{
	Grid vector = this->getGrid();
	vector.getVector()[x][y] = hit;
}