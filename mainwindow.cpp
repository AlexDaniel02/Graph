#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFirstNode = false;

}
void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::RightButton)
    {
        bool ok=true;
        Node n(ev->position());
        for(Node& node: graph.getNodes())
        {
            if(node.distance(n.getCoordinate())<nodeRadius*2)
            {
                ok=false;
            }
        }
        if(ok==true)
        {
            n.setInfo(graph.getNumberOfNodes() + 1);
            graph.addNode(n);
            graph.updateAdjacencyMatrix();
            update();
        }
    }
    else if (ev->button() == Qt::LeftButton)
    {
        vector<Node> nodes = graph.getNodes();
        Node selected;
        bool ok=false;
        for(Node& n: nodes)
        {
            if (n.distance(ev->position()) <= nodeRadius)
            {
                selected = n;
                ok = true;
                break;
            }
        }
        if (ok)
        {
            if (!isFirstNode)
            {
                firstNode = selected;
                isFirstNode = true;
            }
            else
            {
                for(Edge& edge:graph.getEdges())
                {
                    if(edge.getFirstNode().getCoordinate().x()==firstNode.getCoordinate().x()&&edge.getFirstNode().getCoordinate().y()==firstNode.getCoordinate().y()&&edge.getSecondNode().getCoordinate().x()==selected.getCoordinate().x()&&edge.getSecondNode().getCoordinate().y()==selected.getCoordinate().y())
                    {
                        isFirstNode=false;
                        return;
                    }
                }
                graph.addEdge(Edge(firstNode, selected));
                isFirstNode= false;
                graph.updateAdjacencyMatrix();
                update();
            }
        }
        else
        {
            isFirstNode = false;
        }
    }
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    vector<Node> nodes = graph.getNodes();
    for(Node& n:nodes)
    {
        QPointF coord = n.getCoordinate();
        QRect r(coord.x() - nodeRadius, coord.y()- nodeRadius,
                2*nodeRadius, 2*nodeRadius);
        QPen pen;
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawEllipse(r);
        QString num = QString::number(n.getInfo());
        p.drawText(r, Qt::AlignCenter, num);
    }
    vector<Edge> edges = graph.getEdges();
    for(Edge& e:edges)
    {
        QLineF line(e.getFirstNode().getCoordinate(),e.getSecondNode().getCoordinate());
        p.drawLine(line);
        if(!graph.getGraphType())
        {
            QLineF arrowLine1,arrowLine2;
            arrowLine1.setP1(e.getSecondNode().getCoordinate());
            arrowLine2.setP1(e.getSecondNode().getCoordinate());
            arrowLine1.setLength(nodeRadius*2);
            arrowLine2.setLength(nodeRadius*2);
            arrowLine1.setAngle(line.angle()+150);
            arrowLine2.setAngle(line.angle()-150);
            p.drawLine(arrowLine1);
            p.drawLine(arrowLine2);
        }
    }
}
void MainWindow::on_radioButton_released()
{
    if(ui->radioButton->isChecked())
    {
        graph.setUndirected(true);
        graph.updateAdjacencyMatrix();
        update();
    }
    else
    {
        graph.setUndirected(false);
        graph.updateAdjacencyMatrix();
        update();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        vector<Node> nodes =graph.getNodes();
        for(Node& n:nodes){


            if(n.distance(ev->position()) <  nodeRadius){
                n.setCoordinate(ev->position());
                break;
            }
        }
        graph.setNodes(nodes);
        graph.updateEdges();
        update();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

