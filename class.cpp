#include "class.h"
#include <iostream>

SimpleNode::SimpleNode()
{
}

SimpleNode::SimpleNode(int nodeId) {
    this->nodeId = nodeId;
    neighborCount = 0;
    arrNeighbors = nullptr;
}

SimpleNode::~SimpleNode() {
    delete[] arrNeighbors;
}

void SimpleNode::addNeighbor(const SimpleNode& neighbor) 
{
    if (neighborCount == 0) {
        arrNeighbors = new SimpleNode[1];
        arrNeighbors[0] = neighbor;
    } 
    else 
    {
        SimpleNode* temp = new SimpleNode[neighborCount + 1];
        for (int i = 0; i < neighborCount; ++i) {
            temp[i] = arrNeighbors[i];
        }
        temp[neighborCount] = neighbor;
        delete[] arrNeighbors;
        arrNeighbors = temp;
    }
    ++neighborCount;
}

int SimpleNode::getNeighborCount() const {
    return neighborCount;
}

void SimpleNode::printNeighbors() const {
    for (int i = 0; i < neighborCount; ++i) {
        std::cout << "Neighbor: " << arrNeighbors[i].nodeId << std::endl;
    }
}

int SimpleNode::getNodeId() const {
    return nodeId;
}

SimpleGraph::SimpleGraph() {
    numNodes = 0;
    numEdges = 0;
    nodes = nullptr;
}

SimpleGraph::~SimpleGraph() {
    delete[] nodes;
}

void SimpleGraph::addNode(int nodeId) {
    if (numNodes == 0) {
        nodes = new SimpleNode[1];
        nodes[0] = SimpleNode(nodeId);
    } else {
        SimpleNode* temp = new SimpleNode[numNodes + 1];
        for (int i = 0; i < numNodes; ++i) {
            temp[i] = nodes[i];
        }
        temp[numNodes] = SimpleNode(nodeId);
        delete[] nodes;
        nodes = temp;
    }
    ++numNodes;
}

void SimpleGraph::addEdge(int nodeId1, int nodeId2) {
    SimpleNode* node1 = nullptr;
    SimpleNode* node2 = nullptr;

    for (int i = 0; i < numNodes; ++i) {
        if (nodes[i].getNodeId() == nodeId1)
            node1 = &nodes[i];
        else if (nodes[i].getNodeId() == nodeId2)
            node2 = &nodes[i];
    }

    if (node1 != nullptr && node2 != nullptr) {
        node1->addNeighbor(*node2);
        node2->addNeighbor(*node1);
        ++numEdges;
    }
}

int SimpleGraph::getNeighborCount(int nodeId) const {
    for (int i = 0; i < numNodes; ++i) {
        if (nodes[i].getNodeId() == nodeId)
            return nodes[i].getNeighborCount();
    }
    return 0;
}

void SimpleGraph::printNeighbors(int nodeId) const {
    for (int i = 0; i < numNodes; ++i) {
        if (nodes[i].getNodeId() == nodeId) {
            nodes[i].printNeighbors();
            return;
        }
    }
    std::cout << "Node not found." << std::endl;
}

void SimpleGraph::printGraphData() const {
    std::cout << "Total Nodes: " << numNodes << std::endl;
    std::cout << "Total Edges: " << numEdges << std::endl;
    for (int i = 0; i < numNodes; ++i) {
        nodes[i].printNeighbors();
    }
}


