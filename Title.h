#ifndef TITLE_H
#define TITLE_H

#include<QWidget>
#include<QMouseEvent>
#include<QPushButton>
#include<QHBoxLayout>
#include<QToolButton>
#include<QSpacerItem>
class Title:public QWidget
{
    Q_OBJECT
public:
  explicit  Title(QWidget *parent= nullptr);
  virtual ~Title();
  bool is_press;
  QPoint pos;   //保存鼠标点击的坐标
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);
  QToolButton *button_min;
  QToolButton *button_close;
  QToolButton *button_max;
  QHBoxLayout *hb;
  QSpacerItem *SpaceItem;
  void InitWidget();
public slots:
  void slot_close();    //关闭曹函数
  void slot_min();      // 最小化
  void slot_max();      //最大话
};

#endif // TITLE_H
