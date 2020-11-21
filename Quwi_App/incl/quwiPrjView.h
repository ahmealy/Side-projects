#ifndef QUWIPRJVIEW_H
#define QUWIPRJVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QJsonObject>
#include "checkablebutton.h"

#include "quwiNetworkMgr.h"

class QuwiMainWindow;

class quwiPrjView : public QWidget
{
    Q_OBJECT

    QuwiMainWindow *dMainWin;
    quwiNetworkMgr *dNetworkMgr;
    QLabel *dSetActiveLabel;
    QLabel *dNameLabel;
    QLabel *dUsersLabel;
    QLabel *dAddWatcherLabel;
    QLabel *dImageLabel;
    QLineEdit *dPrjNameLineedit;
    checkableButton *dSetActiveCheckBox;
    checkableButton *dAddWatcherCheckBox;
    QPushButton *dSaveButton;
    QGridLayout *dViewGridLayout;
    QListWidget *dUsersList;
    bool dProcess;

public:
    quwiPrjView(QuwiMainWindow *xMainWin, quwiNetworkMgr *xNetworkMgr);
    void mShow(QJsonObject& xObj);

private slots:
    void mSaveButtonPressed();
    void mUpdateSavePrjNameButton(QString xNewPrjName);
};

#endif // QUWIPRJVIEW_H
