#include "class.h"

int main() {
    SimpleGraph graph;

    // Test code - adding nodes and printing neighbors
    graph.addNode(10);
    graph.addNode(22);
    graph.addNode(33);
    graph.addNode(44);

    graph.addEdge(10, 22);
    graph.addEdge(10, 33);

    graph.printNeighbors(10);
    
    return 0;
}
