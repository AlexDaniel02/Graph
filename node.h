#ifndef NODE_H
#define NODE_H

#include <QPoint>
class Node
{
    int info;
    QPointF coord;
public:
    Node(int inf = -1);
    Node(QPointF cood, int inf = -1);
    void setInfo(int inf){info = inf;}
    QPointF getCoordinate(){return coord;}
    void setCoordinate(QPointF cood){coord=cood;}
    int getInfo(){return info;}
    float distance(QPointF node)
    {
        return sqrt(pow(this->coord.x()-node.x(),2)+pow(this->coord.y()-node.y(),2));
    }
    //functie pentru distanta dintre 2 noduri
};

#endif // NODE_H
