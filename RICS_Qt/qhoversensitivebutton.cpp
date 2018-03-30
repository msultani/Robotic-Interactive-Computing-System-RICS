#include "qhoversensitivebutton.h"
#include "ui_mainwindow.h"

QTime QHoverSensitiveButton::activationTime(-1, -1, -1, -1);
bool QHoverSensitiveButton::hoverMode = true;
//bool QHoverSensitiveButton::hoverPending = false;
QString QHoverSensitiveButton::hoverButton = "";
int QHoverSensitiveButton::hoverTime = 3000;

QList<QString> QHoverSensitiveButton::activeButtons;


QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}


void QHoverSensitiveButton::hoverEnter(QHoverEvent *){
    //qDebug() << "hover " << hoverMode;
/*
    if (this->objectName() == "hoverButton"){
        if (hoverPending){
            return;
        }
        activationTime.start();
        hoverPending = true;
        hoverButton = this->objectName();
        hoverButtonEntered();
    }
*/
    if (!hoverMode || activeButtons.contains(this->objectName())){
        return;
    }

    //qDebug() << "starting t: " + activationTime.toString();
    //qDebug() << activationTime.isValid();
    //qDebug() << "adding " + this->objectName() + " to activeButtons";
    activationTime.start();
    hoverButton = this->objectName();

    if (this->objectName() == "hoverButton"){
        hoverButtonEntered();
    }
    else{
        buttonEntered();
    }

}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *){

    //qDebug() << "hoverLeave";
    activeButtons.removeAll(this->objectName());
    hoverButton = "";
    activationTime.setHMS(-1,-1,-1,-1);

}

void QHoverSensitiveButton::hoverButtonEntered(){
    while (activationTime.isValid() && activationTime.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (activationTime.isValid() && hoverButton == this->objectName()){
        //qDebug() << "Hover mode toggled";
        hoverMode = !hoverMode;

        emit changeLabel();
    }
}

void QHoverSensitiveButton::buttonEntered(){
    //qDebug() << "buttonEntered begin";
    while (activationTime.isValid() && activationTime.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (activationTime.isValid() && hoverButton == this->objectName()){
        //qDebug() << "Button pressed";
        //qDebug() << "Emit hovered from" + this->objectName();
        //qDebug() << activationTime.toString();
        //qDebug() << activationTime.isValid();

        emit pressed();
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
