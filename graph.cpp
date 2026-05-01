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
void Graph::Set(int s, int b, int dStart, int dEnd) {
    slope = s;
    intercept = b;
    domainStart = dStart;
    domainEnd = dEnd;
    WindowSize();
    GetIncrement();
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
