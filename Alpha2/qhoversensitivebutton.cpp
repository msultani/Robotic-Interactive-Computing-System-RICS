#include "qhoversensitivebutton.h"
#include "ui_mainwindow.h"

bool QHoverSensitiveButton::hoverMode = false;

QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}


void QHoverSensitiveButton::hoverEnter(QHoverEvent *){

    emitHovered();

    qDebug() << "Hover Enter";

    qDebug() << this->hoverMode;

    if (this->objectName() == "hoverButton"){
        //qDebug() << "Hover Button";
        t.start();
    }

    if (!hoverMode){
        //qDebug() << "Hover mode is off";
        return;
    }

    if (this->objectName() == "fetchButton"){
        this->hoverFetch();
    }

    //connect(this, SIGNAL (pressed()), this, SLOT (Widget::leftPressed()));
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
                qDebug() << "Turned hovermode on";
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

void QHoverSensitiveButton::hoverFetch(){
    qDebug() << "Fetch button pressed";
}
void QHoverSensitiveButton::hoverBack(){
    MainWindow* instance = MainWindow::GetInstance();
    instance->ui->stackedWidget->setCurrentIndex(0);
}


void QHoverSensitiveButton::emitHovered(){
    qDebug() << "Hovered signal";
    emit hovered();
}
