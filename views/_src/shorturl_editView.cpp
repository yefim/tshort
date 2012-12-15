#include <QtCore>
#include <TreeFrogView>
#include "shorturl.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT shorturl_editView : public TActionView
{
  Q_OBJECT
public:
  shorturl_editView() : TActionView() { }
  shorturl_editView(const shorturl_editView &) : TActionView() { }
  QString toString();
};

QString shorturl_editView::toString()
{
  responsebody.reserve(1752);
  responsebody += tr("<!DOCTYPE HTML>\n");
    tfetch(QVariantHash, shorturl);
  responsebody += tr("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Editing Shorturl</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", shorturl["id"]), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"shorturl[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["id"]);
  responsebody += tr("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Keyword<br /><input type=\"text\" name=\"shorturl[keyword]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["keyword"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Url<br /><input type=\"text\" name=\"shorturl[url]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["url"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Hits<br /><input type=\"text\" name=\"shorturl[hits]\" value=\"");
  responsebody += THttpUtility::htmlEscape(shorturl["hits"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", shorturl["id"]))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(shorturl_editView)
T_REGISTER_VIEW(shorturl_editView)

#include "shorturl_editView.moc"