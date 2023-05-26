#include "Unit.hpp"

using namespace std;

Unit::Unit(sf::RenderWindow* window,sf::Texture* texture,int i,int j,bool hero){

    m_PI =i;
    m_PJ =j;

    int t_x,t_y =0; // position de la tuile x,y (ce sera à déplacer dans map après)
    double pi =3.14;
    if(m_PI%2==0){
        t_x =TILE_SIZE*m_PJ;
        t_y = TILE_SIZE*m_PI- m_PI*15;//(int)(std::tan(pi/6)*TILE_SIZE*0.5);
    }
    else{
        t_x = TILE_SIZE*m_PJ+TILE_SIZE*0.5;
        t_y = TILE_SIZE*m_PI-m_PI*15;//(int)(std::tan(pi/6)*TILE_SIZE*0.5);
    }
    m_PX = t_x;
    m_PY =t_y;

    is_the_hero = hero;
    m_window = window;
    m_texture = texture;

}

void Unit::init() {
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(m_PX,m_PY);
}

void Unit::update() {
    m_sprite.setPosition(m_PX,m_PY);
}

void Unit::draw() {
    m_window->draw(m_sprite);
}

bool Unit::move(int i,int j){
    m_PI =i;
    m_PJ =j;

    int t_x,t_y =0; // position de la tuile x,y (ce sera à déplacer dans map après)
    double pi =3.14;
    if(m_PI%2==0){
        t_x =TILE_SIZE*m_PJ;
        t_y = TILE_SIZE*m_PI- m_PI*15;//(int)(std::tan(pi/6)*TILE_SIZE*0.5);
    }
    else{
        t_x = TILE_SIZE*m_PJ+TILE_SIZE*0.5;
        t_y = TILE_SIZE*m_PI-m_PI*15;//(int)(std::tan(pi/6)*TILE_SIZE*0.5);
    }
    m_PX = t_x;
    m_PY =t_y;
    return true;
}

bool Unit::recrute() {
    if (is_the_hero){
        return true;
    }
    else{return false;}
}

Unit::~Unit() {

}
