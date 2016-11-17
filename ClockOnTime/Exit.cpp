#include <iostream>
#include "room.h"
#include "Exit.h"


Exit::Exit(const char* name, const char* oppositeName, const char* description, Room* origin, Room* destination) :
	Entity(name, description, (Entity*)origin), oppositeName(oppositeName), destination(destination)
{
	entityType = EXIT;
	destination->storedEntities.push_back(this);
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << name << "\n";
}

const string& Exit::GetNameFrom(const Room* room) const
{
	if (room == (Room*)parent)
		return name;
	if (room == (Room*)destination)
		return oppositeName;
	return name;
}

void Exit::ChangeDirection(const char * direction, const char * oppositeDir, Room* newDestination)
{
	name = direction;
	oppositeName = oppositeDir;

	if (newDestination != NULL)
	{
		destination->storedEntities.remove(this);
		newDestination->storedEntities.push_back(this);
		destination = newDestination;
	}
	//destination->storedEntities(Find(this->oppositeName))
}



Room * Exit::GetDestinationFrom(const Room* room) const
{
	if (room == (Room*)parent)
		return destination;
	if (room == (Room*)destination)
		return (Room*)parent;
	return NULL;
}
