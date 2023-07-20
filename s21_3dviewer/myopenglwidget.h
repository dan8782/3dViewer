#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#define GL_SILENCE_DEPRECATION
#include <QKeyEvent>
#include <QtOpenGLWidgets/QtOpenGLWidgets>

class MyOpenGLWidget : public QOpenGLWidget {
    Q_OBJECT
public:
    MyOpenGLWidget(QWidget *parent = nullptr);

    // масштаб
    double scale = 1;

    // перемещение
    double x_move = 0;
    double y_move = 0;


    // перспектива
    int perspective = 1;


    void *points;
    void *lines;

    bool renderStatus = true;

protected:
    void initializeGL() override;

    /**
   * @brief Отрисовка окна. В данном методе задаётся
   * перспектива,цвет фона, и вызываются методы отрисовки
   * точек и линий
   */
    void paintGL() override;

};

#endif  // MYOPENGLWIDGET_H
