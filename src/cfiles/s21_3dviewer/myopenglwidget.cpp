#include "myopenglwidget.h"
#include <cmath>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void MyOpenGLWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0 / 255.f, 0 / 255.f, 0 / 255.f, 1);
}

void MyOpenGLWidget::paintGL() {
    if (!renderStatus) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
    }
}

