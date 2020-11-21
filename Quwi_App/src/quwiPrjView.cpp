#include "quwiPrjView.h"
#include "QuwiMainwindow.h"

quwiPrjView::quwiPrjView(QuwiMainWindow *xMainWin, quwiNetworkMgr *xNetworkMgr)
    : QWidget(xMainWin),
      dMainWin(xMainWin),
      dNetworkMgr(xNetworkMgr),
      dSetActiveLabel(new QLabel("Active")),
      dNameLabel(new QLabel("Name")),
      dUsersLabel(new QLabel("Users")),
      dImageLabel(new QLabel),
      dAddWatcherLabel(new QLabel("Add me as watcher to tickets created by others")),
      dPrjNameLineedit(new QLineEdit),
      dSetActiveCheckBox(new checkableButton),
      dAddWatcherCheckBox(new checkableButton),
      dSaveButton(new QPushButton("OK")),
      dViewGridLayout(new QGridLayout(this)),
      dUsersList (new QListWidget())
{
    dImageLabel->setFixedSize(80, 80);
    dSetActiveLabel->setFixedSize(80, 40);
    dSetActiveCheckBox->setFixedWidth(40);
    dNameLabel->setFixedSize(80, 40);
    dPrjNameLineedit->setFixedSize(300, 40);
    dPrjNameLineedit->setStyleSheet("QLineEdit { border: 1px solid grey; border-radius: 5px; }");
    connect(dPrjNameLineedit, &QLineEdit::textChanged, this, &quwiPrjView::mUpdateSavePrjNameButton);
    dSaveButton->setFixedSize(50, 40);
    dSaveButton->setStyleSheet("QPushButton { color: white; background-color: darkblue; border-radius: 5px; }");
    dAddWatcherCheckBox->setFixedWidth(40);
    dAddWatcherLabel->setFixedSize(450, 40);

    dViewGridLayout->addWidget(dSetActiveLabel, 0, 0);
    dViewGridLayout->addWidget(dSetActiveCheckBox, 0, 1, 1, 2);
    dViewGridLayout->addWidget(dImageLabel, 0, 3, 2, 1);
    dViewGridLayout->addWidget(dNameLabel, 1, 0);
    dViewGridLayout->addWidget(dPrjNameLineedit, 1, 1);
    dViewGridLayout->addWidget(dSaveButton, 1, 2);
    dViewGridLayout->addWidget(dAddWatcherCheckBox, 2, 0);
    dViewGridLayout->addWidget(dAddWatcherLabel, 2, 1, 1, 3);
    dViewGridLayout->setAlignment(Qt::AlignCenter);
    dViewGridLayout->addWidget(dUsersLabel, 3, 0);
    dViewGridLayout->addWidget(dUsersList, 3, 1,1,3);

    connect(dSaveButton, &QPushButton::clicked, this, &quwiPrjView::mSaveButtonPressed);
}

void quwiPrjView::mShow(QJsonObject& obj)
{
    QJsonObject proj = obj["project"].toObject();
    dPrjNameLineedit->setText(proj["name"].toString());
    dSetActiveCheckBox->setChecked(proj["is_active"].toInt() == 1);
    dAddWatcherCheckBox->setChecked(proj["is_owner_watcher"].toInt() == 1);
    dUsersList->clear();
    QJsonArray arrayUsers = proj["users"].toArray();
    for(int user = 0; user < arrayUsers.size(); user++){
        QJsonObject objUserItem = arrayUsers.at(user).toObject();

        QListWidgetItem *lUserItem = new QListWidgetItem(dUsersList);
        lUserItem->setSizeHint(QSize(50, 50));
        dUsersList->addItem(lUserItem);
        QWidget *lUserWidget = new QWidget();
        dUsersList->setItemWidget(lUserItem, lUserWidget);
        QHBoxLayout *lUserLayout = new QHBoxLayout(lUserWidget);
        QLabel *lUserImage = new QLabel(lUserWidget);
        QLabel *lUserName = new QLabel(objUserItem["name"].toString(), lUserWidget);

        dNetworkMgr->mGetImageRequest(lUserImage, objUserItem["avatar_url"].toString(), {30, 30}, true);

        lUserLayout->addWidget(lUserImage);
        lUserLayout->addWidget(lUserName);
        lUserLayout->setAlignment(Qt::AlignLeft);
    }

    dNetworkMgr->mGetImageRequest(dImageLabel, proj["logo_url"].toString(), {80, 80});

}

void quwiPrjView::mSaveButtonPressed()
{
    QJsonObject obj;
    obj.insert("name", QJsonValue(dPrjNameLineedit->text()));
    dNetworkMgr->mChangePrjNameRequest(dMainWin->property("current_project_id").toString(), obj);
}

void quwiPrjView::mUpdateSavePrjNameButton(QString xNewPrjName)
{
    if(xNewPrjName.length())
    {
        dSaveButton->setStyleSheet("QPushButton { color: white; background-color: darkblue; border-radius: 5px; }");
        dSaveButton->setEnabled(true);
    }
    else
    {
        dSaveButton->setStyleSheet("QPushButton { color: white; background-color: grey; border-radius: 5px; }");
        dSaveButton->setEnabled(false);
    }
}

