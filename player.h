/*
 * player.h
 * ---------------------------------
 * Contains the Player class. This class
 * hold all the data for a particular
 * player.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "resource.h"

using namespace std;

class Unit;
class Tile;

class Player
{
	private:
		//Controlled units and territories
		vector<Unit*> m_units;
		vector<Tile*> m_terrs;
		//Total resources
		Resource m_resources;
		//Name
		string m_name;
		
	public:
		//Default constructor
		Player();
		//Name constructor
		Player(string name);

		//Add unit
		void addUnit(Unit* unit);
		//Delete unit
		void deleteUnit(Unit* unit);
		//Add territory
		void addTerritory(Tile* terr);
		//Delete territory
		void deleteTerritory(Tile* terr);
};

#endif
