#ifndef QUWILOGINREQUEST_H
#define QUWILOGINREQUEST_H

#include "quwiRequest.h"
#define LOGINREQUESTURL "https://api.quwi.com/v2/auth/login"

class quwiLoginRequest : public quwiRequest
{
    Q_OBJECT

public:
    quwiLoginRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xUser, const QString& xPassword);

private:
    void mDataReceived(QJsonObject& xObj) override;
    void mErrorReceived(QString xError) override;

signals:
    void tokenReceived(QString xToken);
    void errorSignal(QString xError);
};

#endif // QUWILOGINREQUEST_H
