#include <QtCore>
#include <TreeFrogView>
#include "shorturl.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT shorturl_entryView : public TActionView
{
  Q_OBJECT
public:
  shorturl_entryView() : TActionView() { }
  shorturl_entryView(const shorturl_entryView &) : TActionView() { }
  QString toString();
};

QString shorturl_entryView::toString()
{
  responsebody.reserve(1371);
  responsebody += tr("<!DOCTYPE HTML>\n");
    tfetch(QVariantHash, shorturl);
  responsebody += tr("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>New Shorturl</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>Keyword<br /><input name=\"shorturl[keyword]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["keyword"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Url<br /><input name=\"shorturl[url]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["url"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Hits<br /><input name=\"shorturl[hits]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["hits"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(shorturl_entryView)
T_REGISTER_VIEW(shorturl_entryView)

#include "shorturl_entryView.moc"