/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 4
 * @compiler VC
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	char figureX, kingX, figureType;
	int figureY, kingY;

	//cout << "Enter the type of the attacking figure: \n"
	//	<< "Q - Queen;\n"
	//	<< "R - Rook;\n"
	//	<< "B - Bishop.\n"
	//	<< "N - kNight;\n";
	cin >> figureType;

	//cout << "Enter the coordinates of the attacking figure (delimited by space)\n";
	cin >> figureX
		>> figureY;
	//cout << "Enter the coordinates of the king (delimited by space)\n";
	cin >> kingX
		>> kingY;

	figureX -= 96; // Convert ASCII codes to useful numbers:
	kingX -= 96; // a => 1, b => 2, ... , h => 8

	if (figureX <= 0 || figureX >= 9 || figureY <= 0 || figureY >= 9) {
		cout << "Invalid figure coordinates!";
		return 1;
	}

	if (kingX <= 0 || kingX >= 9 || kingY <= 0 || kingY >= 9) {
		cout << "Invalid king coordinates!";
		return 1;
	}

	switch (figureType) {
	case 'Q': // Queen
		if (figureX - figureY == kingX - kingY || // same "straight" diagonal
			figureX + figureY == kingX + kingY || // same "reverse" diagonal
			figureX == kingX || // same X coord
			figureY == kingY) { // same Y coord
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		break;
	case 'R': // Rook
		if (figureX == kingX || // same X coord
			figureY == kingY) { // same Y coord
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		break;
	case 'B': // Bishop
		if (figureX - figureY == kingX - kingY || // same "straight" diagonal
			figureX + figureY == kingX + kingY) { // same "reverse" diagonal
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		break;
	case 'N': // kNight
		if ((abs(figureX - kingX) == 1 && abs(figureY - kingY) == 2) || // (1)
			(abs(figureX - kingX) == 2 && abs(figureY - kingY) == 1)) { // (2)
			cout << "Yes\n";
		}
		// (1)   x   x   (1)
		// (2) x       x (2)
		//        |N|   
		// (2) x       x (2)
		// (1)   x   x   (1)
		else {
			cout << "No\n";
		}
		break;
	default:
		cout << "Invalid figure!\n";
		return 1;
	}

	return 0;
}