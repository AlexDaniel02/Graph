#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class Edge
{
    Node firstNode, secondNode;
public:
    Edge();
    Edge(Node fN, Node sN){
        firstNode = fN;
        secondNode = sN;
    }
    Node getFirstNode(){return firstNode;}
    Node getSecondNode(){return secondNode;}

};
#endif // EDGE_H
