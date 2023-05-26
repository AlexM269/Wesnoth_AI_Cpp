

#ifndef WESNOTH_AI_CPP_UTILITAIRE_HPP
#define WESNOTH_AI_CPP_UTILITAIRE_HPP
#include <vector>
#define TILE_SIZE 80

// fonction permettant d'obtenir les positions x et y du sprite correspondant à la tuile i,j
std::vector<int> coordonnesIJtoXY(int i,int j);

// fonction permettant de trouver quelle tuile i,j correspond à celle pointée par la souris
bool hitbox(int i,int j,int x,int y);

#endif //WESNOTH_AI_CPP_UTILITAIRE_HPP
