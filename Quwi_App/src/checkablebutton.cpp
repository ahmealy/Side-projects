#include "checkablebutton.h"

checkableButton::checkableButton(QWidget *parent) : QAbstractButton(parent),
    dHeight(16),
    dOpacity(0.000),
    dSwitch(false),
    dMargin(3),
    dThumb("#d5d5d5"),
    dAnimation(new QPropertyAnimation(this, "offset", this))
{
    setOffset(dHeight / 2);
    dY = dHeight / 2;
    setBrush(QColor("#009688"));
}

checkableButton::checkableButton(const QBrush &brush, QWidget *parent) : QAbstractButton(parent),
    dHeight(16),
    dSwitch(false),
    dOpacity(0.000),
    dMargin(3),
    dThumb("#d5d5d5"),
    dAnimation(new QPropertyAnimation(this, "offset", this))
{
    setOffset(dHeight / 2);
    dY = dHeight / 2;
    setBrush(brush);
}

void checkableButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.setPen(Qt::NoPen);
    if (isEnabled()) {
        p.setBrush(dSwitch ? brush() : Qt::black);
        p.setOpacity(dSwitch ? 0.5 : 0.38);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(dMargin, dMargin, width() - 2 * dMargin, height() - 2 * dMargin), 8.0, 8.0);
        p.setBrush(dThumb);
        p.setOpacity(1.0);
        p.drawEllipse(QRectF(offset() - (dHeight / 2), dY - (dHeight / 2), height(), height()));
    } else {
        p.setBrush(Qt::black);
        p.setOpacity(0.12);
        p.drawRoundedRect(QRect(dMargin, dMargin, width() - 2 * dMargin, height() - 2 * dMargin), 8.0, 8.0);
        p.setOpacity(1.0);
        p.setBrush(QColor("#BDBDBD"));
        p.drawEllipse(QRectF(offset() - (dHeight / 2), dY - (dHeight / 2), height(), height()));
    }
}

void checkableButton::mouseReleaseEvent(QMouseEvent *e) {
    if (e->button() & Qt::LeftButton) {
        dSwitch = dSwitch ? false : true;
        dThumb = dSwitch ? dBrush : QBrush("#d5d5d5");
        if (dSwitch) {
            dAnimation->setStartValue(dHeight / 2);
            dAnimation->setEndValue(width() - dHeight);
            dAnimation->setDuration(120);
            dAnimation->start();
        } else {
            dAnimation->setStartValue(offset());
            dAnimation->setEndValue(dHeight / 2);
            dAnimation->setDuration(120);
            dAnimation->start();
        }
    }
    QAbstractButton::mouseReleaseEvent(e);
}

void checkableButton::enterEvent(QEvent *e) {
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent(e);
}

QSize checkableButton::sizeHint() const {
    return QSize(2 * (dHeight + dMargin), dHeight + 2 * dMargin);
}
