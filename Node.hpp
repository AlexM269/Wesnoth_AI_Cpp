//
// Created by Nolhan on 29/05/2023.
//

#ifndef WESNOTH_AI_CPP_NODE_HPP
#define WESNOTH_AI_CPP_NODE_HPP


#include <list>
#include "State.hpp"

class Node {
public:
    Node(State s);
    std::list<Node>getFils();
    void incrementerN();
    void addToT(int t);
private:
    int n;
    int t;
    State state;
    std::list<Node> fils;
};


#endif //WESNOTH_AI_CPP_NODE_HPP
