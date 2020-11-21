#include "quwiLoginView.h"
#include <QSettings>

quwiLoginView::quwiLoginView(QuwiMainWindow *xMainWin, quwiNetworkMgr *xNetworkMgr)
    : dMainWindow(xMainWin),
      dNetworkMgr(xNetworkMgr),
      dLoginLayout(new QVBoxLayout(this)),
      dLoginLabel(new QLabel("Login")),
      dLoginLineedit(new QLineEdit),
      dPasswordLineedit(new QLineEdit),
      dLoginButton(new QPushButton("Login")),
      dErrorLabel(new QLabel)
{
    dLoginLabel->setFixedSize(50, 30);
    dLoginLineedit->setFixedSize(250, 30);
    dPasswordLineedit->setFixedSize(250, 30);
    dLoginButton->setFixedHeight(30);
    dErrorLabel->setFixedSize(250, 30);

    dLoginLabel->setStyleSheet("font-weight: bold");
    dLoginLineedit->setPlaceholderText("Email");
    dPasswordLineedit->setPlaceholderText("Password");
    dPasswordLineedit->setEchoMode(QLineEdit::Password);

    dLoginLineedit->setStyleSheet("QLineEdit { border: 1px solid grey; border-radius: 5px; } QLineEdit:focus { border:1px solid #47AAE4; border-radius: 5px;}");
    dPasswordLineedit->setStyleSheet("QLineEdit { border: 1px solid grey; border-radius: 5px;} QLineEdit:focus { border:1px solid #47AAE4; border-radius: 5px;}");
    dLoginButton->setStyleSheet("QPushButton { color: white; background-color: #2668c1; border-radius: 5px; }");
    dErrorLabel-> setStyleSheet("color: red");

    dLoginButton->setDefault(true);

    dLoginLayout->addWidget(dLoginLabel);
    dLoginLayout->addWidget(dLoginLineedit);
    dLoginLayout->addWidget(dPasswordLineedit);
    dLoginLayout->addWidget(dLoginButton);
    dLoginLayout->addWidget(dErrorLabel);
    dLoginLayout->setAlignment(Qt::AlignCenter);

    mResetSettings();

    connect(dLoginButton, &QPushButton::clicked, this, &quwiLoginView::loginClicked);
    connect(dNetworkMgr, &quwiNetworkMgr::loginErrorReceived, this, &quwiLoginView::loginError);
    connect(dNetworkMgr, &quwiNetworkMgr::login, this, &quwiLoginView::mSetLastSuccesEmail);
}

void quwiLoginView::loginClicked()
{
    dNetworkMgr->mLoginRequest(dLoginLineedit->text(), dPasswordLineedit->text());
}

void quwiLoginView::loginError(QString error)
{
    dErrorLabel->setText(error);
}

void quwiLoginView::mResetSettings()
{
    if(dLoginLineedit)      dLoginLineedit->setText(mGetLastSuccesEmail());
    if(dPasswordLineedit)   dPasswordLineedit->setText("");
    if(dErrorLabel)         dErrorLabel->setText("");
}

QString quwiLoginView::mGetLastSuccesEmail()
{
    QSettings lSettings("config.ini",QSettings::IniFormat);
    QString lLastSuccessMail = lSettings.value("SETTINGS/email","").toString();
    return lLastSuccessMail;
}

void quwiLoginView::mSetLastSuccesEmail()
{
    QSettings lSettings("config.ini",QSettings::IniFormat);
    lSettings.beginGroup("SETTINGS");
    if(dLoginLineedit)  lSettings.setValue("email",dLoginLineedit->text().trimmed());
    lSettings.endGroup();
}
