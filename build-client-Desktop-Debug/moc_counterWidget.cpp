/****************************************************************************
** Meta object code from reading C++ file 'counterWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/counterWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'counterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_counterWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x0a,
      86,   79,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_counterWidget[] = {
    "counterWidget\0\0id,flag,inp\0"
    "setOwnershipFlag(int,bool,boardWidget::playerColor)\0"
    "id,inp\0setMortgageFlag(int,bool)\0"
};

void counterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        counterWidget *_t = static_cast<counterWidget *>(_o);
        switch (_id) {
        case 0: _t->setOwnershipFlag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< boardWidget::playerColor(*)>(_a[3]))); break;
        case 1: _t->setMortgageFlag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData counterWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject counterWidget::staticMetaObject = {
    { &boardWidget::staticMetaObject, qt_meta_stringdata_counterWidget,
      qt_meta_data_counterWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &counterWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *counterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *counterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_counterWidget))
        return static_cast<void*>(const_cast< counterWidget*>(this));
    return boardWidget::qt_metacast(_clname);
}

int counterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = boardWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
