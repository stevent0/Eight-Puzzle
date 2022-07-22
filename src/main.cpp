#include "../include/Solver.h"
#include "../include/EightPuzzleNode.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    EightPuzzleNode* node = new EightPuzzleNode();
    Solver solver(node);
    
    node->setState(vector<char> {'-', '2', '8', '6', '7', '3', '5', '1', '4'});
    node->setHeuristic(EightPuzzleHeuristic::MANHATTAN_DISTANCE);

    auto start = std::chrono::high_resolution_clock::now();
    solver.search();
    auto stop = std::chrono::high_resolution_clock::now();

    solver.printSolutionPath();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Finished search in " << duration.count() << " milliseconds" << std::endl;
}