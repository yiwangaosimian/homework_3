#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"
#include "rpgobj.h"
#include <QTimer>
#include <map>
#include <iostream>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
    _game.initWorld("/Users/linhailan1/Desktop/RPG/mapFile.txt");//TODO 应该是输入有效的地图文件
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(MoveMon()));//timeoutslot()为自定义槽
    timer2->start(200);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(ShowFruit()));//timeoutslot()为自定义槽
    timer->start(5000);

}

MW1::~MW1()
{
    delete ui;
}

void MW1::MoveMon(){
     _game.monstermove(1);
     this->repaint();
}

void MW1::ShowFruit(){
    QPainter *pa;
    pa = new QPainter();
     _game.showfruit(pa);
     this->repaint();
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    pa->drawPixmap(rect(), QPixmap("/Users/linhailan1/Desktop/RPG/map_background.png"));
    this->_game.show(pa);
    pa->end();
    delete pa;

}

void MW1::keyPressEvent(QKeyEvent *e)
{
    flag=0;
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        flag=this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        flag=this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        flag=this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         flag=this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
    if(flag==3){
        if(QMessageBox::question (this, tr("提示"), tr("GAME OVER"), QMessageBox::Yes) == QMessageBox::Yes){
            this->close ();
            //delete this;    //释放自己的资源
            //return;
        }
    }
}


void MW1::on_pushButton_clicked()
{
    _game.save("/Users/linhailan1/Desktop/RPG/mapFile.txt");
}

void MW1::on_pushButton_2_clicked()
{
    close();
}


