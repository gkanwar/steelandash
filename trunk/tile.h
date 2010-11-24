/*
 * tile.h
 * ----------------------------------
 * Contains the class Tile. This class
 * defines one tile on the map, including
 * its type, resource, owner, whether or
 * not it has an energy harvester and
 * what units it has on it.
 */

#ifndef TILE_H
#define TILE_H

#include "unit.h"

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

#endif
