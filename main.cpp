#include <iostream>
#include <string>
#include "Vertex.h"
#include "Graph.h"
#include "Printer.h"
#include <list>

int main() {
  auto *node1 = new Vertex<int>(1);
  auto *node2 = new Vertex<int>(2);
  auto *node3 = new Vertex<int>(3);
  auto *node4 = new Vertex<int>(4);
  auto *node5 = new Vertex<int>(5);
  auto *node6 = new Vertex<int>(6);
  auto *node7 = new Vertex<int>(7);
  node1->add_outgoing_edge(node4, 1);
  node2->add_bidirectional_edge(node5, 1);
  node3->add_ingoing_edge(node4, 1);
  node4->add_outgoing_edge(node6, 1);
  node4->add_outgoing_edge(node5, 1);
  auto vector = new std::vector<Vertex<int> *>();
  vector->push_back(node1);
  vector->push_back(node2);
  vector->push_back(node3);
  vector->push_back(node4);
  vector->push_back(node5);
  vector->push_back(node6);
  vector->push_back(node7);

  auto *graph = new Graph<int>(vector);
  auto *matrix_printer = new Printer([](Graph<int> *g) -> void {
                                       const int s = g->getGraph()->size();
                                       int v[s][s];
                                       for (int i = 0; i < s; i++) {
                                         for (int j = 0; j < s; j++) {
                                           if (g->getGraph()->at(i)->has_outgoing_edge_to(g->getGraph()->at(j)))
                                             v[i][j] = 1;
                                           else
                                             v[i][j] = 0;
                                           std::cout << v[i][j];
                                         }
                                         std::cout << std::endl;
                                       }
                                     }
  );
  matrix_printer->print(graph);

  auto *bfs_printer = new Printer([](Graph<int> *g) -> void {
                                    auto *list = new std::list<Vertex<int> *>();
                                    Vertex<int> *start = g->getGraph()->front();
                                    list->push_back(start);
                                    start->visisted = true;
                                    while (!list->empty()) {
                                      Vertex<int> *node = list->back();
                                      list->pop_back();
                                      std::cout << node << std::endl;
                                      for (auto i : node->getOutgoing()) {
                                        if (!i->getV()->visisted) {
                                          i->getV()->visisted = true;
                                          list->push_back(i->getV());
                                        }
                                      }
                                    }

                                  }
  );
  bfs_printer->print(graph);
  return 0;
}