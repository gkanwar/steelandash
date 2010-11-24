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
    int type;
    int owner;
    int power;
    Tile* loc;
    Tile* target;
    Cost c;
};

#endif
