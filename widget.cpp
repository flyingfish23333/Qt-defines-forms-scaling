#include "widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent) :
    QDialog(parent),
    pressed_flag(false)
{

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_Mapped);
    this->setMinimumSize(500,300);
    this->set_title();


}

Widget::~Widget()
{
    try{
        delete title;
        delete HB;
    }catch(...)
    {
        qDebug()<<"Crash ...";
    }
}

void Widget::mouseMoveEvent(QMouseEvent *enevt)
{

    if(!pressed_flag)
    {

        set_Cursor(enevt);
    }
    else
    {
        set_Stretch(enevt);
    }


}

void Widget::mousePressEvent(QMouseEvent *event)
{


    if(event->button()== Qt::LeftButton)
    {
        pressed_flag = true;
        Current_Pos = event->globalPos();
    }
    else
    {
          event->ignore();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{

    if(event->button()== Qt::LeftButton)
    {
        pressed_flag = false;
    }
    else
    {
         event->ignore();
    }

}

void Widget::set_Cursor(QMouseEvent *event)
{


    int width = this->width();
    int height = this->height();


    QRect top_ =            QRect(pading, 0, width - pading * 2, pading);
    QRect bottom_ =         QRect(pading, height - pading, width - pading * 2,pading);
    QRect left_ =           QRect(0, pading, pading, height - pading * 2);
    QRect right_ =          QRect(width - pading, pading, pading,height - pading * 2);
    QRect top_left =        QRect(0, 0, pading, pading);
    QRect top_right =       QRect(width - pading, 0, pading, pading);
    QRect bottom_left =     QRect(0, height - pading, pading, pading);
    QRect bottom_right =    QRect(width - pading, height - pading, pading, pading);




    if(top_.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeVerCursor));  // 设置鼠标形状  上
        site_flag = top;
    }

    else if(bottom_.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeVerCursor));  // 设置鼠标形状  下
        site_flag = bottom;
    }
    else if(left_.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeHorCursor));  // 设置鼠标形状  左
        site_flag = left;
    }
    else if(right_.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeHorCursor));  // 设置鼠标形状  右
        site_flag = right;
    }
    else if (top_left.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeFDiagCursor));  // 设置鼠标形状 左上
        site_flag = left_top;

    }
    else if (top_right.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeBDiagCursor));  // 设置鼠标形状 右上
        site_flag = right_top;
    }
    else if (bottom_left.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeBDiagCursor));  // 设置鼠标形状 左下
        site_flag = left_bottm;
    }
    else if(bottom_right.contains(event->pos()))
    {
        this->setCursor(QCursor(Qt::SizeFDiagCursor));  // 设置鼠标形状 右下
        site_flag = right_botm;
    }
    else
    {
        this->setCursor(QCursor(Qt::ArrowCursor));
        site_flag =  middle;
    }

}

void Widget::set_Stretch(QMouseEvent *event)
{

    QRect rect = this->rect();
    QPoint gloPoint = event->globalPos() ;
    QPoint  topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());
    QPoint bottomLeft = mapToGlobal(rect.bottomLeft());
    QPoint topRight = mapToGlobal(rect.topRight());



    QRect rMove(topLeft, bottomRight);

    switch (site_flag) {
    case left:

        if (bottomRight.x() - gloPoint.x() > this->minimumWidth())
        {
           rMove.setX(gloPoint.x());
        }
        this->setGeometry(rMove);
        break;
    case top:
        if (bottomRight.y() - gloPoint.y() > this->minimumHeight())
        {
            rMove.setY(gloPoint.y());
        }
        this->setGeometry(rMove);
        break;
    case right:
        if (gloPoint.x() - bottomLeft.x() > this->minimumWidth())
        {
            rMove.setWidth(gloPoint.x() - bottomLeft.x());
        }
        this->setGeometry(rMove);
        break;
    case bottom:
        if (gloPoint.y() - topRight.y() > this->minimumHeight())
        {
            rMove.setHeight(gloPoint.y() - topRight.y());
        }
        this->setGeometry(rMove);
        break;
    case left_top:
        if ((bottomRight.y() - gloPoint.y() <= this->minimumHeight()) )
        {
            rMove.setX(topLeft.x());
            rMove.setHeight(this->height());
        }
        else if( (bottomRight.x() - gloPoint.x() <= this->minimumWidth()))
        {
             rMove.setWidth(this->minimumWidth());
             rMove.setY(gloPoint.y());
        }
        else
        {
            rMove.setX(gloPoint.x());
            rMove.setY(gloPoint.y());

        }
        this->setGeometry(rMove);
        break;
    case right_top:
        if (bottomRight.y() - gloPoint.y()  <= this->minimumHeight())
        {
            rMove.setWidth(gloPoint.x() - topLeft.x());
            rMove.setY(topRight.y());
        }
        else if(( gloPoint.x() - bottomLeft.x()  <= this->minimumWidth()))
        {
            rMove.setWidth(this->minimumWidth());
            rMove.setY(gloPoint.y());
        }
        else
        {
            rMove.setWidth(gloPoint.x() - topLeft.x());
            rMove.setY(gloPoint.y());
        }
        this->setGeometry(rMove);
        break;
    case left_bottm:

        if(bottomRight.x() - gloPoint.x() <= this->minimumWidth())
        {

            rMove.setWidth(this->minimumWidth());
            rMove.setHeight(gloPoint.y() - topLeft.y());
        }
        else if(gloPoint.y() - topLeft.y() <= this->minimumHeight())
        {
            rMove.setX(gloPoint.x());
            rMove.setHeight(this->minimumHeight());
        }
        else
        {
            rMove.setBottomLeft(gloPoint);
        }
        this->setGeometry(rMove);
        break;
    case right_botm:
        if( gloPoint.y() - topLeft.y()  <= this->minimumHeight())
        {
            rMove.setWidth(gloPoint.x()- topLeft.x());
            rMove.setHeight(this->minimumHeight());
        }
        else if(( gloPoint.x() - bottomLeft.x()  <= this->minimumWidth()))
        {
            rMove.setWidth(this->minimumWidth());
            rMove.setHeight(gloPoint.y()- topLeft.y());
        }
        else
        {
            rMove.setWidth(gloPoint.x()- topLeft.x());
            rMove.setHeight(gloPoint.y()- topLeft.y());
        }
        this->setGeometry(rMove);
        break;
    case middle:

        window()->move(window()->pos() +  gloPoint - Current_Pos);
        Current_Pos = gloPoint;

    default:
        event->ignore();
        break;
    }
    HB->setContentsMargins(0,0,0,this->height()-30);


}

void Widget::set_title(QColor color ,int height )
{

    QColor(22, 164, 250);
    QPalette pal;
    pal.setColor(QPalette::Background, color);
    title = new QWidget(this);
    title->setParent(this);
    title->setAutoFillBackground(true);
    title->setPalette(pal);
    title->setFixedHeight(30);
    title->setMouseTracking(true);
    HB = new QHBoxLayout;
    HB->addWidget(title);
    HB->setContentsMargins(0,0,0,this->height()- height);
    this->setLayout(HB);

}
