#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QString>
#include <QResizeEvent>

class MyWidget : public QWidget {
    Q_OBJECT
public:
    MyWidget(const QString&, QWidget* parent = nullptr);
    void resizeEvent(QResizeEvent* event) override;

private:
    QString file;
};

#endif // MYWIDGET_H
