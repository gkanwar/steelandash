/*
 * combat.h
 * ----------------------------
 * Contains the Combat class, which
 * is used to collect the data for
 * a combat situation, and contains
 * a resolve function that ultimately
 * is used to resolve the combat.
 */

#include <vector>

using namespace std;

#ifndef COMBAT_H
#define

class Combat
{
	private:
		//Primary attacker
		Unit* m_pAttacker;
		//Vector of secondary attackers
		vector<Unit*> m_sAttackers;

		//Primary defender
		Unit* m_pDefender;
		//Vector of secondary defenders
		vector<Unit*> m_sDefenders;

	public:
		//Default constructor
		Combat();
		//Basic constructor
		Combat(Unit* pAttacker, Unit* pDefender);

		//Set primary attacker
		void setAttacker(Unit* pAttacker);
		//Set primary defender
		void setDefender(Unit* pDefender);
		//Add secondary attacker
		void addAttacker(Unit* sAttacker);
		//Add seconday defender
		void addDefender(Unit* sDefender);

		//Resolve combat
		Unit* resolve();
};

#endif
