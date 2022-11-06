#include "graph.h"

void Graph::AddNode(Node n) {m_nodes.push_back(n);}

void Graph::AddEdge(Edge a) {m_edges.push_back(a);}

int Graph::GetNumberOfNodes(){return m_nodes.size();}

std::vector<Node> Graph::GetNodes() {return  m_nodes;}

std::vector<Edge> Graph::GetEdges(){return m_edges;}

void Graph::UpdateAdjacencyMatrix()
{
    m_adjacencyMatrix.resize(GetNumberOfNodes());
    for(int i=0;i<GetNumberOfNodes();i++)
        for(int j=0;j<GetNumberOfNodes();j++)
            m_adjacencyMatrix[i].push_back(0);
    for(Edge& edge:GetEdges())
    {
        m_adjacencyMatrix[edge.GetFirstNode().GetInfo()-1][edge.GetSecondNode().GetInfo()-1]=1;
        if(!m_isDirected)
        {
        m_adjacencyMatrix[edge.GetSecondNode().GetInfo()-1][edge.GetFirstNode().GetInfo()-1]=1;
        }
    }
    PrintMatrix();
}

void Graph::PrintMatrix()
{
    std::ofstream output("output.txt");
    if(output.is_open())
    {
        output<<(int)m_nodes.size()<<std::endl;
        for(int i=0;i<(int)m_nodes.size();i++)
        {
            for(int j=0;j<(int)m_nodes.size();j++)
                output<<m_adjacencyMatrix[i][j]<<" ";
            output<<std::endl;
        }
    }
    output.close();
}

void Graph::SetDirected(bool condition)
{
    m_isDirected=condition;
}

bool Graph::GetGraphType()
{
    return m_isDirected;
}

void Graph::SetNodes(std::vector<Node> nodesVec)
{
    m_nodes=nodesVec;
}

void Graph::UpdateEdges()
{
    m_edges.clear();
    for(int i=0;i<GetNumberOfNodes();i++)
    {
        for(int j=0;j<GetNumberOfNodes();j++)
        {
            if(m_adjacencyMatrix[i][j]==1){
                if(m_isDirected==true)
                    m_edges.emplace_back(m_nodes[i],m_nodes[j]);
                else
                {
                    m_edges.emplace_back(m_nodes[i],m_nodes[j]);
                    m_edges.emplace_back(m_nodes[j],m_nodes[i]);
                }
            }

        }
    }
}
