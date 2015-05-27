/****************************************************************************
** Meta object code from reading C++ file 'ClientSocket.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/ClientSocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      27,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   52,   13,   13, 0x0a,
      93,   81,   13,   13, 0x0a,
     139,  122,   13,   13, 0x0a,
     174,  122,   13,   13, 0x0a,
     225,  210,   13,   13, 0x0a,
     282,  258,   13,   13, 0x0a,
     317,  210,   13,   13, 0x0a,
     344,  210,   13,   13, 0x0a,
     379,  371,   13,   13, 0x0a,
     414,  407,   13,   13, 0x0a,
     446,   52,   13,   13, 0x0a,
     472,   52,   13,   13, 0x0a,
     496,   52,   13,   13, 0x0a,
     517,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientSocket[] = {
    "ClientSocket\0\0diceSignal()\0"
    "questionResponseSignal()\0inp\0"
    "sendInfoMessage(QString)\0roundNumber\0"
    "sendCurrentRoundMessage(int)\0"
    "placeId,playerId\0sendTokenIsLeavingMessage(int,int)\0"
    "sendTokenIsEnteringMessage(int,int)\0"
    "placeId,status\0sendMortgageFlagStatus(int,bool)\0"
    "placeId,status,playerId\0"
    "sendOwnershipMessage(int,bool,int)\0"
    "sendHotelMessage(int,bool)\0"
    "sendHouseMessage(int,bool)\0placeId\0"
    "deleteAllHousesMessage(int)\0number\0"
    "sendPrisonCardsInformation(int)\0"
    "sendWealthMessage(double)\0"
    "sendCashMessage(double)\0showMessage(QString)\0"
    "readClient()\0"
};

void ClientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientSocket *_t = static_cast<ClientSocket *>(_o);
        switch (_id) {
        case 0: _t->diceSignal(); break;
        case 1: _t->questionResponseSignal(); break;
        case 2: _t->sendInfoMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sendCurrentRoundMessage((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->sendTokenIsLeavingMessage((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 5: _t->sendTokenIsEnteringMessage((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 6: _t->sendMortgageFlagStatus((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 7: _t->sendOwnershipMessage((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 8: _t->sendHotelMessage((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->sendHouseMessage((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->deleteAllHousesMessage((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 11: _t->sendPrisonCardsInformation((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 12: _t->sendWealthMessage((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 13: _t->sendCashMessage((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 14: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->readClient(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientSocket,
      qt_meta_data_ClientSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientSocket))
        return static_cast<void*>(const_cast< ClientSocket*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ClientSocket::diceSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClientSocket::questionResponseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
