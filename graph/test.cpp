#include "./graph.hpp"
#include <iostream>

int main(){
  Graph graph = Graph(6);
  graph.addEdge(0,1, 0.5);
  graph.addEdge(1,0, 0.5);
  graph.removeEdge(1,0);
  graph.addEdge(5, 3, 0.5);
  graph.addEdge(3, 5, 0.5);
  graph.spit();
  std::cout << "HERE: " << "\n" 
    << graph.hasCycle();
  return 0;
}
