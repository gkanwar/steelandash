/*
 * combat.h
 * -----------------------------------
 * Contains the class Combat. This class
 * is used to set up and resolve combats.
 */

#ifndef COMBAT_H
#define COMBAT_H

#include <cstdlib>
#include <vector>

#include "tile.h"
#include "unit.h"
#include "cost.h"

class Combat
{
  private:
    Unit m_attackerP;
    Unit m_defenderP;
    vector<Unit> m_attackerS;
    vector<Unit> m_defenderS;
    Tile m_loc;

    void bounce()
    {
        m_attackerP.m_pTarget = m_attackerP.m_pLoc;
    }
    void retreat()
    {
        Tile retreat_loc;
        //input the retreat loc somehow
        //with error checking

        m_defenderP.m_pLoc = &retreat_loc;
    }


  public:
    Combat()
    {
        m_attackerS.resize(0);
        m_defenderS.resize(0);
    }
    Combat(Unit p_a, Unit p_d, Tile l)
    {
        //These don't copy
        m_attackerP = p_a;
        m_defenderP = p_d;
        m_loc = l;
        p_a.m_pTarget = &m_loc;
    }

    void addDefender(Unit s_d)
    {
        m_defenderS.push_back(s_d);
    }
    void addAttacker(Unit s_a)
    {
        m_attackerS.push_back(s_a);
    }
    void resolve()
    {
        int attack_total = 0, defense_total = 0;
        attack_total += rand() % m_attackerP.m_power;
        defense_total += rand() % m_defenderP.m_power;


        for(int i = 0; i < m_attackerS.size(); i++)
        {
            attack_total += rand() % m_attackerS[i].m_power;
        }
        for(int i = 0; i < m_defenderS.size(); i++)
        {
            defense_total += rand() % m_defenderS[i].m_power;
        }

        if(attack_total > defense_total)
        {
            bounce();
        }
        else
        {
            retreat();
        }
    }
    Cost attackCost()
    {
        Cost c;

        c += m_attackerP.m_cost;
        for(int i = 0; i < m_attackerS.size(); i++)
        {
            c += m_attackerS[i].m_cost;
        }

        return c;
    }
    Cost defenseCost()
    {
        Cost c;

        c += m_defenderP.m_cost;
        for(int i = 0; i < m_defenderS.size(); i++)
        {
            c += m_defenderS[i].m_cost;
        }

        return c;
    }
};

#endif
