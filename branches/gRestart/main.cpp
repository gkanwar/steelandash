#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

#define EXIT_SUCCESS 0
#define EXIT_ERROR 1

#include "tile.h"
#include "player.h"
#include "unit.h"

using namespace std;

Tile** map;
vector<Unit> units;
vector<Player> players;

bool init(int argc, char** argv);
void gameLoop();


int main(int argc, char** argv)
{
	if(!init(argc, argv))
	{
		return EXIT_ERROR;
	}

	gameLoop();

	return EXIT_SUCCESS;
}

bool init(int argc, char** argv)
{
	//Not enough arguments
	if(argc <= 2)
	{
		return false;
	}

	//Read in map data
	string filename = argv[1];
	ifstream mapf;
	int mapNumPlayers;
	int x, y;
	int base, res;

	mapf.open(filename.c_str(), ifstream::in);
	mapf >> mapNumPlayers;
	mapf >> x >> y;

	//Set up dynamic array
	map = new Tile*[x];
	for(int i = 0; i < x; i++)
	{
		map[i] = new Tile[y];
	}

	//Read in tile data
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			mapf >> base;
			map[i][j] = Tile(base);
		}
	}

	//Read in player info
	int numPlayers = atoi(argv[2]);
	string pName;
	Player temp;

	if(mapNumPlayers < numPlayers)
	{
		return false;
	}

	players.resize(0);
	for(int i = 0; i < numPlayers; i++)
	{
		cout << "Player " << i << " name? ";
		cin >> pName;
		temp = Player(pName);
		players.push_back(temp);
	}

	//Initialize the units vector
	units.resize(0);

	return true;
}

void gameLoop()
{
	int currPlayer = 0;
	
	while(true)
	{
		//1. Upkeep - check energy, collect resources
		upkeep(currPlayer);
		//2. Development
		development(currPlayer);
		//3. Declare movement/attacks
		

		//4. Declare defenders
		//5. Resolve combat
		//6. Fees - pay for all combat

		//Cycle to next player
		currPlayer++;
		if(currPlayer == players.size())
		{
			currPlayer = 0;
		}
	}
}
