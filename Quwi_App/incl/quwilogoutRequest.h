#ifndef LOGOUTREQUEST_H
#define LOGOUTREQUEST_H

#include "quwiRequest.h"
#define LOGOUTREQUESTURL "https://api.quwi.com/v2/auth/logout"

class quwiLogoutRequest : public quwiRequest
{
    Q_OBJECT

public:
    quwiLogoutRequest(QNetworkAccessManager *xNetworkAccMgr);
};

#endif // LOGOUTREQUEST_H
