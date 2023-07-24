/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../3dviewer/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "loadSettings",
    "",
    "saveSettings",
    "on_pushButton_choose_file_clicked",
    "on_doubleSpinBox_translations_x_valueChanged",
    "arg1",
    "on_doubleSpinBox_translations_y_valueChanged",
    "on_doubleSpinBox_translations_z_valueChanged",
    "on_doubleSpinBox_rotation_x_valueChanged",
    "on_doubleSpinBox_rotation_y_valueChanged",
    "on_doubleSpinBox_rotation_z_valueChanged",
    "on_horizontalSlider_scale_valueChanged",
    "value"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[34];
    char stringdata5[45];
    char stringdata6[5];
    char stringdata7[45];
    char stringdata8[45];
    char stringdata9[41];
    char stringdata10[41];
    char stringdata11[41];
    char stringdata12[39];
    char stringdata13[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "loadSettings"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "saveSettings"
        QT_MOC_LITERAL(38, 33),  // "on_pushButton_choose_file_cli..."
        QT_MOC_LITERAL(72, 44),  // "on_doubleSpinBox_translations..."
        QT_MOC_LITERAL(117, 4),  // "arg1"
        QT_MOC_LITERAL(122, 44),  // "on_doubleSpinBox_translations..."
        QT_MOC_LITERAL(167, 44),  // "on_doubleSpinBox_translations..."
        QT_MOC_LITERAL(212, 40),  // "on_doubleSpinBox_rotation_x_v..."
        QT_MOC_LITERAL(253, 40),  // "on_doubleSpinBox_rotation_y_v..."
        QT_MOC_LITERAL(294, 40),  // "on_doubleSpinBox_rotation_z_v..."
        QT_MOC_LITERAL(335, 38),  // "on_horizontalSlider_scale_val..."
        QT_MOC_LITERAL(374, 5)   // "value"
    },
    "MainWindow",
    "loadSettings",
    "",
    "saveSettings",
    "on_pushButton_choose_file_clicked",
    "on_doubleSpinBox_translations_x_valueChanged",
    "arg1",
    "on_doubleSpinBox_translations_y_valueChanged",
    "on_doubleSpinBox_translations_z_valueChanged",
    "on_doubleSpinBox_rotation_x_valueChanged",
    "on_doubleSpinBox_rotation_y_valueChanged",
    "on_doubleSpinBox_rotation_z_valueChanged",
    "on_horizontalSlider_scale_valueChanged",
    "value"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    1,   77,    2, 0x08,    4 /* Private */,
       7,    1,   80,    2, 0x08,    6 /* Private */,
       8,    1,   83,    2, 0x08,    8 /* Private */,
       9,    1,   86,    2, 0x08,   10 /* Private */,
      10,    1,   89,    2, 0x08,   12 /* Private */,
      11,    1,   92,    2, 0x08,   14 /* Private */,
      12,    1,   95,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'loadSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_choose_file_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_translations_x_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_doubleSpinBox_translations_y_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_doubleSpinBox_translations_z_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_doubleSpinBox_rotation_x_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_doubleSpinBox_rotation_y_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_doubleSpinBox_rotation_z_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_horizontalSlider_scale_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadSettings(); break;
        case 1: _t->saveSettings(); break;
        case 2: _t->on_pushButton_choose_file_clicked(); break;
        case 3: _t->on_doubleSpinBox_translations_x_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->on_doubleSpinBox_translations_y_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_translations_z_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->on_doubleSpinBox_rotation_x_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_rotation_y_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->on_doubleSpinBox_rotation_z_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->on_horizontalSlider_scale_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
