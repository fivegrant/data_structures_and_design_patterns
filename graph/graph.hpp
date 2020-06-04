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
        matrix = new double[size*size] {-1};
	dijkstra = new double[size*3] {MAX_DISTANCE};
	  //size*0 + i, access node visit
	  //size*1 + i, access node shortest distance
	  //size*2 + i, access node previous
	clean();
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

    bool hasCycle(int node = 0, bool clean_up = true){
    	if(clean_up){
	  clean();
	}
	
	dijkstra[node] = 1;
	dijkstra[size*2+node] = 1;

	for(int i = 0; i < size; i++){
	  if(node == i){
	    continue;
	  }
	  if(dijkstra[i] == -1 and verticesAreAdjacent(node, i)){
	    dijkstra[i] = 1;
	    if(hasCycle(i, false)){
	      return true;
	    }
	  }
	  else{
	    if(dijkstra[size*2 + i] == 1){
	      return true;
	    }
	    else{
	      continue;
	    }
	  }
	}
	return false;
    };
};

#endif
