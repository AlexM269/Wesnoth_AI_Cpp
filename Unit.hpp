#ifndef WESNOTH_AI_CPP_UNIT_H
#define WESNOTH_AI_CPP_UNIT_H
#define TILE_SIZE 80
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Tile.hpp"
#include "Utilitaire.hpp"

class Unit {
public:
    Unit(sf::Texture* texture,int i,int j,bool hero=false);
    bool move(int i, int j);
    bool recrute();
    void init();
    void update(sf::Vector2i localPosition,sf::Event event);
    void draw(sf::RenderWindow* win);
    ~Unit();

private:
    int id;
    int m_PI;
    int m_PJ;
    int m_PX;
    int m_PY;
    bool is_the_hero;
    bool m_selected;
    bool m_key_pressed;
    sf::Texture* m_texture;
    sf::Sprite m_sprite;
};


#endif
