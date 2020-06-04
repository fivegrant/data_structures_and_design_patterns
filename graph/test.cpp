#include "./graph.hpp"
#include <iostream>

int main(){
  Graph graph = Graph(6);
  //graph.addEdge(0,1, 0.5);
  //graph.addEdge(1,0, 0.5);
  //graph.removeEdge(1,0);
  std::cout << "HERE: " << graph.hasCycle();

  return 0;
}
