#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <vector>
#include <fstream>
class Graph
{
    std::vector<Node> m_nodes;
    std::vector<Edge> m_edges;
    std::vector<std::vector<int>> m_adjacencyMatrix;
    bool m_isDirected=false;
public:
    Graph()=default;
    void AddNode(Node n);
    void AddEdge(Edge a);
    int GetNumberOfNodes();
    std::vector<Node> GetNodes();
    std::vector<Edge> GetEdges();
    void UpdateAdjacencyMatrix();
    void PrintMatrix();
    void SetDirected(bool condition);
    bool GetGraphType();
    void SetNodes(std::vector <Node> nodesVec);
    void UpdateEdges();
};

#endif // GRAPH_H
