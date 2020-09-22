#include"Title.h"
#include<QDebug>
Title::Title(QWidget *parent):QWidget(parent)
{
    this->setFixedHeight(50);
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(22, 164, 250));
    setAutoFillBackground(true);
    setPalette(pal);
    InitWidget();
    connect(button_close,SIGNAL(clicked()),this,SLOT(slot_close()));
//    connect(button_max,SIGNAL(clicked()),this,SLOT(slot_max()));
    connect(button_min,SIGNAL(clicked()),this,SLOT(slot_min()));
}

Title::~Title()
{

    if(button_min)
    {
        delete button_min;
        button_min = nullptr;
    }
    if(button_close)
    {
        delete button_close;
        button_close = nullptr;
    }
    if(button_max)
    {
        delete button_max;
        button_max = nullptr;
    }
    if(hb)
    {
        delete hb;
        hb = nullptr;
    }
}


void Title::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
       is_press=true;
       pos=event->globalPos();
    }
    event->ignore();
}
void Title::mouseReleaseEvent(QMouseEvent *event)
{
    is_press = false;
    event->ignore();
}

void Title::mouseMoveEvent(QMouseEvent *event)
{
    QPoint move_pos;
    if(is_press)
    {
        move_pos = event->globalPos()-pos;
        pos = event->globalPos();
        window()->move(window()->pos()+move_pos);
    }
    event->ignore();
}
void Title::InitWidget()
{


    button_close=new QToolButton;
    button_close->setFixedSize(30,30);
    button_close->setStyleSheet("border-style:outset;background-color: rgb(22, 164, 250);image: url(:/image/close.png);");
    button_max=new QToolButton;
    button_max->setStyleSheet("border-style:outset;background-color: rgb(22, 164, 250);image: url(:/image/max.png);");
    button_max->setFixedSize(30,30);
    button_min=new QToolButton;
    button_min->setFixedSize(30,30);
    button_min->setStyleSheet("border-style:outset;background-color: rgb(22, 164, 250);image: url(:/image/min.png);");
    hb=new QHBoxLayout;
    SpaceItem =new QSpacerItem(100,10,QSizePolicy::Expanding,QSizePolicy::Fixed);
    hb->addItem(SpaceItem);
    hb->addWidget(button_min);
   // hb->addWidget(button_max);
    hb->addWidget(button_close);
    hb->setSpacing(20);

    setLayout(hb);
}
void Title::slot_close()
{
    this->window()->close();
}
void Title::slot_max()
{
    this->window()->showMaximized();
}
void Title::slot_min()
{
    this->window()->showMinimized();
}














