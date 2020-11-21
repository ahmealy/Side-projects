#include "quwiPrjsListView.h"
#include "QuwiMainwindow.h"
#define PRJIDUSERROLE Qt::UserRole+1

quwiPrjsListView::quwiPrjsListView(QuwiMainWindow *xMainWin, quwiNetworkMgr *xNetworkMgr)
    : QWidget(xMainWin),
      dMainWindow(xMainWin),
      dNetworkMgr(xNetworkMgr),
      dProjectsListWidget(new QListWidget(this)),
      dProjectsListLayout(new QVBoxLayout(this))
{
    dProjectsListWidget->setFixedWidth(600);

    dProjectsListLayout->setAlignment(Qt::AlignCenter);
    dProjectsListLayout->addWidget(dProjectsListWidget);
    connect(dProjectsListWidget, &QListWidget::itemClicked, this, &quwiPrjsListView::mProjectClicked);
}

void quwiPrjsListView::mAddProjectToList(QJsonObject xObj)
{
    QListWidgetItem *lPrjItem = new QListWidgetItem(dProjectsListWidget);
    lPrjItem->setSizeHint(QSize(30, 100));
    lPrjItem->setData(PRJIDUSERROLE, xObj["id"].toInt());

    dProjectsListWidget->addItem(lPrjItem);

    QWidget *lPrjWidget = new QWidget();
    dProjectsListWidget->setItemWidget(lPrjItem, lPrjWidget);

    QHBoxLayout *lPrjLayout = new QHBoxLayout(lPrjWidget);
    QLabel *lPrjImage = new QLabel(lPrjWidget);
    QLabel *lPrjName = new QLabel(xObj["name"].toString(), lPrjWidget);
    QLabel *lPrjActive = new QLabel(lPrjWidget);
    //QLabel *lWeekTime = new QLabel(QString::number(xObj["spent_time_week"].toInt()), lPrjWidget);
    //QLabel *lMonthTime = new QLabel(QString::number(xObj["spent_time_month"].toInt()), lPrjWidget);
    //QLabel *lTotalTime = new QLabel(QString::number(xObj["spent_time_all"].toInt()), lPrjWidget);
    QLabel *lWeekTime = new QLabel(QDateTime::fromTime_t(xObj["spent_time_week"].toDouble()).toUTC().toString("hh:mm:ss"), lPrjWidget);
    QLabel *lMonthTime = new QLabel(QDateTime::fromTime_t(xObj["spent_time_month"].toDouble()).toUTC().toString("hh:mm:ss"), lPrjWidget);
    QLabel *lTotalTime = new QLabel(QDateTime::fromTime_t(xObj["spent_time_all"].toDouble()).toUTC().toString("hh:mm:ss"), lPrjWidget);

    QFormLayout *lTimeFormLayout = new QFormLayout();

    dNetworkMgr->mGetImageRequest(lPrjImage, xObj["logo_url"].toString(), {80, 80});

    lPrjName->setStyleSheet("font-weight: bold");

    lPrjActive->setText(xObj["is_active"].toInt() == 1 ? "Active" : "Not active");
    lPrjActive->setStyleSheet(xObj["is_active"].toInt() == 1 ? "color: green" : "color: gray");
    lPrjName->setStyleSheet("font-weight: bold");

    lTimeFormLayout->addRow("Time this week", lWeekTime);
    lTimeFormLayout->addRow("Time this month", lMonthTime);
    lTimeFormLayout->addRow("Total time", lTotalTime);

    lPrjLayout->addWidget(lPrjImage);
    lPrjLayout->addWidget(lPrjName);
    lPrjLayout->addWidget(lPrjActive);
    lPrjLayout->addLayout(lTimeFormLayout);


}

void quwiPrjsListView::mShow(QJsonArray& proj_list)
{
    dProjectsListWidget->clear();
    for(auto i = proj_list.begin(); i != proj_list.end(); i++)
        mAddProjectToList(i->toObject());
}

void quwiPrjsListView::mProjectClicked(QListWidgetItem *item)
{
    int id = item->data(PRJIDUSERROLE).toInt();
    QString id_str = QString::number(id);
    dMainWindow->setProperty("current_project_id", QVariant(id_str));
    dMainWindow->mCreatePrjView(id_str);
}
