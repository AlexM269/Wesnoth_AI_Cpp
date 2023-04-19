#ifndef WESNOTH_AI_CPP_UNIT_H
#define WESNOTH_AI_CPP_UNIT_H


class Unit {
public:
    Unit::Unit();
    Unit::move();

private:
    int m_X;
    int m_Y;
    int m_id;
};


#endif
