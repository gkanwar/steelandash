/*
 * player.h
 * -------------------------------
 * Contains the class Player. This
 * is used to keep track of units
 * and territories owned, and resource
 * production energy, etc.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "tile.h"

class Player
{
    vector<Tile> terr_owned;
    vector<Unit> unit_owned;
    string name;

  public:
    Player()
    {
        terr_owned.resize(0);
        unit_owned.resize(0);
    }

    void addName(string s)
    {
        name = s;
    }
    string getName()
    {
        return name;
    }
    void addTerr(Tile t)
    {
        terr_owned.push_back(t);
    }
    void addUnit(Unit u)
    {
        unit_owned.push_back(u);
    }
    void loseTerr(Tile t)
    {
        for(int i = 0; i < terr_owned.size(); i++)
        {
            if(terr_owned[i] == t)
            {
                terr_owned.erase(terr_owned.begin() + i);
                break;
            }
        }
    }
    void loseUnit(Unit u)
    {
        for(int i = 0; i < unit_owned.size(); i++)
        {
            if(&unit_owned[i] == &u)
            {
                unit_owned.erase(unit_owned.begin() + i);
            }
        }
    }
};

#endif
