#ifndef SHORTURLCONTROLLER_H
#define SHORTURLCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ShorturlController : public ApplicationController
{
    Q_OBJECT
public:
    ShorturlController() { }
    ShorturlController(const ShorturlController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantHash &shorturl = QVariantHash());
    void renderEdit(const QVariantHash &shorturl = QVariantHash());
};

T_DECLARE_CONTROLLER(ShorturlController, shorturlcontroller)

#endif // SHORTURLCONTROLLER_H
