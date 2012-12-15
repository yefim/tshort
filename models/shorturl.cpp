#include <TreeFrogModel>
#include "shorturl.h"
#include "shorturlobject.h"

Shorturl::Shorturl()
    : TAbstractModel(), d(new ShorturlObject)
{
    d->hits = 0;
}

Shorturl::Shorturl(const Shorturl &other)
    : TAbstractModel(), d(new ShorturlObject(*other.d))
{ }

Shorturl::Shorturl(const ShorturlObject &object)
    : TAbstractModel(), d(new ShorturlObject(object))
{ }

Shorturl::~Shorturl()
{
    // If the reference count becomes 0,
    // the shared data object 'ShorturlObject' is deleted.
}

int Shorturl::id() const
{
    return d->id;
}

QString Shorturl::keyword() const
{
    return d->keyword;
}

void Shorturl::setKeyword(const QString &keyword)
{
    d->keyword = keyword;
}

QString Shorturl::url() const
{
    return d->url;
}

void Shorturl::setUrl(const QString &url)
{
    d->url = url;
}

int Shorturl::hits() const
{
    return d->hits;
}

void Shorturl::setHits(int hits)
{
    d->hits = hits;
}

QString Shorturl::createdAt() const
{
    return d->created_at;
}

QString Shorturl::updatedAt() const
{
    return d->updated_at;
}

int Shorturl::lockRevision() const
{
    return d->lock_revision;
}

Shorturl &Shorturl::operator=(const Shorturl &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Shorturl Shorturl::create(const QString &keyword, const QString &url, int hits)
{
    ShorturlObject obj;
    obj.keyword = keyword;
    obj.url = url;
    obj.hits = hits;
    if (!obj.create()) {
        obj.clear();
    }
    return Shorturl(obj);
}

Shorturl Shorturl::create(const QVariantHash &values)
{
    Shorturl model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Shorturl Shorturl::get(int id)
{
    TSqlORMapper<ShorturlObject> mapper;
    return Shorturl(mapper.findByPrimaryKey(id));
}

Shorturl Shorturl::get(int id, int lockRevision)
{
    TSqlORMapper<ShorturlObject> mapper;
    TCriteria cri;
    cri.add(ShorturlObject::Id, id);
    cri.add(ShorturlObject::LockRevision, lockRevision);
    return Shorturl(mapper.findFirst(cri));
}

QList<Shorturl> Shorturl::getAll()
{
    return tfGetModelListByCriteria<Shorturl, ShorturlObject>(TCriteria());
}

TSqlObject *Shorturl::data()
{
    return d.data();
}

const TSqlObject *Shorturl::data() const
{
    return d.data();
}
