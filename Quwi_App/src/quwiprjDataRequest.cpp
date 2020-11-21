#include "quwiprjDataRequest.h"

quwiPrjDataRequest::quwiPrjDataRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xToken, const QString& xProjId)
{
    QNetworkRequest lRequest(QUrl(BASEPRJDATAREQUESTURL + xProjId));
    lRequest.setRawHeader("Authorization", ("Bearer " + xToken).toUtf8());
    mSetReply(xNetworkAccMgr->get(lRequest));
}

void quwiPrjDataRequest::mDataReceived(QJsonObject& xObj)
{
    emit projectDataReceived(xObj);
}
