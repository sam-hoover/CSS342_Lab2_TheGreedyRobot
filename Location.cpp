// Location.cpp
// contains the class declarations for the Location class

#ifndef LOCATION_CPP
#define LOCATION_CPP
#include "Location.h"
#include <iostream>
using namespace std;

Location::Location() 
{
	 setX(NAUGHT);
	 setY(NAUGHT);
}

Location::Location(int x, int y) 
{
	setX(x);
	setY(y);
}

Location::Location(Location const &location) 
{
	setX(location.getX());
	setY(location.getY());
}

int Location::getX() const
{
	return(xPos);
}

int Location::getY() const
{
	return(yPos);
}

void Location::setX(int x) 
{
	xPos = x;
}

void Location::setY(int y) 
{
	yPos = y;
}

bool Location::operator==(Location const &that) const 
{
	if(xPos == that.xPos && yPos == that.yPos) 
	{
		return(true);
	}
	return(false);
}

bool Location::operator!=(Location const &that) const 
{
	if(!(*this == that)) 
	{
		return(true);
	}
	return(false);
}

Location Location::operator+(Location const &that) const 
{
	Location temp = *this;
	temp.xPos += that.xPos;
	temp.yPos += that.yPos;
	return(temp);
}

Location Location::operator-(Location const &that) const 
{
	Location temp = *this;
	temp.xPos -= that.xPos;
	temp.yPos -= that.yPos;
	return(temp);
}

Location Location::operator+=(Location const &that) 
{
	*this = *this + that;
	return(*this);
}

Location Location::operator-=(Location const &that) 
{
	*this = *this - that;
	return(*this);
}

ostream &operator<<(ostream &sout, const Location &loc) 
{
	sout << loc.getX() << " " << loc.getY();
	return(sout);
}

#endif