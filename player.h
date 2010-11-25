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
    vector<Tile> m_terrOwned;
    vector<Unit> m_unitOwned;
    //Player name
    string m_name;
    //Resources the player has
    Cost m_resources;

  public:
    Player()
    {
        m_terrOwned.resize(0);
        m_unitOwned.resize(0);
        m_resources = Cost();
    }

    void addName(string s)
    {
        m_name = s;
    }
    string getName()
    {
        return m_name;
    }
    void addTerr(Tile t)
    {
        m_terrOwned.push_back(t);
    }
    void addUnit(Unit u)
    {
        m_unitOwned.push_back(u);
    }
    void loseTerr(Tile t)
    {
        for(int i = 0; i < m_terrOwned.size(); i++)
        {
            if(m_terrOwned[i] == t)
            {
                m_terrOwned.erase(m_terrOwned.begin() + i);
                break;
            }
        }
    }
    void loseUnit(Unit u)
    {
        for(int i = 0; i < m_unitOwned.size(); i++)
        {
            if(&m_unitOwned[i] == &u)
            {
                m_unitOwned.erase(m_unitOwned.begin() + i);
            }
        }
    }
    void addResources(Cost r)
    {
        m_resources += r;
    }
    void spendResources(Cost r)
    {
        m_resources -= r;
    }

    void upkeep()
    {
        int energy = 0;
        Cost res_gained = Cost();
        for(int i = 0; i < m_terrOwned.size(); i++)
        {
            if(m_terrOwned[i].isHarvester())
            {
                energy++;
            }
            else
            {
                energy--;
                switch(m_terrOwned[i].getResource())
                {
                    case 1:
                    {
                        res_gained.m_organics++;
                        break;
                    }
                    case 2:
                    {
                        res_gained.m_ore++;
                        break;
                    }
                    case 3:
                    {
                        res_gained.m_rareMetals++;
                        break;
                    }
                    case 4:
                    {
                        res_gained.m_production++;
                        break;
                    }
                }
            }

            if(energy < 0)
            {
                res_gained.m_organics -= 2;
                if(res_gained.m_organics < 0) res_gained.m_organics = 0;
                res_gained.m_ore -= 2;
                if(res_gained.m_ore < 0) res_gained.m_ore = 0;
                res_gained.m_rareMetals -= 2;
                if(res_gained.m_rareMetals < 0) res_gained.m_rareMetals = 0;
                res_gained.m_production -= 2;
                if(res_gained.m_production < 0) res_gained.m_production = 0;
            }

            m_resources += res_gained;
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
