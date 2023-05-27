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
    m_key_pressed =false;

}

void Unit::init() {
    m_sprite.setTexture(*m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,TILE_SIZE,TILE_SIZE));
    m_sprite.setPosition(m_PX,m_PY);
}

void Unit::update(sf::Vector2i localPosition, sf::Event event) {
    if (event.type == sf::Event::MouseButtonReleased){ // Released pour éviter que le recoive l'event tant qu'on reste appuyé sur la touche
        if(event.mouseButton.button == sf::Mouse::Left){
            // Si personnage sélectionner le déplacer après un clic à la case pointée par la souris
            if(m_selected){
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (hitbox(i, j, localPosition.x, localPosition.y)) {
                            move(i, j);
                        }
                    }
                }
            }
            // si la souris est sur la case du perso et que l'on clique il devient selectionné (et deselectionné)
            if(hitbox(m_PI, m_PJ, localPosition.x, localPosition.y)) {
                m_selected = 1 - m_selected;
            }
        }
    }
    // changement du sprite selon la selection
    m_sprite.setTextureRect(sf::IntRect(TILE_SIZE*m_selected,0,TILE_SIZE,TILE_SIZE));
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

bool Unit::recrute() {
    if (is_the_hero){
        return true;
    }
    else{return false;}
}

Unit::~Unit() {

}
