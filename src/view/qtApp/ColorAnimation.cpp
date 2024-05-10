#include <ColorAnimation.h>
#include <QPropertyAnimation>

ColorAnimation::ColorAnimation(QObject* parent, const QByteArray& propertyName) : QPropertyAnimation(parent, propertyName) {
}

QVariant ColorAnimation::interpolated(const QVariant&from, const QVariant&to, qreal progress) const {
    if (progress < 0.5) {
        return from;
    }
    return to;
}
