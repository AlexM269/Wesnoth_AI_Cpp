#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Map::Map(sf::RenderWindow * window, int N, int M, int * tab) {
    m_N = N;
    m_M = M;
    m_map = tab;
    m_window = window;
    /*for(int i =0;i<m_N*m_N;i++){
            printf("%d\n",m_map[i]);
    }*/
}

void Map::init() {
    double pi=3.14;
    if(!m_texture.loadFromFile("c:/Users/nolha/Documents/GitHub/Wesnoth_AI_Cpp/idees_map/brouillon.png")){
        std::cout << "claqué au sol";
    }
    for(int i =0;i<m_N;i++){
        for(int j =0;j<m_M;j++){
            m_sprites[i][j].setTexture(m_texture);
            m_sprites[i][j].setTextureRect(sf::IntRect(TILE_SIZE*m_map[i*m_M+j],0,TILE_SIZE,TILE_SIZE));
            //sf::CircleShape sprite(TILE_SIZE/2);
            //sprite.setTexture(&m_texture);
            //sprite.setTextureRect(sf::IntRect(TILE_SIZE*m_map[i*m_M+j],0,TILE_SIZE,TILE_SIZE));
            //m_sprites[i][j] = sprite;
            if(i%2 == 0){
                // On soustrait en y une cst pour que les hexagones s'emboitent = tan(60°)*(T_SIZE/2)
                m_sprites[i][j].setPosition(TILE_SIZE*j,TILE_SIZE*i- i*15);//(int)(std::tan(pi/6)*TILE_SIZE*0.5));
            }
            else{
                m_sprites[i][j].setPosition(TILE_SIZE*j+TILE_SIZE*0.5,TILE_SIZE*i-i*15);//(int)(std::tan(pi/6)*TILE_SIZE*0.5));
            }

        }
    }
}

void Map::update() {}

std::vector<int> Map::hitbox(int x, int y) {
    std::vector<int> res(2);
    res[0] = y/TILE_SIZE;
    res[1] = x/TILE_SIZE;
    return res;

}

void Map::draw() {
    for(int i =0;i<m_N;i++){
        for(int j =0;j<m_N;j++){
            m_window->draw(m_sprites[i][j]);
        }
    }
}