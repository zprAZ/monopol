/****************************************************************************
** Meta object code from reading C++ file 'mainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/mainWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      35,   21,   11,   11, 0x05,
      81,   21,   11,   11, 0x05,
     132,  126,   11,   11, 0x05,
     153,  145,   11,   11, 0x05,
     180,  176,   11,   11, 0x05,
     197,  176,   11,   11, 0x05,
     212,  176,   11,   11, 0x05,
     238,  231,   11,   11, 0x05,
     259,  256,   11,   11, 0x05,
     279,  231,   11,   11, 0x05,
     311,  297,   11,   11, 0x05,
     361,  231,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     402,  385,   11,   11, 0x0a,
     426,  385,   11,   11, 0x0a,
     451,  126,   11,   11, 0x0a,
     469,  145,   11,   11, 0x0a,
     493,  176,   11,   11, 0x0a,
     515,  176,   11,   11, 0x0a,
     535,  176,   11,   11, 0x0a,
     559,  231,   11,   11, 0x0a,
     577,  256,   11,   11, 0x0a,
     598,  231,   11,   11, 0x0a,
     637,  616,   11,   11, 0x0a,
     668,  231,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mainWidget[] = {
    "mainWidget\0\0dice_s()\0placeId,color\0"
    "tokenEntering_s(int,boardWidget::playerColor)\0"
    "tokenLeaving_s(int,boardWidget::playerColor)\0"
    "round\0round_s(int)\0message\0"
    "sendMessage_s(QString)\0inp\0wealth_s(double)\0"
    "cash_s(double)\0prisonCards_s(int)\0"
    "id,inp\0house_s(int,bool)\0id\0"
    "deleteHouses_s(int)\0hotel_s(int,bool)\0"
    "id,flag,color\0"
    "setOwnership_s(int,bool,boardWidget::playerColor)\0"
    "setMortgage_s(int,bool)\0placeId,playerId\0"
    "tokenIsLeaving(int,int)\0"
    "tokenIsEntering(int,int)\0displayRound(int)\0"
    "displayMessage(QString)\0displayWealth(double)\0"
    "displayCash(double)\0displayPrisonCards(int)\0"
    "doHouse(int,bool)\0deleteAllHouses(int)\0"
    "doHotel(int,bool)\0id,flag,playerNumber\0"
    "setOwnershipFlag(int,bool,int)\0"
    "setMortgageFlag(int,bool)\0"
};

void mainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mainWidget *_t = static_cast<mainWidget *>(_o);
        switch (_id) {
        case 0: _t->dice_s(); break;
        case 1: _t->tokenEntering_s((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< boardWidget::playerColor(*)>(_a[2]))); break;
        case 2: _t->tokenLeaving_s((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< boardWidget::playerColor(*)>(_a[2]))); break;
        case 3: _t->round_s((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendMessage_s((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->wealth_s((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->cash_s((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->prisonCards_s((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->house_s((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->deleteHouses_s((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->hotel_s((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->setOwnership_s((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< boardWidget::playerColor(*)>(_a[3]))); break;
        case 12: _t->setMortgage_s((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->tokenIsLeaving((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->tokenIsEntering((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->displayRound((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->displayMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->displayWealth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->displayCash((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->displayPrisonCards((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->doHouse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: _t->deleteAllHouses((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->doHotel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->setOwnershipFlag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 24: _t->setMortgageFlag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData mainWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainWidget,
      qt_meta_data_mainWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainWidget))
        return static_cast<void*>(const_cast< mainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void mainWidget::dice_s()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void mainWidget::tokenEntering_s(int _t1, boardWidget::playerColor _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mainWidget::tokenLeaving_s(int _t1, boardWidget::playerColor _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mainWidget::round_s(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void mainWidget::sendMessage_s(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void mainWidget::wealth_s(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void mainWidget::cash_s(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void mainWidget::prisonCards_s(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void mainWidget::house_s(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void mainWidget::deleteHouses_s(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void mainWidget::hotel_s(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void mainWidget::setOwnership_s(int _t1, bool _t2, boardWidget::playerColor _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void mainWidget::setMortgage_s(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
