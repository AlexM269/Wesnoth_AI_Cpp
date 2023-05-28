#ifndef WESNOTH_AI_CPP_PLAYER_H
#define WESNOTH_AI_CPP_PLAYER_H

#include "Unit.hpp"
#include "Map.hpp"
#include "list"

using namespace std;

class Player {
public:
    Player(Map * map, sf::Texture* texture,sf::Font* font, int id);
    void init();
    void update(sf::Vector2i localPosition, sf::Event event);
    void draw(sf::RenderWindow* win);
    int Calcul_income();
    void setTurn();
    bool is_turn();
    void setAdversary(Player* player);
    void addUnit(Unit* u);
    void selectUnit();
    void Attackwith();
    Unit* getUnit(int i, int j);
    ~Player();

private:
    Map* m_map;
    sf::Texture* m_texture;
    list<Unit*> m_units;
    sf::Font* m_font;
    Player* m_adversary;
    TYPE_TERRAINS Village_Adverse;
    TYPE_TERRAINS Village;
    bool smthg_selected;
    int nb_villages;
    int m_gold;
    bool my_turn;
    int m_id;
};


#endif
