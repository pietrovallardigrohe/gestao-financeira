#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>
#include <QGraphicsSceneMouseEvent>

class GraphNode : public QGraphicsEllipseItem
{
public:
    GraphNode(const QString &label, qreal x, qreal y, qreal width = 50, qreal height = 50, QGraphicsItem *parent = nullptr);

    QString getLabel() const { return m_label; }
    void setLabel(const QString &label) { m_label = label; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QString m_label;
    QBrush m_defaultBrush;
    QBrush m_hoverBrush;
    QPen m_defaultPen;
    QPen m_hoverPen;
};

#endif // GRAPHNODE_H