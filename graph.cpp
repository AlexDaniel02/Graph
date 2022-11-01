#include "graph.h"

void Graph::AddNode(Node n) {m_Nodes.push_back(n);}

void Graph::AddEdge(Edge a) {m_Edges.push_back(a);}

int Graph::GetNumberOfNodes(){return (int)m_Nodes.size();}

vector<Node> Graph::GetNodes() {return  m_Nodes;}

vector<Edge> Graph::GetEdges(){return m_Edges;}

void Graph::UpdateAdjacencyMatrix()
{
    m_AdjacencyMatrix.resize(GetNumberOfNodes());
    for(int i=0;i<GetNumberOfNodes();i++)
        for(int j=0;j<GetNumberOfNodes();j++)
            m_AdjacencyMatrix[i].push_back(0);
    for(Edge& edge:GetEdges())
    {
        m_AdjacencyMatrix[edge.getFirstNode().GetInfo()-1][edge.getSecondNode().GetInfo()-1]=1;
        if(m_IsUndirected)
        {
            m_AdjacencyMatrix[edge.getSecondNode().GetInfo()-1][edge.getFirstNode().GetInfo()-1]=1;

        }
    }
    PrintMatrix();
}

void Graph::PrintMatrix()
{
    ofstream output("output.txt");
    if(output.is_open())
    {
        output<<(int)m_Nodes.size()<<endl;
        for(int i=0;i<(int)m_Nodes.size();i++)
        {
            for(int j=0;j<(int)m_Nodes.size();j++)
                output<<m_AdjacencyMatrix[i][j]<<" ";
            output<<endl;
        }
    }
    output.close();
}

void Graph::SetUndirected(bool condition)
{
    m_IsUndirected=condition;
}

bool Graph::GetGraphType()
{
    return m_IsUndirected;
}

void Graph::SetNodes(vector<Node> nodesVec)
{
    m_Nodes=nodesVec;
}

void Graph::UpdateEdges()
{
    m_Edges.clear();
    for(int i=0;i<GetNumberOfNodes();i++)
    {
        for(int j=0;j<GetNumberOfNodes();j++)
        {
            if(m_AdjacencyMatrix[i][j]==1){
                if(m_IsUndirected==false)
                    m_Edges.emplace_back(m_Nodes[i],m_Nodes[j]);
                else
                {
                    m_Edges.emplace_back(m_Nodes[i],m_Nodes[j]);
                    m_Edges.emplace_back(m_Nodes[j],m_Nodes[i]);
                }
            }

        }
    }
}
