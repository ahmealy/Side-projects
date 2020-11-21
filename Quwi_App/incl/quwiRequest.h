#ifndef QUWIREQUEST_H
#define QUWIREQUEST_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QLabel>

class quwiRequest : public QObject
{
    Q_OBJECT
public:
    explicit quwiRequest(QObject* parent = nullptr);

protected:
    QNetworkReply* dReply;

    void mSetReply(QNetworkReply* xReply);
    void mSetImageReply(QNetworkReply *xReply);

    virtual void mDataReceived(QJsonObject& obj) {}
    virtual void mErrorReceived(QString error) {}


private slots:
    void mRequestFinished();
    void mImageRequest();
};

#endif //QUWIREQUEST_H
