#include "functions.h"
#include <QTime>
#include <QCoreApplication>

void delay( int millisecondsToWait )
{
    QTime currentTime;
    currentTime.start();
    while( currentTime.elapsed() < millisecondsToWait )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
