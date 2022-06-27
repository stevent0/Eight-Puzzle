#include "../include/Solver.h"
#include "../include/EightPuzzleNode.h"

using namespace std;

int main() {
    Node* node = new EightPuzzleNode();
    Solver solver(node);
    solver.search();

    for (Node* node: solver.stateTrace) {
        cout << node->getState() << endl;
    }
}