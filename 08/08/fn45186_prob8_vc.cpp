/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 8
 * @compiler VC
 *
 */

#include <iostream>
using namespace std;

int main() {
	unsigned sum, originalSum,
		cnt50, cnt20, cnt10, cnt5, cnt2;

	//cout << "Enter the sum:\n";
	cin >> sum;

	originalSum = sum;

	cnt50 = sum / 50;
	sum %= 50;
	cnt20 = sum / 20;
	sum %= 20;
	cnt10 = sum / 10;
	sum %= 10;
	cnt5 = sum / 5;
	sum %= 5;
	cnt2 = sum / 2;
	sum %= 2;
	
	cout << originalSum << " = ";

	if (cnt50) {
		cout << cnt50 << "*50";
	}
	if (cnt20) {
		if (cnt50) {
			cout << " + ";
		}
		cout << cnt20 << "*20";
	}
	if (cnt10) {
		if (cnt50 || cnt20) {
			cout << " + ";
		}
		cout << cnt10 << "*10";
	}
	if (cnt5) {
		if (cnt50 || cnt20 || cnt10) {
			cout << " + ";
		}
		cout << cnt5 << "*5";
	}
	if (cnt2) {
		if (cnt50 || cnt20 || cnt10 || cnt5) {
			cout << " + ";
		}
		cout << cnt2 << "*2";
	}
	if (sum) {
		if (cnt50 || cnt20 || cnt10 || cnt5 || cnt2) {
			cout << " + ";
		}
		cout << "1*1";
	}
	if (!originalSum) { // == 0
		cout << "0";
	}
	cout << "\n";

	return 0;
}