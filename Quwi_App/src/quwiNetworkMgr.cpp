#include "quwiNetworkMgr.h"

quwiNetworkMgr::quwiNetworkMgr(QObject *xParent)
    : QObject(xParent),
      dToken(QString("")),
      dNetworkAccMgr(new QNetworkAccessManager(this))
{}

void quwiNetworkMgr::mLoginRequest(const QString& xUser, const QString& xPassword)
{
    quwiLoginRequest *lRequest = new quwiLoginRequest(dNetworkAccMgr, xUser, xPassword);
    connect(lRequest, &quwiLoginRequest::tokenReceived, this, &quwiNetworkMgr::tokenReceived);
    connect(lRequest, &quwiLoginRequest::tokenReceived, lRequest, &quwiLoginRequest::deleteLater);
    connect(lRequest, &quwiLoginRequest::errorSignal, this, &quwiNetworkMgr::loginErrorReceived);
}

void quwiNetworkMgr::mLogoutRequest()
{
    auto lRequest = new quwiLogoutRequest(dNetworkAccMgr);
}

void quwiNetworkMgr::mGetPrjListRequest()
{
    quwiPrjListRequest *lRequest = new quwiPrjListRequest(dNetworkAccMgr, dToken);
    connect(lRequest, &quwiPrjListRequest::projectsListReceived, this, &quwiNetworkMgr::prjListReceived);
    connect(lRequest, &quwiPrjListRequest::projectsListReceived, lRequest, &quwiPrjListRequest::deleteLater);
}

void quwiNetworkMgr::mGetPrjDataRequest(const QString &xId)
{
    quwiPrjDataRequest *lRequest = new quwiPrjDataRequest(dNetworkAccMgr, dToken, xId);
    connect(lRequest, &quwiPrjDataRequest::projectDataReceived, this, &quwiNetworkMgr::prjDataReceived);
    connect(lRequest, &quwiPrjDataRequest::projectDataReceived, lRequest, &quwiPrjDataRequest::deleteLater);
}

void quwiNetworkMgr::mGetImageRequest(QLabel *xLabel, const QString& xUrl, const QSize& xSize, bool xIsUser)
{
    quwiImageRequest *lRequest = new quwiImageRequest(dNetworkAccMgr, xLabel, xUrl, xSize, xIsUser);
    connect(lRequest, &quwiImageRequest::imageReady, lRequest, &quwiImageRequest::deleteLater);
    // QEventLoop loop;
    // connect(dReply, SIGNAL(finished()), &loop, SLOT(quit()));
    // loop.exec();
    emit imageReady();
}

void quwiNetworkMgr::mChangePrjNameRequest(const QString& xId, const QJsonObject& xObj)
{
    quwiChangePrjNameRequest(dNetworkAccMgr, dToken, xId, xObj);
}

void quwiNetworkMgr::tokenReceived(const QString& xToken)
{
    dToken = xToken;
    if(dToken != "")
        emit login();
}
