#include "qhoversensitivebutton.h"
#include "ui_widget.h"

bool QHoverSensitiveButton::hoverMode = true;

QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}


void QHoverSensitiveButton::hoverEnter(QHoverEvent *){

    qDebug() << "Hover Enter";

    if (this->objectName() == "hoverButton"){
        qDebug() << "Hover Button";
        t.start();
    }

    if (!hoverMode){
        qDebug() << "Hover mode is off";
        return;
    }
}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *){

    qDebug() << "Hover Leave";

    if (this->objectName() == "hoverButton"){
        qDebug() << "Hover Button";
        if (t.isValid() && t.elapsed() > 5000){
            if (hoverMode){
                hoverMode = false;
                qDebug() << "Turned hovermode off";
            }
            else{
                hoverMode = true;
                qDebug() << "Should turn on hovermode";
            }
        }
        t.setHMS(-1,-1,-1,-1);
    }
}


bool QHoverSensitiveButton::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(event);
}
