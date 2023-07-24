#include "myopenglwidget.h"
#include <QDebug>
#include <cmath>


MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void MyOpenGLWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0 / 255.f, 0 / 255.f, 0 / 255.f, 1);
}

void MyOpenGLWidget::resizeGL(int w, int h) {
    glViewport(0,0,w,h);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MyOpenGLWidget::paintGL() {
    if (!renderStatus) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if (!perspective) {
          glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 1000);
        } else {
          glFrustum(-1.5, 1.5, -1.5, 1.5, 0.8, 1000);
          glTranslatef(0, 0, -2);
        }
        glMatrixMode(GL_MODELVIEW);
        glClearColor(background_color.redF(), background_color.greenF(),background_color.blueF(), 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rotate();
        draw_points(current_output);
        draw_lines();
        update();
    }
}

void MyOpenGLWidget::draw_points(const parser_output& output) {
    glEnable(edge_type);
    glPointSize(8);
    glColor3f(edge_color.redF(), edge_color.greenF(), edge_color.blueF());
    glBegin(GL_POINTS);
    for (int i = 0; i < output.points_count; i++) {
        struct point current_point = output.points[i];
        for (int j = 0; j < current_point.coordinates_count; j += 3) {
          double x = current_point.coordinates[j];
          double y = current_point.coordinates[j + 1];
          double z = current_point.coordinates[j + 2];
          glVertex3d((x + x_move) * scale, (y + y_move) * scale, (z + z_move) * scale);
          qDebug() << "Point" << (i + 1) << ":" << x << y << z;
        }
    }
    glEnd();
    glDisable(edge_type);
}

void MyOpenGLWidget::draw_lines() {
    glLineStipple(3, 0x1C47);
    glEnable(vertical_type);
    glLineWidth(vertical_size);
    glColor3f(vertical_color.redF(), vertical_color.greenF(), vertical_color.blueF());
    glBegin(GL_LINES);

    // Iterate through each polygon
    for (int i = 0; i < current_output.poligons_count; i++) {
        struct poligon& current_polygon = current_output.poligons_value[i];

        // Check if the polygon has at least two elements
        if (current_polygon.poligon_elems_count < 2)
          continue;

        // Iterate through the polygon elements
        for (int j = 0; j < current_polygon.poligon_elems_count; j++) {
          int from_index = current_polygon.poligon_elems[j] - 1;
          int to_index = current_polygon.poligon_elems[(j + 1) % current_polygon.poligon_elems_count] - 1;

          // Check if the vertex indices are valid
          if (from_index < 0 || from_index >= current_output.points_count ||
              to_index < 0 || to_index >= current_output.points_count)
              continue;

          struct point& from_point = current_output.points[from_index];
          struct point& to_point = current_output.points[to_index];

          double from_x = from_point.coordinates[0];
          double from_y = from_point.coordinates[1];
          double from_z = from_point.coordinates[2];

          double to_x = to_point.coordinates[0];
          double to_y = to_point.coordinates[1];
          double to_z = to_point.coordinates[2];

          glVertex3d((from_x + x_move) * scale, (from_y + y_move) * scale, (from_z + z_move) * scale);
          glVertex3d((to_x + x_move) * scale, (to_y + y_move) * scale, (to_z + z_move) * scale);
        }
    }

    glEnd();
    glDisable(vertical_type);
}

void MyOpenGLWidget::rotate() {
    if (x_rotate != last_x_rotate || y_rotate != last_y_rotate || z_rotate != last_z_rotate) {
        last_x_rotate = x_rotate;
        last_y_rotate = y_rotate;
        last_z_rotate = z_rotate;

        double angle_x = x_rotate * (3.14f / 180.0f);
        double angle_y = y_rotate * (3.14f / 180.0f);
        double angle_z = z_rotate * (3.14f / 180.0f);

        for (int i = 0; i < current_output.points_count; i++) {
          struct point& current_point = current_output.points[i];
          for (int j = 0; j < current_point.coordinates_count; j += 3) {
              double x = current_point.coordinates[j];
              double y = current_point.coordinates[j + 1];
              double z = current_point.coordinates[j + 2];

              // X-axis
              double temp_y = std::cos(angle_x) * y - std::sin(angle_x) * z;
              double temp_z = std::sin(angle_x) * y + std::cos(angle_x) * z;

              // Y-axis
              double temp_x = std::cos(angle_y) * x + std::sin(angle_y) * temp_z;
              double new_z = -std::sin(angle_y) * x + std::cos(angle_y) * temp_z;

              // Z-axis
              x = std::cos(angle_z) * temp_x - std::sin(angle_z) * temp_y;
              y = std::sin(angle_z) * temp_x + std::cos(angle_z) * temp_y;
              z = new_z;

              current_point.coordinates[j] = x;
              current_point.coordinates[j + 1] = y;
              current_point.coordinates[j + 2] = z;
          }
        }
        update();    }
}
