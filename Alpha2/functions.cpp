#include "functions.h"


void delay( int millisecondsToWait )
{
    QTime currentTime;
    currentTime.start();
    while( currentTime.elapsed() < millisecondsToWait )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

bool check_hovermode(){
    if (QHoverSensitiveButton::hoverMode){
        QHoverSensitiveButton::hoverMode = false;
        return true;
    }
    return false;
}
