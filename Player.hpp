#ifndef WESNOTH_AI_CPP_PLAYER_H
#define WESNOTH_AI_CPP_PLAYER_H

#include "Unit.hpp"
#include "Map.hpp"
#include "list"

using namespace std;

class Player {
public:
    Player(Map * map, sf::Texture* texture, int id);
    void init();
    void update(sf::Vector2i localPosition, sf::Event event);
    void draw(sf::RenderWindow* win);
    int Calcul_income();
    void setTurn(bool b);
    bool is_turn();
    ~Player();

private:
    Map* m_map;
    sf::Texture* m_texture;
    list<Unit*> m_units;
    bool smthg_selected;
    int nb_villages;
    int m_gold;
    bool my_turn;
    int m_id;
};


#endif
