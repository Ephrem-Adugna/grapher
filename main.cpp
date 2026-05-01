#include <iostream>
#include <string>
#include "graph.h"
#include "linearGraph.h"
using namespace std;
int main(int argc, char** argv) {
    int slope = 0, intercept = 0, domainStart = 0, domainEnd = 0;

    if (argc >= 5) {
        try {
            slope = stoi(argv[1]);
            intercept = stoi(argv[2]);
            domainStart = stoi(argv[3]);
            domainEnd = stoi(argv[4]);
        } catch (...) {
            cerr << "Invalid command-line arguments. Falling back to interactive input.\n";
        }
    }

    if (argc < 5) {
        cout << "Slope: ";
        cin >> slope;
        cout << "Intercept: ";
        cin >> intercept;
        cout << "Domain start: ";
        cin >> domainStart;
        cout << "Domain end: ";
        cin >> domainEnd;
    }

    LinearGraph g;
    g.Set(slope, intercept, domainStart, domainEnd);
    g.PrintFunction();
    g.PlotFunction();
    return 0;
}
