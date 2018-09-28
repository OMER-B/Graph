#ifndef UNTITLED_EDGE_H
#define UNTITLED_EDGE_H
#include "Vertex.h"
template<class T> class Vertex;
template<class T> class Edge {
private:
  double cost;
  Vertex<T> *u, *v;
public:
  double getCost() const;
  Vertex<T> *getU() const;
  Vertex<T> *getV() const;
public:
  Edge(Vertex<T> *u, Vertex<T> *v, double cost);
  ~Edge() {}
};

template<class T> bool operator==(const Edge<T> &edge1, const Edge<T> &edge2) {
  return edge1.getCost() == edge2.getCost() && edge1.getU() == edge2.getU() && edge1.getV() == edge2.getV();
}
template<class T> Edge<T>::Edge(Vertex<T> *u, Vertex<T> *v, double cost) {
  this->v = v;
  this->u = u;
  this->cost = cost;
}
template<class T> double Edge<T>::getCost() const {
  return cost;
}
template<class T> Vertex<T> *Edge<T>::getU() const {
  return u;
}
template<class T> Vertex<T> *Edge<T>::getV() const {
  return v;
}

#endif //UNTITLED_EDGE_H
