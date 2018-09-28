#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
#include <vector>
#include "Vertex.h"

template<class T> class Graph {
private:
  std::vector<Vertex<T> *> *graph;
public:
  std::vector<Vertex<T> *> *getGraph() const {
    return graph;
  }

public:
  Graph(std::vector<Vertex<T> *> *graph) {
    this->graph = graph;
  }
};

#endif //UNTITLED_GRAPH_H
