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
    //Player name
    string name;
    //Resources the player has
    Cost resources = Cost();

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
    void addResources(Cost r)
    {
        resources += r;
    }
    void spendResources(Cost r)
    {
        resources -= r;
    }

    void upkeep()
    {
        int energy = 0;
        Cost res_gained = Cost();
        for(int i = 0; i < terr_owned.length(); i++)
        {
            if(terr_owned[i].isHarvester())
            {
                energy++;
            }
            else
            {
                energy--;
                switch(terr_owned[i].resource)
                {
                    case 1:
                    {
                        res_gained.organics++;
                        break;
                    }
                    case 2:
                    {
                        res_gained.ore++;
                        break;
                    }
                    case 3:
                    {
                        res_gained.rare_metals++;
                        break;
                    }
                    case 4:
                    {
                        res_gained.production++;
                        break;
                    }
                }
            }

            if(energy < 0)
            {
                res_gained.orgranics -= 2;
                if(res_gained.organics < 0) res_gained.organics = 0;
                res_gained.ore -= 2;
                if(res_gained.ore < 0) res_gained.ore = 0;
                res_gained.rare_metals -= 2;
                if(res_gained.rare_metals < 0) res_gained.rare_metals = 0;
                res_gained.production -= 2;
                if(res_gained.production < 0) res_gained.production = 0;
            }

            resources += res_gained;
        }
    }

    void develop()
    {
        //Development stuff
    }

    void attack(vector<Combat> combats)
    {
        //Input all attacks and moves, create combat objects for each combat, return the vector of them
    }
};

#endif
