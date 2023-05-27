#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utilitaire.hpp"

Map::Map(sf::Texture * texture, int N, int M, int * tab) {
    m_N = N;
    m_M = M;
    m_map = tab;
    m_texture = texture;
}

void Map::init() {
    for(int i =0;i<m_N;i++){
        for(int j =0;j<m_M;j++){

            m_sprites[i][j].setTexture(*m_texture);
            m_sprites[i][j].setTextureRect(sf::IntRect(TILE_SIZE*m_map[i*m_M+j],0,TILE_SIZE,TILE_SIZE));

            /*sf::CircleShape sprite(TILE_SIZE/2);
            sprite.setTexture(&m_texture);
            sprite.setTextureRect(sf::IntRect(TILE_SIZE*m_map[i*m_M+j],0,TILE_SIZE,TILE_SIZE));
            m_sprites[i][j] = sprite;*/

            std::vector<int> position = coordonnesIJtoXY(i,j);
            m_sprites[i][j].setPosition(position[0],position[1]);


        }
    }
}

void Map::update() {}

void Map::draw(sf::RenderWindow* win) {
    for(int i =0;i<m_N;i++){
        for(int j =0;j<m_N;j++){
            win->draw(m_sprites[i][j]);
        }
    }
}

TYPE_TERRAINS Map::getTileType(int i, int j) {
    TYPE_TERRAINS res;
    switch(int a = i*m_M+j){
        case 0:
            res =Chateau;
        case 1:
            res = Village_vide;
        case 2:
            res = Village_J1;
        case 3 :
            res = Village_J2;
        case 4:
            res = Plaine;
        default:
            res = Chateau;
    }
}