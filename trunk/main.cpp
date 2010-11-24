/*
 * File: main.cpp
 * --------------------------------
 * Entry point for the program.
 */

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;


class Cost
{
  public:
    int organics;
    int ore;
    int rare_metals;
    int production;

    Cost()
    {
        organics = 0;
        ore = 0;
        rare_metals = 0;
        production = 0;
    }
    Cost(int org, int o, int r_m, int p)
    {
        organics = org;
        ore = o;
        rare_metals = r_m;
        production = p;
    }

    Cost operator+(Cost c)
    {
        return Cost(organics+c.organics, ore+c.ore, rare_metals+c.rare_metals, production+c.production);
    }
    void operator+=(Cost c)
    {
        organics += c.organics;
        ore += c.ore;
        rare_metals += c.rare_metals;
        production += c.production;
    }
};

class Tile;

struct Unit
{
    int type;
    int owner;
    int power;
    Tile* loc;
    Tile* target;
    Cost c;
};

class Combat
{
  private:
    Unit p_attacker;
    Unit p_defender;
    vector<Unit> s_attacker;
    vector<Unit> s_defender;
    Tile *loc;

    void bounce()
    {
        p_attacker.target = p_attacker.loc;
    }
    void retreat()
    {
        Tile* retreat_loc;
        //input the retreat loc somehow
        //with error checking

        p_defender.loc = retreat_loc;
    }


  public:
    Combat()
    {
        s_attacker.resize(0);
        s_defender.resize(0);
    }
    Combat(Unit p_a, Unit p_d, Tile* l)
    {
        //These don't copy
        p_attacker = p_a;
        p_defender = p_d;
        loc = l;
        p_a.target = loc;
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

class Tile
{
  private:
    int type, resource, owner;
    bool e_harvester;
    vector<Unit> unit_stack;

  public:
    Tile()
    {
        type = 0;
        resource = 0;
        e_harvester = false;
        unit_stack.resize(0);
    }
    Tile(int t, int r, int o, bool e_h)
    {
        type = t;
        resource = r;
        owner = o;
        e_harvester = e_h;
    }
    Tile(int t, int r, int o, bool e_h, vector<Unit> unit_stack_copy)
    {
        type = t;
        resource = r;
        owner = o;
        e_harvester = e_h;
        unit_stack = unit_stack_copy;
    }

    void setType(int t)
    {
        type = t;
    }
    void setHarvester(bool e_h)
    {
        e_harvester = e_h;
    }
    void setOwner(int o)
    {
        owner = o;
    }
    void setUnitStack(vector<Unit> unit_stack_copy)
    {
        unit_stack = unit_stack_copy;
    }
    void addUnit(Unit u)
    {
        unit_stack.push_back(u);
    }
};


int main (int argc, char** argv)
{
    int type, resource;
    string filename;
    ifstream mapf;

    int x, y;
    Tile** map;

    if(argc > 1)
    {
        filename = argv[1];
    }
    mapf.open(filename.c_str(), ifstream::in);

    mapf >> x >> y;

    map = new Tile*[x];
    for(int i = 0; i < x; i++)
    {
        map[i] = new Tile[y];
    }

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            mapf >> type >> resource;
            map[x][y] = Tile(type, resource, false);
        }
    }

    while(true)
    {
        //Main game loop
    }

    return 0;
}
