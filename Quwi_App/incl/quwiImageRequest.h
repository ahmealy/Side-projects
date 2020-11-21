#ifndef QUWIIMAGEREQUEST_H
#define QUWIIMAGEREQUEST_H

#include <QLabel>
#include <QImage>
#include <QImageReader>
#include <QPixmap>

#include "quwiRequest.h"

class quwiImageRequest : public quwiRequest
{
    Q_OBJECT

    QLabel* dLabel;
    QSize dSize;

private:
    void mDataReceived(QJsonObject& xObj) override;

public:
    quwiImageRequest(QNetworkAccessManager *xNetworkAccMgr, QLabel *xLabel, const QString& xUrl, const QSize& xSize, bool xIsUser);

signals:
    void imageReady();
};

#endif // QUWIIMAGEREQUEST_H
