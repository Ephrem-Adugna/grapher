#ifndef GRAPH_H
#define GRAPH_H

class Graph{
public:
    Graph();
    void CreateGraph();
private:
    void WindowSize();
    int slope;
    int intercept;
    int domainStart;
    int domainEnd;
    int domainIncrement;
    int rangeIncrement;
    int consoleHeight;
    int consoleWidth;
};

#endif