/****************************************************************************
** Meta object code from reading C++ file 'shorturlobject.h'
**
** Created: Sat Dec 15 18:06:40 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/shorturlobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shorturlobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShorturlObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      19,   15, 0x02095003,
      30,   22, 0x0a095003,
      38,   22, 0x0a095003,
      42,   15, 0x02095003,
      47,   22, 0x0a095003,
      58,   22, 0x0a095003,
      69,   15, 0x02095003,

       0        // eod
};

static const char qt_meta_stringdata_ShorturlObject[] = {
    "ShorturlObject\0int\0id\0QString\0keyword\0"
    "url\0hits\0created_at\0updated_at\0"
    "lock_revision\0"
};

void ShorturlObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ShorturlObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ShorturlObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ShorturlObject,
      qt_meta_data_ShorturlObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShorturlObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShorturlObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShorturlObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShorturlObject))
        return static_cast<void*>(const_cast< ShorturlObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ShorturlObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ShorturlObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getkeyword(); break;
        case 2: *reinterpret_cast< QString*>(_v) = geturl(); break;
        case 3: *reinterpret_cast< int*>(_v) = gethits(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getcreated_at(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getupdated_at(); break;
        case 6: *reinterpret_cast< int*>(_v) = getlock_revision(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: setkeyword(*reinterpret_cast< QString*>(_v)); break;
        case 2: seturl(*reinterpret_cast< QString*>(_v)); break;
        case 3: sethits(*reinterpret_cast< int*>(_v)); break;
        case 4: setcreated_at(*reinterpret_cast< QString*>(_v)); break;
        case 5: setupdated_at(*reinterpret_cast< QString*>(_v)); break;
        case 6: setlock_revision(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
