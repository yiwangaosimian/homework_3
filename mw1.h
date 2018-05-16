#ifndef MW1_H
#define MW1_H

#include <QTime>
#include <QMainWindow>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include <QMessageBox>

namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    //int status;
public slots:
    void MoveMon();
    void ShowFruit();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
    QTimer *timer2;
    int flag;
};

#endif // MW1_H
