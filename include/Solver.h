#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "../include/Node.h"
#include <unordered_set>

class Solver {
    public:
        Solver(Node* node) : startingNode(node) {}
        void search() {
            std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
            std::unordered_set<std::string> us;

            pq.push(startingNode);
            while (!pq.empty()) {
                Node* node = pq.top(); pq.pop();
                if (!node) continue;
                stateTrace.push_back(node);
                if (node->isAtGoalState()) return;
                std::vector<Node*> nextNodes = node->applyOperations();
                for (Node* nextNode: nextNodes) {
                    std::string stateString = nextNode->getState();
                    if (us.count(stateString) == 0) {
                        pq.push(nextNode);
                        us.insert(stateString);
                    }
                }
            }
        }

    public:
        std::vector<Node*> stateTrace;
        Node* startingNode;
};