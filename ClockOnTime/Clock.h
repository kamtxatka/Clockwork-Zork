#ifndef __Clock__
#define __Clock__

#include <list>
#include "Exit.h"
#include "Entity.h"
#include "Room.h"

using namespace std;

enum CardinalHour {
	NORTH = 12,
	WEST = 9,
	SOUTH = 6,
	EAST = 3
};

class Room;


class Clock : public Entity
{
public:
	Clock(const char* name, const char* description, Room* room, Exit* linkedExit, 
		Room* linkR1, Room* linkR2, Room* linkR3, Room* linkR4, CardinalHour hour = EAST);
	~Clock();
	void Look() const;
	void ChangeHour(CardinalHour hour);
public:
	CardinalHour cardinalHour;
	bool modifiable;
	Exit* linkedExit;
	Room* linkR1;
	Room* linkR2;
	Room* linkR3;
	Room* linkR4;
	
};

#endif

