#ifndef QUWINETWORKMGR_H
#define QUWINETWORKMGR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLabel>

#include "quwiloginRequest.h"
#include "quwilogoutRequest.h"
#include "quwiprjListRequest.h"
#include "quwiprjDataRequest.h"
#include "quwiImageRequest.h"
#include "quwiChangePrjNameRequest.h"

class quwiNetworkMgr : public QObject
{
    Q_OBJECT

    QString dToken;
    QNetworkAccessManager *dNetworkAccMgr;

public:
    quwiNetworkMgr(QObject *xParent = nullptr);
    void mLoginRequest(const QString& xUser, const QString& xPassword);
    void mGetPrjListRequest();
    void mGetPrjDataRequest(const QString& xId);
    void mGetImageRequest(QLabel *xLabel, const QString& xUrl, const QSize& xSize, bool xIsUser = false);
    void mChangePrjNameRequest(const QString& xId, const QJsonObject& xObj);
    void mLogoutRequest();

signals:
    void login();
    void prjListReceived(QJsonArray xPrjList);
    void prjDataReceived(QJsonObject xObj);
    void loginErrorReceived(QString xError);
    void imageReady();

private slots:
    void  tokenReceived(const QString& xToken);
};

#endif // QUWINETWORKMGR_H
