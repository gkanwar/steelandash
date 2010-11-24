/*
 * File: main.cpp
 * --------------------------------
 * Entry point for the program.
 */

#include <string>
#include <fstream>
#include <vector>

using namespace std;


struct unit
{
    int type;
    int owner;
    int a_val, d_val;
};

class attack
{
  private:
    unit p_attacker;
    unit p_defender;
    vector<unit> s_attacker;
    vector<unit> s_defender;

  public:
    attack()
    {
        s_attacker.resize(0);
        s_defender.resize(0);
    }
    attack(unit p_a, unit p_d)
    {
        p_attacker = p_a;
        p_defender = p_d;
    }

    void addDefender(unit s_d)
    {
        s_defender.push_back(s_d);
    }
    void addAttacker(unit s_a)
    {
        s_attacker.push_back(s_a);
    }
    void resolve()
    {
        //Do something
    }
};

class tile
{
  private:
    int type, resource;
    bool e_harvester;
    vector<unit> unit_stack;

  public:
    tile()
    {
        type = 0;
        resource = 0;
        e_harvester = false;
        unit_stack.resize(0);
    }
    tile(int t, int r, bool e_h, vector<unit> unit_stack_copy)
    {
        type = t;
        resource = r;
        e_harvester = e_h;
        unit_stack = unit_stack_copy;
    }

    void setType(int t)
    {
        type = t;
    }
    void setHarvester(bool e_h)
    {
        e_harvester = e_h;
    }
    void setUnitStack(vector<unit> unit_stack_copy)
    {
        unit_stack = unit_stack_copy;
    }
    void addUnit(unit u)
    {
        unit_stack.push_back(u);
    }
};


int main (int argc, char** argv)
{
    string filename;
    ifstream mapf;

    int x, y;
    tile** map;

    if(argc > 1)
    {
        filename = argv[1];
    }
    mapf.open(filename.c_str(), ifstream::in);

    mapf >> x >> y;

    map = new tile*[x];
    for(int i = 0; i < x; i++)
    {
        map[i] = new tile[y];
    }


}
