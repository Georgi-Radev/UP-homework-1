/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 9
 * @compiler VC
 *
 */

#include <iostream>
using namespace std;

const int BASE = 16;

int main() {
	int left, right, result;
	char operation;

	cin >> left
		>> operation
		>> right;

	if (left < 0 || right < 0) {
		cout << "Invalid numbers!\n";
		return 1;
	}

	if (left >= BASE) {
		left %= BASE;
	}
	if (right >= BASE) {
		right %= BASE;
	}

	switch (operation) {
	case '+':
		result = left + right;
		if (result >= BASE) {
			result %= BASE;
		}
		cout << result << "\n";
		break;
	case '-':
		result = left - right;
		if (result < 0) {
			result += BASE;
		}
		cout << result << "\n";
		break;
	case '*':
		result = left * right;
		if (result >= BASE) {
			result %= BASE;
		}
		cout << result << "\n";
		break;
	case '/':
		if (right != 0) {
			result = left / right;
			cout << result << "\n";
		}
		else {
			cout << "Division by zero!\n";
			return 1;
		}
		break;
	case '%':
		if (right != 0) {
			result = left % right;
			cout << result << "\n";
		}
		else {
			cout << "Division by zero!\n";
			return 1;
		}
		break;
	default:
		cout << "invalid operation\n";
		return 1;
	}

	return 0;
}