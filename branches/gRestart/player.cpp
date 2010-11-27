/*
 * player.cpp
 * -----------------------------
 * Implementation of the Player
 * class.
 */

#include <vector>
#include <string>
#include "player.h"
#include "tile.h"
#include "unit.h"

using namespace std;

Player::Player()
{
	m_units.resize(0);
	m_terrs.resize(0);
}
Player::Player(string name)
{
	m_name = name;
}

void Player::addUnit(Unit* unit)
{
	m_units.push_back(unit);
}
void Player::deleteUnit(Unit* unit)
{
	for(vector<Unit*>::iterator it = m_units.begin(); it != m_units.end(); it++)
	{
		if((*it) == unit)
		{
			it = m_units.erase(it);
			break;
		}
	}
}
void Player::addTerritory(Tile* terr)
{
	m_terrs.push_back(terr);
}
void Player::deleteTerritory(Tile* terr)
{
	for(vector<Tile*>::iterator it = m_terrs.begin(); it != m_terrs.end(); it++)
	{
		if((*it) == terr)
		{
			it = m_terrs.erase(it);
			break;
		}
	}
}
