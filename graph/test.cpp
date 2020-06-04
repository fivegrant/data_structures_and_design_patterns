#include "./graph.hpp"
#include <iostream>

int main(){
  Graph graph = Graph(6);
  graph.addEdge(0,1, 0.5);
  graph.addEdge(1,0, 0.5);
  graph.removeEdge(1,0);
  graph.addEdge(5, 2, 0.5);
  graph.addEdge(5, 3, 0.2);
  graph.addEdge(2, 1, 1.5);
  graph.addEdge(3, 1, 0.5);
  std::cout << "\n" ;
  std::cout << "\n" ;
  std::vector<int> a = graph.shortestPathFromVertex(5,1);
  for(int i = 0; i < a.size(); i++){
    std::cout << a[i] << "-";
  }
  std::cout << "<<";
  return 0;
}
