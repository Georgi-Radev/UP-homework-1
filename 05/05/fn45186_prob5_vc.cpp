/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 5
 * @compiler VC
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

const float EPS = 1e-4;

const float LARGE_RADIUS = 8.0;
const float MEDIUM_RADIUS = 3.0;
const float SMALL_RADIUS = 1.0;

const int SMALL_SCORE = 10;
const int MEDIUM_SCORE = 20;
const int LARGE_SCORE = 60;

int main() {
	double x, y,
	  deltaX, deltaY;

	//cout << "Enter x and y (delimited by space)\n";
	cin >> x >> y;
	//cout << "Enter x and y of the new coordinate system's center (delimited by space)\n";
	cin >> deltaX >> deltaY;

	double distance = (x + deltaX)*(x + deltaX) + (y + deltaY)*(y + deltaY);

	if (distance > LARGE_RADIUS*LARGE_RADIUS ||
		abs(distance - LARGE_RADIUS*LARGE_RADIUS) < EPS ||
		abs(distance - MEDIUM_RADIUS*MEDIUM_RADIUS) < EPS ||
		abs(distance - SMALL_RADIUS*SMALL_RADIUS) < EPS) {
		cout << 0 << "\n";
	}
	else if (distance > MEDIUM_RADIUS*MEDIUM_RADIUS) {
		cout << SMALL_SCORE << "\n";
	}
	else if (distance > SMALL_RADIUS*SMALL_RADIUS) {
		cout << MEDIUM_SCORE << "\n";
	}
	else { // distance < SMALL_RADIUS*SMALL_RADIUS
		cout << LARGE_SCORE << "\n";
	}

	return 0;
}