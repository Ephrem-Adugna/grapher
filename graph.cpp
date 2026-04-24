#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph() {
    WindowSize();
}
void Graph::WindowSize() {
      struct winsize w;
    // STDOUT_FILENO refers to the standard output file descriptor
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        consoleHeight = w.ws_row;
        consoleWidth = w.ws_col;
    } else {
        std::cerr << "Failed to get terminal size." << std::endl;
    }
}