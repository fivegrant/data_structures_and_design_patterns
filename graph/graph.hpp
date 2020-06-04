#ifndef GRAPH
#define GRAPH
#include <vector>

const int MAX_DISTANCE = 999999999;
const int DIJKSTRA_CONTENT [3] = { 0, MAX_DISTANCE, -1};

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
	clean();
    };
    
    // Accessing components of the matrix
    int findIndex(int first, int second){
    	return first*size+second;
    };

    void clean() {
    	for(int i = 0; i < size; i++){
	  dijkstra[size*0 + i] = 0;
	  dijkstra[size*1 + i] = MAX_DISTANCE;
	  dijkstra[size*2 + i] = -1;
	}
    }

    void addEdge(int first, int second, double weight){
    	int index = findIndex(first, second);
	matrix[index] = weight;
    };

    void removeEdge(int first, int second){
    	addEdge(first, second, -1);
    };

    // Checks from node to see what its connected to
    std::vector<int> neighborsOfVertex(int node){
	std::vector<int> neighbors = {};
    	for(int i = 0; i < size; i++){
	  if(matrix[findIndex(node,i)] > 0){
	    neighbors.push_back(i);
	  }
	}
    	return neighbors;
    };

    // Checks one way
    bool verticesAreAdjacent(int first, int second){
	return matrix[findIndex(first,second)] >= 0;
    };

    std::vector<int> shortestPathFromVertex(int from, int to){


        clean();
	dijkstra[size + from] = 0;
	int current = from;
	while(true){
	  for(int neighbor : neighborsOfVertex(current)){
	    if(not dijkstra[neighbor]){
	      if(dijkstra[size + current] + matrix[findIndex(current,neighbor)] < dijkstra[size + neighbor]){
		dijkstra[size + neighbor] = dijkstra[size + current] + matrix[findIndex(current,neighbor)];
		dijkstra[size * 2 + neighbor] = current;
	      }
	    }
	  dijkstra[current] = 1;
	  }
	  int capture = current;
	  for(int i = 0; i < size; i++){
	    if(not dijkstra[i] and i != to){
	      capture = i;
	      break;
	    }
	  }
	  if(capture != current){
	    current = capture;
	    continue;
	  }
	  break;
	}
	std::vector<int> content = {};
	int view = to;
	int count = 0;
	while(view != -1 and count <= size){
	  content.insert(content.begin(), { view });
	  view = dijkstra[size*2 + view];
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
