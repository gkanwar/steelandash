/*
 * combat.cpp
 * --------------------------
 * Implements the Combat class.
 */

#include <vector>
#include <cstdlib>
#include <ctime>

#include "combat.h"

using namespace std;

Combat::Combat()
{
	m_sAttackers.resize(0);
	m_sDefenders.resize(0);
}
Combat(Unit* pAttacker, Unit* pDefender)
{
	m_pAttacker = pAttacker;
	m_pDefender = pDefender;
	m_sAttackers.resize(0);
	m_sDefenders.resize(0);
}

void setAttacker(Unit* pAttacker)
{
	m_pAttacker = pAttacker;
}
void setDefender(Unit* pDefender)
{
	m_pDefender = pDefender;
}
void addAttacker(Unit* sAttacker)
{
	m_sAttackers.push_back(sAttacker);
}
void addDefender(Unit* sDefender)
{
	m_sDefenders.push_back(sDefender);
}

Unit* resolve()
{
	int attackerTotal = 0, defenderTotal = 0;

	//Seed the rand() function
	srand(time());

	//Add the primary unit's power values
	attackerTotal += rand() % (m_pAttacker->getPower());
	defenderTotal += rand() % (m_pDefender->getPower());

	//Loop through secondary unit vectors and add their power values
	for(vector<Unit*>::iterator it = m_sAttackers.begin(); it != m_sAttackers.end(); it++)
	{
		attackerTotal += rand() % ((*it)->getPower());
	}
	for(vector<Unit*>::iterator it = m_sDefenders.begin(); it != m_sDefenders.end(); it++)
	{
		defenderTotal += rand() % ((*it)->getPower());
	}

	if(attackerTotal > defenderTotal)
	{
		m_pAttacker->setMove(m_pDefender->getXLoc, m_pDefender->getYLoc);
		return m_pDefender;
	}
	else
	{
		return (Unit*)-1;
	}
}
		
