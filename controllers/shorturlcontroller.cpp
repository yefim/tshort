#include <TGlobal>
#include <TreeFrogModel>
#include <TCriteria>

#include "shorturlcontroller.h"
#include "shorturl.h"
#include "sqlobjects/shorturlobject.h"


ShorturlController::ShorturlController(const ShorturlController &)
    : ApplicationController()
{ }

void ShorturlController::index()
{
    QList<Shorturl> shorturlList = Shorturl::getAll();
    texport(shorturlList);
    render();
}

void ShorturlController::show(const QString &pk)
{
    Shorturl shorturl = Shorturl::get(pk.toInt());
    texport(shorturl);
    render();
}

void ShorturlController::lookup(const QString &pk)
{
    // Based on example tfrog code
    TSqlORMapper<ShorturlObject> mapper;
    TCriteria criteria(ShorturlObject::Keyword, TSql::Equal, pk);
    mapper.find(criteria);
    Shorturl shorturl = mapper.value(0);

    shorturl.setHits(shorturl.hits() + 1);

    QString url = shorturl.url();
    QString newurl;
    if (url.startsWith(QString("http://"))) {
        redirect("http://" + url.right(url.size() - 7));
    } else if (url.startsWith(QString("https://"))) {
        redirect("https://" + url.right(url.size() - 8));
    } else {
        redirect("http://" + shorturl.url());
    }
}

void ShorturlController::entry()
{
    renderEntry();
}

void ShorturlController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }
    
    QVariantHash form = httpRequest().formItems("shorturl");
    Shorturl shorturl = Shorturl::create(form);
    if (!shorturl.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", shorturl.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ShorturlController::renderEntry(const QVariantHash &shorturl)
{
    texport(shorturl);
    render("entry");
}

void ShorturlController::edit(const QString &pk)
{
    Shorturl shorturl = Shorturl::get(pk.toInt());
    if (!shorturl.isNull()) {
        session().insert("shorturl_lockRevision", shorturl.lockRevision());
        renderEdit(shorturl.properties());
    } else {
        redirect(urla("entry"));
    }
}

void ShorturlController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("shorturl_lockRevision").toInt();
    Shorturl shorturl = Shorturl::get(pk.toInt(), rev);
    if (shorturl.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    } 
    
    QVariantHash form = httpRequest().formItems("shorturl");
    shorturl.setProperties(form);
    if (shorturl.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ShorturlController::renderEdit(const QVariantHash &shorturl)
{
    texport(shorturl);
    render("edit");
}

void ShorturlController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }
    
    Shorturl shorturl = Shorturl::get(pk.toInt());
    shorturl.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(shorturlcontroller)
