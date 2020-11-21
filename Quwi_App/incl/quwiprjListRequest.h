#ifndef QUWIPRJLISTREQUEST_H
#define QUWIPRJLISTREQUEST_H

#include "quwiRequest.h"
#define PRJLISTREQUESTURL "https://api.quwi.com/v2/projects-manage/index"

class quwiPrjListRequest : public quwiRequest
{
    Q_OBJECT

public:
    quwiPrjListRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xToken);

private:
    void mDataReceived(QJsonObject& xObj) override;

signals:
    void projectsListReceived(QJsonArray xPrjList);
};

#endif // QUWIPRJLISTREQUEST_H
