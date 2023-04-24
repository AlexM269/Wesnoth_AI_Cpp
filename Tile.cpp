#include "Tile.hpp"

Tile::Tile(int x,int y,Type t){
    m_x = x;
    m_y = y;
    m_type = t;
    m_emptied = 0;
}

bool Tile::is_a_plain(){
    return m_type == 0;
}

bool Tile::is_a_mountain_or_river(){
    return m_type == 1 || m_type == 2;
}

bool Tile::is_a_village(){
    return m_type == 3;
}

bool Tile::is_village_empty(){
    return m_emptied;
}

bool Tile::empty_village() {
    m_emptied = 1;
}