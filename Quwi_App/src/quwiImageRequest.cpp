#include "quwiImageRequest.h"
#include <QIcon>

quwiImageRequest::quwiImageRequest(QNetworkAccessManager *xNetworkAccMgr, QLabel *xLabel, const QString& xUrl, const QSize& xSize, bool xIsUser)
    : dLabel(xLabel),
      dSize(xSize)
{
    //qDebug() << "if(xUrl.length()) " << xUrl.length();
    if(xUrl.length())
    {
        QNetworkRequest lRequest;
        lRequest.setUrl(QUrl(xUrl));
        mSetImageReply(xNetworkAccMgr->get(lRequest));
    }
    else
    {
        QIcon lIcon;
        if(!xIsUser)     lIcon = QIcon(":/icons/presentation.png");
        else             lIcon = QIcon(":/icons/user.png");

        QPixmap lPixmap = lIcon.pixmap(lIcon.actualSize(xSize));
        dLabel->setPixmap(lPixmap);
    }
}

void quwiImageRequest::mDataReceived(QJsonObject &xObj)
{
    if(dReply->error())
    {
        //qDebug() << "Error recieving project image " << dReply->errorString();
    }
    QByteArray imgData = dReply->readAll();
    //qDebug() <<  "if(imgData.size()>0){ " << imgData.size();
    if(imgData.size()>0){

        QPixmap image;
        image.loadFromData(imgData);

        dLabel->setPixmap(image.scaled(dSize, Qt::KeepAspectRatio));
    }

    // Alternative way of reading images
    /* QImageReader lImageReader(dReply);
    lImageReader.setAutoDetectImageFormat(true);
    QImage lImage = lImageReader.read();
    lImage = lImage.scaled(dSize, Qt::KeepAspectRatio);
    dLabel->setPixmap(QPixmap::fromImage(lImage));*/

    QCoreApplication::processEvents();
    emit imageReady();
}
