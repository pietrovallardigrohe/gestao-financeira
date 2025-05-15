#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "GraphNode.h"
#include <QMap>

class GraphView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphView(QWidget *parent = nullptr);
    ~GraphView();

    void addNode(const QString &id, const QString &label, qreal x, qreal y);
    void addEdge(const QString &fromId, const QString &toId);
    GraphNode *getNode(const QString &id);

signals:
    void nodeClicked(const QString &nodeId);

private slots:
    void handleSelectionChanged();

private:
    QGraphicsScene *m_scene;
    QMap<QString, GraphNode *> m_nodes;
};

#endif // GRAPHVIEW_H