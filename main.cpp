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
void init(int argc, char** argv, Tile** map, vector<Player> players);
void gameLoop(Tile** map, vector<Player> players);

int main(int argc, char** argv)
{
    vector<Player> players;
    Tile** map;
    init(argc, argv, map, players);

    gameLoop(map, players);

    return 0;
}

void rageQuit(string s)
{
    cout << "Error: " << s << endl;
    exit(EXIT_ERR_CODE);
}

void init(int argc, char** argv, Tile** map, vector<Player> players)
{
    int x, y, num_players;
    int type, resource, owner;
    string filename, name;
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

    players.resize(num_players);
    for(int i = 0; i < num_players; i++)
    {
        cout << "Enter name for player " << i << ": ";
        cin >> name;
        players[i] = Player();
        players[i].addName(name);
    }
}

//Main game loop
void gameLoop(Tile** map, vector<Player> players)
{
    unsigned int turn = 0;
    Player currPlayer;
    vector<Combat> combats;

    //Main loop
    while(true)
    {
        currPlayer = players[turn];
        //1. Upkeep - Energy, collect resources
        currPlayer.upkeep();
        //2. Development - Research/energy harvester stuff
        currPlayer.develop();
        //3. Attack/Move - Declare all moves and attacks
        currPlayer.attack(combats);
        //4. Combat - Resolve all combats
        for (vector<Combat>::iterator it = combats.begin(); it!=combats.end(); ++it) {
            (*it).resolve();
        }

        turn++;
        if(turn >= players.size())
        {
            turn = 0;
        }
    }

}
