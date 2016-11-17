
#ifndef __Exit__
#define __Exit__

#include <string>
#include "entity.h"

class Room;

using namespace std;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* opposite_name, const char* description, Room* origin, Room* destination);
	~Exit();

	void Look() const;
	const string& GetNameFrom(const Room* room) const;
	void ChangeDirection(const char* direction, const char* oppositeDir, Room* newDestination);
	Room* GetDestinationFrom(const Room* room) const;
public:
	string oppositeName;
	Room* destination;
	//Entity* key;
};

#endif 