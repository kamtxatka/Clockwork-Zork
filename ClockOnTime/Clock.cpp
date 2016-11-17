#include <iostream>
#include <vector>
#include "Clock.h"


Clock::Clock(const char * name, const char * description, Room * room, Exit * linkedExit, 
	Room * linkR1, Room * linkR2, Room * linkR3, Room * linkR4, CardinalHour hour) :
	Entity(name, description, (Entity*)room), linkedExit (linkedExit), linkR1(linkR1),
	linkR2(linkR2), linkR3(linkR3), linkR4(linkR4), cardinalHour(hour)
{
	entityType = CLOCK;
}

Clock::~Clock()
{
}

void Clock::Look() const
{
	int hour = 0;
	if (cardinalHour == NORTH)
		hour = 12;
	if (cardinalHour == WEST)
		hour = 9;
	if (cardinalHour == SOUTH)
		hour = 6;
	if (cardinalHour == EAST)
		hour = 3;

	cout << "\n The clock marks " << hour << " o'clock \n";
}

void Clock::ChangeHour(CardinalHour hour)
{
	Exit* exit = (Exit*)parent->Find(EXIT);

	if (hour == NORTH) {
		exit->ChangeDirection("north", "south", NULL);
		linkedExit->ChangeDirection("north", "south", linkR1);
	}
	if (hour == WEST) {
		exit->ChangeDirection("north", "south", NULL);
		linkedExit->ChangeDirection("west", "east", linkR2);
	}
	if (hour == SOUTH) {
		exit->ChangeDirection("north", "south", NULL);
		linkedExit->ChangeDirection("south", "north", linkR3);
	}
	if (hour == EAST) {
		exit->ChangeDirection("north", "south", NULL);
		linkedExit->ChangeDirection("east", "west", linkR4);
	}
	cardinalHour = hour;



}
