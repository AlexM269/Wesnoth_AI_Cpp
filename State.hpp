#ifndef WESNOTH_AI_CPP_STATE_HPP
#define WESNOTH_AI_CPP_STATE_HPP


#include "Player.hpp"
#include "Map.hpp"

class State {
public:

private:
    list<Unit*> m_units0;
    list<Unit*> m_units1;

    int m_gold0;
    int m_gold1;

    int m_village1;
    int m_village2;

    Map m_map;
    int currentPlayer;

};


#endif
