#ifndef WESNOTH_AI_CPP_MAP_HPP
#define WESNOTH_AI_CPP_MAP_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Utilitaire.hpp"
class Map {
public:
    Map(sf::Texture * texture, int N,int M,int * tab);
    void init();
    void update();
    void draw(sf::RenderWindow* win);
    TYPE_TERRAINS getTileType(int i, int j);
private:
    int m_N;
    int m_M;
    int* m_map;
    sf::Texture* m_texture;
    sf::Sprite m_sprites [10][10];
    //sf::CircleShape m_sprites [10][10];
};


#endif //WESNOTH_AI_CPP_MAP_HPP
