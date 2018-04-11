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


// TODO - how will this work???
void push_command(QString command_char, int target_pos, int current_pos){

    if (target_pos > current_pos){
        while (target_pos > current_pos){
            current_pos += MainWindow::arm_movement_degrees;
            MainWindow::command_queue.push_back(QPair<QString, int>(command_char, current_pos));
        }

        return;
    }

    while (target_pos < current_pos){
        current_pos -= MainWindow::arm_movement_degrees;
        MainWindow::command_queue.push_back(QPair<QString, int>(command_char, current_pos));
    }

}
