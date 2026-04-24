#include <iostream>
#include "graph.h"

int main() {
    Graph g;

    int slope, intercept, domainStart, domainEnd;
    std::cout << "Slope: ";
    std::cin >> slope;
    std::cout << "Intercept: ";
    std::cin >> intercept;
    std::cout << "Domain start: ";
    std::cin >> domainStart;
    std::cout << "Domain end: ";
    std::cin >> domainEnd;
    g.SetLinear(slope, intercept, domainStart, domainEnd);
    g.PrintFunction();
    return 0;
}
