#ifndef QUWIPRJSLISTVIEW_H
#define QUWIPRJSLISTVIEW_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>

#include "quwiNetworkMgr.h"

class QuwiMainWindow;

class quwiPrjsListView : public QWidget
{
    Q_OBJECT

    QuwiMainWindow *dMainWindow;
    quwiNetworkMgr *dNetworkMgr;
    QListWidget *dProjectsListWidget;
    QVBoxLayout *dProjectsListLayout;

public:
    explicit quwiPrjsListView(QuwiMainWindow *xMainWindow, quwiNetworkMgr *xNetworkMgr);
    void mShow(QJsonArray& xPrjList);

private:
    void mAddProjectToList(QJsonObject xObj);

private slots:
    void mProjectClicked(QListWidgetItem* xItem);
};

#endif // QUWIPRJSLISTVIEW_H
