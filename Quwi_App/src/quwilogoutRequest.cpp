#include "quwilogoutRequest.h"

quwiLogoutRequest::quwiLogoutRequest(QNetworkAccessManager *xNetworkAccMgr)
{
    QUrlQuery lArgs;
    lArgs.addQueryItem("anywhere", "false");
    xNetworkAccMgr->post(QNetworkRequest(QUrl(LOGOUTREQUESTURL)), lArgs.query().toUtf8());
}
