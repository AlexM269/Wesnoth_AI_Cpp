#include "Player.hpp"

using namespace std;

Player::Player(Map * map, sf::Texture* texture){
    m_map = map;
    m_units.push_back(new Unit(texture,4,5,true));
}

void Player::init() {
    m_map->init();
    for(Unit* ptr : m_units){
        ptr->init();
    }
}

void Player::update(sf::Vector2i localPosition,sf::Event event) {

    m_map->update();
    for(Unit* ptr : m_units){
        ptr->update(localPosition,event);
    }
}

void Player::draw(sf::RenderWindow* win) {
    m_map->draw(win);
    for(Unit* ptr : m_units){
        ptr->draw(win);
    }
}

int Player::Calcul_income() {
    return 0;
}