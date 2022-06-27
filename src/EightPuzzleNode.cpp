#include "../include/EightPuzzleNode.h"

EightPuzzleNode::EightPuzzleNode() {
    state = std::vector<std::vector<char>>(3);
    state.at(0) = std::vector<char> {'1', '3', '6'};
    state.at(1) = std::vector<char> {'5', '-', '7'};
    state.at(2) = std::vector<char> {'4', '8', '2'};

    for (int row = 0; row < state.size(); ++row) {
        for (int col = 0; col < state.at(0).size(); ++col) {
            if (state.at(row).at(col) == '-') {
                blankSpotLocation = std::vector<int> {row, col};
            }
        }
    }
}

EightPuzzleNode::EightPuzzleNode(EightPuzzleNode* node) {
    this->addCost(node->getCost());
    state = node->state;
    blankSpotLocation = node->blankSpotLocation;
}

bool EightPuzzleNode::isAtGoalState() const {

    for (int row = 0; row < state.size(); ++row) {
        for (int col = 0; col < state.at(0).size(); ++col) {
            if (state.at(row).at(col) != '-') {
                int number = state.at(row).at(col) - '0';
                int expectedNumber = (3*row + col) + 1;
                if (number != expectedNumber) return false;
            }
        }
    }

    return true;
}

std::vector<Node*> EightPuzzleNode::applyOperations() {

    EightPuzzleNode* left = operation_shiftHorizontally(-1);
    EightPuzzleNode* right = operation_shiftHorizontally(1);
    EightPuzzleNode* up = operation_shiftVertically(1);
    EightPuzzleNode* down = operation_shiftVertically(-1);
    std::vector<Node*> nextStates;

    if (left) nextStates.push_back(left);
    if (right) nextStates.push_back(right);
    if (up) nextStates.push_back(up);
    if (down) nextStates.push_back(down);

    return nextStates;
}

double EightPuzzleNode::getHeuristicValue() const {


    std::vector<std::vector<int>> map(10); //key=tile number, value=correct (row, col) for a solved eight puzzle
    double heuristicValue = 0;
    map.at(1) = std::vector<int> {0, 0};
    map.at(2) = std::vector<int> {0, 1};
    map.at(3) = std::vector<int> {0, 2};
    map.at(4) = std::vector<int> {1, 0};
    map.at(5) = std::vector<int> {1, 1};
    map.at(6) = std::vector<int> {1, 2};
    map.at(7) = std::vector<int> {2, 0};
    map.at(8) = std::vector<int> {2, 1};
    map.at(9) = std::vector<int> {2, 2};

    for (int row = 0; row < state.size(); ++row) {
        for (int col = 0; col < state.at(0).size(); ++col) {

            if (state.at(row).at(col) != '-') {
                int tileNumber = state.at(row).at(col) - '0';
                int horizontalDistance = abs(map.at(tileNumber).at(1) - col);
                int verticalDistance = abs(map.at(tileNumber).at(0) - row);
                heuristicValue += (horizontalDistance + verticalDistance);       
            }

        }
    }

    return heuristicValue;

    // int count = 0;

    // for (int row = 0; row < state.size(); ++row) {
    //     for (int col = 0; col < state.at(0).size(); ++col) {
    //         int n = state.at(row).at(col) - '0';
    //         int expectedNumber = (3*row + col) + 1;
    //         if (n != expectedNumber) {
    //             ++count;
    //         }
    //     }
    // }

    // return count;

}

std::string EightPuzzleNode::getState() const {

    std::string stateString = "=============\n";

    for (int row = 0; row < 3; ++row) {

        stateString += "| ";

        for (int col = 0; col < 3; ++col) {
            char tileNum = state.at(row).at(col);
            stateString += std::string(1, tileNum);
            if (col != 2) {
                stateString += " |";
            }
        }

        stateString += "\n";
    }

    stateString += "=============\n";

    return stateString;
    

}

EightPuzzleNode* EightPuzzleNode::operation_shiftHorizontally(int direction) {

    EightPuzzleNode* nextState = nullptr;
    int blankSpotRowIndex = this->blankSpotLocation.at(0);
    int blankSpotColIndex = this->blankSpotLocation.at(1);

    if (direction == -1 && blankSpotColIndex-1 >= 0) { //left

        nextState = new EightPuzzleNode(this);

        int a = nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex);
        int b = nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex-1);

        nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex) = b;
        nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex-1) = a;

        nextState->blankSpotLocation.at(1) -= 1;
        nextState->addCost(1);
    }
    else if (direction == 1 &&  blankSpotColIndex+1 < state.at(0).size()) { //right

        nextState = new EightPuzzleNode(this);

        int a = nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex);
        int b = nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex+1);

        nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex) = b;
        nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex+1) = a;

        nextState->blankSpotLocation.at(1) += 1;
        nextState->addCost(1);
    }


    return nextState;
}


EightPuzzleNode* EightPuzzleNode::operation_shiftVertically(int direction) {

    EightPuzzleNode* nextState = nullptr;
    int blankSpotRowIndex = this->blankSpotLocation.at(0);
    int blankSpotColIndex = this->blankSpotLocation.at(1);

    if (direction == 1 && blankSpotRowIndex-1 >= 0 ) { //up

        nextState = new EightPuzzleNode(this);
        int a = nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex);
        int b = nextState->state.at(blankSpotRowIndex-1).at(blankSpotColIndex);


        nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex) = b;
        nextState->state.at(blankSpotRowIndex-1).at(blankSpotColIndex) = a;

        nextState->blankSpotLocation.at(0) -= 1;

        nextState->addCost(1);
    }
    else if (direction == -1 && blankSpotRowIndex+1 < state.size()) {  //down

        nextState = new EightPuzzleNode(this);
        int a = nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex);
        int b = nextState->state.at(blankSpotRowIndex+1).at(blankSpotColIndex);

        nextState->state.at(blankSpotRowIndex).at(blankSpotColIndex) = b;
        nextState->state.at(blankSpotRowIndex+1).at(blankSpotColIndex) = a;

        nextState->blankSpotLocation.at(0) += 1;
        nextState->addCost(1);
    }



    return nextState;
}