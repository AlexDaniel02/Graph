#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    Node m_FirstNode, m_SecondNode;
public:
    Edge()=default;
    Edge(Node fN, Node sN);
    Node getFirstNode();
    Node getSecondNode();
};
#endif // EDGE_H
