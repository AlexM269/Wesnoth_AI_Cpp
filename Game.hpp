//
// Created by Nolhan on 29/05/2023.
//

#ifndef WESNOTH_AI_CPP_GAME_HPP
#define WESNOTH_AI_CPP_GAME_HPP

#include "Map.hpp"
#include "Player.hpp"
# include "Utilitaire.hpp"

class Game {
public:

    Game(state s);
    state start();
    int current_player(state s);
    state next_state(state s, int play);
    int legal_plays(state s);
    int winner(state s);

private:
    state m_s;
};


#endif //WESNOTH_AI_CPP_GAME_HPP
