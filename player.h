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

    	for (vector<Tile>::iterator it = m_terrOwned.begin(); it!=m_terrOwned.end(); ++it)
    	{
    	    if((*it) == t)
    	    {
    	    	m_terrOwned.erase(it);
    	    	break;
    	    }
    	}
    }
    void loseUnit(Unit u)
    {

    	for (vector<Unit>::iterator it = m_unitOwned.begin(); it!=m_unitOwned.end(); ++it)
    	{
    	    if(&(*it) == &u)
    	    {
    	    	m_unitOwned.erase(it);
    	    	break;
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
        Cost resGained = Cost();
        for (vector<Tile>::iterator it = m_terrOwned.begin(); it!=m_terrOwned.end(); ++it)
        {
        	if((*it).isHarvester())
			{
				energy++;
			}
			else
			{
				energy--;
				switch((*it).getResource())
				{
					case 1:
					{
						resGained.m_organics++;
						break;
					}
					case 2:
					{
						resGained.m_ore++;
						break;
					}
					case 3:
					{
						resGained.m_rareMetals++;
						break;
					}
					case 4:
					{
						resGained.m_production++;
						break;
					}
				}
			}

			if(energy < 0)
			{
				resGained.m_organics -= 2;
				if(resGained.m_organics < 0) resGained.m_organics = 0;
				resGained.m_ore -= 2;
				if(resGained.m_ore < 0) resGained.m_ore = 0;
				resGained.m_rareMetals -= 2;
				if(resGained.m_rareMetals < 0) resGained.m_rareMetals = 0;
				resGained.m_production -= 2;
				if(resGained.m_production < 0) resGained.m_production = 0;
			}

			m_resources += resGained;
        }
    }

    void develop()
    {
        //Development stuff
        //Nothing yet
    }

    void attack(vector<Combat> combats)
    {
        //Input all attacks and moves, create combat objects for each combat, return the vector of them
        Combat tempCombat;
        char code;
        int unitX, unitY, targetX, targetY;
        Unit attacker, defender;
        vector<Unit> movedUnits;

        movedUnits.resize(0);
        combats.resize(0);

        while(true)
        {
            cout << "Input: <code> <unit:x y> <target:x y> or '.' to end" << endl;
            cin >> code;
            if(code == '.')
            {
                break;
            }
            else if(code == 'A')
            {
                cin >> unitX >> unitY >> targetX >> targetY;
                if(map[unitX][unitY].hasUnit())
                {
                    attacker = map[unitX][unitY].getUnit();
                }
                else
                {
                    cout << "Error: no unit" << endl;
                    continue;
                }
                if(map[targetX][targetY].hasUnit())
                {
                    defender = map[targetX][targetY].getUnit();
                }
                else
                {
                    attacker.move(map[targetX][targetY]);
                    movedUnits.push_back(attacker);
                    continue;
                }
                tempCombat = Combat(map[unitX][unitY].getUnit(), map[targetX][targetY].getUnit(), map[targetX][targetY]);
                combats.push_back(tempCombat);
            }
            else if(code == 'S')
            {
                cin >> unitX >> unitY >> targetX >> targetY;
                //Do something
            }
            else
            {
                cout << "Error, try again" << endl;
                continue;
            }
        }
    }
};

#endif
