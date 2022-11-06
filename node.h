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
    void SetInfo(int inf);
    QPointF GetCoordinate();
    void SetCoordinate(QPointF cood);
    int GetInfo();
    float Distance(QPointF node);
};

#endif // NODE_H

