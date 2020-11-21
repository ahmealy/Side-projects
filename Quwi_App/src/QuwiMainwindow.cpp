#include "QuwiMainwindow.h"
#include "ui_quwimainwindow.h"

QuwiMainWindow::QuwiMainWindow(QWidget *parent) :
    QMainWindow(parent),
    dNetworkMgr(new quwiNetworkMgr(this)),
    dViews(new QStackedWidget(this)),
    ui(new Ui::QuwiMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Quwi"));
    this->setWindowIcon(QIcon(":/icons/quwi-logo.png"));


    mCreateGui();

    mCreateToolbar();

    setCentralWidget(dViews);

    mRegiterSignals();
}

QuwiMainWindow::~QuwiMainWindow()
{
    delete ui;
}

void QuwiMainWindow::mCreateGui()
{
    dLoginView = new quwiLoginView(this, dNetworkMgr);
    dPrjsListView = new quwiPrjsListView(this, dNetworkMgr);
    dPrjView = new quwiPrjView(this, dNetworkMgr);

    dViews->setObjectName("dViews");
    dViews->setStyleSheet("#dViews { background-image:url(\":/backgroundImg.jpg\"); background-position: center; }");
    dViews->addWidget(dLoginView);
    dViews->addWidget(dPrjsListView);
    dViews->addWidget(dPrjView);

    dViews->setCurrentWidget(dLoginView);
}

void QuwiMainWindow::mRegiterSignals()
{
    connect(dNetworkMgr, &quwiNetworkMgr::login, this, &QuwiMainWindow::mCreatePrjsListView);
    connect(dNetworkMgr, &quwiNetworkMgr::prjListReceived, this, &QuwiMainWindow::mShowPrjsListView);
    connect(dNetworkMgr, &quwiNetworkMgr::prjDataReceived, this, &QuwiMainWindow::mShowPrjView);
}

void QuwiMainWindow::mCreateToolbar()
{
    delete ui->mainToolBar;

    dToolbar = new QToolBar("Quwi toolbar");

    dPrjsAction = new QAction(QIcon(":/icons/back.png"), "Back to Projects", dToolbar);
    dLogoutAction = new QAction(QIcon(":/icons/logout.png"), "Logout", dToolbar);

    dToolbar->addAction(dPrjsAction);
    dToolbar->addAction(dLogoutAction);

    connect(dPrjsAction, &QAction::triggered, this, &QuwiMainWindow::mCreatePrjsListView);
    connect(dLogoutAction, &QAction::triggered, this, &QuwiMainWindow::mLogout);
    addToolBar(dToolbar);

    dToolbar->setVisible(false);
}

void QuwiMainWindow::mCreatePrjsListView()
{
    dNetworkMgr->mGetPrjListRequest();
}

void QuwiMainWindow::mShowPrjsListView(QJsonArray proj_list)
{

    dPrjsAction->setEnabled(false);
    dToolbar->setVisible(true);
    dPrjsListView->mShow(proj_list);
    dViews->setCurrentWidget(dPrjsListView);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
}

void QuwiMainWindow::mCreatePrjView(const QString& id)
{
    dPrjsAction->setEnabled(true);
    dNetworkMgr->mGetPrjDataRequest(id);
}

void QuwiMainWindow::mShowPrjView(QJsonObject obj)
{
    dToolbar->setVisible(true);
    dPrjView->mShow(obj);
    dViews->setCurrentWidget(dPrjView);
}

void QuwiMainWindow::mLogout()
{
    dToolbar->setVisible(false);
    dViews->setCurrentWidget(dLoginView);
    if(dLoginView) dLoginView->mResetSettings();
    dNetworkMgr->mLogoutRequest();
}
