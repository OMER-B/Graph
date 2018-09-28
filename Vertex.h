#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include <iostream>
#include <algorithm>
#include <vector>
#include "Edge.h"
#include <memory>
template<class T> class Edge;
template<class T> class Vertex {
private:
  T data;
  std::vector<Edge<T> *> outgoing, ingoing;
public:
  const std::vector<Edge<T> *> &getOutgoing() const;
  const std::vector<Edge<T> *> &getIngoing() const;

public:
  bool visisted = false;
  Vertex(T data);
  ~Vertex();
  void add_outgoing_edge(Vertex<T> *v, double codt);
  void add_ingoing_edge(Vertex<T> *v, double cost);
  void add_bidirectional_edge(Vertex<T> *v, double cost);
  bool has_outgoing_edge_to(Vertex<T> *v);
  T getData();
  friend std::ostream &operator<<(std::ostream &out, const Vertex *val) {
    return out << val->data;
  }
};

template<class T> Vertex<T>::Vertex(T data) {
  this->data = data;
  this->outgoing.push_back(new Edge<T>(this, this, 0));
  this->ingoing.push_back(new Edge<T>(this, this, 0));
}

template<class T> void Vertex<T>::add_outgoing_edge(Vertex<T> *v, double cost) {
  auto *edge = new Edge<T>(this, v, cost);
  for (Edge<T> *edge2 : this->outgoing) {
    if (*edge == *edge2) {
      delete edge;
      return;
    }
  }
  this->outgoing.push_back(new Edge<T>(this, v, cost));
  v->add_ingoing_edge(this, cost);
}

template<class T> void Vertex<T>::add_ingoing_edge(Vertex<T> *v, double cost) {
  auto *edge = new Edge<T>(this, v, cost);
  for (Edge<T> *edge2 : this->ingoing) {
    if (*edge == *edge2) {
      delete edge;
      return;
    }
  }
  this->ingoing.push_back(new Edge<T>(this, v, cost));
  v->add_outgoing_edge(this, cost);
}

template<class T> void Vertex<T>::add_bidirectional_edge(Vertex<T> *v, double cost) {
  this->add_ingoing_edge(v, cost);
  this->add_outgoing_edge(v, cost);
}

template<class T> bool Vertex<T>::has_outgoing_edge_to(Vertex<T> *v) {
  for (int i = 0; i < outgoing.size(); i++)
    if (this->outgoing.at(i)->getV() == v || this->outgoing.at(i)->getU() == v)
      return true;

  return false;
}

template<class T> Vertex<T>::~Vertex() {
  for (int i = 0; i < this->ingoing.size(); i++)
    delete this->outgoing.at(i);
  for (int i = 0; i < this->outgoing.size(); i++)
    delete this->outgoing.at(i);
}
template<class T>
const std::vector<Edge<T> *> &Vertex<T>::getOutgoing() const {
  return outgoing;
}
template<class T>
const std::vector<Edge<T> *> &Vertex<T>::getIngoing() const {
  return ingoing;
}

#endif //UNTITLED_NODE_H
