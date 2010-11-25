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

struct Unit
{
    int m_type;
    int m_owner;
    int m_power;
    Tile* m_pLoc;
    Tile* m_pTarget;
    Cost m_cost;
};

#endif
