/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 2
 * @compiler VC
 *
 */

#include <iostream>
using namespace std;

int main() {
	enum Month {
		InvalidLow,
		Jan,
		Feb,
		March,
		April,
		May,
		June,
		July,
		Aug,
		Sep,
		Oct,
		Nov,
		Dec,
		InvalidHigh
	};
	unsigned long long pin, originalPin, sum;
	unsigned day,
		month,
		year;
	bool isFemale;
	// cout << "Enter a PIN number." << "\n";
	cin >> pin;
	originalPin = pin;

	year = pin / 100000000; // 1e8
	pin %= 100000000;
	month = pin / 1000000; // 1e6
	pin %= 1000000;
	day = pin / 10000; // 1e4
	pin %= 100;
	isFemale = (pin / 10) % 2; // Check if digit #9 is odd.
									// Even (0) == male
									// Odd (1) == female

	if (month >= InvalidLow && month <= InvalidHigh) { // Born in: 20-th century
		year += 1900;
	}
	else if (month >= 21 && month <= 32) { // 19-th century
		year += 1800;
		month -= 20;
	}
	else if (month >= 41 && month <= 52) { // 21-st century
		year += 2000;
		month -= 40;
	}

	if (year <= 100 || day >= 32 || day == 0) { // invalid month => no increment for the year
		cout << "Bad input data!\n";
	}
	else if (day == 31 && month == April || month == June || month == Sep || month == Nov) { // months with 30 days
		cout << "Bad input data!\n";
	}
	else if (Feb == month && // Leap year in this range (special cases: 1800, 1900 - no-leap, 2000 - leap)
		(day == 29 && // De Morgan's law: !(A || B && C) == !A && !B || !C
			year % 4 &&
			year % 100
			|| year % 400)) {
		cout << "Bad input data!\n";
	}
	else { // Valid date
		if (day <= 9) {
			cout << "0";
		}
		cout << day << "."
			<< (month <= 9 ? "0" : "")
			<< month << "."
			<< year << " "
			<< (isFemale ? "F" : "M") << "\n";
	}

	return 0;
}
