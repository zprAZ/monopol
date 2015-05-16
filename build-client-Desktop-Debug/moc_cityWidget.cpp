/****************************************************************************
** Meta object code from reading C++ file 'cityWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/cityWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cityWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cityWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   12,   11,   11, 0x0a,
      40,   37,   11,   11, 0x0a,
      61,   12,   11,   11, 0x0a,
      91,   79,   11,   11, 0x0a,
     143,   12,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cityWidget[] = {
    "cityWidget\0\0id,inp\0doHouse(int,bool)\0"
    "id\0deleteAllHouses(int)\0doHotel(int,bool)\0"
    "id,flag,inp\0"
    "setOwnershipFlag(int,bool,boardWidget::playerColor)\0"
    "setMortgageFlag(int,bool)\0"
};

void cityWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cityWidget *_t = static_cast<cityWidget *>(_o);
        switch (_id) {
        case 0: _t->doHouse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->deleteAllHouses((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->doHotel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->setOwnershipFlag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< boardWidget::playerColor(*)>(_a[3]))); break;
        case 4: _t->setMortgageFlag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData cityWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cityWidget::staticMetaObject = {
    { &boardWidget::staticMetaObject, qt_meta_stringdata_cityWidget,
      qt_meta_data_cityWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cityWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cityWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cityWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cityWidget))
        return static_cast<void*>(const_cast< cityWidget*>(this));
    return boardWidget::qt_metacast(_clname);
}

int cityWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = boardWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
