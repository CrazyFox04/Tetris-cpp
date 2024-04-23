#include <QString>
#include <QStringBuilder>
#include <QPalette>

#include "PlayerDataWidget.h"
#include "ui_PlayerDataWidget.h"

using namespace labyrinth;

static std::string getStatus(model::Player &player, bool isCurrentPlayer) {
    std::string status;
    if (isCurrentPlayer) {
        if (player.isReadyToMove()) {
            status += "is ready to move...";
        } else {
            status += "is ready to insert...";
        }
    } else {
        status += "is waiting...";
    }
    return status;
}

PlayerDataWidget::PlayerDataWidget(bool isCurrentPlayer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerDataWidget(false, nullptr)),
    player_(player)
{
    ui->setupUi(this);
    setupPlayerData(isCurrentPlayer);
    setupBackgroundColor();
}

void PlayerDataWidget::setupPlayerData(bool isCurrentPlayer) {
    std::string name = view::toString(player_.getColor()) + " player";
    std::string status = getStatus(player_, isCurrentPlayer);
    std::stringstream objectivesSize;
    objectivesSize << player_.getObjectives().getCards().size();
    ui->player->setText(QString::fromStdString(name));
    ui->status->setText(QString::fromStdString(status));
    ui->nbObjectives->setText(QString::fromStdString(objectivesSize.str()));
    setCurrentObjective();
}

void PlayerDataWidget::setCurrentObjective() {
    model::Object obj = player_.getCurrentObjective().getObject();
    unsigned value = static_cast<unsigned>(obj);
    std::string objective = view::toString(obj) + " (" + std::to_string(value + 1) + ")";
    ui->objective->setText(QString::fromStdString(objective));
}

static QString getBackgroundStyle(const model::Player &player) {
    QString backgroundStyle = "background-color:";
    switch (player.getColor()) {
    case model::Player::RED:
        backgroundStyle += "orangered;";
        break;
    case model::Player::BLUE:
        backgroundStyle += "cornflowerblue;";
        break;
    case model::Player::YELLOW:
        backgroundStyle += "gold;";
        break;
    case model::Player::GREEN:
        backgroundStyle += "green;";
    }
    return backgroundStyle;
}

void PlayerDataWidget::setupBackgroundColor() {
    setStyleSheet(getBackgroundStyle(player_));
}

PlayerDataWidget::~PlayerDataWidget()
{
    delete ui;
}
