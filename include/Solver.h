#pragma once
#include "../include/Node.h"

class Solver {
    public:
        Solver(Node* node) : startingNode(node) {}
        void search();
        void printStateTrace();
    public:
        std::vector<Node*> stateTrace;
        Node* startingNode;
};