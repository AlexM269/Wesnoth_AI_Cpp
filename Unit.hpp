#ifndef WESNOTH_AI_CPP_UNIT_H
#define WESNOTH_AI_CPP_UNIT_H
#define TILE_SIZE 80
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Tile.hpp"
#include "Utilitaire.hpp"
#include "Map.hpp"
class Unit {
public:
    Unit(sf::Texture* texture,int i,int j,bool hero=false);
    bool move(int i, int j);
    bool is_selected();
    void set_selected(bool b);
    int getPI();
    int getPJ();
    bool canRecrute(Map* m);
    void init();
    void update();
    void draw(sf::RenderWindow* win);
    ~Unit();

private:
    int m_PI;
    int m_PJ;
    int m_PX;
    int m_PY;
    bool is_the_hero;
    bool m_selected;
    sf::Texture* m_texture;
    sf::Sprite m_sprite;
};


#endif
