#include "quwiRequest.h"

quwiRequest::quwiRequest(QObject *parent)
    : QObject(parent)
{}

void quwiRequest::mSetReply(QNetworkReply *xReply)
{
    xReply->setParent(this);
    this->dReply = xReply;
    connect(xReply, &QNetworkReply::readyRead, this, &quwiRequest::mRequestFinished);
}

void quwiRequest::mSetImageReply(QNetworkReply *xReply)
{
    xReply->setParent(this);
    this->dReply = xReply;
    connect(xReply, &QNetworkReply::readyRead, this, &quwiRequest::mImageRequest);
}

void quwiRequest::mRequestFinished()
{
    if(dReply->error())
    {
        mErrorReceived(dReply->errorString());
        return;
    }
    QString lAns = dReply->readAll();
    //qDebug() << lAns;
    QJsonDocument lDocument = QJsonDocument::fromJson(lAns.toUtf8());
    QJsonObject lObject = lDocument.object();
    if(lObject.contains("first_errors"))
    {
        //qDebug() << "if(lObject.contains(first_errors))";
        mErrorReceived(lObject["first_errors"].toObject().begin().value().toString());
        return;
    }
    emit mDataReceived(lObject);
}

void quwiRequest::mImageRequest()
{
    QJsonObject obj;
    emit mDataReceived(obj);
}
