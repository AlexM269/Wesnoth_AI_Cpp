#include "Unit.hpp"

using namespace std;

Unit::Unit(Tile t,int id, bool hero):m_tile(t){
    m_id = id;
    is_the_hero = hero;
}

bool Unit::move(){
    return true;
}

bool Unit::recrute() {
    if (is_the_hero){
        return true;
    }
    else{return false;}
}

Unit::~Unit() {

}
