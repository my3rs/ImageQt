/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[494];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 25), // "on_actionAdjust_triggered"
QT_MOC_LITERAL(4, 62, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(5, 87, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(6, 111, 9), // "imagePath"
QT_MOC_LITERAL(7, 121, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(8, 148, 26), // "on_actionRestore_triggered"
QT_MOC_LITERAL(9, 175, 24), // "on_actionRight_triggered"
QT_MOC_LITERAL(10, 200, 23), // "on_actionLeft_triggered"
QT_MOC_LITERAL(11, 224, 25), // "on_actionNormal_triggered"
QT_MOC_LITERAL(12, 250, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(13, 275, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(14, 303, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(15, 330, 17), // "receiveZoomFactor"
QT_MOC_LITERAL(16, 348, 6), // "factor"
QT_MOC_LITERAL(17, 355, 21), // "receiveGaussianFactor"
QT_MOC_LITERAL(18, 377, 6), // "radius"
QT_MOC_LITERAL(19, 384, 23), // "on_zoomAction_triggered"
QT_MOC_LITERAL(20, 408, 32), // "on_actionGaussian_blur_triggered"
QT_MOC_LITERAL(21, 441, 28), // "on_actionGrayscale_triggered"
QT_MOC_LITERAL(22, 470, 23) // "on_actionWarm_triggered"

    },
    "MainWindow\0on_actionExit_triggered\0\0"
    "on_actionAdjust_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionOpen_triggered\0imagePath\0"
    "on_actionSave_As_triggered\0"
    "on_actionRestore_triggered\0"
    "on_actionRight_triggered\0"
    "on_actionLeft_triggered\0"
    "on_actionNormal_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionZoom_Out_triggered\0"
    "on_actionZoom_In_triggered\0receiveZoomFactor\0"
    "factor\0receiveGaussianFactor\0radius\0"
    "on_zoomAction_triggered\0"
    "on_actionGaussian_blur_triggered\0"
    "on_actionGrayscale_triggered\0"
    "on_actionWarm_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    1,  112,    2, 0x08 /* Private */,
       5,    0,  115,    2, 0x28 /* Private | MethodCloned */,
       7,    0,  116,    2, 0x08 /* Private */,
       8,    0,  117,    2, 0x08 /* Private */,
       9,    0,  118,    2, 0x08 /* Private */,
      10,    0,  119,    2, 0x08 /* Private */,
      11,    0,  120,    2, 0x08 /* Private */,
      12,    0,  121,    2, 0x08 /* Private */,
      13,    0,  122,    2, 0x08 /* Private */,
      14,    0,  123,    2, 0x08 /* Private */,
      15,    1,  124,    2, 0x08 /* Private */,
      17,    1,  127,    2, 0x08 /* Private */,
      19,    0,  130,    2, 0x08 /* Private */,
      20,    0,  131,    2, 0x08 /* Private */,
      21,    0,  132,    2, 0x08 /* Private */,
      22,    0,  133,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_actionAdjust_triggered(); break;
        case 2: _t->on_actionClose_triggered(); break;
        case 3: _t->on_actionOpen_triggered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_actionOpen_triggered(); break;
        case 5: _t->on_actionSave_As_triggered(); break;
        case 6: _t->on_actionRestore_triggered(); break;
        case 7: _t->on_actionRight_triggered(); break;
        case 8: _t->on_actionLeft_triggered(); break;
        case 9: _t->on_actionNormal_triggered(); break;
        case 10: _t->on_actionAbout_triggered(); break;
        case 11: _t->on_actionZoom_Out_triggered(); break;
        case 12: _t->on_actionZoom_In_triggered(); break;
        case 13: _t->receiveZoomFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->receiveGaussianFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_zoomAction_triggered(); break;
        case 16: _t->on_actionGaussian_blur_triggered(); break;
        case 17: _t->on_actionGrayscale_triggered(); break;
        case 18: _t->on_actionWarm_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
