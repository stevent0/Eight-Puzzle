#pragma once
#include <vector>
#include <string>
#include "Node.h"

enum class EightPuzzleHeuristic {
    MANHATTAN_DISTANCE,
    MISPLACED_TILE,
    UNIFORM_COST_SEARCH
};

class EightPuzzleNode : public Node {

    public:
        EightPuzzleNode();
        EightPuzzleNode(const EightPuzzleNode& node);
        bool isAtGoalState() const;
        std::string getState() const;
        std::vector<Node*> applyOperations() const;
        void setHeuristic(EightPuzzleHeuristic heuristic);
        void setState(const std::vector<char>& tileNumbers);
    protected:
        double getHeuristicValue() const;
    private:
        EightPuzzleNode* operation_shiftHorizontally(int direction) const;
        EightPuzzleNode* operation_shiftVertically(int direction) const;
        double calcManhattanDistance() const;
        double calcMisplacedTiles() const;
    private:
        std::vector<std::vector<char>> state;
        std::vector<int> blankSpotLocation;
        EightPuzzleHeuristic heuristic = EightPuzzleHeuristic::MANHATTAN_DISTANCE;

};