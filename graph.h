#ifndef GRAPH_H
#define GRAPH_H

class Graph{
public:
    Graph();
    void Set(int slope, int intercept, int domainStart, int domainEnd);
    virtual void PrintFunction() = 0;
    virtual void PlotFunction() = 0;
private:
    void WindowSize();
    void GetIncrement();

protected:
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