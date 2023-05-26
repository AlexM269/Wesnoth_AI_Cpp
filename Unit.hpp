#ifndef WESNOTH_AI_CPP_UNIT_H
#define WESNOTH_AI_CPP_UNIT_H
#define TILE_SIZE 80
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Tile.hpp"
#include "Utilitaire.hpp"

class Unit {
public:
    Unit(sf::RenderWindow* window,sf::Texture* texture,int x,int y,bool hero=false);
    bool move(int i, int j);
    bool recrute();
    void init();
    void update();
    void draw();
    ~Unit();

private:
    int m_PI;
    int m_PJ;
    int m_PX;
    int m_PY;
    bool is_the_hero;
    sf::RenderWindow* m_window;
    sf::Texture* m_texture;
    sf::Sprite m_sprite;
};


#endif
