#include "edge.h"

Edge::Edge(Node fN, Node sN)
{
    m_firstNode = fN;
    m_secondNode = sN;
}

Node Edge::GetFirstNode()
{
    return m_firstNode;
}
Node Edge::GetSecondNode()
{
    return m_secondNode;
}
