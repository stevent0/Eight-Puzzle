#include "../include/Solver.h"
#include "../include/EightPuzzleNode.h"

using namespace std;

int main() {
    EightPuzzleNode* node = new EightPuzzleNode();
    node->setState(vector<char> {'1', '2', '3', '4', '5', '6', '-', '7', '8'});
    Solver solver(node);
    solver.search();
    solver.printStateTrace();
}