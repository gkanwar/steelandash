/*
 * combat.h
 * -----------------------------------
 * Contains the class Combat. This class
 * is used to set up and resolve combats.
 */

#ifndef COMBAT_H
#define COMBAT_H

#include <cstdlib>

#include "tile.h"
#include "unit.h"
#include "cost.h"

class Combat
{
  private:
    Unit p_attacker;
    Unit p_defender;
    vector<Unit> s_attacker;
    vector<Unit> s_defender;
    Tile loc;

    void bounce()
    {
        p_attacker.target = p_attacker.loc;
    }
    void retreat()
    {
        Tile retreat_loc;
        //input the retreat loc somehow
        //with error checking

        p_defender.loc = &retreat_loc;
    }


  public:
    Combat()
    {
        s_attacker.resize(0);
        s_defender.resize(0);
    }
    Combat(Unit p_a, Unit p_d, Tile l)
    {
        //These don't copy
        p_attacker = p_a;
        p_defender = p_d;
        loc = l;
        p_a.target = &loc;
    }

    void addDefender(Unit s_d)
    {
        s_defender.push_back(s_d);
    }
    void addAttacker(Unit s_a)
    {
        s_attacker.push_back(s_a);
    }
    void resolve()
    {
        int attack_total = 0, defense_total = 0;
        attack_total += rand() % p_attacker.power;
        defense_total += rand() % p_defender.power;

        for(int i = 0; i < s_attacker.size(); i++)
        {
            attack_total += rand() % s_attacker[i].power;
        }
        for(int i = 0; i < s_defender.size(); i++)
        {
            defense_total += rand() % s_defender[i].power;
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

        c += p_attacker.c;
        for(int i = 0; i < s_attacker.size(); i++)
        {
            c += s_attacker[i].c;
        }

        return c;
    }
    Cost defenseCost()
    {
        Cost c;

        c += p_defender.c;
        for(int i = 0; i < s_defender.size(); i++)
        {
            c += s_defender[i].c;
        }

        return c;
    }
};

#endif
