#include <iostream>
#include "globals.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "creature.h"



Creature::Creature(const char * name, const char * description, Room * room) : Entity (name, description, (Entity*)room)
{
	entityType = CREATURE;
	hitPoints = 1;
	minDamage = maxDamage = minProtection = maxProtection = 0;
	weapon = armour = NULL;
	combatTarget = NULL;
}

Creature::~Creature()
{
}

bool Creature::Go(const vector<string>& args)
{
	if (!IsAlive())
		return false;

	Exit* exit = GetRoom()->GetExit(args[1]);

	if (exit == NULL)
		return false;

	if (PlayerInRoom())
		cout << name << "goes" << args[1] << "...\n";

	ChangeParentTo(exit->GetDestinationFrom((Room*)parent));

	return true;
}

void Creature::Look(const vector<string>& args) const
{
}

bool Creature::Take(const vector<string>& args)
{
	return false;
}

bool Creature::Drop(const vector<string>& args)
{
	return false;
}

void Creature::Inventory() const
{
}

bool Creature::Equip(const vector<string>& args)
{
	return false;
}

bool Creature::UnEquip(const vector<string>& args)
{
	return false;
}

bool Creature::AutoEquip()
{
	return false;
}

void Creature::Tick()
{
}

bool Creature::Attack(const vector<string>& args)
{
	return false;
}

int Creature::MakeAttack()
{
	return 0;
}

int Creature::ReceiveAttack(int damage)
{
	return 0;
}

void Creature::Die()
{
}

Room * Creature::GetRoom() const
{
	return (Room*)parent;
}

bool Creature::PlayerInRoom() const
{
	return false;
}

bool Creature::IsAlive() const
{
	return hitPoints>0;
}
