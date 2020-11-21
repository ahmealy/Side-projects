#include "quwiChangePrjNameRequest.h"

quwiChangePrjNameRequest::quwiChangePrjNameRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xToken, const QString& xId, const QJsonObject& xObj)
{
    QNetworkRequest request(QUrl(BASECHANGEPRJNAMEREQUESTURL + xId));
    request.setRawHeader("Authorization", ("Bearer " + xToken.toUtf8()));
    QUrlQuery lArgs;
    for(auto iter = xObj.begin(); iter != xObj.end(); iter++)
        lArgs.addQueryItem(iter.key(), iter.value().toString());
    xNetworkAccMgr->post(request, lArgs.query().toUtf8());
}
