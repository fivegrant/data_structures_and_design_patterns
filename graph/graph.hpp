#ifndef GRAPH
#define GRAPH
#include <vector>

class Graph{
  protected:
    // The Graph is implemented with a table
    int size;
    double* matrix;

  public:
    Graph(int amount): size(amount){
        matrix = new double[size*size] {-1};
    };

    int* findIndices(int first, int second){
    	return new int[2]{first*size+second, second*size+first};
    };

    void addEdge(int first, int second, double weight){
    	int [2] indices = findIndices(first, second);
	matrix[indices[0]] = weight;
	matrix[indices[1]] = weight;
    	return;
    };

    void removeEdge(int first, int second){
    	addEdge(first, second, -1);
    };

    std::vector<int> neighborsOfVertex(int node){
	std::vector<int> neighbors = {};
    	for(int i = 0; i < size; i++){
	  int [2] indices = findIndices(node, i);
	  if matrix[indices[0]] > 0:
	    neighbors.push_back(i);
	}
    	return neighbors;
    };

    bool verticesAreAdjacent(int first, int second){
    	int [2] indices = findIndices(first, second);
	return matrix[indices[0]] >= 0;
    };

    std::vector<int> shortestPathFromVertex(int to, int from){
    	return std::vector<int>{};
    };

    bool hasCycle(){
	for(int i = 0; i < size; i++){
	  for(int j = 0; j < size; j++){
	    if i == j:
	    	continue
	    else:
	    	

	}
    	return false;
    };
};

#endif
