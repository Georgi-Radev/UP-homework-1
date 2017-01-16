/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 7
 * @compiler VC
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

const double BIG_RADIUS = 6.0;
const double MEDIUM_RADIUS = 3.0;
const double SMALL_RADIUS = 1.0;

int main() {
	double x, y;
	double bigSquared = BIG_RADIUS*BIG_RADIUS;
	double mediumSquared = MEDIUM_RADIUS*MEDIUM_RADIUS;
	double smallSquared = SMALL_RADIUS*SMALL_RADIUS;
	
	//cout << "Enter x and y (delimited by space)\n";
	cin >> x >> y;

	if (x*x + y*y > bigSquared || abs(x*x + y*y - bigSquared) < EPS) {
		cout << "Neutral\n";
	}
	else { // Inside the big circle
		double smallCircleEquation = x*x + (abs(y) - MEDIUM_RADIUS)*(abs(y) - MEDIUM_RADIUS);

		if (smallCircleEquation > mediumSquared) {
			if (x < 0) { // the leftmost part of the figure
				cout << "Good\n";
			}
			else { // the rightmost part of the figure
				cout << "Evil\n";
			}
		}
		else if (abs(smallCircleEquation - smallSquared) < EPS || // on one of the inner curves
			(abs(smallCircleEquation - mediumSquared) < EPS && x*y >= 0)) { // x*y >= 0 (1 or 3 quadrant)
			cout << "Neutral\n";
		}
		else {
			bool isEvil = smallCircleEquation < smallSquared;
			isEvil = y > 0 ? isEvil : !isEvil;
			cout << (isEvil ? "Evil\n" : "Good\n");
		}
	}

	return 0;
}