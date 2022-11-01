#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class Graph
{
    vector<Node> m_Nodes;
    vector<Edge> m_Edges;
    vector<vector<int>> m_AdjacencyMatrix;
    bool m_IsUndirected=false;
public:
    Graph()=default;
    void AddNode(Node n);
    void AddEdge(Edge a);
    int GetNumberOfNodes();
    vector<Node>GetNodes();
    vector<Edge> GetEdges();
    void UpdateAdjacencyMatrix();
    void PrintMatrix();
    void SetUndirected(bool condition);
    bool GetGraphType();
    void SetNodes(vector <Node> nodesVec);
    void UpdateEdges();
};

#endif // GRAPH_H
