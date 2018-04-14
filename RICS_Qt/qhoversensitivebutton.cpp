#include "qhoversensitivebutton.h"
#include "ui_mainwindow.h"

QTime QHoverSensitiveButton::activationTime(-1, -1, -1, -1);
bool QHoverSensitiveButton::hoverMode = true;
bool QHoverSensitiveButton::hoverPending = false;
QString QHoverSensitiveButton::hoverButton = "";
int QHoverSensitiveButton::hoverTime;

QList<QString> QHoverSensitiveButton::active_buttons;


QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}

void QHoverSensitiveButton::mousePressEvent(QMouseEvent *e) {
    setStyleSheet("QPushButton { border-style: solid; border-width: 5px; border-color: red;}");
    QPushButton::mousePressEvent(e);
}

void QHoverSensitiveButton::mouseReleaseEvent(QMouseEvent *e) {
    setStyleSheet("QPushButton {}");
    QPushButton::mouseReleaseEvent(e);
}

void QHoverSensitiveButton::hoverEnter(QHoverEvent *){
    if (this->objectName() == "hoverButton"){
        if (hoverPending){
            return;
        }
        activationTime.start();
        hoverPending = true;
        hoverButton = this->objectName();
    }

    if (!hoverMode || active_buttons.contains(this->objectName())){
        return;
    }
    active_buttons.append(this->objectName());
    activationTime.start();
    hoverButton = this->objectName();
    buttonEntered();
}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *){
    active_buttons.removeAll(this->objectName());
    hoverPending = false;
    hoverButton = "";
    activationTime.setHMS(-1,-1,-1,-1);

}

void QHoverSensitiveButton::buttonEntered(){
    while (activationTime.isValid() && activationTime.elapsed() < hoverTime){
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
    if (activationTime.isValid() && hoverButton == this->objectName()){
        emit clicked();
        activationTime.start();
        buttonEntered();
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
