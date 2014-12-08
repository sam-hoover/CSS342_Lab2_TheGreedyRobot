// Robot.cpp
// contains the class declarations for the Robot class.

#ifndef ROBOT_CPP
#define ROBOT_CPP
#include "Robot.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

Robot::Robot() 
{
	paths = NAUGHT;
	moves = EMPTY_STRING;
	setLocation(NAUGHT, NAUGHT);
	setTreasure(NAUGHT, NAUGHT);
}

Robot::Robot(int xRobot, int yRobot, int xTreasure, int yTreasure) 
{
	paths = NAUGHT;
	moves = EMPTY_STRING;
	setLocation(xRobot, yRobot);
	setTreasure(xTreasure, yTreasure);
	if(getDistToTreasure() < MAX_DISTANCE) 
	{
		string directions = EMPTY_STRING;
		findTreasure(directions);
	}
	else 
	{
		paths = -1;
		moves = "Distance to treasure too far.\n";
	}
}

Robot::Robot(Location &robot, Location &theTreasure) 
{
	paths = NAUGHT;
	moves = EMPTY_STRING;
	setLocation(robot.getX(), robot.getY());
	setTreasure(theTreasure.getX(), theTreasure.getY());
	if(getDistToTreasure() < MAX_DISTANCE)
	{
		string directions = EMPTY_STRING;
		findTreasure(directions);
	} 
	else 
	{
		paths = -1;
		moves = "Distance to treasure too far.\n";
	}
}

Robot::Robot(Robot &robot) 
{
	paths = robot.paths;
	moves = robot.moves;
	setLocation(robot.location.getX(), robot.location.getY());
	setTreasure(robot.treasure.getX(), robot.treasure.getY());
}

Location Robot::getLocation() 
{
	return(location);
}

Location Robot::getTreasureLocation() 
{
	return(treasure);
}

Location Robot::getPathToTreasure() 
{
	return(treasure - location);
}

int Robot::getDistToTreasure() 
{
	Location route = getPathToTreasure();
	double horizDist = sqrt(pow(route.getX(), SQUARED) + pow(route.getY(), SQUARED));
	int distance = static_cast<int>(horizDist);
	return(distance);
}

void Robot::findTreasure(string &directions) 
{

	if(location == treasure) 
	{
		if(directions != EMPTY_STRING)
		{
			paths++;
			moves += directions + '\n';
		}
		return;
	} 
	else 
	{
		Location route = getPathToTreasure();
		
		if(route.getY() > NAUGHT) 
		{
			location += MOVE_NORTH;
			findTreasure(directions + NORTH);
			location -= MOVE_NORTH;
		} 
		else if(route.getY() < NAUGHT) 
		{
			location += MOVE_SOUTH;
			findTreasure(directions + SOUTH);
			location -= MOVE_SOUTH;
		} 
		
		if(route.getX() > NAUGHT) 
		{
			location += MOVE_EAST;
			findTreasure(directions + EAST);
			location -= MOVE_EAST;
		} 
		else if(route.getX() < NAUGHT) 
		{
			location += MOVE_WEST;
			findTreasure(directions + WEST);
			location -= MOVE_WEST;
		}	
	}
}

void Robot::setLocation(int x, int y) 
{
	location.setX(x);
	location.setY(y);
}

void Robot::setTreasure(int x, int y) 
{
	treasure.setX(x);
	treasure.setY(y);
}

ostream& operator<<(ostream &sout, Robot const &that) 
{
	sout << "Number of paths: " << that.paths << '\n' << that.moves;
	return(sout);
}

istream &operator>>(istream &sin, Robot &that) 
{
	string token;
	int i = 0;
	int coordinates[MAX_COORDINATES] = {0, 0, 0, 0};
	while(sin.peek() != '\n' && i <= MAX_COORDINATES) 
	{
		token = sin.get();
		char ch = sin.peek();
		while(ch != ' ' && ch != '\n') 
		{
			token += sin.get();
			ch = sin.peek();
		}

		try 
		{
			coordinates[i] = parseToken(token);
			i++;
		} 
		catch(const invalid_argument) 
		{
			i++;
		} 
		catch(const exception) 
		{
			i++;
		}
	}
	that = Robot(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
	return(sin);
}

int parseToken(string const &token) 
{
	int parsedToken = 0;
	char str[BUFFER];
	char* end;
	for(unsigned i = 0; i < token.length() + 1; i++) 
	{
		str[i] = token[i];
	}
	double num = strtod(str, &end);
	parsedToken = static_cast<int>(num);
	return(parsedToken);
}

#endif