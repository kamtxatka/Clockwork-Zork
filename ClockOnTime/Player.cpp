#include <iostream>
#include "globals.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "Clock.h"
#include "player.h"


Player::Player(const char * name, const char * description, Room * room) : Creature(name, description, room)
{
	entityType = PLAYER;
}

Player::~Player()
{
}

bool Player::Go(const vector<string>& args)
{
	Exit* exit = GetRoom()->GetExit(args[1]);

	if (exit == NULL)
	{
		cout << "\nThere is nowhere to go to the " << args[1] << ".\n\n";
		return false;
	}

	cout << "\n You go to the " << args[1] << "\n\n";
	ChangeParentTo(exit->GetDestinationFrom((Room*)parent));
	parent->Look();

	return true;
}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->storedEntities.begin(); it != parent->storedEntities.cend(); ++it)
		{
			if (Same((*it)->name, args[1]))
			{
				(*it)->Look();
				return;
			}
		}
		cout << "\n Unknown target \n";
	}
	else
	{
		parent->Look();
	}
}

bool Player::Take(const vector<string>& args)
{
	if (args.size() == 2)
	{
		Item* item = (Item*)parent->Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item here with that name.\n";
			return false;
		}

		cout << "\nYou take " << item->name << ".\n\n";
		item->ChangeParentTo(this);
	}

	else 	if (args.size() == 4)
	{
		// we want to take an item from a container
		// check if the container is in the room or in inventory
		
		// check room
		Item* containerItem = (Item*)parent->Find(args[3], ITEM);

		//cheack inventory
		if (containerItem == NULL)
			containerItem = (Item*)Find(args[3], ITEM);

		if (containerItem == NULL)
		{
			cout << "\n" << args[3] <<" isn't in this room nor your inventory.\n";
			return false;
		}

		//check for the contained item

		Item* insideItem = (Item*)containerItem->Find(args[1], ITEM);

		if (insideItem == NULL)
		{
			cout << "\n" << containerItem->name << " does not contain '" << args[1] << "'.\n";
			return false;
		}

		cout << "\nYou take " << insideItem->name << " from " << containerItem->name << ".\n";
		insideItem->ChangeParentTo(this);
	}

	

	return false;

}

bool Player::Drop(const vector<string>& args)
{
	if (args.size() == 2)
	{
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item on you with that name.\n";
			return false;
		}

		cout << "\nYou drop " << item->name << "...\n";
		item->ChangeParentTo(parent);

		return true;
	}
	else if (args.size() == 4)
	{
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nCan not find '" << args[1] << "' in your inventory.\n";
			return false;
		}

		Item* container = (Item*)parent->Find(args[3], ITEM);

		if (container == NULL)
		{
			container = (Item*)Find(args[3], ITEM);
			cout << "\nCan not find '" << args[3] << "' in your inventory or in the room.\n";
			return false;
		}

		cout << "\nYou put " << item->name << " into " << container->name << ".\n";
		item->ChangeParentTo(container);

		return true;
	}

	return false;



}

void Player::Inventory() const
{
	list<Entity*>  items;

	for (list<Entity*>::const_iterator it = storedEntities.begin(); it != storedEntities.cend(); ++it)
	{
		if ((*it)->entityType == ITEM)
			items.push_back(*it);
	}

	if (items.size() == 0)
	{
		cout << "\nYou don't have any item.\n";
		return;
	}


	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		if (*it == weapon)
			cout << "\n" << (*it)->name << " (as weapon)";
		else if (*it == armour)
			cout << "\n" << (*it)->name << " (as armour)";
		else
			cout << "\n" << (*it)->name;
	}

}

bool Player::Equip(const vector<string>& args)
{
	return false;
}

bool Player::UnEquip(const vector<string>& args)
{
	return false;
}

bool Player::Attack(const vector<string>& args)
{
	return false;
}

bool Player::Settime(const vector<string>& args)
{
	Clock* clock = (Clock*)parent->Find(args[1], CLOCK);

	if (clock == NULL)
	{
		cout << "\nCan not find '" << args[1] << "' in this actual room.\n";
		return false;
	}
	
	else
	{
		if (Same(args[2], "12"))
			clock->ChangeHour(NORTH);
		else if (Same(args[2], "9"))
			clock->ChangeHour(WEST);
		else if (Same(args[2], "6"))
			clock->ChangeHour(SOUTH);
		else if (Same(args[2], "3"))
			clock->ChangeHour(EAST);
		else
			cout << "\nCan only acept 3,6,9 or 12 o'clock\n";
	}

	return true;

}


