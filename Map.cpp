#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Map::Map(int tab[10][10], sf::RenderWindow * window) {
    for(int i =0;i<10;i++){
        for(int j =0;j<10;j++){
            m_map[i][j] = tab[i][j];
        }
    }
    m_window = window;
}

void Map::init() {
    if(!m_texture.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/map.png")){
        std::cout << "claqué au sol";
    }
    for(int i =0;i<10;i++){
        for(int j =0;j<10;j++){
            m_sprites[i][j].setTexture(m_texture);
        }
    }
}

void Map::update() {
    for(int i =0;i<10;i++){
        for(int j =0;j<10;j++){
            m_sprites[i][j].setTextureRect(sf::IntRect(0,32*m_map[i][j],32,32));
            m_sprites[i][j].setPosition(32*i,32*j);
        }
    }
}

void Map::draw() {
    for(int i =0;i<10;i++){
        for(int j =0;j<10;j++){
            m_window->draw(m_sprites[i][j]);
        }
    }
}