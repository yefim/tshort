#ifndef SHORTURL_H
#define SHORTURL_H

#include <QStringList>
#include <QDateTime>
#include <QHash>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TSqlObject;
class ShorturlObject;


class T_MODEL_EXPORT Shorturl : public TAbstractModel
{
public:
    Shorturl();
    Shorturl(const Shorturl &other);
    Shorturl(const ShorturlObject &object);
    ~Shorturl();

    int id() const;
    QString keyword() const;
    void setKeyword(const QString &keyword);
    QString url() const;
    void setUrl(const QString &url);
    int hits() const;
    void setHits(int hits);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Shorturl &operator=(const Shorturl &other);

    static Shorturl create(const QString &keyword, const QString &url, int hits);
    static Shorturl create(const QVariantHash &values);
    static Shorturl get(int id);
    static Shorturl get(int id, int lockRevision);
    static QList<Shorturl> getAll();

private:
    QSharedDataPointer<ShorturlObject> d;

    TSqlObject *data();
    const TSqlObject *data() const;
};

Q_DECLARE_METATYPE(Shorturl)
Q_DECLARE_METATYPE(QList<Shorturl>)

#endif // SHORTURL_H
