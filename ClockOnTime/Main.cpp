#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "globals.h"
#include "world.h"

using namespace std;

int main() {

	string playernIput;
	vector<string> args;
	args.reserve(10);

	World world;
	bool finish = false;

	cout << "\n Welcome \n\n";

	while (finish == false) 
	{
		getline(cin, playernIput);

		Tokenize(playernIput, args);

		if (world.ParseCommand(args) == false)
			cout << "\n Unknown command \n\n";
		
		if (Same(args[0], "quit"))
			finish = true;

		if ((args.size()) > 0)
		{
			args.clear();
			playernIput = "";
		}


	}

	return 0;
}