#pragma once
#include "../include/Node.h"
#include <unordered_map>
#include <unordered_set>
#include <string>

class Solver {
    public:
        Solver(Node* node) : startingNode(node) {}
        void search();
        void printSolutionPath();
    public:
        std::unordered_map<Node*, Node*> um;  //key=state, value=parent state
        Node* startingNode;
        Node* endingNode;
};