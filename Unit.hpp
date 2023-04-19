#ifndef WESNOTH_AI_CPP_UNIT_H
#define WESNOTH_AI_CPP_UNIT_H


class Unit {
public:
    Unit(int x,int y,int id, bool hero);
    bool move();
    bool recrute();
    ~Unit();

private:
    int m_x;
    int m_y;
    int m_id;
    bool is_the_hero;
};


#endif
