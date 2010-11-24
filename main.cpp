/*
 * File: main.cpp
 * --------------------------------
 * Entry point for the program.
 */

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "tile.h"
#include "combat.h"

int main (int argc, char** argv)
{
    int type, resource, owner;
    string filename;
    ifstream mapf;

    int x, y;
    Tile** map;

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

    return 0;
}
