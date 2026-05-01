#include <iostream>
#include <string>
#include "graph.h"

int main(int argc, char** argv) {
    int slope = 0, intercept = 0, domainStart = 0, domainEnd = 0;

    if (argc >= 5) {
        try {
            slope = std::stoi(argv[1]);
            intercept = std::stoi(argv[2]);
            domainStart = std::stoi(argv[3]);
            domainEnd = std::stoi(argv[4]);
        } catch (...) {
            std::cerr << "Invalid command-line arguments. Falling back to interactive input.\n";
        }
    }

    if (argc < 5) {
        std::cout << "Slope: ";
        std::cin >> slope;
        std::cout << "Intercept: ";
        std::cin >> intercept;
        std::cout << "Domain start: ";
        std::cin >> domainStart;
        std::cout << "Domain end: ";
        std::cin >> domainEnd;
    }

    Graph g;
    g.SetLinear(slope, intercept, domainStart, domainEnd);
    g.PrintFunction();
    g.PlotFunction();
    return 0;
}
