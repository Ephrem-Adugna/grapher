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
        std::cout << "Lines (Height): " << w.ws_row << std::endl;
        std::cout << "Columns (Width): " << w.ws_col << std::endl;
    } else {
        std::cerr << "Failed to get terminal size." << std::endl;
    }
}