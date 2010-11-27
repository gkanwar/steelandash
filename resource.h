/*
 * resource.h
 * --------------------------------
 * Class for resource objects. Mostly
 * just a struct, but with defined
 * + and - operators to make dealing
 * with amounts of resources easy.
 */

#ifndef RESOURCE_H
#define RESOURCE_H

class Resource
{
	private:
		//Individual resource values
		int m_organics, m_ore, m_rareMetals, m_production;
	
	public:
		//Default constructor
		Resource();
		//Full constructor
		Resource(int organics, int ore, int rareMetals, int production);

		//Return individual resource field
		int getOrganics();
		int getOre();
		int getRareMetals();
		int getProduction();

		//Add/subtract Resource objects by adding and subtracting individual fields
		Resource operator+ (Resource r);
		void operator+= (Resource r);
		Resource operator- (Resource r);
		void operator-= (Resource r);
};

#endif
