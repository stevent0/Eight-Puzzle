#pragma once
#include <vector>
#include <string>

class Node {
    public:
        virtual bool isAtGoalState() const = 0;
        virtual std::vector<Node*> applyOperations() = 0;
        virtual double getHeuristicValue() const = 0;
        virtual std::string getState() const = 0;
        virtual double getCost() const { return accumulatedCost; }      
        void addCost(int cost) { accumulatedCost += cost; }
    private:
        double accumulatedCost = 0;
};

struct Compare {
    bool operator()(const Node* A, const Node* B) {
        double estimatedCostA = A->getHeuristicValue() + A->getCost();
        double estimatedCostB = B->getHeuristicValue() + B->getCost();
        return estimatedCostA > estimatedCostB;
    }
};

