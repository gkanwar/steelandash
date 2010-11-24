/*
 * cost.h
 * -----------------------------
 * Contains the class Cost. This
 * class unifies the different
 * cost fields into one class. It
 * would have been a struct except
 * I felt that defining '+' and
 * '+=' operators for it would be
 * useful.
 */

#ifndef COST_H
#define COST_H

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

#endif
