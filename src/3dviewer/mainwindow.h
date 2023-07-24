#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define GL_SILENCE_DEPRECATION

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <vector>
extern "C" {
#include "../cfiles/s21_c_libs.h"
};
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  QImage mp[50];
  int check;
  QTimer *timer_gif;

 public:
  QSettings *settings;
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 public slots:
  void loadSettings();
  void saveSettings();

 private slots:

  void on_pushButton_choose_file_clicked();

  void on_doubleSpinBox_translations_x_valueChanged(double arg1);

  void on_doubleSpinBox_translations_y_valueChanged(double arg1);

  void on_doubleSpinBox_translations_z_valueChanged(double arg1);

  void on_doubleSpinBox_rotation_x_valueChanged(double arg1);

  void on_doubleSpinBox_rotation_y_valueChanged(double arg1);

  void on_doubleSpinBox_rotation_z_valueChanged(double arg1);

  void on_horizontalSlider_scale_valueChanged(int value);

 private:
  Ui::MainWindow *ui;
  MyOpenGLWidget *myopenglwidget;
};
#endif  // MAINWINDOW_H
