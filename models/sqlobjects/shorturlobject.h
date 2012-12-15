#ifndef SHORTURLOBJECT_H
#define SHORTURLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ShorturlObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString keyword;
    QString url;
    int hits;
    QString created_at;
    QString updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Keyword,
        Url,
        Hits,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString keyword READ getkeyword WRITE setkeyword)
    T_DEFINE_PROPERTY(QString, keyword)
    Q_PROPERTY(QString url READ geturl WRITE seturl)
    T_DEFINE_PROPERTY(QString, url)
    Q_PROPERTY(int hits READ gethits WRITE sethits)
    T_DEFINE_PROPERTY(int, hits)
    Q_PROPERTY(QString created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QString, created_at)
    Q_PROPERTY(QString updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QString, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // SHORTURLOBJECT_H
