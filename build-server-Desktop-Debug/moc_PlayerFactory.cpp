/****************************************************************************
** Meta object code from reading C++ file 'PlayerFactory.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/PlayerFactory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayerFactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlayerFactory[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      38,   29,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   14,   14,   14, 0x0a,
      80,   14,   14,   14, 0x0a,
      90,   87,   14,   14, 0x0a,
     124,  120,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PlayerFactory[] = {
    "PlayerFactory\0\0playerReady()\0playerId\0"
    "removePlayerFromBoard(int)\0createPlayer()\0"
    "test()\0id\0deleteDisconnectedPlayer(int)\0"
    "inp\0sendMessageToAllSockets(QString)\0"
};

void PlayerFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlayerFactory *_t = static_cast<PlayerFactory *>(_o);
        switch (_id) {
        case 0: _t->playerReady(); break;
        case 1: _t->removePlayerFromBoard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->createPlayer(); break;
        case 3: _t->test(); break;
        case 4: _t->deleteDisconnectedPlayer((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->sendMessageToAllSockets((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PlayerFactory::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlayerFactory::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PlayerFactory,
      qt_meta_data_PlayerFactory, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlayerFactory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlayerFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlayerFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerFactory))
        return static_cast<void*>(const_cast< PlayerFactory*>(this));
    return QObject::qt_metacast(_clname);
}

int PlayerFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PlayerFactory::playerReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PlayerFactory::removePlayerFromBoard(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
