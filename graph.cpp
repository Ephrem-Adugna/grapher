#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "graph.h"
#include <vector>
#include <string>
#include <cmath>

using namespace std;

Graph::Graph() {
    WindowSize();
}
void Graph::SetLinear(int s, int b, int dStart, int dEnd) {
    slope = s;
    intercept = b;
    domainStart = dStart;
    domainEnd = dEnd;
    WindowSize();
    GetIncrement();
}

void Graph::PrintFunction() {
    cout << "y = " << slope << "x";
    if (intercept > 0) cout << " + " << intercept;
    else if (intercept < 0) cout << " - " << -intercept;
    cout << "  [" << domainStart << ", " << domainEnd << "]" << endl;
}

void Graph::WindowSize() {
      struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        consoleHeight = w.ws_row;
        consoleWidth = w.ws_col;
    } else {
        std::cerr << "Failed to get terminal size." << std::endl;
    }
}

void Graph::GetIncrement() {
    int cols = std::max(1, consoleWidth - 1);
    domainIncrement = double(domainEnd - domainStart) / double(cols);
    double r1 = double(slope) * double(domainStart) + double(intercept);
    double r2 = double(slope) * double(domainEnd) + double(intercept);
    rangeMin = std::min(r1, r2);
    rangeMax = std::max(r1, r2);

    double rangeSpan = (rangeMax - rangeMin);
    if (rangeSpan == 0.0) {
        rangeIncrement = 0.0;
    } else {
        rangeIncrement = rangeSpan / double(std::max(1, consoleHeight - 1));
    }
    cout << "Domain increment: " << domainIncrement << ", Range increment: " << rangeIncrement << endl;
}

void Graph::PlotFunction() {
    if (consoleWidth <= 0 || consoleHeight <= 0) return;

    std::vector<std::string> rows(consoleHeight, std::string(consoleWidth, ' '));

    double rangeSpan = rangeMax - rangeMin;
    for (int x = 0; x < consoleWidth; ++x) {
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

    for (int y = 0; y < consoleHeight; ++y) {
        cout << rows[y] << std::endl;
    }
}