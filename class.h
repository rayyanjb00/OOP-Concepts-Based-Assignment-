#ifndef SIMPLE_NODE_H
#define SIMPLE_NODE_H

class SimpleNode {
private:
    int nodeId;
    int neighborCount;
    SimpleNode* arrNeighbors;

public:
    SimpleNode();
    SimpleNode(int nodeId);
    ~SimpleNode();

    void addNeighbor(const SimpleNode& neighbor);
    int getNeighborCount() const;
    void printNeighbors() const;
    int getNodeId() const;
};

class SimpleGraph {
private:
    int numNodes;
    int numEdges;
    SimpleNode* nodes;

public:
    SimpleGraph();
    ~SimpleGraph();

    void addNode(int nodeId);
    void addEdge(int nodeId1, int nodeId2);
    int getNeighborCount(int nodeId) const;
    void printNeighbors(int nodeId) const;
    void printGraphData() const;
};



#endif // SIMPLE_NODE_H
