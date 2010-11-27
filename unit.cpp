/*
 * unit.cpp
 * -------------------------------
 * Contains the implementation of
 * the Unit class.
 */

#include "unit.h"
#include "tile.h"
#include "player.h"

extern Tile** map;

Unit::Unit()
{
	m_hasMoved = false;
}
Unit::Unit(int x, int y, int power, Player* owner)
{
	m_x = x;
	m_y = y;
	m_power = power;
	m_owner = owner;
	m_hasMoved = false;
}

void Unit::setPower(int power)
{
	m_power = power;
}
void Unit::setLoc(int x, int y)
{
	m_x = x;
	m_y = y;
}
int getXLoc()
{
	return m_x;
}
int getYLoc()
{
	return m_y;
}
void Unit::setMove(int targetX, int targetY)
{
	m_targetX = targetX;
	m_targetY = targetY;
}
bool Unit::hasMoved()
{
	return m_hasMoved;
}
void Unit::resolve()
{
	if(!map[m_targetX][m_targetY].hasUnit())
	{
		m_x = m_targetX;
		m_y = m_targetY;
		map[m_targetX][m_targetY].addUnit(this);
	}
	else
	{
		map[m_x][m_y].addUnit(this);
	}
}
int Unit::getPower()
{
	return m_power;
}
Player* Unit::getOwner()
{
	return m_owner;
}
