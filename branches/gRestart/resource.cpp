/*
 * resource.cpp
 * ---------------------------------
 * Contains the implementation of the
 * Resource class.
 */

#include "resource.h"

Resource::Resource()
{
	m_organics = 0;
	m_ore = 0;
	m_rareMetals = 0;
	m_production = 0;
}
Resource::Resource(int organics, int ore, int rareMetals, int production)
{
	m_organics = organics;
	m_ore = ore;
	m_rareMetals = rareMetals;
	m_production = production;
}
int Resource::getOrganics()
{
	return m_organics;
}
int Resource::getOre()
{
	return m_ore;
}
int Resource::getRareMetals()
{
	return m_rareMetals;
}
int Resource::getProduction()
{
	return m_production;
}

Resource Resource::operator+ (Resource r)
{
	return (Resource(m_organics+r.getOrganics(), m_ore+r.getOre(), m_rareMetals+r.getRareMetals(), m_production+r.getProduction()));
}
void Resource::operator+= (Resource r)
{
	m_organics += r.getOrganics();
	m_ore += r.getOre();
	m_rareMetals += r.getRareMetals();
	m_production += r.getProduction();
}
Resource Resource::operator- (Resource r)
{
	return (Resource(m_organics-r.getOrganics(), m_ore-r.getOre(), m_rareMetals-r.getRareMetals(), m_production-r.getProduction()));
}
void Resource::operator-= (Resource r)
{
	m_organics -= r.getOrganics();
	m_ore -= r.getOre();
	m_rareMetals -= r.getRareMetals();
	m_production -= r.getProduction();
}
