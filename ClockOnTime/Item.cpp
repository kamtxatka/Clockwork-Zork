#include <iostream>
#include "room.h"
#include "exit.h"
#include "globals.h"
#include "item.h"

Item::Item(const char * name, const char * description, Entity * parent, ItemType itemType) : 
	Entity (name, description, parent), itemType(itemType)
{
	entityType = ITEM;
	minValue = maxValue = 0;
}

Item::~Item()
{
}

void Item::Look() const
{
	cout << "\n " << name << "\n";
	cout << " " << description << "\n";
	list<Entity*> stuff;

	for(list<Entity*>::const_iterator it = storedEntities.begin(); it != storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == ITEM)
			stuff.push_back(*it);
	}

	if (stuff.size() > 0)
	{
		cout << " Holds : " << "\n";
		for (list<Entity*>::const_iterator it = stuff.begin(); it != stuff.cend(); ++it)
			cout << " " << (*it)->name << "\n";
	}
}

int Item::GetValue() const
{
	return Roll(minValue, maxValue);
}
