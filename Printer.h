#ifndef UNTITLED_PRINTER_H
#define UNTITLED_PRINTER_H
#include "Graph.h"
class Printer {
private:
  void (*func)(Graph<int> *);
public:
  void print(Graph<int> *graph);
  Printer(void (*func)(Graph<int> *graph));
};
#endif //UNTITLED_PRINTER_H
