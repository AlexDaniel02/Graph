#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    Node m_firstNode, m_secondNode;
public:
    Edge()=default;
    Edge(Node fN, Node sN);
    Node GetFirstNode();
    Node GetSecondNode();
};
#endif // EDGE_H
