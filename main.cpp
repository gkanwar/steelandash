/*
 * File: main.cpp
 * --------------------------------
 * Entry point for the program.
 */

#define EXIT_ERR_CODE 1

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "tile.h"
#include "combat.h"
#include "player.h"

void rageQuit(string s);
void init(int argc, char** argv, Tile** map, int& num_players);
void gameLoop(Tile** map);

int main(int argc, char** argv)
{
    int num_players;
    Tile** map;
    init(argc, argv, map, num_players);

    gameLoop(map);

    return 0;
}

void rageQuit(string s)
{
    cout << "Error: " << s << endl;
    exit(EXIT_ERR_CODE);
}

void init(int argc, char** argv, Tile** map, int& num_players)
{
    int x, y;
    int type, resource, owner;
    string filename;
    ifstream mapf;

    if(argc < 2)
    {
        rageQuit("Not enough arguments. You must supply map file and number of players.");
    }

    filename = argv[1];
    num_players = atoi(argv[2]);

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
            map[x][y] = Tile(type, resource, owner, i, j, false);
        }
    }
}

//Main game loop
void gameLoop(Tile** map)
{
    int turn;
}
