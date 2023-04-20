#ifndef WESNOTH_AI_CPP_PLAYER_H
#define WESNOTH_AI_CPP_PLAYER_H

#include "Unit.hpp"
#include "list"

using namespace std;

class Player {
public:
    Player(int id);
    int Calcul_income();

private:
    int id;
    int nbUnits;
    list<Unit> listUnits;
};


#endif
