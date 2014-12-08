// Locations.h
// contains the class definitions for the Locations class

#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
using namespace std;

const int NAUGHT = 0;

class Location
{
	friend ostream& operator<<(ostream &sout, Location const &loc);

	public:
		Location();
		Location(int x, int y);
		Location(Location const &location);
		~Location() {}

		int getX() const;
		int getY() const;
		void setX(int x);
		void setY(int y);

		bool operator==(Location const &that) const;
		bool operator!=(Location const &that) const;
		Location operator+(Location const &that) const;
		Location operator-(Location const &that) const;
		Location operator+=(Location const &that);
		Location operator-=(Location const &that);

	private:
		int xPos;
		int yPos;
};

#endif