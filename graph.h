#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class Graph
{
    vector<Node> m_nodes;
    vector<Edge> m_edges;
    vector<vector<int>> m_adjacencyMatrix;
    bool m_isDirected=false;
public:
    Graph()=default;
    void AddNode(Node n);
    void AddEdge(Edge a);
    int GetNumberOfNodes();
    vector<Node> GetNodes();
    vector<Edge> GetEdges();
    void UpdateAdjacencyMatrix();
    void PrintMatrix();
    void SetDirected(bool condition);
    bool GetGraphType();
    void SetNodes(vector <Node> nodesVec);
    void UpdateEdges();
};

#endif // GRAPH_H
