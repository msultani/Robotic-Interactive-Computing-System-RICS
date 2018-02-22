
#include "qhoversensitivebutton.h"
#include "ui_mainwindow.h"

QTime QHoverSensitiveButton::t(-1, -1, -1, -1);
bool QHoverSensitiveButton::hoverMode = true;
bool QHoverSensitiveButton::hoverPending = false;
QString QHoverSensitiveButton::hoverButton = "";
int QHoverSensitiveButton::hoverTime = 3000;

QList<QString> QHoverSensitiveButton::active_buttons;


QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}


void QHoverSensitiveButton::hoverEnter(QHoverEvent *){
    //qDebug() << "hoverEnter";

    if (this->objectName() == "hoverButton"){
        if (hoverPending){
            return;
        }
        t.start();
        hoverPending = true;
        hoverButton = this->objectName();
        hoverButtonEntered();
    }

    if (!hoverMode || active_buttons.contains(this->objectName())){
        return;
    }
    active_buttons.append(this->objectName());
    t.start();
    //qDebug() << "starting t: " + t.toString();
    //qDebug() << t.isValid();
    //qDebug() << "adding " + this->objectName() + " to active_buttons";
    hoverButton = this->objectName();
    buttonEntered();
    //emit hovered();
}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *){

    //qDebug() << "hoverLeave";
    active_buttons.removeOne(this->objectName());
    hoverPending = false;
    hoverButton = "";
    t.setHMS(-1,-1,-1,-1);

}

void QHoverSensitiveButton::hoverButtonEntered(){
    while (t.isValid() && t.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (t.isValid() && hoverButton == this->objectName()){
        //qDebug() << "Hover mode toggled";
        hoverMode = !hoverMode;
        emit changeLabel();
    }
}

void QHoverSensitiveButton::buttonEntered(){
    //qDebug() << "buttonEntered begin";
    while (t.isValid() && t.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (t.isValid() && hoverButton == this->objectName()){
        //qDebug() << "Button pressed";
        //qDebug() << "Emit hovered from" + this->objectName();
        //qDebug() << t.toString();
        //qDebug() << t.isValid();

        emit hovered();
        hoverButton = "";

    }
    //qDebug() << "buttonEntered finished";
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
