#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "qhoversensitivebutton.h"
#include "mainwindow.h"
#include <QTime>
#include <QCoreApplication>

void delay(int millisecondsToWait);
bool check_hovermode();
void push_command(QString command_char, int target_pos, int current_pos);

#endif // FUNCTIONS_H
