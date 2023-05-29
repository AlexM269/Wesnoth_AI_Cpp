//
// Created by Nolhan on 29/05/2023.
//

#ifndef WESNOTH_AI_CPP_MCTS_HPP
#define WESNOTH_AI_CPP_MCTS_HPP


#include "Node.hpp"

class MCTS {
public:
    MCTS();
    int getNextMove();
private:
    Node racine;
};


#endif //WESNOTH_AI_CPP_MCTS_HPP
