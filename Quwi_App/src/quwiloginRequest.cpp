#include "quwiloginRequest.h"

quwiLoginRequest::quwiLoginRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xUser, const QString& xPassword)
{
    QUrlQuery lArgs;
    lArgs.addQueryItem("email", xUser);
    lArgs.addQueryItem("password", xPassword);
    mSetReply(xNetworkAccMgr->post(QNetworkRequest(QUrl(LOGINREQUESTURL)), lArgs.query().toUtf8()));
}

void quwiLoginRequest::mDataReceived(QJsonObject& xObj)
{
    QString xToken = xObj["token"].toString();
    emit tokenReceived(xToken);
}

void quwiLoginRequest::mErrorReceived(QString xError)
{
    emit errorSignal(xError);
}
