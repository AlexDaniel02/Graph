#include "node.h"

Node::Node(int inf)
{
    m_info = inf;
}

Node::Node(QPointF cood, int inf)
{
    m_coord = cood;
    m_info = inf;
}

float Node::Distance(QPointF node)
{
    return sqrt(pow(this->m_coord.x()-node.x(),2)+pow(this->m_coord.y()-node.y(),2));
}
