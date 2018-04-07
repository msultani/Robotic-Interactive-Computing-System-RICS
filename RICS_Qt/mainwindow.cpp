#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::popup_open = false;

int MainWindow::x_pos = 90;
int MainWindow::y_pos = 35;
int MainWindow::z_pos = 35;
int MainWindow::target_x = x_pos;
int MainWindow::target_y = y_pos;
int MainWindow::target_z = z_pos;

int MainWindow::claw_pos = 20;
int MainWindow::target_claw = claw_pos;
int MainWindow::move_speed = 5;
int MainWindow::rotation_degrees = 3;
bool MainWindow::auto_movement= true;
bool MainWindow::voice_command_given = false;
QByteArray MainWindow::TCP_data = "";
QVector<QPair<QString, int> > MainWindow::command_queue;
QString MainWindow::move_direction = "";
bool MainWindow::ready_to_send = true;

/* X SERVO: 0
 * Y SERVO: 1
 * Z SERVO: 2
 * CLAW SERVO: 3
 * DELAY: 4
 */

//PYTHON COMMANDS: fetch, up, down, left, right, forward, backward, stop


void MainWindow::establish_TCP_connection(){
    qDebug() << "Establishing TCP connection";
    t = new QTcpServer( this );
    connect(t, SIGNAL (newConnection()), this, SLOT (connection()));

    if (!t->listen(QHostAddress::Any, 6000)){
        qDebug() << "Server did not start";
    }
    else{
        qDebug() << "TCP connected";
    }

}

void MainWindow::connection(){
    qDebug() << "Establishing connection";
    sock = t->nextPendingConnection();

    connect(sock, SIGNAL(readyRead()), this, SLOT(readTCPData()));

    //qDebug() << "closing socket";
    //sock->close();
}

void MainWindow::readTCPData(){
    qDebug() << "here";
    TCP_data = this->sock->readAll();
    qDebug() << "TCP command is:" << TCP_data;
    //voice_command_given = true;
    this->sock->close();
    parse_TCP_command(TCP_data);

}

void MainWindow::parse_TCP_command(QByteArray TCP_data){

    this->ui->ready_label->setText("Receiving Vocal Input...");
    ui->stackedWidget->setCurrentIndex(1);
    qDebug() << TCP_data;

    switch(voice_commands.indexOf(TCP_data)){
        case 0:
            fetchPressed();
            break;
        case 1:
            move_up();
            break;
        case 2:
            move_down();
            break;
        case 3:
            move_left();
            break;
        case 4:
            move_right();
            break;
        case 5:
            move_forward();
            break;
        case 6:
            move_backward();
            break;
        case 7:
            on_clawLeft_pressed();
            break;
        case 8:
            on_clawRight_pressed();
            break;
        default:
            qDebug() << "This shouldn't be called... something went wrong";
            break;
    }

    /*
     * Working code for the "stop" method
     * Reads in a voice command, continues to (slowly) move the arm
     * until "stop" command is received
     * Need to ensure that this method can be implemented safely - waiting for Omega
    while (voice_command_given){
        qDebug() << "entering while loop";
        switch(voice_commands.indexOf(TCP_data)){
            case 0:
                fetchPressed();
                break;
            case 1:
                move_up();
                break;
            case 2:
                move_down();
                break;
            case 3:
                move_left();
                break;
            case 4:
                move_right();
                break;
            case 5:
                move_forward();
                break;
            case 6:
                move_backward();
            case 7:
                voice_command_given = false;
                qDebug() << "Stopping";
                break;
            default:
                qDebug() << "This shouldn't be called... something went wrong";
                break;
        }
        delay(2000);
    }
*/

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //Initialize voice_commands list
    voice_commands << "retract" << "rise" << "down" << "left" << "right" << "forward" << "backward" << "near" << "away";
    directional_commands << "X" << "Y" << "Z";

    establish_TCP_connection();

 /*

    p.setWorkingDirectory(QDir::currentPath());
    qDebug() << QDir::currentPath();
    p.start("python ../../../../qpython.py");
    p.waitForFinished();
    QString output(p.readAllStandardOutput());
    qDebug() << output;

     * speech_recognition/speech_recognition/__main__.py
    p.setWorkingDirectory("speech_recognition/");
    p.start("python ");
    p.waitForFinished();
    QString output(p.readAllStandardOutput());
    qDebug() << output;
*/
    // List of signals and the appropriate slot that they should connect to
    connect(ui->commandButton, SIGNAL (pressed()), this, SLOT (commandsPressed()));

    connect(ui->fetchButton, SIGNAL (pressed()), this, SLOT (fetchPressed()));

    connect(ui->settingButton, SIGNAL (pressed()), this, SLOT (settingsPressed()));

    connect(ui->tutorialButton, SIGNAL (pressed()), this, SLOT (tutorialPressed()));

    connect(ui->backButton, SIGNAL (pressed()), this, SLOT (backPressed()));

    connect(ui->backButton_2, SIGNAL (pressed()), this, SLOT (backPressed()));

    connect(ui->backButton_3, SIGNAL (pressed()), this, SLOT (backPressed()));

    connect(ui->tutorialButton, SIGNAL (pressed()), this, SLOT (tutorialPressed()));

    connect(ui->hover_time_up_button, SIGNAL (pressed()), this, SLOT (hover_time_up()));

    connect(ui->hover_time_down_button, SIGNAL (pressed()), this, SLOT (hover_time_down()));

    connect(ui->hoverButton, SIGNAL (changeLabel()), this, SLOT (changeLabel()));

    connect(ui->upButton, SIGNAL (pressed()), this, SLOT (move_up()));

    connect(ui->downButton, SIGNAL (pressed()), this, SLOT (move_down()));

    connect(ui->leftButton, SIGNAL (pressed()), this, SLOT (move_left()));

    connect(ui->rightButton, SIGNAL (pressed()), this, SLOT (move_right()));

    connect(ui->forwardButton, SIGNAL (pressed()), this, SLOT (move_forward()));

    connect(ui->backwardButton, SIGNAL (pressed()), this, SLOT (move_backward()));

    connect(ui->releaseButton, SIGNAL (pressed()), this, SLOT (move_finished()));

    connect(ui->autoButton, SIGNAL (pressed()), this, SLOT (auto_move()));

    connect(ui->clawLeft, SIGNAL (pressed()), this, SLOT (on_clawLeft_pressed()));

    connect(ui->clawRight, SIGNAL (pressed()), this, SLOT (on_clawRight_pressed()));

    connect(ui->stopButton, SIGNAL (pressed()), this, SLOT (stopPressed()));

    //Open serial port
    port.setPortName("/dev/cu.usbmodem1421");
    port.setBaudRate(QSerialPort::Baud9600);
    port.setDataBits(QSerialPort::Data8);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::OneStop);
    port.setFlowControl(QSerialPort::NoFlowControl);

    port.open(QIODevice::ReadWrite);

    if (port.isOpen()){
        qDebug() << "OPEN!!!";
    }
    else{
        qDebug() << "Serial port could not open";
        qDebug() << port.errorString();
    }

    //connect(port, SIGNAL (readyRead()), this, SLOT (wait_for_confimation()));
    connect(&port, SIGNAL(readyRead()), this, SLOT(received_confimation()));
}


MainWindow::~MainWindow()
{
    if (port.isOpen()){
        port.close();
    }
    //this->sock->close();
    delete ui;
}

void MainWindow::commandsPressed(){
    bool changed = check_hovermode();

    ui->stackedWidget->setCurrentIndex(1);

    if (changed){
        qDebug() << "CHANGING HOVERMODE";
        ui->ready_label->setText("Please wait.");
        delay(4000);
        QHoverSensitiveButton::hoverMode = true;
        qDebug() << "RESTORING HOVERMODE";
        ui->ready_label->setText("Ready for commands!");
    }
}

void MainWindow::fetchPressed(){
    //change_values(x_pos, y_pos, z_pos);
    move_direction = "fetch";
    reset_targets();

    push_command("0", 10, x_pos);
    push_command("1", 0, y_pos);
    push_command("2", 0, z_pos);
    push_command("3", 0, claw_pos); // TODO - target_claw

    write_to_arduino();
}

void MainWindow::tutorialPressed(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::settingsPressed(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::backPressed(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::hover_time_down(){

    QHoverSensitiveButton::hoverTime -= 200;

    if (QHoverSensitiveButton::hoverTime <= 0){
        QHoverSensitiveButton::hoverTime = 0;
    }
    QString display = QString::number(double(QHoverSensitiveButton::hoverTime) / 1000.0, 'f', 1) + " secs";
    ui->hover_time_label->setText(display);
}

void MainWindow::hover_time_up(){
    QHoverSensitiveButton::hoverTime += 200;

    QString display = QString::number(double(QHoverSensitiveButton::hoverTime) / 1000.0, 'f', 1) + " secs";
    ui->hover_time_label->setText(display);
}

void MainWindow::changeLabel(){
    if (ui->label->text() == "Hover + Hold"){
        ui->label->setText("Press Button");
        ui->hoverButton->setText("OFF");
    }
    else{
        ui->label->setText("Hover + Hold");
        ui->hoverButton->setText("ON");
    }
}


void MainWindow::auto_move(){
    auto_movement = !auto_movement;
    if (auto_movement){
        ui->autoButton->setText("ON");
    }
    else{
        ui->autoButton->setText("OFF");
    }
}

// Called when we receive confirmation that the Arduino has finished processing a message
void MainWindow::received_confimation(){
    qDebug() << "FUNCTION CALLED";
    QByteArray data = port.readAll();
    qDebug() << data;

    if (data == "aaaa"){
        qDebug() << "Success";
    }

    // Check that the data was correct/from Arduino?

    ready_to_send = true;
    write_to_arduino();

}

void MainWindow::send_next_command(){
    if (!port.isOpen()){
        qDebug() << "ERROR! PORT NOT OPEN!";
        return;
    }

    QPair<QString, int> command_data = command_queue[0];
    command_queue.pop_front();
    switch(command_data.first.toInt()){
        case 0:
            x_pos = command_data.second;
            break;
        case 1:
            y_pos = command_data.second;
            break;
        case 2:
            z_pos = command_data.second;
            break;
        case 3:
            claw_pos = command_data.second;
            break;
        default:
            qDebug() << "This shouldn't be called... something went wrong";
            break;
    }

    QString data_to_send = command_data.first + QString::number(command_data.second) + "X";
    port.write(data_to_send.toStdString().c_str(), data_to_send.length());

    //wait_for_confimation();
}

// Called whenever a new command is added to the queue
void MainWindow::write_to_arduino(){

    if (!command_queue.empty() && ready_to_send){
        ready_to_send = false;
        send_next_command();
    }

}

void MainWindow::move_down(){
    //ui->downButton->setStyleSheet("QPushButton { background-color: red; }\n");

    if (move_direction != "down"){
        move_direction = "down";
        reset_targets();
    }

    target_y += move_speed;
    if (target_y <= 35){
        qDebug() << "Y POS: " + QString::number(target_y);
        command_queue.push_back(QPair<QString, int>("1", target_y));

        write_to_arduino();
    }

    //ui->downButton->setStyleSheet("QPushButton { background-color: rgb(205, 205, 205); }\n");

}
void MainWindow::move_up(){
    //ui->upButton->setStyleSheet("QPushButton { background-color: red; }\n");

    if (move_direction != "rise"){
        move_direction = "rise";
        reset_targets();
    }

    target_y -= move_speed;
    if (target_y >= 0){
        qDebug() << "Y POS: " + QString::number(target_y);

        command_queue.push_back(QPair<QString, int>("1", target_y));
        write_to_arduino();
    }

}

void MainWindow::move_left(){

    if (move_direction != "left"){
        move_direction = "left";
        reset_targets();
    }
    //ui->leftButton->setStyleSheet("QPushButton { background-color: red; }\n");
    target_x += move_speed;
    if (target_x <= 180){
        command_queue.push_back(QPair<QString, int>("0", target_x));

        qDebug() << "X POS: " + QString::number(target_x);
        write_to_arduino();
    }

}
void MainWindow::move_right(){

    if (move_direction != "right"){
        move_direction = "right";
        reset_targets();
    }
    target_x -= move_speed;
    if (target_x >= 0){
        command_queue.push_back(QPair<QString, int>("0", target_x));

        //ui->rightButton->setStyleSheet("QPushButton { background-color: red; }\n");
        qDebug() << "X POS: " + QString::number(target_x);
        write_to_arduino();
    }
}
void MainWindow::move_forward(){
    if (move_direction != "forward"){
        move_direction = "forward";
        reset_targets();
    }



    target_z -= move_speed;
    if (target_z >= 0){
        command_queue.push_back(QPair<QString, int>("2", target_z));
        qDebug() << "Z POS: " + QString::number(z_pos);
        write_to_arduino();
    }
    else {
        qDebug() << "CAN'T MOVE ANY FARTHER";
    }

}
void MainWindow::move_backward(){

    if (move_direction != "backward"){
        move_direction = "backward";
        reset_targets();
    }
    target_z += move_speed;
    if (target_z <= 60){
        command_queue.push_back(QPair<QString, int>("2", target_z));

        qDebug() << "Z POS: " + QString::number(z_pos);
        write_to_arduino();
    }
}

void MainWindow::move_finished(){
    // TODO!!!!!
    qDebug() << "Retract";
    reset_targets();
    ui->stackedWidget->setCurrentIndex(4);
    QHoverSensitiveButton::activationTime.setHMS(-1,-1,-1,-1);

    bool restore = QHoverSensitiveButton::hoverMode;
    QHoverSensitiveButton::hoverMode = false;

    int countdown = 5;
    QString display = QString::number(countdown);
    this->ui->countdownLabel->setText(display);
    this->ui->countdownLabel2->setText("seconds remaining");

    while (countdown > 0){
        delay(1000);
        countdown--;
        display = QString::number(countdown);
        this->ui->countdownLabel->setText(display);
    }

    while (!ready_to_send){
        qDebug() << "ERROR - Can't move arm yet\n";
        this->ui->countdownLabel->setText("");
        this->ui->countdownLabel2->setText("Oops! Please wait...");
        delay(200);
    }

    push_command("0", 90, x_pos);
    push_command("1", 35, y_pos);
    push_command("2", 35, z_pos);
    write_to_arduino();
    // Actually send the correct values

/*      x_pos = 93;
        y_pos = 40;
        z_pos = 40;
        write_to_arduino();
 */

     ui->stackedWidget->setCurrentIndex(0);




     if (restore){
         QHoverSensitiveButton::hoverMode = true;
     }
}

void MainWindow::on_clawLeft_pressed() {

    if (move_direction != "claw_left"){
        move_direction = "claw_left";
        reset_targets();
    }
    target_claw;
    command_queue.push_back(QPair<QString, int>("3", claw_pos + rotation_degrees));
    //ui->rightButton->setStyleSheet("QPushButton { background-color: red; }\n");
    qDebug() << "CLAW POS: " + QString::number(claw_pos);
    write_to_arduino();
}

void MainWindow::on_clawRight_pressed() {
    if (claw_pos <= 20){
        return;
    }

    if (move_direction != "claw_right"){
        move_direction = "claw_right";
        reset_targets();
    }
    command_queue.push_back(QPair<QString, int>("3", claw_pos - rotation_degrees));
    //ui->rightButton->setStyleSheet("QPushButton { background-color: red; }\n");
    qDebug() << "CLAW POS: " + QString::number(claw_pos);
    write_to_arduino();
}

void MainWindow::invalid_commands(QByteArray TCP_data){
    QString invalid_data = QTextCodec::codecForMib(1015)->toUnicode(TCP_data);

    this->ui->ready_label->setText("Vocal Input: " + invalid_data);

}

void MainWindow::stopPressed() {
    qDebug() << "STOP PRESSED";
    reset_targets();
}

void MainWindow::reset_targets(){
    target_x = x_pos;
    target_y = y_pos;
    target_z = z_pos;
    command_queue.clear();
}
