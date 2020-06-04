#ifndef GRAPH
#define GRAPH
#include <vector>
#include<iostream>

const int MAX_DISTANCE = 999999999;

class Graph{
  protected:
    // The Graph is implemented with a table
    int size;
    double* matrix;
    double* dijkstra;

  public:
    Graph(int amount): size(amount){
        matrix = new double[size*size] {};
	for(int i = 0; i < size; i++){
	  for(int j = 0; j < size; j++){
	    matrix[findIndex(i,j)] = -1;
	  }
	}
	dijkstra = new double[size*3] {};
	  //size*0 + i, access node visit
	  //size*1 + i, access node shortest distance
	  //size*2 + i, access node previous
	for(int c = 0; c < 3; c++){
	  for(int i = 0; i < size; i++){
	    dijkstra[size*c+i] = MAX_DISTANCE;
	  }
	}
	clean();
    };

    void spit() {
    	for(int i = 0; i < size; i++){
    	  for(int j = 0; j < size; j++){
    	    std::cout << matrix[findIndex(i,j)] << " ";
	  }
    	  std::cout << "\n";
	}

    	  std::cout << "\n";
    	  std::cout << "\n";
    	  std::cout << "\n";
    	for(int i = 0; i < 3; i++){
    	  for(int j = 0; j < size; j++){
    	    std::cout << dijkstra[size*i + j] << " ";
	  }
    	  std::cout << "\n";
	}
    };

    // Accessing components of the matrix
    int findIndex(int first, int second){
    	return first*size+second;
    };

    void clean() {
    	for(int i = 0; i < size; i++){
	  dijkstra[size*0 + i] = -1;
	  dijkstra[size*1 + i] = MAX_DISTANCE;
	  dijkstra[size*2 + i] = 0;
	}
    }

    void addEdge(int first, int second, double weight){
    	int index = findIndex(first, second);
	matrix[index] = weight;
    };

    void removeEdge(int first, int second){
    	addEdge(first, second, -1);
    };

    // Checks both ways
    std::vector<int> neighborsOfVertex(int node){
	std::vector<int> neighbors = {};
    	for(int i = 0; i < size; i++){
	  int* indices = new int[findIndex(node, i), findIndex(i, node)];
	  if(matrix[indices[0]] > 0 or matrix[indices[1]] > 0){
	    neighbors.push_back(i);
	  }
	}
    	return neighbors;
    };

    // Checks one way
    bool verticesAreAdjacent(int first, int second){
	return matrix[findIndex(first,second)] >= 0;
    };

    std::vector<int> shortestPathFromVertex(int from, 
    					    int to, 
    					    int travel = 0, 
					    int previous = -1){
    	if (previous == -1){
	  clean();
	}
    	if (dijkstra[size + from] < travel){
	  dijkstra[size + from] = travel;
	  dijkstra[from] = previous;
	}

	for(int i = 0; i < size; i++){
	  if (dijkstra[i] == 0 and verticesAreAdjacent(from, i)){
	    shortestPathFromVertex(i, to, travel + matrix[findIndex(from, i)], from);
	  }
	}
	std::vector<int> content = {};
	int current = to;
	int count = 0;
	while(current != -1 or count >= size){
	  content.push_back(current);
	  current = dijkstra[size*2 + current];
	  count++;
	}
    	return content;
    };

    bool searchCycle(int node = 0){
	dijkstra[node] = 1;
	dijkstra[size*2+node] = 1;

	for(int i = 0; i < size; i++){
	  if(node == i){
	    continue;
	  }
	  else if(dijkstra[i] == -1 and verticesAreAdjacent(node, i)){
	    dijkstra[i] = 1;
	    if(searchCycle(i)){
	      return true;
	    }
	  }
	  else{
	    if(dijkstra[size*2 + i] == 1 and verticesAreAdjacent(node, i)){
	      return true;
	    }
	    else{
	      continue;
	    }
	  }
	}
	return false;
    };



    bool hasCycle(){
	clean();
	for(int i = 0; i < size; i++){
	  if(searchCycle(i)){
	    return true;

	  }
	}
	return false;
    };
};

#endif
