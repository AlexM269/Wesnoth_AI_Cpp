#include "Utilitaire.hpp"

std::vector<int> coordonnesIJtoXY(int i,int j){
    int t_x, t_y = 0;
    double pi = 3.14;

    std::vector<int> res(2);

    // On soustrait en y une cst pour que les hexagones s'emboitent = tan(60°)*(T_SIZE/2)
    if (i % 2 == 0) {
        t_x = TILE_SIZE * j;
        t_y = TILE_SIZE * i - i * 15;//(int)(std::tan(pi/6)*TILE_SIZE*0.5);
    }
    else {
        t_x = TILE_SIZE * j + TILE_SIZE * 0.5;
        t_y = TILE_SIZE * i - i * 15;//(int)(std::tan(pi/6)*TILE_SIZE*0.5);
    }
    res[0] = t_x;
    res[1] = t_y;
    return res;
}

bool hitbox(int i, int j,int x, int y){
    std::vector<int> position = coordonnesIJtoXY(i,j);
    int t_x = position[0];
    int t_y = position[1];

    if (x >= t_x and x <= t_x + TILE_SIZE and y >= t_y and y <= t_y + TILE_SIZE) {
        if (x < t_x + TILE_SIZE / 2) {
            if (y >= 15 - (15 / TILE_SIZE * 0.5) * x and y <= TILE_SIZE - 15 + (15 / TILE_SIZE * 0.5) * x);
            return true;
        }
        else if (x >= t_x + TILE_SIZE / 2) {
            if (y >= 15 - (15 / TILE_SIZE * 0.5) * (TILE_SIZE - x) and
            y <= TILE_SIZE - 15 + (15 / TILE_SIZE * 0.5) * (TILE_SIZE - x));
            return true;
        }
    }
    return false;
}

std::list<std::vector<int>> voisins(int i, int j){
    std::list<std::vector<int>> res;
    //res.push_back()
}