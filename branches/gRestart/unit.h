/*
 * unit.h
 * -------------------------------
 * Contains the Unit class. This class
 * contains data for a unit with
 * functions to operate on it.
 */

#ifndef UNIT_H
#define UNIT_H

class Player;

class Unit
{
	private:
		//Current location
		int m_x, m_y;
		//Target location
		int m_targetX, m_targetY;
		//Power value
		int m_power;
		//Has the unit been set to move this turn?
		bool m_hasMoved;
		//Owner
		Player* m_owner;

	public:
		//Default constructor
		Unit();
		//Regular constructor
		Unit(int x, int y, int power, Player* m_owner);

		//Set the power of the unit
		void setPower(int power);
		//Async set the location of the unit
		void setLoc(int x, int y);
		//Set the target location
		void setMove(int targetX, int targetY);
		//Find out if a target is set
		bool hasMoved();
		//Resolve movement
		void resolve();
		//Get the power level
		int getPower();
		//Get the owner
		Player* getOwner();
};

#endif

