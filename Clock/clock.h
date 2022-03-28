#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <qmath.h>
#include <QRectF>

QT_BEGIN_NAMESPACE
namespace Ui { class Clock; }
QT_END_NAMESPACE

class Clock : public QWidget
{
    Q_OBJECT

public:
    Clock(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    ~Clock();

private:
    Ui::Clock *ui;
};
#endif // CLOCK_H
