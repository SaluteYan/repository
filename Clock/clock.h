#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <qmath.h>
#include <QRectF>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Clock; }
QT_END_NAMESPACE

class Clock : public QWidget
{
    Q_OBJECT

public:
    Clock(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    double angle_hour = 0;
    double angle_minute = 0;
    double angle_second = 0;
    ~Clock();

private:
    QTimer *timer;
    Ui::Clock *ui;
};
#endif // CLOCK_H
