/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Georgi Radev
 * @idnumber 45186
 * @task 6
 * @compiler VC
 *
 */

#include <iostream>
using namespace std;

int main() {
	int left1, bottom1, left2, bottom2;
	unsigned width1, height1, width2, height2;
	int right1, top1, right2, top2;
	unsigned area;

	//cout << "Enter first rectangle's coords:\n left bottom height width\n";

	cin >> left1 >> bottom1 >> height1 >> width1;
	//cout << "Enter second rectangle's coords:\n left bottom height width\n";
	cin >> left2 >> bottom2 >> height2 >> width2;

	if (width1 * height1 * width2 * height2 == 0) { // one of them is == 0
		area = 0;
	}

	right1 = left1 + width1;
	top1 = bottom1 + height1;
	right2 = left2 + width2;
	top2 = bottom2 + height2;

	if (right1 <= left2 || right2 <= left1 ||
		top1 <= bottom2 || top2 <= bottom1) {
		area = 0;
	}
	else if (left1 < left2 && bottom1 < bottom2) {
		if (right1 < right2) {
			area = top1 < top2 ?
				(right1 - left2) * (top1 - bottom2):
				(right1 - left2) * height2;
		}
		else { // right1 >= right2
			area = top1 < top2 ?
				width2 * (top1 - bottom2) :
				width2 * height2;
		}
	}
	else if (left1 < left2 && bottom1 > bottom2) {
		if (right1 < right2) {
			area = top1 < top2 ?
				(right1 - left2) * height1 :
				(right1 - left2) * (top2 - bottom1);
		}
		else { // right1 >= right2
			area = top1 < top2 ?
				width2 * height1 :
				width2 * (top2 - bottom1);
		}
	}
	else if (left1 > left2 && bottom1 < bottom2) {
		if (right1 < right2) {
			area = top1 < top2 ?
				width1 * (top1 - bottom2) :
				width1 * height2;
		}
		else { // right1 >= right2
			area = top1 < top2 ?
				(right2 - left1) * (top1 - bottom2) :
				(right2 - left1) * height2;
		}
	}
	else { // left1 > left2 && bottom1 > bottom2
		if (right1 < right2) {
			area = top1 < top2 ?
				width1 * height1 :
				width1 * (top2 - bottom1);
		}
		else { // right1 >= right2
			area = top1 < top2 ?
				(right2 - left1) * height1 :
				(right2 - left1) * (top2 - bottom1);
		}
	}

	cout << area << "\n";

	return 0;
}