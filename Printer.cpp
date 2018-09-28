#include "Printer.h"
Printer::Printer(void (*func)(Graph<int> *)) {
  this->func = func;
}
void Printer::print(Graph<int> *graph) {
  func(graph);
}
