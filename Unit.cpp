#include "Unit.hpp"
using namespace std;

Unit::Unit(sf::Texture* texture,int i,int j,bool hero){

    m_PI =i;
    m_PJ =j;

    std::vector<int> res = coordonnesIJtoXY(i,j);
    m_PX = res[0];
    m_PY =res[1];

    is_the_hero = hero;
    m_texture = texture;
    m_selected =false;

}

void Unit::init() {
    m_sprite.setTexture(*m_texture);
    m_sprite.setTextureRect(sf::IntRect(TILE_SIZE*m_selected,TILE_SIZE*is_the_hero,TILE_SIZE,TILE_SIZE));
    m_sprite.setPosition(m_PX,m_PY);
}

void Unit::update() {
    // changement du sprite selon la selection
    m_sprite.setTextureRect(sf::IntRect(TILE_SIZE*m_selected,TILE_SIZE*is_the_hero,TILE_SIZE,TILE_SIZE));
    m_sprite.setPosition(m_PX,m_PY);
}


void Unit::draw(sf::RenderWindow* win) {
    win->draw(m_sprite);
}

bool Unit::move(int i,int j){

    m_PI =i;
    m_PJ =j;

    std::vector<int> res = coordonnesIJtoXY(i,j);
    m_PX = res[0];
    m_PY =res[1];

    return true;
}

bool Unit::is_selected() {
    return m_selected;
}

void Unit::set_selected(bool b) {
    m_selected=b;
}

int Unit::getPI() {
    return m_PI;
}

int Unit::getPJ() {
    return m_PJ;
}

bool Unit::canRecrute(Map* map) {
    return is_the_hero and (map->getTileType(m_PI,m_PJ)==Chateau);
}

Unit::~Unit() {

}
