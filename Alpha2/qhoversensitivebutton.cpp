
#include "qhoversensitivebutton.h"
#include "ui_mainwindow.h"

bool QHoverSensitiveButton::hoverMode = true;
bool QHoverSensitiveButton::hoverPending = false;
QString QHoverSensitiveButton::hoverButton = "";
int QHoverSensitiveButton::hoverTime = 3000;


QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}


void QHoverSensitiveButton::hoverEnter(QHoverEvent *){


    if (this->objectName() == "hoverButton"){
        if (hoverPending){
            return;
        }
        t.start();
        hoverPending = true;
        hoverButton = this->objectName();
        hoverButtonEntered();
    }

    if (!hoverMode){
        return;
    }

    t.start();
    hoverButton = this->objectName();
    buttonEntered();
    //emit hovered();
}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *){

    hoverPending = false;
    hoverButton = "";
    t.setHMS(-1,-1,-1,-1);

}

void QHoverSensitiveButton::hoverButtonEntered(){
    while (t.isValid() && t.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (t.isValid() && hoverButton == this->objectName()){
        qDebug() << "Hover mode toggled";
        hoverMode = !hoverMode;
        emit changeLabel();
    }
}

void QHoverSensitiveButton::buttonEntered(){
    while (t.isValid() && t.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (t.isValid() && hoverButton == this->objectName()){
        //qDebug() << "Button pressed";
        emit hovered();
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
