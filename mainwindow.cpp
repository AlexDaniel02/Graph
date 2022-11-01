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
        for(Node& node: graph.GetNodes())
        {
            if(node.Distance(n.GetCoordinate())<nodeRadius*2)
            {
                ok=false;
            }
        }
        if(ok==true)
        {
            n.SetInfo(graph.GetNumberOfNodes() + 1);
            graph.AddNode(n);
            graph.UpdateAdjacencyMatrix();
            update();
        }
    }
    else if (ev->button() == Qt::LeftButton)
    {
        vector<Node> nodes = graph.GetNodes();
        Node selected;
        bool ok=false;
        for(Node& n: nodes)
        {
            if (n.Distance(ev->position()) <= nodeRadius)
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
                for(Edge& edge:graph.GetEdges())
                {
                    if(edge.getFirstNode().GetCoordinate().x()==firstNode.GetCoordinate().x()&&edge.getFirstNode().GetCoordinate().y()==firstNode.GetCoordinate().y()&&edge.getSecondNode().GetCoordinate().x()==selected.GetCoordinate().x()&&edge.getSecondNode().GetCoordinate().y()==selected.GetCoordinate().y())
                    {
                        isFirstNode=false;
                        return;
                    }
                }
                graph.AddEdge(Edge(firstNode, selected));
                isFirstNode= false;
                graph.UpdateAdjacencyMatrix();
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
    vector<Node> nodes = graph.GetNodes();
    for(Node& n:nodes)
    {
        QPointF coord = n.GetCoordinate();
        QRect r(coord.x() - nodeRadius, coord.y()- nodeRadius,
                2*nodeRadius, 2*nodeRadius);
        QPen pen;
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawEllipse(r);
        QString num = QString::number(n.GetInfo());
        p.drawText(r, Qt::AlignCenter, num);
    }
    vector<Edge> edges = graph.GetEdges();
    for(Edge& e:edges)
    {
        QLineF line(e.getFirstNode().GetCoordinate(),e.getSecondNode().GetCoordinate());
        p.drawLine(line);
        if(!graph.GetGraphType())
        {
            QLineF arrowLine1,arrowLine2;
            arrowLine1.setP1(e.getSecondNode().GetCoordinate());
            arrowLine2.setP1(e.getSecondNode().GetCoordinate());
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
        graph.SetUndirected(true);
        graph.UpdateAdjacencyMatrix();
        update();
    }
    else
    {
        graph.SetUndirected(false);
        graph.UpdateAdjacencyMatrix();
        update();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        vector<Node> nodes =graph.GetNodes();
        for(Node& n:nodes){


            if(n.Distance(ev->position()) <  nodeRadius){
                n.SetCoordinate(ev->position());
                break;
            }
        }
        graph.SetNodes(nodes);
        graph.UpdateEdges();
        update();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

