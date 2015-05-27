/****************************************************************************
** Meta object code from reading C++ file 'ServerConnector.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/ServerConnector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerConnector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerConnector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x05,
      58,   46,   16,   16, 0x05,
      94,   89,   16,   16, 0x05,
     135,  118,   16,   16, 0x05,
     165,  118,   16,   16, 0x05,
     202,  196,   16,   16, 0x05,
     226,   17,   16,   16, 0x05,
     260,  256,   16,   16, 0x05,
     288,  256,   16,   16, 0x05,
     314,  256,   16,   16, 0x05,
     351,  344,   16,   16, 0x05,
     378,  375,   16,   16, 0x05,
     405,  344,   16,   16, 0x05,
     450,  429,   16,   16, 0x05,
     487,  344,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     536,  519,   16,   16, 0x0a,
     567,  559,   16,   16, 0x0a,
     600,   16,   16,   16, 0x0a,
     622,  559,   16,   16, 0x0a,
     650,   16,   16,   16, 0x0a,
     668,   16,   16,   16, 0x0a,
     688,   16,   16,   16, 0x08,
     721,  715,   16,   16, 0x08,
     757,   16,   16,   16, 0x08,
     788,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerConnector[] = {
    "ServerConnector\0\0message\0errorSignal(QString)\0"
    "id,question\0askQuestionSignal(int,QString)\0"
    "info\0showInfoSignal(QString)\0"
    "placeId,playerId\0tokenIsLeavingSignal(int,int)\0"
    "tokenIsEnteringSignal(int,int)\0round\0"
    "displayRoundSignal(int)\0"
    "displayMessageSignal(QString)\0inp\0"
    "displayWealthSignal(double)\0"
    "displayCashSignal(double)\0"
    "displayPrisonCardsSignal(int)\0id,inp\0"
    "doHouseSignal(int,bool)\0id\0"
    "deleteAllHousesSignal(int)\0"
    "doHotelSignal(int,bool)\0id,flag,playerNumber\0"
    "setOwnershipFlagSignal(int,bool,int)\0"
    "setMortgageFlagSignal(int,bool)\0"
    "messageId,answer\0sendResponse(int,bool)\0"
    "ip,port\0establishConnection(QString,int)\0"
    "establishConnection()\0setTcpSettings(QString,int)\0"
    "closeConnection()\0handleDiceRequest()\0"
    "connectionClosedByServer()\0error\0"
    "error(QAbstractSocket::SocketError)\0"
    "connectionHasBeenEstablished()\0"
    "readDataFromSocket()\0"
};

void ServerConnector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerConnector *_t = static_cast<ServerConnector *>(_o);
        switch (_id) {
        case 0: _t->errorSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->askQuestionSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->showInfoSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->tokenIsLeavingSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->tokenIsEnteringSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->displayRoundSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->displayMessageSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->displayWealthSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->displayCashSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->displayPrisonCardsSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->doHouseSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->deleteAllHousesSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->doHotelSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->setOwnershipFlagSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->setMortgageFlagSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->sendResponse((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->establishConnection((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->establishConnection(); break;
        case 18: _t->setTcpSettings((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->closeConnection(); break;
        case 20: _t->handleDiceRequest(); break;
        case 21: _t->connectionClosedByServer(); break;
        case 22: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 23: _t->connectionHasBeenEstablished(); break;
        case 24: _t->readDataFromSocket(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerConnector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerConnector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerConnector,
      qt_meta_data_ServerConnector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerConnector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerConnector))
        return static_cast<void*>(const_cast< ServerConnector*>(this));
    return QObject::qt_metacast(_clname);
}

int ServerConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ServerConnector::errorSignal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerConnector::askQuestionSignal(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServerConnector::showInfoSignal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ServerConnector::tokenIsLeavingSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ServerConnector::tokenIsEnteringSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ServerConnector::displayRoundSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ServerConnector::displayMessageSignal(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ServerConnector::displayWealthSignal(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ServerConnector::displayCashSignal(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ServerConnector::displayPrisonCardsSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ServerConnector::doHouseSignal(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ServerConnector::deleteAllHousesSignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ServerConnector::doHotelSignal(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ServerConnector::setOwnershipFlagSignal(int _t1, bool _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ServerConnector::setMortgageFlagSignal(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_END_MOC_NAMESPACE
