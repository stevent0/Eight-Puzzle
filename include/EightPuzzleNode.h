#pragma once
#include <vector>
#include <string>
#include "Node.h"

enum Heuristic {
    MANHATTAN_DISTANCE,
    MISPLACED_TILE,
    UNIFORM_COST_SEARCH
};

class EightPuzzleNode : public Node {

    public:
        EightPuzzleNode();
        EightPuzzleNode(EightPuzzleNode* node);
        bool isAtGoalState() const;
        double getHeuristicValue() const;
        std::string getState() const;
        std::vector<Node*> applyOperations();
        void setHeuristic(Heuristic heuristic);
    private:
        EightPuzzleNode* operation_shiftHorizontally(int direction);
        EightPuzzleNode* operation_shiftVertically(int direction);
        double calcManhattanDistance() const;
        double calcMisplacedTiles() const;
    private:
        std::vector<std::vector<char>> state;
        std::vector<int> blankSpotLocation;
        Heuristic heuristic = MANHATTAN_DISTANCE;

};