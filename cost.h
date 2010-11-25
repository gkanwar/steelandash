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
    int m_organics;
    int m_ore;
    int m_rareMetals;
    int m_production;

    Cost()
    {
        m_organics = 0;
        m_ore = 0;
        m_rareMetals = 0;
        m_production = 0;
    }
    Cost(int org, int o, int r_m, int p)
    {
        m_organics = org;
        m_ore = o;
        m_rareMetals = r_m;
        m_production = p;
    }

    Cost operator+(Cost c)
    {
        return Cost(m_organics+c.m_organics, m_ore+c.m_ore, m_rareMetals+c.m_rareMetals, m_production+c.m_production);
    }
    void operator+=(Cost c)
    {
        m_organics += c.m_organics;
        m_ore += c.m_ore;
        m_rareMetals += c.m_rareMetals;
        m_production += c.m_production;
    }
    Cost operator-(Cost c)
    {
        return Cost(m_organics-c.m_organics, m_ore-c.m_ore, m_rareMetals-c.m_rareMetals, m_production-c.m_production);
    }
    void operator-=(Cost c)
    {
        m_organics -= c.m_organics;
        m_ore -= c.m_ore;
        m_rareMetals -= c.m_rareMetals;
        m_production -= c.m_production;
    }
};

#endif
