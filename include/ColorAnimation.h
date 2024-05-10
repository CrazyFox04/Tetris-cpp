//
// Created by Enzo Renard on 10/05/2024.
//

#ifndef COLORANIMATION_H
#define COLORANIMATION_H
#include <QPropertyAnimation>

class ColorAnimation : public QPropertyAnimation {
public:
    ColorAnimation(QObject* parent = nullptr, const QByteArray& = QByteArray());

protected :
    QVariant interpolated(const QVariant&from, const QVariant&to, qreal progress) const override;
};
#endif //COLORANIMATION_H
