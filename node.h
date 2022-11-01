#ifndef NODE_H
#define NODE_H

#include <QPoint>
class Node
{
    int m_Info;
    QPointF m_Coord;
public:
    Node(int inf = -1);
    Node(QPointF cood, int inf = -1);
    void SetInfo(int inf){m_Info = inf;}
    QPointF GetCoordinate(){return m_Coord;}
    void SetCoordinate(QPointF cood){m_Coord=cood;}
    int GetInfo(){return m_Info;}
    float Distance(QPointF node);

};

#endif // NODE_H
