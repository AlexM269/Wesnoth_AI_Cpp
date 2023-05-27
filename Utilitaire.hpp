

#ifndef WESNOTH_AI_CPP_UTILITAIRE_HPP
#define WESNOTH_AI_CPP_UTILITAIRE_HPP
#include <vector>
#include <list>
#define TILE_SIZE 80

// fonction permettant d'obtenir les positions x et y du sprite correspondant à la tuile i,j
std::vector<int> coordonnesIJtoXY(int i,int j);

// fonction permettant de trouver quelle tuile i,j correspond à celle pointée par la souris
bool hitbox(int i,int j,int x,int y);

// fonction permettant de récupérer les coordonnées des 6 voisins
std::list<std::vector<int>> voisins(int i, int j);

enum TYPE_TERRAINS{
    Chateau = 0,
    Village_Vide = 1,
    Village_J1 = 2,
    Autre = 3,
};

#endif //WESNOTH_AI_CPP_UTILITAIRE_HPP
