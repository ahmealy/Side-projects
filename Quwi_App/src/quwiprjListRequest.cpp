#include "quwiprjListRequest.h"

quwiPrjListRequest::quwiPrjListRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xToken)
{
    QNetworkRequest lRequest(QUrl(PRJLISTREQUESTURL));
    lRequest.setRawHeader("Authorization", ("Bearer " + xToken).toUtf8());
    mSetReply(xNetworkAccMgr->get(lRequest));
}

void quwiPrjListRequest::mDataReceived(QJsonObject& obj)
{
    emit projectsListReceived(obj["projects"].toArray());
}
