#include "GraphView.h"
#include <QGraphicsLineItem>
#include <QDebug>

GraphView::GraphView(QWidget *parent)
    : QGraphicsView(parent)
{
    m_scene = new QGraphicsScene(this);
    setScene(m_scene);

    // Setup the view
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    // Connect to selectionChanged
    connect(m_scene, &QGraphicsScene::selectionChanged, this, &GraphView::handleSelectionChanged);
}

GraphView::~GraphView()
{
    // Scene is deleted automatically as child of the view
}

void GraphView::addNode(const QString &id, const QString &label, qreal x, qreal y)
{
    GraphNode *node = new GraphNode(label, x, y);
    m_scene->addItem(node);
    m_nodes[id] = node;
}

void GraphView::addEdge(const QString &fromId, const QString &toId)
{
    GraphNode *fromNode = m_nodes.value(fromId);
    GraphNode *toNode = m_nodes.value(toId);

    if (!fromNode || !toNode)
    {
        qDebug() << "Cannot add edge: node not found";
        return;
    }

    // Calculate center points
    QPointF fromCenter = fromNode->boundingRect().center() + fromNode->pos();
    QPointF toCenter = toNode->boundingRect().center() + toNode->pos();

    // Create a line between the centers
    QGraphicsLineItem *line = new QGraphicsLineItem(fromCenter.x(), fromCenter.y(), toCenter.x(), toCenter.y());
    line->setPen(QPen(Qt::black, 1));
    line->setZValue(-1); // Put lines behind nodes

    m_scene->addItem(line);
}

GraphNode *GraphView::getNode(const QString &id)
{
    return m_nodes.value(id);
}

void GraphView::handleSelectionChanged()
{
    QList<QGraphicsItem *> selectedItems = m_scene->selectedItems();
    for (auto item : selectedItems)
    {
        GraphNode *node = dynamic_cast<GraphNode *>(item);
        if (node)
        {
            emit nodeClicked(node->getLabel());
        }
    }
}