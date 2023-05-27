#ifndef WESNOTH_AI_CPP_PLAYER_H
#define WESNOTH_AI_CPP_PLAYER_H

#include "Unit.hpp"
#include "Map.hpp"
#include "list"

using namespace std;

class Player {
public:
    Player(Map * map, sf::Texture* texture);
    void init();
    void update(sf::Vector2i localPosition, sf::Event event);
    void draw(sf::RenderWindow* win);
    int Calcul_income();

private:
    Map* m_map;
    list<Unit*> m_units;
};


#endif
