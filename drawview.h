#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include "rulebar.h"

class QMouseEvent;

class drawview : public QGraphicsView
{
    Q_OBJECT
public:
    drawview(QWidget *parent = 0);
    //drawview(QGraphicsScene *scene);
    void zoomIn();
    void zoomOut();
    QGraphicsScene  *scene = new QGraphicsScene;

protected:
    QtRuleBar *m_hruler;
    QtRuleBar *m_vruler;
    void resizeEvent(QResizeEvent *event);
    void updateRuler();
    void wheelEvent(QWheelEvent *event);
    double scaleValue = 1.0;

signals:

public slots:
};

#endif // DRAWVIEW_H
