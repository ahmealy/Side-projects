#ifndef QUWILOGINVIEW_H
#define QUWILOGINVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFrame>

#include "quwiNetworkMgr.h"

class QuwiMainWindow;

class quwiLoginView : public QFrame
{
    Q_OBJECT

    QuwiMainWindow *dMainWindow;
    quwiNetworkMgr *dNetworkMgr;
    QVBoxLayout *dLoginLayout;
    QLabel *dLoginLabel;
    QLineEdit *dLoginLineedit;
    QLineEdit *dPasswordLineedit;
    QPushButton *dLoginButton;
    QLabel *dErrorLabel;

public:
    explicit quwiLoginView(QuwiMainWindow *dMainWindow, quwiNetworkMgr *dNetworkMgr);

private:
    QString mGetLastSuccesEmail();
private slots:
    void loginClicked();
    void loginError(QString error);
    void mSetLastSuccesEmail();
public slots:
    void mResetSettings();
};

#endif // QUWILOGINVIEW_H
