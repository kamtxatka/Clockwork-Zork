#include <iostream>
#include "globals.h"
#include "exit.h"
#include "item.h"
#include "Clock.h"
#include "creature.h"
#include "room.h"

Room::Room(const char * name, const char * description) : Entity(name, description, NULL)
{
	entityType = ROOM;
}

Room::~Room()
{
}

void Room::Look() const
{

	cout << "\n " << name << "\n";
	cout << " " << description;

	for (list<Entity*>::const_iterator it = this->storedEntities.begin(); it != this->storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == EXIT)
		{
			Exit* exit = (Exit*)*it;
			cout << "\n To the " << exit->GetNameFrom(this) << " you can see " << exit->GetDestinationFrom(this)->name;
		}
	}


	for (list<Entity*>::const_iterator it = this->storedEntities.begin(); it != this->storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == CLOCK)
		{
			Clock* clock = (Clock*)*it;
			cout << "\n There is a clock named: " << clock->name;
		}
	}

	for (list<Entity*>::const_iterator it = this->storedEntities.begin(); it != this->storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == ITEM)
		{
			Item* item = (Item*)*it;
			cout << "\n There is an item: " << item->name;
		}
	}


	for (list<Entity*>::const_iterator it = storedEntities.begin(); it != storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == CREATURE)
		{
			Creature* cr = (Creature*)*it;
			cout << "\n There is someone else here: " << cr->name;
			if (cr->IsAlive() == false)
				cout << " (dead)";
		}
	}

	cout << "\n\n";

}


Exit * Room::GetExit(const string & direction) const
{
	
	for (list<Entity*>::const_iterator it = storedEntities.begin(); it != storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == EXIT)
		{
			Exit* ex = (Exit*)*it;
			if (Same(ex->GetNameFrom(this), direction))
				return ex;
		}
	}

	return NULL;


}
