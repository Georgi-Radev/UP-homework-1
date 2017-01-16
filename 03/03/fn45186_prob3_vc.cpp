/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 3
 * @compiler VC
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned number,
		digitsCount,
		digit1,
		mask;

	//cout << "Enter a number\n";
	cin >> number;

	digitsCount = ((unsigned)(log((double)number)/log(16.0)) + 1);
	mask = digit1 = number & (1 << 4) - 1;

	if (digitsCount > 1) {
		mask |= (digit1 << 4);
	}
	if (digitsCount > 2) {
		mask |= (digit1 << 8);
	}
	if (digitsCount > 3) {
		mask |= (digit1 << 12);
	}
	if (digitsCount > 4) {
		mask |= (digit1 << 16);
	}
	if (digitsCount > 5) {
		mask |= (digit1 << 20);
	}
	if (digitsCount > 6) {
		mask |= (digit1 << 24);
	}
	if (digitsCount == 8) {
		mask |= (digit1 << 28);
	}

	bool hasSameDigits = !(number ^ mask);

	cout << (hasSameDigits ? "Yes\n" : "No\n");

	return 0;
}
// I can make it much better with loops:(