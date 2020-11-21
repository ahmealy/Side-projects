#ifndef QUWIMAINWINDOW_H
#define QUWIMAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QSizePolicy>
#include <QStackedWidget>

#include "quwiLoginView.h"
#include "quwiPrjsListView.h"
#include "quwiPrjView.h"
#include "quwiNetworkMgr.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class QuwiMainWindow;
}
QT_END_NAMESPACE



class QuwiMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuwiMainWindow(QWidget *parent = 0);
    ~QuwiMainWindow();

private:
    Ui::QuwiMainWindow *ui;
    QStackedWidget *dViews;
    QToolBar *dToolbar;
    QAction *dPrjsAction;
    QAction *dLogoutAction;
    quwiLoginView *dLoginView;
    quwiPrjsListView *dPrjsListView;
    quwiPrjView *dPrjView;
    quwiNetworkMgr *dNetworkMgr;

private:
    void mCreateGui();
    void mRegiterSignals();
    void mCreateToolbar();
    QSize sizeHint() const
    {
        return QSize(50,100); // initial size
    }

public slots:
    void mCreatePrjsListView();
    void mShowPrjsListView(QJsonArray xPrjsList);
    void mCreatePrjView(const QString& id);
    void mShowPrjView(QJsonObject obj);
    void mLogout();
};

#endif // QUWIMAINWINDOW_H
