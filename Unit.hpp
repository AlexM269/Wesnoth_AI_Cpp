#ifndef WESNOTH_AI_CPP_UNIT_H
#define WESNOTH_AI_CPP_UNIT_H


#include "Tile.hpp"

class Unit {
public:
    Unit(Tile tile, int id, bool hero);
    bool move();
    bool recrute();
    ~Unit();

private:
    Tile m_tile;
    int m_id;
    bool is_the_hero;
};


#endif
