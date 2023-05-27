#include "Player.hpp"

using namespace std;

Player::Player(Map * map, sf::Texture* texture){
    m_texture = texture;
    m_map = map;
    smthg_selected =false;
}

void Player::init() {
    m_units.push_back(new Unit(m_texture,4,5,true));
    m_map->putUnit(4,5);
    for(Unit* ptr : m_units){
        ptr->init();
    }
}

void Player::update(sf::Vector2i localPosition,sf::Event event) {

    for(Unit* ptr : m_units){
        // gestion souris
        if (event.type == sf::Event::MouseButtonReleased){ // Released pour éviter que le recoive l'event tant qu'on reste appuyé sur la touche
            if(event.mouseButton.button == sf::Mouse::Left){
                // Si personnage sélectionner le déplacer après un clic à la case pointée par la souris
                if((*ptr).is_selected()){
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 10; j++) {
                            if (hitbox(i, j, localPosition.x, localPosition.y)) {
                                if(m_map->tile_is_free(i,j)){
                                    m_map->deleteUnit((*ptr).getPI(),(*ptr).getPJ());
                                    (*ptr).move(i, j);
                                    m_map->putUnit(i,j);
                                }
                            }
                        }
                    }
                }
                // si la souris est sur la case du perso et que l'on clique il devient selectionné (et deselectionné)
                if(hitbox((*ptr).getPI(), (*ptr).getPJ(), localPosition.x, localPosition.y) and (*ptr).is_selected()==smthg_selected) {
                    (*ptr).set_selected(1-(*ptr).is_selected());
                    smthg_selected = 1-smthg_selected;

                }
            }
        }
        // gestion du clavier
        if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::N){
                printf("%d\n",(*ptr).canRecrute(m_map));
                if((*ptr).canRecrute(m_map)){
                    m_units.push_back(new Unit(m_texture,(*ptr).getPI()+1,(*ptr).getPJ(),false));
                    m_units.back()->init();
                    m_map->putUnit(m_units.back()->getPI(),m_units.back()->getPJ());
                }
            }
        }

        ptr->update();
    }
}

void Player::draw(sf::RenderWindow* win) {
    for(Unit* ptr : m_units){
        ptr->draw(win);
    }
}

int Player::Calcul_income() {
    return 0;
}