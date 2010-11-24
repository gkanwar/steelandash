/*
 * File: main.cpp
 * --------------------------------
 * Entry point for the program.
 */

#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "tile.h"
#include "combat.h"

void init(int argc, char** argv, Tile** map);
void gameLoop(Tile** map);

int main(int argc, char** argv)
{
    Tile** map;
    init(argc, argv, map);

    gameLoop(map);

    return 0;
}

void init(int argc, char** argv, Tile** map)
{
    int x, y;
    int type, resource, owner;
    string filename;
    ifstream mapf;

    if(argc > 1)
    {
        filename = argv[1];
    }
    mapf.open(filename.c_str(), ifstream::in);

    mapf >> x >> y;

    map = new Tile*[x];
    for(int i = 0; i < x; i++)
    {
        map[i] = new Tile[y];
    }

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            mapf >> type >> resource >> owner;
            map[x][y] = Tile(type, resource, owner, false);
        }
    }
}

void gameLoop(Tile** map)
{
    //Main game loop
}
