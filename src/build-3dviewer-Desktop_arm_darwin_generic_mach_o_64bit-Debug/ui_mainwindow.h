/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <myopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    MyOpenGLWidget *widget;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_choose_file;
    QDoubleSpinBox *doubleSpinBox_translations_x;
    QDoubleSpinBox *doubleSpinBox_translations_z;
    QDoubleSpinBox *doubleSpinBox_translations_y;
    QDoubleSpinBox *doubleSpinBox_rotation_y;
    QDoubleSpinBox *doubleSpinBox_rotation_x;
    QDoubleSpinBox *doubleSpinBox_rotation_z;
    QSlider *horizontalSlider_scale;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QTextEdit *textEdit_filename;
    QLabel *label;
    QTextEdit *textEdit_edges_count;
    QLabel *label_2;
    QTextEdit *textEdit_verticles_count;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1047, 697);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new MyOpenGLWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 531, 531));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 37, 34)"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 30, 91, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(560, 80, 58, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(570, 130, 58, 16));
        pushButton_choose_file = new QPushButton(centralwidget);
        pushButton_choose_file->setObjectName("pushButton_choose_file");
        pushButton_choose_file->setGeometry(QRect(570, 500, 100, 32));
        doubleSpinBox_translations_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_translations_x->setObjectName("doubleSpinBox_translations_x");
        doubleSpinBox_translations_x->setGeometry(QRect(650, 20, 121, 31));
        doubleSpinBox_translations_x->setMinimum(-100.000000000000000);
        doubleSpinBox_translations_x->setMaximum(100.000000000000000);
        doubleSpinBox_translations_x->setSingleStep(1.000000000000000);
        doubleSpinBox_translations_z = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_translations_z->setObjectName("doubleSpinBox_translations_z");
        doubleSpinBox_translations_z->setGeometry(QRect(910, 20, 121, 31));
        doubleSpinBox_translations_z->setMinimum(-100.000000000000000);
        doubleSpinBox_translations_z->setMaximum(100.000000000000000);
        doubleSpinBox_translations_y = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_translations_y->setObjectName("doubleSpinBox_translations_y");
        doubleSpinBox_translations_y->setGeometry(QRect(780, 20, 121, 31));
        doubleSpinBox_translations_y->setMinimum(-100.000000000000000);
        doubleSpinBox_translations_y->setMaximum(100.000000000000000);
        doubleSpinBox_rotation_y = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_rotation_y->setObjectName("doubleSpinBox_rotation_y");
        doubleSpinBox_rotation_y->setGeometry(QRect(780, 70, 121, 31));
        doubleSpinBox_rotation_y->setMinimum(-360.000000000000000);
        doubleSpinBox_rotation_y->setMaximum(360.000000000000000);
        doubleSpinBox_rotation_y->setSingleStep(5.000000000000000);
        doubleSpinBox_rotation_x = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_rotation_x->setObjectName("doubleSpinBox_rotation_x");
        doubleSpinBox_rotation_x->setGeometry(QRect(650, 70, 121, 31));
        doubleSpinBox_rotation_x->setMinimum(-360.000000000000000);
        doubleSpinBox_rotation_x->setMaximum(360.000000000000000);
        doubleSpinBox_rotation_x->setSingleStep(5.000000000000000);
        doubleSpinBox_rotation_z = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_rotation_z->setObjectName("doubleSpinBox_rotation_z");
        doubleSpinBox_rotation_z->setGeometry(QRect(910, 70, 121, 31));
        doubleSpinBox_rotation_z->setMinimum(-360.000000000000000);
        doubleSpinBox_rotation_z->setMaximum(360.000000000000000);
        doubleSpinBox_rotation_z->setSingleStep(5.000000000000000);
        horizontalSlider_scale = new QSlider(centralwidget);
        horizontalSlider_scale->setObjectName("horizontalSlider_scale");
        horizontalSlider_scale->setGeometry(QRect(650, 130, 351, 25));
        horizontalSlider_scale->setMinimum(10);
        horizontalSlider_scale->setMaximum(200);
        horizontalSlider_scale->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 561, 978, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 16));

        horizontalLayout->addWidget(label_3);

        textEdit_filename = new QTextEdit(layoutWidget);
        textEdit_filename->setObjectName("textEdit_filename");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit_filename->sizePolicy().hasHeightForWidth());
        textEdit_filename->setSizePolicy(sizePolicy1);
        textEdit_filename->setMaximumSize(QSize(16777215, 30));
        textEdit_filename->setReadOnly(true);
        textEdit_filename->setOverwriteMode(false);

        horizontalLayout->addWidget(textEdit_filename);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 16));

        horizontalLayout->addWidget(label);

        textEdit_edges_count = new QTextEdit(layoutWidget);
        textEdit_edges_count->setObjectName("textEdit_edges_count");
        sizePolicy1.setHeightForWidth(textEdit_edges_count->sizePolicy().hasHeightForWidth());
        textEdit_edges_count->setSizePolicy(sizePolicy1);
        textEdit_edges_count->setMaximumSize(QSize(16777215, 30));
        textEdit_edges_count->setReadOnly(true);

        horizontalLayout->addWidget(textEdit_edges_count);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 16));

        horizontalLayout->addWidget(label_2);

        textEdit_verticles_count = new QTextEdit(layoutWidget);
        textEdit_verticles_count->setObjectName("textEdit_verticles_count");
        sizePolicy1.setHeightForWidth(textEdit_verticles_count->sizePolicy().hasHeightForWidth());
        textEdit_verticles_count->setSizePolicy(sizePolicy1);
        textEdit_verticles_count->setMaximumSize(QSize(16777215, 30));
        textEdit_verticles_count->setReadOnly(true);

        horizontalLayout->addWidget(textEdit_verticles_count);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        pushButton_choose_file->setText(QCoreApplication::translate("MainWindow", "Choose file", nullptr));
        doubleSpinBox_translations_x->setSpecialValueText(QString());
        doubleSpinBox_translations_x->setPrefix(QCoreApplication::translate("MainWindow", "X: ", nullptr));
        doubleSpinBox_translations_z->setSpecialValueText(QString());
        doubleSpinBox_translations_z->setPrefix(QCoreApplication::translate("MainWindow", "Z: ", nullptr));
        doubleSpinBox_translations_y->setSpecialValueText(QString());
        doubleSpinBox_translations_y->setPrefix(QCoreApplication::translate("MainWindow", "Y: ", nullptr));
        doubleSpinBox_rotation_y->setSpecialValueText(QString());
        doubleSpinBox_rotation_y->setPrefix(QCoreApplication::translate("MainWindow", "Y: ", nullptr));
        doubleSpinBox_rotation_y->setSuffix(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        doubleSpinBox_rotation_x->setSpecialValueText(QString());
        doubleSpinBox_rotation_x->setPrefix(QCoreApplication::translate("MainWindow", "X: ", nullptr));
        doubleSpinBox_rotation_x->setSuffix(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        doubleSpinBox_rotation_z->setSpecialValueText(QString());
        doubleSpinBox_rotation_z->setPrefix(QCoreApplication::translate("MainWindow", "Z: ", nullptr));
        doubleSpinBox_rotation_z->setSuffix(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "File name:", nullptr));
        textEdit_filename->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> </p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Verticles:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
