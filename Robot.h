// Robot.h
// contains the class definition for the Robot class.

// istream is overloaded to accept integer or decimal values (which are converted to int), any
// non-numeric data will be thrown out and corresponding values set to zero.

#ifndef ROBOT_H
#define ROBOT_H
#include "Location.h"
#include <iostream>
#include <string>
using namespace std;

const Location MOVE_NORTH = Location(0, 1);
const Location MOVE_SOUTH = Location(0, -1);
const Location MOVE_EAST = Location(1, 0);
const Location MOVE_WEST = Location(-1, 0);
const string NORTH = "N";
const string SOUTH = "S";
const string EAST = "E";
const string WEST = "W";
const string EMPTY_STRING = "";
const int MAX_DISTANCE = 13;
const int MAX_COORDINATES = 4;
const int BUFFER = 256;
const int SQUARED = 2;


class Robot 
{
	friend istream& operator>>(istream &sin, Robot &that);
	friend ostream& operator<<(ostream &sout, Robot const &that);

	public:
		Robot();
		Robot(int xRobot, int yRobot, int xTreasure, int yTreasure);
		Robot(Location &robot, Location &theTreasure);
		Robot(Robot &robot);
		~Robot() {}

		Location getLocation();
		Location getTreasureLocation();
		Location getPathToTreasure();
		int getDistToTreasure();

	protected:
		void setLocation(int x, int y);
		void setTreasure(int x, int y);
		void setMovements(string move);
		void findTreasure(string &directions);

	private:
		Location location;
		Location treasure;
		string moves;
		int paths;
};
int parseToken(string const &token);

#endif