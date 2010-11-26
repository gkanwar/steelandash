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
    int m_type, m_resource, m_owner;
    int m_x, m_y;
    bool m_eHarvester;
    vector<Unit> m_unitStack;

  public:
    Tile()
    {
        m_type = 0;
        m_resource = 0;
        m_eHarvester = false;
        m_unitStack.resize(0);
    }
    Tile(int t, int r, int o, int x_c, int y_c, bool e_h)
    {
        m_type = t;
        m_resource = r;
        m_owner = o;
        m_x = x_c;
        m_y = y_c;
        m_eHarvester = e_h;
    }
    Tile(int t, int r, int o, int x_c, int y_c, bool e_h, vector<Unit> unit_stack_copy)
    {
        m_type = t;
        m_resource = r;
        m_owner = o;
        m_x = x_c;
        m_y = y_c;
        m_eHarvester = e_h;
        m_unitStack = unit_stack_copy;
    }

    void setType(int t)
    {
        m_type = t;
    }
    void setHarvester(bool e_h)
    {
        m_eHarvester = e_h;
    }
    void setOwner(int o)
    {
        m_owner = o;
    }
    void setX(int x_c)
    {
        m_x = x_c;
    }
    void setY(int y_c)
    {
        m_y = y_c;
    }
    void setUnitStack(vector<Unit> unit_stack_copy)
    {
        m_unitStack = unit_stack_copy;
    }
    void addUnit(Unit u)
    {
        m_unitStack.push_back(u);
    }

    int getType()
    {
        return m_type;
    }
    bool isHarvester()
    {
        return m_eHarvester;
    }
    int getResource()
    {
        return m_resource;
    }
    int getOwner()
    {
        return m_owner;
    }
    int getX()
    {
        return m_x;
    }
    int getY()
    {
        return m_y;
    }
    bool hasUnit()
    {
        return (m_unitStack.size() > 0);
    }
    Unit getUnit()
    {
            return m_unitStack[0];
    }
    void removeUnit(Unit u)
    {
        for(vector<Unit>::iterator it=m_unitStack.begin(); it != m_unitStack.end(); ++it)
        {
            if((*it) == u)
            {
                m_unitStack.erase(it);
                break;
            }
        }
    }

    bool operator==(Tile t)
    {
        return (t.getX() == m_x && t.getY() == m_y);
    }
};

#endif
