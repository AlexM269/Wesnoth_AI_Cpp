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
    m_selected =false;
    m_key_pressed =false;

}

void Unit::init() {
    m_sprite.setTexture(*m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,TILE_SIZE,TILE_SIZE));
    m_sprite.setPosition(m_PX,m_PY);
}

void Unit::update() {
    sf::Vector2i localPosition = sf::Mouse::getPosition(*m_window);

    if(!m_key_pressed) {
        if(m_selected){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (hitbox(i, j, localPosition.x, localPosition.y)) {
                            move(i, j);
                        }
                    }
                }
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(hitbox(m_PI, m_PJ, localPosition.x, localPosition.y)) {
                m_selected = 1 - m_selected;
            }
        }
    }

    if(!m_key_pressed){

    }
    if(m_selected){
        m_sprite.setTextureRect(sf::IntRect(TILE_SIZE,0,TILE_SIZE,TILE_SIZE));
    }
    else{
        m_sprite.setTextureRect(sf::IntRect(0,0,TILE_SIZE,TILE_SIZE));
    }
    m_sprite.setPosition(m_PX,m_PY);
    m_key_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
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
