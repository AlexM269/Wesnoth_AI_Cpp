#ifndef WESNOTH_AI_CPP_MAP_HPP
#define WESNOTH_AI_CPP_MAP_HPP
#include <SFML/Graphics.hpp>
#define TILE_SIZE 32
class Map {
public:
    Map(int tab [10][10], sf::RenderWindow * window);
    void init();
    void update();
    void draw();
private:
    int m_map [10][10];
    sf::Texture m_texture;
    sf::RenderWindow* m_window;
    sf::Sprite m_sprites [10][10];
};


#endif //WESNOTH_AI_CPP_MAP_HPP
