/*
 * tile.h
 * -------------------------------
 * Contains the Tile class. This class
 * respresents each tile on the board.
 */

#ifndef TILE_H
#define TILE_H

class Player;
class Unit;

class Tile
{
	private:
		//The type of tile
		int m_type;
		//The resouce on the tile
		int m_resource;
		//Does it have an energy harvester on it?
		bool m_eHarvester;
		//Pointer to owner Player
		Player* m_owner;
		//Pointer to Unit on tile
		Unit* m_unit;
		//Does it have a unit on it?
		bool m_hasUnit;

	public:
		//Default constructor
		Tile();
		//Type only constructor
		Tile(int type);
		//Full constructor
		Tile(int type, int resource, Player* owner);

		//Set the type
		void setType(int type);
		//Set the resource
		void setResource(int resource);
		//Toggle energy harvester
		void toggleEHarvester();
		//Change owner
		void setOwner(Player* owner);
		//Add unit
		void addUnit(Unit* unit);
		//Remove unit
		void removeUnit(Unit* unit);
		//Does this have a unit?
		bool hasUnit();
};

#endif

	
