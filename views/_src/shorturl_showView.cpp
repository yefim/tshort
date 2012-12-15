#include <QtCore>
#include <TreeFrogView>
#include "shorturl.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT shorturl_showView : public TActionView
{
  Q_OBJECT
public:
  shorturl_showView() : TActionView() { }
  shorturl_showView(const shorturl_showView &) : TActionView() { }
  QString toString();
};

QString shorturl_showView::toString()
{
  responsebody.reserve(1627);
  responsebody += tr("<!DOCTYPE HTML>\n");
    tfetch(Shorturl, shorturl);
  responsebody += tr("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Showing Shorturl</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.id());
  responsebody += tr("</dd><br />\n<dt>Keyword</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.keyword());
  responsebody += tr("</dd><br />\n<dt>Url</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.url());
  responsebody += tr("</dd><br />\n<dt>Hits</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.hits());
  responsebody += tr("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.createdAt());
  responsebody += tr("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.updatedAt());
  responsebody += tr("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(shorturl.lockRevision());
  responsebody += tr("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", shorturl.id()))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(shorturl_showView)
T_REGISTER_VIEW(shorturl_showView)

#include "shorturl_showView.moc"