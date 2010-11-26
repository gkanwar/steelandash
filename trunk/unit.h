/*
 * unit.h
 * ---------------------------------
 * Contains the struct Unit. This
 * defines the type, owner, power,
 * location, cost and optionally target
 * in the case of moving or attacking.
 */

#ifndef UNIT_H
#define UNIT_H

#include "cost.h"

class Tile;

class Unit
{
  public:
    bool m_canMove;
    int m_type;
    int m_owner;
    int m_power;
    Tile* m_pLoc;
    Tile* m_pTarget;
    Cost m_cost;

    Unit()
    {
        m_canMove = true;
    }

    bool canMove()
    {
        return m_canMove;
    }
    void move(Tile* target)
    {
        m_pTarget = target;
        m_canMove = false;
    }

    void resolve()
    {
        (*m_pLoc).removeUnit(this);
        m_pLoc = m_pTarget;
        (*m_pTarget).addUnit(this);
    }
};

#endif
