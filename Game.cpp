//
// Created by Nolhan on 29/05/2023.
//

#include "Game.hpp"

Game::Game(state s) {
    m_s = s;
}

int Game::current_player(state s) {
    return s.currentPlayer;
}

state Game::next_state(state s, int play) {

}