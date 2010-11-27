/*
 * tile.cpp
 * -------------------------
 * Contains the implementation
 * for class Tile.
 */

#include "tile.h"
#include "unit.h"
#include "player.h"

Tile::Tile()
{
	m_eHarvester = false;
	m_hasUnit = false;
}
Tile::Tile(int type)
{
	m_eHarvester = false;
	m_hasUnit = false;
	m_type = type;
}
Tile::Tile(int type, int resource, Player* owner)
{
	m_type = type;
	m_resource = resource;
	m_owner = owner;
	m_eHarvester = false;
	m_hasUnit = false;
}


void Tile::setType(int type)
{
	m_type = type;
}
void Tile::setResource(int resource)
{
	m_resource = resource;
}
void Tile::toggleEHarvester()
{
	m_eHarvester = m_eHarvester ? false : true;
}
void Tile::setOwner(Player* owner)
{
	m_owner = owner;
}
void Tile::addUnit(Unit* unit)
{
	m_unit = unit;
	m_hasUnit = true;
}
void Tile::removeUnit(Unit* unit)
{
	m_unit = (Unit*)-1;
	m_hasUnit = false;
}
bool Tile::hasUnit()
{
	return m_hasUnit;
}
