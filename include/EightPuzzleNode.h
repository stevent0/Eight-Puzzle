#include <vector>
#include <string>
#include "Node.h"

class EightPuzzleNode : public Node {

    public:
        EightPuzzleNode();
        EightPuzzleNode(EightPuzzleNode* node);
        bool isAtGoalState() const;
        double getHeuristicValue() const;
        std::string getState() const;
        std::vector<Node*> applyOperations();
    private:
        EightPuzzleNode* operation_shiftHorizontally(int direction);
        EightPuzzleNode* operation_shiftVertically(int direction);
    private:
        std::vector<std::vector<char>> state;
        std::vector<int> blankSpotLocation;

};