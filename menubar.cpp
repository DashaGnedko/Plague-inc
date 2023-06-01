#include "menubar.h"

#include <QDebug>

MenuBar::MenuBar(MyText* name_, int currentLevel_, int maxLevel_, const QPointF& begin_, const QPointF& end_, QColor progressColor_, QBrush progressBrush_) {
    name = name_;
    currentLevel = currentLevel_;
    maxLevel = maxLevel_;
    begin = begin_;
    end = end_;
    progressBar = nullptr;
    progressBarShow = nullptr;
    progressColor = progressColor_;
    progressBrush = progressBrush_;
    setCurrentLevel(currentLevel);
    setPrediction(0);
}

void MenuBar::setText(MyText* name_) {
    name = name_;
}

void MenuBar::setCurrentLevel(int level_) {
    currentLevel = level_;
    double ratio = 1.0 * currentLevel / maxLevel;
    double lengthX = end.x() - begin.x();
    if (progressBar != nullptr && progressBar->item != nullptr) {
        progressBar->item->setRect(begin.x(), begin.y(), lengthX * ratio, end.y() - begin.y());
    }
    progressBar = new MyRectangle(begin.x(), begin.y(), begin.x() + lengthX * ratio, end.y(), progressColor, progressBrush, (progressBar == nullptr ? nullptr : progressBar->item));
}

MyText* MenuBar::getName() {
    return name;
}

int MenuBar::getCurrentLevel() {
    return currentLevel;
}

MyRectangle* MenuBar::getProgressBar() {
    return progressBar;
}

MyRectangle* MenuBar::getProgressBarShow() {
    return progressBarShow;
}

void MenuBar::setPrediction(int prediction) {
    double ratio = 1.0 * prediction / maxLevel;
    double lengthX = end.x() - begin.x();
    QColor color(progressBar->pen.color().red(), progressBar->pen.color().green(), progressBar->pen.color().blue(), 100);
    if (progressBarShow != nullptr && progressBarShow != nullptr && progressBarShow->item != nullptr) {
        progressBarShow->item->setRect(progressBar->end.x(), progressBar->begin.y(), lengthX * ratio, progressBar->end.y() - progressBar->begin.y());
    }
    progressBarShow = new MyRectangle(progressBar->end.x(), progressBar->begin.y(), progressBar->end.x() + lengthX * ratio,
                                      progressBar->end.y(), color, color,  (progressBarShow == nullptr ? nullptr : progressBarShow->item));
}
