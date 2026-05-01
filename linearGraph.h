#ifndef LINEARGRAPH_H
#define LINEARGRAPH_H
#include "graph.h"

class LinearGraph:public Graph{
public:
    LinearGraph();
    virtual void PrintFunction();
    virtual void PlotFunction();
};

#endif