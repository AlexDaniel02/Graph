#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class Graph
{
    vector<Node> nodes;
    vector<Edge> edges;
    vector<vector<int>> adjacencyMatrix;
    bool isUndirected=false;
public:
    Graph();
    void addNode(Node n) {nodes.push_back(n);}
    void addEdge(Edge a) {edges.push_back(a);}
    int getNumberOfNodes(){return (int)nodes.size();}
    vector<Node>getNodes() {return  nodes;}
    vector<Edge> getEdges(){return edges;}
    void updateAdjacencyMatrix()
    {

        adjacencyMatrix.resize(getNumberOfNodes());
        for(int i=0;i<getNumberOfNodes();i++)
            for(int j=0;j<getNumberOfNodes();j++)
                adjacencyMatrix[i].push_back(0);
        for(Edge& edge:getEdges())
        {
            adjacencyMatrix[edge.getFirstNode().getInfo()-1][edge.getSecondNode().getInfo()-1]=1;
            if(isUndirected)
            {
                adjacencyMatrix[edge.getSecondNode().getInfo()-1][edge.getFirstNode().getInfo()-1]=1;

            }
        }
        printMatrix();
    }
    void printMatrix()
    {
        ofstream output("output.txt");
        if(output.is_open())
        {
            output<<(int)nodes.size()<<endl;
            for(int i=0;i<(int)nodes.size();i++)
            {
                for(int j=0;j<(int)nodes.size();j++)
                    output<<adjacencyMatrix[i][j]<<" ";
                output<<endl;
            }
        }
        output.close();
    }
    void setUndirected(bool condition)
    {
        isUndirected=condition;
    }
    bool getGraphType()
    {
        return isUndirected;
    }
    void setNodes(vector <Node> nodesVec)
    {
        nodes=nodesVec;
    }
    void updateEdges()
    {
        edges.clear();
        for(int i=0;i<getNumberOfNodes();i++)
        {
            for(int j=0;j<getNumberOfNodes();j++)
            {
                if(adjacencyMatrix[i][j]==1){
                    if(isUndirected==false)
                        edges.emplace_back(nodes[i],nodes[j]);
                    else
                    {
                        edges.emplace_back(nodes[i],nodes[j]);
                        edges.emplace_back(nodes[j],nodes[i]);
                    }
                }

            }
        }
    }
};

#endif // GRAPH_H
