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

void change_values(){
    /*
    if (x_pos > 10){
        while (x_pos > 10){
            x_pos -= MainWindow::move_speed;
            MainWindow::command_queue.push_back(x_pos);
        }
    }
    else{
        while (x_pos < 10){
            x_pos += MainWindow::move_speed;
            MainWindow::command_queue.push_back(x_pos);
        }
    }

    if (y_pos > 0){
        while (y_pos > 0){
            y_pos -= MainWindow::move_speed;
            MainWindow::command_queue.push_back(y_pos);
        }
    }
    else {
        while (y_pos < 0){
            y_pos += MainWindow::move_speed;
            MainWindow::command_queue.push_back(y_pos);
        }
    }

    if (z_pos > 0){
        while (z_pos > 0){
            z_pos -= MainWindow::move_speed;
            MainWindow::command_queue.push_back(z_pos);
        }
    }

    else {
        while (z_pos < 0){
            z_pos -= MainWindow::move_speed;
            MainWindow::command_queue.push_back(z_pos);
        }
    }
    */
}
