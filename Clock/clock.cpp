#include "clock.h"
#include "ui_clock.h"
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPalette>
#define PI 3.14159026

Clock::Clock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clock)
{
    ui->setupUi(this);
}
void Clock::paintEvent(QPaintEvent *){

    //设置外框，时针，分针，秒针,中心点，背景，文本的颜色
    QColor bordercol(105,105,105);
    QColor hourcol(255,215,0);
    QColor minutecol(255,215,0);
    QColor secondcol(190,190,190);
    QColor centercol(211,211,211);
    QColor backcol(0,0,0);
    QColor textcol(245,245,245);

    //画钟表的外框
    //实例化画家对象，this指定当前的设备
    QPainter painter(this);
    //防止图形走样
    painter.setRenderHint(QPainter::Antialiasing);
    //将坐标系原点移至中心点
    painter.translate(width()/2,height()/2);
    //设置画笔颜色
    QPen pen(bordercol);
    //设置画笔的宽度
    pen.setWidth(8);
    //设置风格
    pen.setStyle(Qt::SolidLine);
    //让画家使用该画笔
    painter.setPen(pen);
    //画圆
    painter.drawEllipse(QPoint(0,0),150,150);

    //填充背景颜色
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(backcol));
    this->setPalette(palette);

    //画时针
    pen.setColor(hourcol);
    //设置画笔的宽度
    pen.setWidth(5);
    //让画家使用该画笔
    painter.setPen(pen);
    //画时钟的直线
    painter.drawLine(0,0,60,60);
    //画小时线
    pen.setWidth(3);
    pen.setColor(textcol);
    painter.setPen(pen);
    for (int i =0;i < 12;i++){
        painter.drawLine(135,0,140,0);
        painter.rotate(30);
    }

    //画分针
    pen.setColor(minutecol);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawLine(0,0,70,-70);
    //画分针线
    pen.setWidth(2);
    pen.setColor(textcol);
    painter.setPen(pen);
    for (int m = 0;m < 60;m++){
        painter.drawLine(137,0,140,0);
        painter.rotate(6);
    }

    //画秒针
    pen.setColor(secondcol);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawLine(0,0,-80,-80);

    //画中心点
    painter.setBrush(centercol);
    pen.setColor(centercol);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawEllipse(-5,-5,10,10);

   /* //绘制文本
    pen.setColor(hourcol);
    pen.setWidth(3);
    painter.setPen(pen);
    //设置字体样式
    QFont font;
    font.setPointSize(17);
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);
    painter.setFont(font);
    for (int i = 1;i <= 12;i++){
        painter.drawText(QPoint(110*cos(PI*(i-1)/6 - PI/3),110*sin(PI*(i-1)/6 - PI/3)),QString::number(i));
    }*/












}

Clock::~Clock()
{
    delete ui;
}

