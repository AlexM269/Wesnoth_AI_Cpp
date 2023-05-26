#include "Unit.hpp"

using namespace std;

Unit::Unit(sf::RenderWindow* window,sf::Texture* texture,int i,int j,bool hero){

    m_PI =i;
    m_PJ =j;

    std::vector<int> res = coordonnesIJtoXY(i,j);
    m_PX = res[0];
    m_PY =res[1];

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

    std::vector<int> res = coordonnesIJtoXY(i,j);
    m_PX = res[0];
    m_PY =res[1];

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
