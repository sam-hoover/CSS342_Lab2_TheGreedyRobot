// RobotDriver.cpp
// This file contains main for the Greedy Robot Program

#include "Robot.h"
#include "Location.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
	Robot bot;

	cout << "Welcome to the Greedy Robot Program! \tby Sam Hoover" << endl << endl;
	cout << "Coordinates should be in the format: x1 y1 x2 y2" << endl;
	cout << "Enter coordinates: ";
	cin >> bot;
	cout << bot;

	cout << endl << "any key to exit." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return(0);
}