#include "edge.h"

Edge::Edge(Node fN, Node sN)
{
    m_FirstNode = fN;
    m_SecondNode = sN;
}

Node Edge::getFirstNode()
{
    return m_FirstNode;
}
Node Edge::getSecondNode()
{
    return m_SecondNode;
}
