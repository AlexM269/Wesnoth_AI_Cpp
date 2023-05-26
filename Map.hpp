#ifndef WESNOTH_AI_CPP_MAP_HPP
#define WESNOTH_AI_CPP_MAP_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#define TILE_SIZE 80
class Map {
public:
    Map(sf::RenderWindow * window, int N,int M,int * tab);
    void init();
    void update();
    void draw();
    static std::vector<int> hitbox(int x,int y);
private:
    int m_N;
    int m_M;
    int* m_map{};
    sf::Texture m_texture;
    sf::RenderWindow* m_window;
    sf::Sprite m_sprites [10][10];
    //sf::CircleShape m_sprites [10][10];
};


#endif //WESNOTH_AI_CPP_MAP_HPP
