#include <iostream>
#include "globals.h"
#include "entity.h"
#include "creature.h"
#include "item.h"
#include "Clock.h"
#include "exit.h"
#include "room.h"
#include "player.h"
#include "world.h"


World::World()
{
	Room* apartment = new Room("Apartment", "This is your house, a little room. You can see the clouds grasping the window");
	Room* fountSquare = new Room("FountainPlaza", "You are in a circular square that is floating in the skyes. The plaza is bounded by a downside stairway and 11 houses that surround a fountain in the middle. Your house is facing the stairway.");
	Room* northTown = new Room("NorthTown", "One of the 4 skyland cities. Now empty");
	Room* westTown = new Room("WestTown", "One of the 4 skyland cities. Now empty");
	Room* southTown = new Room("SouthTown", "One of the 4 skyland cities. Now empty");
	Room* eastTown = new Room("EastTown", "One of the 4 skyland cities. Now empty");
	Room* forge = new Room("Forge", "A very dark and tall room filled with infinite clock pieces. It narrows towards its far end whe you can see a bright light that seems to be the sun");


	Exit* houseDoor = new Exit("East", "West", "Your house's door", apartment, fountSquare);
	Exit* stairway = new Exit("East", "West", "Stairway that connects your neighbourhood with gear-city", fountSquare, eastTown);
	Exit* forgePortal = new Exit("North", "South", "A portal between gear-city and the forge", northTown, forge);


	entities.push_back(apartment);
	entities.push_back(fountSquare);
	entities.push_back(northTown);
	entities.push_back(westTown);
	entities.push_back(southTown);
	entities.push_back(eastTown);
	entities.push_back(forge);

	entities.push_back(houseDoor);
	entities.push_back(stairway);
	entities.push_back(apartment);


	//Item* pendulumClock = new Item("Clock", "Pendulum clock that marks your house's hour", apartment);
	Item* box = new Item("Box", "A box where you use to place your properties", apartment);
	Item* note = new Item("Note", "A note from your closest friend: -lets meet at the forge when your watch marks 12 o'clock-", box);
	Item* watch = new Item("Watch", "Your watch. You allways bring it with you. It marks 9 o'clock as allways", box, ARMOUR);
	Item* abandonedCrate = new Item("Crate", "An abandoned crate filled with weapons", eastTown);
	Item* letter = new Item("Letter", "Another letter from your friend: 'I see you realized how time affect to this city, but you also carry a watch yourself... I will explain in the future.", forge);
	
	Item* Sword = new Item("Sword", "A narrow sharp sword", abandonedCrate, WEAPON);
	Sword->minValue = 2;
	Sword->maxValue = 4;

	//entities.push_back(pendulumClock);
	entities.push_back(box);
	entities.push_back(note);
	entities.push_back(watch);
	entities.push_back(abandonedCrate);
	entities.push_back(Sword);


	player = new Player("Henlein", "You, yourself", apartment);
	player->hitPoints = 20;
	entities.push_back(player);



	//creation of a tricky clock


	Clock* pendulum = new Clock("Clock", "a clock", apartment, stairway, northTown, westTown, southTown, eastTown);
	entities.push_back(pendulum);


	//pendulum->ChangeHour(NORTH);


}


World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete *it;

	entities.clear();
}



bool World::ParseCommand(vector<string>& args)
{
	bool returnValue = true;

	switch (args.size()) {
	case 0:
		returnValue = false;
		break;

	case 1:
		if (Same(args[0], "look"))
			player->Look(args);

		else if (Same(args[0], "north"))
		{
			args.push_back("north");
			player->Go(args);
		}

		else if (Same(args[0], "south"))
		{
			args.push_back("south");
			player->Go(args);
		}

		else if (Same(args[0], "east"))
		{
			args.push_back("east");
			player->Go(args);
		}

		else if (Same(args[0], "west"))
		{
			args.push_back("west");
			player->Go(args);
		}

		else if (Same(args[0], "inventory"))
		{
			player->Inventory();
		}
		else
			returnValue = false;
		break;

	case 2:
		if (Same(args[0], "look"))
		{
			player->Look(args);
		}
		else if (Same(args[0], "go"))
		{
			player->Go(args);
		}
		else if (Same(args[0], "take"))
		{
			player->Take(args);
		}
		else
			returnValue = false;
		break;
	case 3:
		if (Same(args[0], "settime"))
			player->Settime(args);
		break;

	case 4:
		if (Same(args[0], "take"))
		{
			player->Take(args);
		}
		else if (Same(args[0], "put"))
		{
			player->Drop(args);
		}
		else
			returnValue = false;
		break;
	}

	return returnValue;
}




void World::GameLoop()
{
}
