#include "mywidget.h"
#include <QDebug>
MyWidget::MyWidget(const QString& file_, QWidget* parent) : QWidget(parent) {
    file = file_;
}

void MyWidget::resizeEvent(QResizeEvent* event) {
    QPixmap bkgnd (file);
    bkgnd = bkgnd.scaled (size (), Qt :: IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    setAutoFillBackground(true);
}
