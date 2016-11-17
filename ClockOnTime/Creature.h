#ifndef __Creature__
#define __Creature__

#include <string>
#include <vector>
#include "entity.h"

class Room;
class Item;

using namespace std;

class Creature : public Entity 
{
public:
	Creature(const char* name, const char* description, Room* room);

	~Creature();

	virtual bool Go(const vector<string>& args);
	virtual void Look(const vector<string>& args) const;
	virtual bool Take(const vector<string>& args);
	virtual bool Drop(const vector<string>& args);
	virtual void Inventory() const;
	virtual bool Equip(const vector<string>& args);
	virtual bool UnEquip(const vector<string>& args);
	virtual bool AutoEquip();
	virtual void Tick();

	virtual bool Attack(const vector<string>& args);
	virtual int MakeAttack();
	virtual int ReceiveAttack(int damage);
	virtual void Die();

	Room* GetRoom() const;
	bool PlayerInRoom() const;
	bool IsAlive() const;


public:
	int hitPoints;
	int minDamage;
	int maxDamage;
	int minProtection;
	int maxProtection;
	Creature* combatTarget;
	Item* weapon;
	Item* armour;
};

#endif