#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "linearGraph.h"
#include <vector>
#include <string>
#include <cmath>

using namespace std;

LinearGraph::LinearGraph() {
}


void LinearGraph::PrintFunction() {
    cout << "y = " << slope << "x";
    if (intercept > 0) cout << " + " << intercept;
    else if (intercept < 0) cout << " - " << -intercept;
    cout << "  [" << domainStart << ", " << domainEnd << "]" << endl;
}

void LinearGraph::PlotFunction() {
    if (consoleWidth <= 0 || consoleHeight <= 0) return;

    std::vector<std::string> rows(consoleHeight, std::string(consoleWidth, ' '));

    double rangeSpan = rangeMax - rangeMin;
    for (int x = 0; x < consoleWidth; x++) {
        double domainValue = double(domainStart) + x * domainIncrement;
        double value = double(slope) * domainValue + double(intercept);

        int row;
        if (rangeSpan == 0.0) {
            row = consoleHeight / 2;
        } else {
            double normalized = (value - rangeMin) / rangeSpan;
            double yf = (1.0 - normalized) * double(consoleHeight - 1);
            row = int(std::round(yf));
        }
        if (row < 0) row = 0;
        if (row >= consoleHeight) row = consoleHeight - 1;
        rows[row][x] = '*';
    }

    for (int y = 0; y < consoleHeight; y++) {
        cout << rows[y] << std::endl;
    }
}