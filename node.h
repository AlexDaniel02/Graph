#ifndef NODE_H
#define NODE_H

#include <QPoint>
class Node
{
    int m_info;
    QPointF m_coord;
public:
    Node(int inf = -1);
    Node(QPointF cood, int inf = -1);
    void SetInfo(int inf){m_info = inf;}
    QPointF GetCoordinate(){return m_coord;}
    void SetCoordinate(QPointF cood){m_coord=cood;}
    int GetInfo(){return m_info;}
    float Distance(QPointF node);

};

#endif // NODE_H

