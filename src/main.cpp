#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "../include/EightPuzzleNode.h"
#include <unordered_set>

using namespace std;

class Solver {
    private:
        Node* startingNode;
        std::unordered_set<string> us;
        int expansions = 0;
    public:
        Solver(Node* node) : startingNode(node) {}
        bool search() {
            std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
            pq.push(startingNode);

            while (!pq.empty()) {

                // cout << pq.size() << " " << us.size() << endl;

                Node* node = pq.top(); pq.pop();
                
                cout << node->getCost() << ", " << node->getHeuristicValue() << endl;
                cout << node->getState() << endl;

                if (node) {
                    
                    if (node->isAtGoalState()) {
                        cout << expansions << endl;
                        return true;
                    }
                    else {
                        std::vector<Node*> nextNodes = node->applyOperations();
                        ++expansions;
                        for (Node* nextNode: nextNodes) {

                            string stateString = nextNode->getState();

                            if (us.count(stateString) == 0) {
                                pq.push(nextNode);
                                us.insert(stateString);
                                // cout << nextNode->getCost() << ", " << node->getHeuristicValue() << endl;
                                // cout << nextNode->getState() << endl;
                            }

                        }


                    }
                }

            }

            return false;
        }
};



int main() {
    EightPuzzleNode* node = new EightPuzzleNode();
    Solver solver(node);
    std::cout << solver.search() << std::endl;
}