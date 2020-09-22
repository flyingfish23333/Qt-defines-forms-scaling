#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>
#include<QMouseEvent>
#include<QWidget>
#include<QHBoxLayout>
#include<QMap>
#include<iostream>
#include<tuple>
#include"Title.h"
using namespace std;
class Widget : public QDialog
{
    Q_OBJECT
public:
    enum class LocaTion{top,bottom,left,right,left_top,left_bottm,right_top,right_botm,middle};

    explicit Widget(QWidget *parent = nullptr);
    virtual ~Widget();
protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    const int pading = 5;
    bool pressed_flag;
    LocaTion site_flag;
    Title *title;
    QHBoxLayout *HB;
    QPoint Current_Pos;
private:
    void set_Cursor(QMouseEvent *enevt);
    void set_Stretch(QMouseEvent *enevt);
    void set_title(QColor color = QColor(22, 164, 250),int height = 40);

};

#endif // WIDGET_H
