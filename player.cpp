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

void Player::resetResearch()
{
	for(int i = 0; i < NUM_DEVELOPMENTS; i++)
	{
		m_research[i] = false;
	}
}

Player::Player()
{
	m_units.resize(0);
	m_terrs.resize(0);
	resetResearch();
}
Player::Player(string name)
{
	m_units.resize(0);
	m_terrs.resize(0);
	m_name = name;
	resetResearch();
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
void Player::research(int numDevelopment)
{
	m_research[numDevelopment] = true;
}
