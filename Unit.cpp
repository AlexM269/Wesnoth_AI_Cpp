#include "Unit.hpp"

using namespace std;

Unit::Unit(int x,int y,int id, bool hero){
    m_x = x;
    m_y = y;
    m_id = id;
    is_the_hero = hero;
}

Unit::move(){

}

bool Unit::recrute() {
    if (is_the_hero){

    }
    else{return false;}
}

Unit::~Unit() {

}
