#ifndef GRAPH_H
#define GRAPH_H

class Graph{
public:
    Graph();
    void SetLinear(int slope, int intercept, int domainStart, int domainEnd);
    void PrintFunction();
    void PlotFunction();
private:
    void WindowSize();
    void GetIncrement();
    int slope;
    int intercept;
    int domainStart;
    int domainEnd;
    double domainIncrement;
    double rangeIncrement;
    double rangeMin;
    double rangeMax;
    int consoleHeight;
    int consoleWidth;
};

#endif