#include <QtCore>
#include <TreeFrogView>
#include "shorturl.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT shorturl_indexView : public TActionView
{
  Q_OBJECT
public:
  shorturl_indexView() : TActionView() { }
  shorturl_indexView(const shorturl_indexView &) : TActionView() { }
  QString toString();
};

QString shorturl_indexView::toString()
{
  responsebody.reserve(1698);
  responsebody += tr("<!DOCTYPE HTML>\n");
    responsebody += tr("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n</head>\n<body>\n\n<h1>Listing Shorturl</h1>\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += tr("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Keyword</th>\n    <th>Url</th>\n    <th>Hits</th>\n  </tr>\n");
  tfetch(QList<Shorturl>, shorturlList);
  for (QListIterator<Shorturl> it(shorturlList); it.hasNext(); ) {
     const Shorturl &i = it.next();
  responsebody += tr("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.keyword());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.url());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.hits());
  responsebody += tr("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("edit", i.id()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += tr("\n    </td>\n  </tr>\n");
  };
  responsebody += tr("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(shorturl_indexView)
T_REGISTER_VIEW(shorturl_indexView)

#include "shorturl_indexView.moc"