#ifndef GRAPH
#define GRAPH

class WeightedGraph{
  private:
    int size;
    int* matrix

  public:
    Graph(int amount): size(amount){
      matrix = new int[size*size] {0};
    };

    void addEdge(int first, int second, double weight){
    	return;
    };

    void removeEdge(int first, int second){
	return;
    };

    std::vector<int> neighborsOfVertex(int node){
    	return {};
    };

    bool verticesAreAdjacent(int first, int second){
	return true;
    };

    std::vector<int> shortestPathFromVertex(int to, int from){
    	return {};
    };

    bool hasCycle(){
    	return true
    };
};

#endif
