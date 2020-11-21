#ifndef QUWICHANGEPRJNAMEREQUEST_H
#define QUWICHANGEPRJNAMEREQUEST_H

#include "quwiRequest.h"
#define BASECHANGEPRJNAMEREQUESTURL "https://api.quwi.com/v2/projects-manage/update?id="

class quwiChangePrjNameRequest : public quwiRequest
{
    Q_OBJECT

public:
    quwiChangePrjNameRequest(QNetworkAccessManager *xNetworkAccMgr, const QString& xToken, const QString& xId, const QJsonObject& xObj);
};

#endif // QUWICHANGEPRJNAMEREQUEST_H
