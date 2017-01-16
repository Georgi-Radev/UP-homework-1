/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 10
 * @compiler VC
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

int main() {
	double a1, b1, c1,
		  a2, b2, c2;
	
	// | a1*x + b1*y = c1
	// | a2*x + b2*y = c2

	// / a1 b1 | c1\
	// \ a2 b2 | c2/

	// cout << "Enter equation #1:\n a1 b1 c1\n";
	cin >> a1 >> b1 >> c1;
	// cout << "Enter equation #2:\n a2 b2 c2\n";
	cin >> a2 >> b2 >> c2;

	double determinant = a1*b2 - b1*a2;

	if (abs(determinant) > EPS) { // one solution
		cout << (c1*b2 - b1*c2) / determinant << " " // Kramer's formulas
			 << (a1*c2 - c1*a2) / determinant << "\n";
		// cout << cout.precision(6) << x << " " << cout.precision(6) << y << "\n";
	}
	else {
		if (abs(a1 * c2 - c1 * a2) < EPS) { // (a1, b1, c1) == k*(a2, b2, c2)
			cout << "Many solutions" << "\n";
		}
		else { // (a1, b1, c1) != k*(a2, b2, c2)
			cout << "No solution" << "\n";
		}
	}

	return 0;
}