/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 1
 * @compiler VC
 *
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 3000;

int main() {
	int number = 0;
	//cout << "Enter a number between 0 and 3000." << "\n";
	cin >> number;

	if (number > MAX_SIZE || number < 0) {
		cout << "Invalid number!\n";
		return 1;
	}

	switch (number / 1000) {
	case 3:
		cout << "MMM"; break;
	case 2:
		cout << "MM"; break;
	case 1:
		cout << "M"; break;
	}

	number %= 1000;
	switch (number / 100) {
	case 9:
		cout << "CM"; break;
	case 8:
		cout << "DCCC"; break;
	case 7:
		cout << "DCC"; break;
	case 6:
		cout << "DC"; break;
	case 5:
		cout << "D"; break;
	case 4:
		cout << "CD"; break;
	case 3:
		cout << "CCC"; break;
	case 2:
		cout << "CC"; break;
	case 1:
		cout << "C"; break;
	}

	number %= 100;
	switch (number / 10) {
	case 9:
		cout << "XC"; break;
	case 8:
		cout << "LXXX"; break;
	case 7:
		cout << "LXX"; break;
	case 6:
		cout << "LX"; break;
	case 5:
		cout << "L"; break;
	case 4:
		cout << "XL"; break;
	case 3:
		cout << "XXX"; break;
	case 2:
		cout << "XX"; break;
	case 1:
		cout << "X"; break;
	}

	switch (number % 10) {
	case 9:
		cout << "IX"; break;
	case 8:
		cout << "VIII"; break;
	case 7:
		cout << "VII"; break;
	case 6:
		cout << "VI"; break;
	case 5:
		cout << "V"; break;
	case 4:
		cout << "IV"; break;
	case 3:
		cout << "III"; break;
	case 2:
		cout << "II"; break;
	case 1:
		cout << "I"; break;
	}

	cout << "\n";

	return 0;
}
