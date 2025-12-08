#include "drawview.h"
#include <QGraphicsScene>

drawview::drawview(QWidget *parent) : QGraphicsView(parent)
{
    m_hruler = new QtRuleBar(Qt::Horizontal,this,this);
    m_vruler = new QtRuleBar(Qt::Vertical,this,this);

}

void drawview::zoomIn()
{
    scaleValue *= 1.1;
    scale(1.1,1.1);
    updateRuler();
}

void drawview::zoomOut()
{
    scaleValue *= (1/1.1);
    scale(1/1.1, 1/1.1);
    updateRuler();
}

void drawview::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    this->setViewportMargins(RULER_SIZE-1,RULER_SIZE-1,0,0);
    m_hruler->resize(this->size().width()- RULER_SIZE - 1,RULER_SIZE);
    m_hruler->move(RULER_SIZE,0);
    m_vruler->resize(RULER_SIZE,this->size().height() - RULER_SIZE - 1);
    m_vruler->move(0,RULER_SIZE);

    updateRuler();
}

void drawview::updateRuler()
{
    QRectF viewbox = this->rect();
    QPointF offset = mapFromScene(scene->sceneRect().topLeft());
    double factor =  1./transform().m11();
    double lower_x = factor * ( viewbox.left()  - offset.x() );
    double upper_x = factor * ( viewbox.right() -RULER_SIZE- offset.x()  );
    m_hruler->setRange(lower_x,upper_x,upper_x - lower_x );
    m_hruler->update();

    double lower_y = factor * ( viewbox.top() - offset.y()) * -1;
    double upper_y = factor * ( viewbox.bottom() - RULER_SIZE - offset.y() ) * -1;

    m_vruler->setRange(lower_y,upper_y,upper_y - lower_y );
    m_vruler->update();
}

void drawview::wheelEvent(QWheelEvent *event)
{
    if((event->delta() > 0)&&(scaleValue >= 50))
    {
        return;
    }
    else if((event->delta() < 0)&&(scaleValue <= 1))
    {
        scale(1,1);
        return;
    }
    else
    {
        if(event->delta() > 0)
        {
            zoomIn();
        }
        else
        {
            zoomOut();
        }
    }
}
