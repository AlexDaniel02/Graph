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

void Node::SetInfo(int inf)
{
    m_info = inf;
}

QPointF Node::GetCoordinate()
{
    return m_coord;
}

void Node::SetCoordinate(QPointF cood)
{
    m_coord=cood;
}

int Node::GetInfo(){
    return m_info;
}

float Node::Distance(QPointF node)
{
    return sqrt(pow(this->m_coord.x()-node.x(),2)+pow(this->m_coord.y()-node.y(),2));
}
