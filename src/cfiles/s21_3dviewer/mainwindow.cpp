#include "mainwindow.h"

#include <cstdio>
#include <cstring>
#include <iostream>

#include "myopenglwidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("3d viewer");
    loadSettings();
}

MainWindow::~MainWindow() {
    saveSettings();
    delete ui;
}

void MainWindow::saveSettings() {
    QSettings settings("settings_3D", "Conf");

    //  settings.setValue("vertical_color", ui->widget->vertical_color);
}

void MainWindow::loadSettings() {
    QSettings settings("settings_3D", "Conf");

    //    ui->widget->vertical_color = settings.value("vertical_color");
}

void MainWindow::on_pushButton_choose_file_clicked() {
    QString fileName =
        QFileDialog::getOpenFileName(this, "Open a file", "/Users", "*.obj");
}

void MainWindow::on_doubleSpinBox_translations_x_valueChanged(double arg1) {
    ui->widget->x_move = arg1;
}

void MainWindow::on_doubleSpinBox_translations_y_valueChanged(double arg1) {
    ui->widget->y_move = arg1;
}

void MainWindow::on_doubleSpinBox_translations_z_valueChanged(double arg1) {
    ui->widget->z_move = arg1;
}

void MainWindow::on_doubleSpinBox_rotation_x_valueChanged(double arg1) {
    ui->widget->x_rotate = arg1;
}

void MainWindow::on_doubleSpinBox_rotation_y_valueChanged(double arg1) {
    ui->widget->y_rotate = arg1;
}

void MainWindow::on_doubleSpinBox_rotation_z_valueChanged(double arg1) {
    ui->widget->z_rotate = arg1;
}

void MainWindow::on_horizontalSlider_scale_valueChanged(int value) {
    ui->widget->scale = value * 0.1;
}

void MainWindow::on_pushButton_color_background_clicked() {
    ui->widget->background_color =
        QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

void MainWindow::on_pushButton_color_edge_clicked() {
    ui->widget->edge_color =
        QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

void MainWindow::on_pushButton_color_verticles_clicked() {
    ui->widget->vertical_color =
        QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

void MainWindow::on_radioButton_central_clicked() {
    ui->widget->perspective = 0;
}

void MainWindow::on_radioButton_parallel_clicked() {
    ui->widget->perspective = 1;
}

void MainWindow::on_horizontalSlider_edge_size_valueChanged(int value) {
    ui->widget->edge_size = value;
}

void MainWindow::on_radioButton_edge_none_clicked() {
    ui->widget->edge_type = 0;
}

void MainWindow::on_radioButton_edge_circle_clicked() {
    ui->widget->edge_type = GL_POINT_SMOOTH;
}

void MainWindow::on_radioButton_edge_square_clicked() {
    ui->widget->edge_type = GL_POINT;
}

void MainWindow::on_horizontalSlider_verticles_size_valueChanged(int value) {
    ui->widget->vertical_size = value;
}

void MainWindow::on_radioButton_verticle_solid_clicked() {
    ui->widget->vertical_type = GL_LINES;
}

void MainWindow::on_radioButton_verticle_dashed_clicked() {
    ui->widget->vertical_type = GL_LINE_STIPPLE;
}

void MainWindow::on_pushButton_screen_clicked() {
    QString str = QFileDialog::getSaveFileName();

    if (!str.isEmpty()) {
        ui->widget->grab().save(str);
    }
}

void MainWindow::on_pushButton_gif_clicked() {
    check = 0;
    timer_gif = new QTimer();
    connect(timer_gif, SIGNAL(timeout()), this, SLOT(timer_grab()));
    timer_gif->start(100);
    ui->pushButton_gif->setEnabled(0);
}

void MainWindow::timer_grab() {
    if (check > 49) {
        timer_gif->stop();
        disconnect(timer_gif);
        check = 0;
        for (int i = 0; i < 50; gif.addFrame(mp[i++], 200)) {
        }
        QString str =
            QFileDialog::getSaveFileName(0, "Сохранить файл как", "", "*.gif");
        gif.save(str);
        ui->pushButton_gif->setText("GIF");
        ui->pushButton_gif->setEnabled(1);
    } else {
        mp[check] = ui->widget->grab().toImage();
        check += 1;
        ui->pushButton_gif->setText(QString::number(check / 10));
    }
}

void MainWindow::print_grab() {
    if (check > 49) {
        timer_gif->stop();
        disconnect(timer_gif);
    } else {
        gif.addFrame(mp[check]);
        check += 1;
    }
}
