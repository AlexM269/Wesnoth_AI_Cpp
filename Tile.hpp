#ifndef WESNOTH_AI_CPP_TILE_HPP
#define WESNOTH_AI_CPP_TILE_HPP

using namespace std;

class Tile {
public:
    enum Type {Plain = 0,Mountain,River,Village};
    Tile(int x,int y,Type t);
    bool is_a_plain();
    bool is_a_mountain_or_river();
    bool is_a_village();
    bool is_village_empty();
    bool empty_village();

private:
    int m_x;
    int m_y;
    Type m_type;
    bool m_emptied;
};


#endif
