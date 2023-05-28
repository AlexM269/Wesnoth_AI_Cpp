#include "Player.hpp"

using namespace std;

Player::Player(Map * map, sf::Texture* texture, int id){
    m_texture = texture;
    m_map = map;
    smthg_selected =false;
    nb_villages =0;
    m_gold = 100;
    my_turn = 1-id;
    m_id = id;
}

void Player::init() {
    if(m_id == 0){
        m_units.push_back(new Unit(m_texture,0,0,true));
        m_map->putUnit(0,0);
    }
    if (m_id == 1){
        m_units.push_back(new Unit(m_texture,9,9,true));
        m_map->putUnit(9,9);
    }

    for(Unit* ptr : m_units){
        ptr->init();
    }
}


void Player::update(sf::Vector2i localPosition,sf::Event event) {
    // faudra foutre tout ce bordel dans des fct à un moment
    for(Unit* ptr : m_units){
        // gestion souris
        if (my_turn) {
            if (event.type == sf::Event::MouseButtonReleased) { // Released pour éviter que le recoive l'event tant qu'on reste appuyé sur la touche
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Si personnage sélectionner le déplacer après un clic à la case pointée par la souris
                    if ((*ptr).is_selected()) {
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 10; j++) {
                                if (hitbox(i, j, localPosition.x, localPosition.y)) {
                                    if (m_map->tile_is_free(i, j)) {
                                        if (i != (*ptr).getPI() or j != (*ptr).getPJ()) {
                                            m_map->deleteUnit((*ptr).getPI(), (*ptr).getPJ());
                                            (*ptr).move(i, j);
                                            m_map->putUnit(i, j);
                                            my_turn = false;
                                            if (m_map->getTileType(i, j) == Village_Vide) {
                                                nb_villages++;
                                                m_map->setTile(i, j, Village_J1);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // si la souris est sur la case du perso et que l'on clique il devient selectionné (et deselectionné)
                    if (hitbox((*ptr).getPI(), (*ptr).getPJ(), localPosition.x, localPosition.y) and
                        (*ptr).is_selected() == smthg_selected) {
                        (*ptr).set_selected(1 - (*ptr).is_selected());
                        smthg_selected = 1 - smthg_selected;
                    }
                }
            }
            // gestion du clavier
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::N) {
                    if ((*ptr).canRecrute(m_map)) {
                        for (std::vector<int> v: voisins((*ptr).getPI(), (*ptr).getPJ())) {
                            if (m_map->tile_is_free(v[0], v[1])) {
                                m_units.push_back(new Unit(m_texture, v[0], v[1], false));
                                m_units.back()->init();
                                m_map->putUnit(m_units.back()->getPI(), m_units.back()->getPJ());
                                my_turn = false;
                                break;
                            }
                        }
                    }
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
    int res = 2 + nb_villages - std::max(0,(int)m_units.size()-nb_villages);
    return res;
}

void Player::setTurn(bool b) {
    my_turn=b;
}

bool Player::is_turn() {
    return my_turn;
}

Player::~Player() {
    for(Unit* ptr : m_units){
        ptr->~Unit();
    }
}
