//
// Created by Nolhan on 29/05/2023.
//

#include "Node.hpp"
using namespace std;


Node::Node(State s) {
    state = s;
    n = 0;
    t = 0;
}

list<Node*> Node::getFils() {
    return fils;
}

Node* Node::getPere() {
    return pere;
}

void Node::incrementerN() {
    n++;
}

void Node::addToT(int ad) {
    t+=ad;
}