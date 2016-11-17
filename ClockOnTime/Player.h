#ifndef __Player__
#define __Player__

#include "creature.h"
#include "Clock.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	bool Go(const vector<string>& args);
	void Look(const vector<string>& args) const;
	bool Take(const vector<string>& args);
	bool Drop(const vector<string>& args);
	void Inventory() const;
	bool Equip(const vector<string>& args);
	bool UnEquip(const vector<string>& args);
	bool Attack(const vector<string>& args);
	bool Settime(const vector<string>& args);
};

#endif