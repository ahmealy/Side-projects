#ifndef CHECKABLEBUTTON_H
#define CHECKABLEBUTTON_H

#pragma once
#include <QtWidgets>

class checkableButton : public QAbstractButton {
    Q_OBJECT
    Q_PROPERTY(int offset READ offset WRITE setOffset)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)

public:
    checkableButton(QWidget* xParent = nullptr);
    checkableButton(const QBrush& xBrush, QWidget* xParent = nullptr);

    QSize sizeHint() const override;

    QBrush brush() const {
        return dBrush;
    }
    void setBrush(const QBrush &xBrush) {
        dBrush = xBrush;
    }

    int offset() const {
        return dX;
    }
    void setOffset(int o) {
        dX = o;
        update();
    }

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void enterEvent(QEvent*) override;

private:
    bool dSwitch;
    qreal dOpacity;
    int dX, dY, dHeight, dMargin;
    QBrush dThumb, dTrack, dBrush;
    QPropertyAnimation *dAnimation = nullptr;
};

#endif // CHECKABLEBUTTON_H
