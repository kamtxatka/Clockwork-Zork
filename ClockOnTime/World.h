#ifndef __World__
#define __World__

#include <string>
#include <list>
#include <time.h>
#include <vector>

using namespace std;


class Entity;
class Player;

class World
{
public:
	World();
	~World();

	bool ParseCommand(vector<string>& args);
	void GameLoop();

private:
	clock_t tickTimer;
	list<Entity*> entities;
	Player* player;

};


#endif
