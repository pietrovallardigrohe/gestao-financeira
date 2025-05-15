#include "GraphNode.h"
#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include <QDebug>
#include <QGraphicsScene>

GraphNode::GraphNode(const QString &label, qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent), m_label(label), m_defaultBrush(Qt::white), m_hoverBrush(Qt::lightGray), m_defaultPen(Qt::black), m_hoverPen(Qt::darkBlue, 2)
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
    setBrush(m_defaultBrush);
    setPen(m_defaultPen);
}

void GraphNode::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Node clicked:" << m_label;
    // Emit signal through scene
    if (scene())
    {
        scene()->emit selectionChanged();
    }
    QGraphicsEllipseItem::mousePressEvent(event);
}

void GraphNode::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(m_hoverBrush);
    setPen(m_hoverPen);
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void GraphNode::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(m_defaultBrush);
    setPen(m_defaultPen);
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

void GraphNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter, option, widget);

    // Draw the label text in the center
    painter->setFont(QFont("Arial", 10));
    painter->drawText(boundingRect(), Qt::AlignCenter, m_label);
}