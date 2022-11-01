#include "node.h"

Node::Node(int inf)
{
    m_Info = inf;
}

Node::Node(QPointF cood, int inf)
{
    m_Coord = cood;
    m_Info = inf;
}

float Node::Distance(QPointF node)
{
    return sqrt(pow(this->m_Coord.x()-node.x(),2)+pow(this->m_Coord.y()-node.y(),2));
}
