//
// Created by Julien Delcombel on 23/04/2024.
//
#include "myQHboxLayout.h"
#include <QPushButton>
#include <QLabel>

myQHboxLayout::myQHboxLayout() : QHBoxLayout(), pb("Hello"), label("World") {
    this->addWidget(&pb);
    this->addWidget(&label);
}