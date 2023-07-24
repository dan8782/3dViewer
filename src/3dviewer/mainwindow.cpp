#include "mainwindow.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include "myopenglwidget.h"
#include "ui_mainwindow.h"

extern "C" {
#include "../cfiles/s21_c_libs.h"
};

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

    settings.setValue("X_translation", ui->doubleSpinBox_translations_x->value());
    settings.setValue("Y_translation", ui->doubleSpinBox_translations_y->value());
    settings.setValue("Z_translation", ui->doubleSpinBox_translations_z->value());

    settings.setValue("X_rotation", ui->doubleSpinBox_rotation_x->value());
    settings.setValue("Y_rotation", ui->doubleSpinBox_rotation_y->value());
    settings.setValue("Z_rotation", ui->doubleSpinBox_rotation_z->value());

    settings.setValue("scale", ui->horizontalSlider_scale->value());

    settings.setValue("edges_format", ui->widget->edge_type);

    //  settings.setValue("vertical_color", ui->widget->vertical_color);
}

void MainWindow::loadSettings() {
    QSettings settings("settings_3D", "Conf");

    ui->doubleSpinBox_translations_x->setValue(
        settings.value("X_translation", 0).toInt());
    ui->widget->x_move = ui->doubleSpinBox_translations_x->value();
    ui->doubleSpinBox_translations_y->setValue(
        settings.value("Y_translation", 0).toInt());
    ui->widget->y_move = ui->doubleSpinBox_translations_y->value();
    ui->doubleSpinBox_translations_z->setValue(
        settings.value("Z_translation", 0).toInt());
    ui->widget->z_move = ui->doubleSpinBox_translations_z->value();

    ui->doubleSpinBox_rotation_x->setValue(
        settings.value("X_rotation", 0).toDouble());
    ui->widget->x_rotate = ui->doubleSpinBox_rotation_x->value();
    ui->doubleSpinBox_rotation_y->setValue(
        settings.value("Y_rotation", 0).toDouble());
    ui->widget->y_rotate = ui->doubleSpinBox_rotation_y->value();
    ui->doubleSpinBox_rotation_z->setValue(
        settings.value("Z_rotation", 0).toDouble());
    ui->widget->z_rotate = ui->doubleSpinBox_rotation_z->value();

    ui->horizontalSlider_scale->setValue(settings.value("scale", 0).toInt());
    ui->widget->scale = ui->horizontalSlider_scale->value() * 0.1;

    //    ui->widget->vertical_color = settings.value("vertical_color");
}

void MainWindow::on_pushButton_choose_file_clicked() {
    QString fileName =
        QFileDialog::getOpenFileName(this, "Open a file", "/Users", "*.obj");
    if (fileName != "") {
        auto path = fileName.toStdString();
        struct viwer_input input;
        struct parser_output output;
        input.file_path = path.c_str();
        int result = parse_obj_file(input, &output);
        ui->widget->points = output.points;
        ui->widget->lines = output.poligons_value;
        ui->widget->renderStatus = false;
        ui->widget->current_output = output;
        ui->textEdit_edges_count->setText("0");
        ui->textEdit_verticles_count->setText("0");
        ui->textEdit_filename->setText(fileName.split('/').last());
        ui->textEdit_verticles_count->setText(QString::number(output.points_count));
        ui->textEdit_edges_count->setText(QString::number(output.poligons_count));
    }
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
