#include "../include/Solver.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

void Solver::search() {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    std::unordered_set<std::string> us;

    pq.push(startingNode);
    while (!pq.empty()) {
        Node* node = pq.top(); pq.pop();
        if (!node) continue;
        if (node->isAtGoalState()) {
            endingNode = node;
            return;
        }
        std::vector<Node*> nextNodes = node->applyOperations();
        for (Node* nextNode: nextNodes) {
            std::string stateString = nextNode->getState();
            if (us.count(stateString) == 0) {
                pq.push(nextNode);
                us.insert(stateString);
                um[nextNode] = node;
            }
        }
    }
}

void Solver::printSolutionPath() {

    std::stack<Node*> solutionPath;
    Node* currentNode = endingNode;


    if (startingNode && currentNode) {

        std::string startingState = startingNode->getState();
        std::string currentState = currentNode->getState();

        while (startingState != currentState) {
            solutionPath.push(currentNode);
            currentNode = um[currentNode];
            currentState = currentNode->getState();
        }

        while (!solutionPath.empty()) {
            std::cout << solutionPath.top()->getState() << std::endl;
            solutionPath.pop();
        }

        
    }
    else {
        std::cout << "Solution path does not exist" << std::endl;
    }
}