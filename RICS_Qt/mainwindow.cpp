#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>

bool MainWindow::popup_open = false;

int MainWindow::x_pos = 90;
int MainWindow::y_pos = 35;
int MainWindow::z_pos = 35;
int MainWindow::target_x = x_pos;
int MainWindow::target_y = y_pos;
int MainWindow::target_z = z_pos;
bool MainWindow::change_hover_vals;

int MainWindow::claw_pos = 20;
int MainWindow::target_claw = claw_pos;
int MainWindow::arm_movement_degrees;
int MainWindow::claw_movement_degrees = 3;
int MainWindow::move_delay = 150;
//QByteArray MainWindow::TCP_data = "";
QVector<QPair<QString, int> > MainWindow::command_queue;
QString MainWindow::move_direction = "";
bool MainWindow::ready_to_send = true;

int MainWindow::fetch_x;
int MainWindow::fetch_y;
int MainWindow::fetch_z;
int MainWindow::fetch_claw;

/*
 * X SERVO: 0
 * Y SERVO: 1
 * Z SERVO: 2
 * CLAW SERVO: 3
 * DELAY: 4
 */

// PYTHON COMMANDS: retract, rise, down, left, right,
    // forward, backward, cancel, near, away


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
    //qDebug() << "Establishing connection";
    QTcpSocket *sock = t->nextPendingConnection();
    sock->waitForReadyRead();
    QByteArray TCP_data = sock->readAll();
    qDebug() << "TCP command is:" << TCP_data;
    sock->close();
    parse_TCP_command(TCP_data);
}


void MainWindow::parse_TCP_command(QByteArray TCP_info){

    //ui->stackedWidget->setCurrentIndex(1);
    qDebug() << TCP_info;

    switch(voice_commands.indexOf(TCP_info)){
        case 0:
            ui->fetchButton->click();
            break;
        case 1:
            ui->upButton->click();
            break;
        case 2:
            ui->downButton->click();
            break;
        case 3:
            ui->leftButton->click();
            break;
        case 4:
            ui->rightButton->click();
            break;
        case 5:
            ui->forwardButton->click();
            break;
        case 6:
            ui->backwardButton->click();
            break;
        case 7:
            ui->clawLeft->click();
            break;
        case 8:
            ui->clawRight->click();
            break;
        case 9:
            this->ui->ready_label->setText("Receiving Vocal Input...");
            break;
        case 10:
            this->ui->ready_label->setText("Got it! Parsing Input...");
            ui->voice_label->setText("");
            break;
        case 11:
            message_too_long_error();
            break;
        case 12:
            parsing_error();
            break;
        default:
            invalid_commands(TCP_info);
            break;
    }
}

void MainWindow::read_settings(){
    QSettings settings("RICS", "RICS");

    arm_movement_degrees = settings.value("arm_movement_degrees", 5).toInt();
    QHoverSensitiveButton::hoverTime = settings.value("hoverTime", 3000).toInt();
    fetch_x = settings.value("fetch_x", 10).toInt();
    fetch_y = settings.value("fetch_y", 0).toInt();
    fetch_z = settings.value("fetch_z", 0).toInt();
    fetch_claw = settings.value("fetch_claw", 120).toInt();
    change_hover_vals = settings.value("change_hover_vals", true).toBool();

    arm_movement_degrees = settings.value("arm_movement_degrees", 10).toInt();
    claw_movement_degrees = settings.value("claw_movement_degrees", 3).toInt();
    move_delay = settings.value("move_delay", 150).toInt();

}

void MainWindow::write_settings(){
    QSettings settings("RICS", "RICS");

    settings.setValue("arm_movement_degrees", arm_movement_degrees);
    settings.setValue("hoverTime", QHoverSensitiveButton::hoverTime);
    settings.setValue("fetch_x", fetch_x);
    settings.setValue("fetch_y", fetch_y);
    settings.setValue("fetch_z", fetch_z);
    settings.setValue("fetch_claw", fetch_claw);
    settings.setValue("change_hover_vals", change_hover_vals);
    settings.setValue("arm_movement_degrees", arm_movement_degrees);
    settings.setValue("claw_movement_degrees", claw_movement_degrees);
    settings.setValue("move_delay", move_delay);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

    read_settings();

    // Set UI
    QString display = QString::number(double(QHoverSensitiveButton::hoverTime) / 1000.0, 'f', 1) + " secs";
    ui->hover_time_label->setText(display);
    ui->arm_rotation_label->setText(QString::number(arm_movement_degrees) + " degrees");
    ui->claw_rotation_label->setText(QString::number(claw_movement_degrees) + " degrees");
    ui->move_delay_label->setText(QString::number(double(move_delay) / 1000.0, 'f', 2) + " secs");

    //Initialize voice_commands list
    voice_commands << "retract" << "rise" << "down" << "left" << "right" << "forward" << "backward" << "near" << "away" << "Recording on" << "Recording off" << "message_too_long" << "unintelligible_message";
    directional_commands << "X" << "Y" << "Z";

    establish_TCP_connection();

    // List of signals and the appropriate slot that they should connect to

    connect(ui->fetchButton, SIGNAL (clicked()), this, SLOT (fetchPressed()));

    connect(ui->settingButton, SIGNAL (clicked()), this, SLOT (settingsPressed()));

    connect(ui->tutorialButton, SIGNAL (clicked()), this, SLOT (tutorialPressed()));

    connect(ui->settingsTutorial, SIGNAL (clicked()), this, SLOT (settingsHelpPressed()));

    connect(ui->backButton, SIGNAL (clicked()), this, SLOT (backPressed()));

    connect(ui->backButton_2, SIGNAL (clicked()), this, SLOT (backPressed()));

    connect(ui->backButton_3, SIGNAL (clicked()), this, SLOT (settingsPressed()));

    connect(ui->tutorialButton, SIGNAL (clicked()), this, SLOT (tutorialPressed()));

    connect(ui->hover_time_up_button, SIGNAL (clicked()), this, SLOT (hover_time_up()));

    connect(ui->hover_time_down_button, SIGNAL (clicked()), this, SLOT (hover_time_down()));

    //connect(ui->hoverButton, SIGNAL (clicked()), this, SLOT (changeLabel()));

    connect(ui->upButton, SIGNAL (clicked()), this, SLOT (move_up()));

    connect(ui->downButton, SIGNAL (clicked()), this, SLOT (move_down()));

    connect(ui->leftButton, SIGNAL (clicked()), this, SLOT (move_left()));

    connect(ui->rightButton, SIGNAL (clicked()), this, SLOT (move_right()));

    connect(ui->forwardButton, SIGNAL (clicked()), this, SLOT (move_forward()));

    connect(ui->backwardButton, SIGNAL (clicked()), this, SLOT (move_backward()));

    connect(ui->releaseButton, SIGNAL (clicked()), this, SLOT (move_finished()));

    connect(ui->clawLeft, SIGNAL (clicked()), this, SLOT (on_clawLeft_pressed()));

    connect(ui->clawRight, SIGNAL (clicked()), this, SLOT (on_clawRight_pressed()));

    connect(ui->stopButton, SIGNAL (clicked()), this, SLOT (stopPressed()));

    connect(ui->hoverButton, SIGNAL (clicked()), this, SLOT (hoverButtonEntered()));

    connect(ui->change_fetch_vals_button, SIGNAL (clicked()), this, SLOT (toggle_change_to_fetch_vals()));

    connect(ui->claw_rotation_up_button, SIGNAL (clicked()), this, SLOT (claw_movement_degrees_up()));

    connect(ui->claw_rotation_down_button, SIGNAL (clicked()), this, SLOT (claw_movement_degrees_down()));

    connect(ui->arm_rotation_up_button, SIGNAL (clicked()), this, SLOT (arm_movement_degrees_up()));

    connect(ui->arm_rotation_down_button, SIGNAL (clicked()), this, SLOT (arm_movement_degrees_down()));

    connect(ui->move_delay_up_button, SIGNAL (clicked()), this, SLOT (move_delay_up()));

    connect(ui->move_delay_down_button, SIGNAL (clicked()), this, SLOT (move_delay_down()));

    connect(ui->retract_cancel_button, SIGNAL (clicked()), this, SLOT (retract_cancel()));

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
    connect(&port, SIGNAL(readyRead()), this, SLOT(received_confimation()));
}


MainWindow::~MainWindow()
{
    if (port.isOpen()){
        port.close();
    }
    write_settings();
    //this->sock->close();
    delete ui;
}

/*
void MainWindow::commandsPressed(){
    qDebug() << "commandsPressed";
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
*/
void MainWindow::fetchPressed(){
    qDebug() << "FETCH";
    //change_values(x_pos, y_pos, z_pos);
    qDebug() << "Fetch pressed";
    move_direction = "extend";

    reset_targets();

    push_command("0", fetch_x, x_pos);
    push_command("1", fetch_y, y_pos);
    push_command("2", fetch_z, z_pos);
    push_command("3", fetch_claw, claw_pos); // TODO - target_claw

    write_to_arduino();
}

void MainWindow::tutorialPressed(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::settingsHelpPressed(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::settingsPressed(){
    //QHoverSensitiveButton::hoverMode = false;
    ui->stackedWidget->setCurrentIndex(2);
    if (change_hover_vals){
        ui->change_fetch_vals_button->setText("ON");
    }
    else{
        ui->change_fetch_vals_button->setText("OFF");
    }
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

void MainWindow::move_delay_up() {
    int new_move_delay = move_delay + 10;
    if (new_move_delay <= 999){
        move_delay = new_move_delay;
        qDebug() << "Move delay: " + QString::number(new_move_delay);
        command_queue.push_back(QPair<QString, int>("4", new_move_delay));

        ui->move_delay_label->setText(QString::number(double(move_delay) / 1000.0, 'f', 2) + " secs");

        write_to_arduino();
    }
}

void MainWindow::move_delay_down() {
    int new_move_delay = move_delay - 10;
    if (new_move_delay >= 0) {
        move_delay = new_move_delay;
        qDebug() << "Move delay: " + QString::number(new_move_delay);
        command_queue.push_back(QPair<QString, int>("4", new_move_delay));
        ui->move_delay_label->setText(QString::number(double(move_delay) / 1000.0, 'f', 2) + " secs");
        write_to_arduino();
    }
}

void MainWindow::arm_movement_degrees_up() {
    if (arm_movement_degrees + 1 <= 15) {
        qDebug() << "Arm movement degrees: " + QString::number(++arm_movement_degrees);
        ui->arm_rotation_label->setText(QString::number(arm_movement_degrees) + " degrees");
    }
}

void MainWindow::arm_movement_degrees_down() {
    if (arm_movement_degrees - 1 >= 3) {
        qDebug() << "Arm movement degrees: " + QString::number(--arm_movement_degrees);
        ui->arm_rotation_label->setText(QString::number(arm_movement_degrees) + " degrees");
    }
}

void MainWindow::claw_movement_degrees_up() {
    if (claw_movement_degrees + 1 <= 10) {
        qDebug() << "Claw movement degrees: " + QString::number(++claw_movement_degrees);
        ui->claw_rotation_label->setText(QString::number(claw_movement_degrees) + " degrees");
    }
}

void MainWindow::claw_movement_degrees_down() {
    if (claw_movement_degrees - 1 >= 3) {
        qDebug() << "Claw movement degrees: " + QString::number(--claw_movement_degrees);
        ui->claw_rotation_label->setText(QString::number(claw_movement_degrees) + " degrees");
    }
}

//void MainWindow::changeLabel(){
//    if (ui->label->text() == "Hover + Hold"){
//        ui->label->setText("Press Button");
//        ui->hoverButton->setText("OFF");
//    }
//    else{
//        ui->label->setText("Hover + Hold");
//        ui->hoverButton->setText("ON");
//    }
//}


// Called when we receive confirmation that the Arduino has finished processing a message
void MainWindow::received_confimation(){
    QByteArray data = port.readAll();
    qDebug() << "data is " << data;

    if (data == "X"){
        qDebug() << "Arduino movement completed";
        ready_to_send = true;
        write_to_arduino();
    }
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
        case 4:
            move_delay = command_data.second;
            break;
        default:
            qDebug() << "This shouldn't be called... something went wrong";
            break;
    }
    QString data_to_send = command_data.first + QString::number(command_data.second) + "X";
    port.write(data_to_send.toStdString().c_str(), data_to_send.length());
}

// Called whenever a new command is added to the queue
void MainWindow::write_to_arduino(){
    if (!command_queue.empty() && ready_to_send){
        ready_to_send = false;
        send_next_command();
    }
}

void MainWindow::move_down(){
    qDebug() << "Down pressed";
    if (move_direction != "down"){
        move_direction = "down";
        reset_targets();
    }
    target_y += arm_movement_degrees;
    if (target_y <= 35){
        command_queue.push_back(QPair<QString, int>("1", target_y));
        write_to_arduino();
    }
}
void MainWindow::move_up(){
    qDebug() << "Up pressed";
    if (move_direction != "rise"){
        move_direction = "rise";
        reset_targets();
    }
    target_y -= arm_movement_degrees;
    if (target_y >= 0){
        command_queue.push_back(QPair<QString, int>("1", target_y));
        write_to_arduino();
    }
}

void MainWindow::move_left(){
    qDebug() << "Left pressed";
    if (move_direction != "left"){
        move_direction = "left";
        reset_targets();
    }
    target_x += arm_movement_degrees;
    if (target_x <= 180){
        command_queue.push_back(QPair<QString, int>("0", target_x));
        write_to_arduino();
    }

}
void MainWindow::move_right(){
    qDebug() << "Right pressed";
    if (move_direction != "right"){
        move_direction = "right";
        reset_targets();
    }
    target_x -= arm_movement_degrees;
    if (target_x >= 0){
        qDebug() << "Pushing x pos " << QString::number(target_x);
        command_queue.push_back(QPair<QString, int>("0", target_x));
        write_to_arduino();
    }
}
void MainWindow::move_forward() {
    qDebug() << "Forward pressed";
    if (move_direction != "forward") {
        move_direction = "forward";
        reset_targets();
    }
    target_z -= arm_movement_degrees;
    if (target_z >= 0) {
        command_queue.push_back(QPair<QString, int>("2", target_z));
        write_to_arduino();
    }
    else {
        qDebug() << "CAN'T MOVE ANY FARTHER";
    }

}
void MainWindow::move_backward() {
    qDebug() << "Backward pressed";
    if (move_direction != "backward") {
        move_direction = "backward";
        reset_targets();
    }
    target_z += arm_movement_degrees;
    if (target_z <= 60){
        command_queue.push_back(QPair<QString, int>("2", target_z));

        write_to_arduino();
    }
}

void MainWindow::move_finished(){
    qDebug() << "Retract";
    reset_targets();
    ui->stackedWidget->setCurrentIndex(4);
    QHoverSensitiveButton::activationTime.setHMS(-1,-1,-1,-1);

    if (change_hover_vals){
        fetch_x = x_pos;
        fetch_y = y_pos;
        fetch_z = z_pos;
        fetch_claw = claw_pos;
    }

    int countdown = 5;
    QString display = QString::number(countdown);
    this->ui->countdownLabel->setText(display);
    this->ui->countdownLabel2->setText("seconds remaining");

    while (!ready_to_send){
        qDebug() << "ERROR - Can't move arm yet\n";
        this->ui->countdownLabel->setText("");
        this->ui->countdownLabel2->setText("Oops! Please wait...");
        delay(200);
    }

    while (countdown > 0){
        delay(1000);
        countdown--;
        display = QString::number(countdown);
        this->ui->countdownLabel->setText(display);
    }

    push_command("0", 90, x_pos);
    push_command("1", 35, y_pos);
    push_command("2", 35, z_pos);
    write_to_arduino();

/*      x_pos = 93;
        y_pos = 40;
        z_pos = 40;
        write_to_arduino();
 */

     ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_clawLeft_pressed() {
    qDebug() << "Claw left pressed";
    if (move_direction != "claw_left"){
        move_direction = "claw_left";
        reset_targets();
    }
    target_claw += claw_movement_degrees;

    if (target_claw <= 140){
        command_queue.push_back(QPair<QString, int>("3", target_claw));
        write_to_arduino();
    }

}

void MainWindow::on_clawRight_pressed() {
    qDebug() << "Claw right pressed";
    if (move_direction != "claw_right"){
        move_direction = "claw_right";
        reset_targets();
    }
    target_claw -= claw_movement_degrees;
    if (target_claw >= 17){
        command_queue.push_back(QPair<QString, int>("3", target_claw));
        write_to_arduino();
    }

}

void MainWindow::invalid_commands(QByteArray TCP_info){

    //QString full_voice_transcript = QTextCodec::codecForMib(1015)->toUnicode(TCP_data);
    QString full_voice_transcript = TCP_info;
    // Check to see if the first two characters are "m:"
    // If yes, this is the full transcript. Otherwise, this is an invalid command.

    qDebug() << full_voice_transcript;
    qDebug() << full_voice_transcript.left(2);
    if (full_voice_transcript.size() > 2 && full_voice_transcript.left(2) == "m:") {
        //ui->ready_label->setText(full_voice_transcript.mid(2));
        this->ui->voice_label->setText("You said: " + full_voice_transcript.right(full_voice_transcript.size() - 2));
    } else {
        qDebug() << "Error in parse_TCP_command: Could not recognize TCP_Data";
    }
}

void MainWindow::message_too_long_error() {
    ui->voice_label->setText("Uh oh! Couldn't request results from Google Speech Recognition service");
}

void MainWindow::parsing_error(){
    ui->voice_label->setText("Oops! I couldn't understand. Please retry your message.");
}

void MainWindow::stopPressed() {
    qDebug() << "Stop pressed";
    reset_targets();
}

void MainWindow::reset_targets(){
    target_x = x_pos;
    target_y = y_pos;
    target_z = z_pos;
    target_claw = claw_pos;
    command_queue.clear();
}

void MainWindow::hoverButtonEntered(){
    QHoverSensitiveButton::hoverMode = !QHoverSensitiveButton::hoverMode;
//    emit changeLabel();
    qDebug() << "Hover button toggled";
}

void MainWindow::toggle_change_to_fetch_vals(){
    change_hover_vals = !change_hover_vals;
    if (change_hover_vals){
        ui->change_fetch_vals_button->setText("ON");
    }
    else{
        ui->change_fetch_vals_button->setText("OFF");
    }
}

void MainWindow::backPressed(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::retract_cancel(){
    reset_targets();
    ui->stackedWidget->setCurrentIndex(1);
}
