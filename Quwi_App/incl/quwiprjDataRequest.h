#ifndef QUWIPRJDATAREQUEST_H
#define QUWIPRJDATAREQUEST_H

#include "quwiRequest.h"
#define BASEPRJDATAREQUESTURL "https://api.quwi.com/v2/projects-manage/"

class quwiPrjDataRequest : public quwiRequest

{
    Q_OBJECT
    int dId;

public:
    quwiPrjDataRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xToken, const QString& xProjId);

private:
    void mDataReceived(QJsonObject& xObj) override;

signals:
    void projectDataReceived(QJsonObject xObj);
};

#endif // QUWIPRJDATAREQUEST_H
