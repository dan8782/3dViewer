#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#define GL_SILENCE_DEPRECATION
#include <QKeyEvent>
#include <QtOpenGLWidgets/QtOpenGLWidgets>
extern "C" {
#include "../cfiles/s21_c_libs.h"
};

class MyOpenGLWidget : public QOpenGLWidget {
    Q_OBJECT
public:
    MyOpenGLWidget(QWidget *parent = nullptr);

    // масштаб
    double scale = 1;
    int points_count;

    // перемещение
    double x_move = 0;
    double y_move = 0;
    double z_move = 0;

    // вращение
    double x_rotate = 0;
    double last_x_rotate = 0;
    double y_rotate = 0;
    double last_y_rotate = 0;
    double z_rotate = 0;
    double last_z_rotate = 0;

    // перспектива
    int perspective = 1;

    // цвета
    QColor background_color = QColorConstants::White;
    QColor edge_color;
    QColor vertical_color;

    // размер
    int edge_size = 1;
    int vertical_size = 1;

    // тип
    int edge_type = GL_POINT;
    int vertical_type = GL_LINES;

    void *points;
    void *lines;
    void *points_print;

    bool renderStatus = true;
    void draw_points(const parser_output& output);
public:
    parser_output current_output;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void draw_lines();
    void rotate();
    void rotate_ox();
    void rotate_oy();
    void rotate_oz();

};

#endif  // MYOPENGLWIDGET_H
