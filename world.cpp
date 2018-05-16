#include "world.h"
#include "icon.h"
#include "mw1.h"
#include <iostream>
#include <fstream>
using namespace  std;
void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);
    this->_monster.initObj("monster");
    this->_monster.setPosX(9);
    this->_monster.setPosY(7);

    //stone 4 5
    fstream in;
    in.open(mapFile,ios::in);
    if(!in.is_open()) cout<<"Wrong!"<<endl;
    else{
        vector<RPGObj>::iterator it;
        string TypeName;
        int X,Y;
        while(in>>TypeName>>X>>Y){
            RPGObj obj;
            obj.initObj(TypeName);   obj.setPosX(X);   obj.setPosY(Y);
            this->_objs.push_back(obj);
        }
        in.close();
    }
}

void World::showfruit(QPainter * painter){
    vector<RPGObj>::iterator it;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int X= rand()%44,Y=rand()%28,flag=0;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if(X>=(*it).getPosX()&&X<=(*it).getPosX()+(*it).getWidth()
                &&Y>=(*it).getPosY()&&Y<=(*it).getPosY()+(*it).getHeight()){
                flag=1; break;
         }
    }
    if(!flag){
        RPGObj obj;
        obj.initObj("fruit");   obj.setPosX(X);   obj.setPosY(Y);
        this->_objs.push_back(obj);
        obj.show(painter);
    }
}

void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_monster.show(painter);
    this->_player.show(painter); 
}

void World::monstermove(int steps){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int Direction = rand()%4+1;
    int flag=0;
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((_monster.getPosY()-((*it).getHeight()-1)==(*it).getPosY())&&(_monster.getPosX()>=(*it).getPosX())
                &&(_monster.getPosX()<=(*it).getPosX()+(*it).getWidth()-1)&&(Direction==1)){
            flag=1;  break;
        }
        else if((_monster.getPosY()+2==(*it).getPosY())&&(_monster.getPosX()>=(*it).getPosX())
                &&(_monster.getPosX()<=(*it).getPosX()+(*it).getWidth()-1)&&(Direction==2)){
            flag=1;     break;
        }
        else if((_monster.getPosX()-(*it).getWidth()==(*it).getPosX())&&(_monster.getPosY()+1>=(*it).getPosY())
                &&(_monster.getPosY()+1<=(*it).getPosY()+(*it).getHeight()-1)&&(Direction==3)){
            flag=1;    break;
        }
        else if((_monster.getPosX()+1==(*it).getPosX())&&(_monster.getPosY()+1>=(*it).getPosY())
                &&(_monster.getPosY()+1<=(*it).getPosY()+(*it).getHeight()-1)&&(Direction==4)){
           flag=1;     break;
        }
    }
    if(!flag)  {
        this->_monster.move(Direction, steps);
    }
}

int World::handlePlayerMove(int direction, int steps){
    int flag=0;
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((_player.getPosY()-((*it).getHeight()-1)==(*it).getPosY())&&(_player.getPosX()>=(*it).getPosX())
                &&(_player.getPosX()<=(*it).getPosX()+(*it).getWidth()-1)&&(direction==1)){
            if((*it).canEat())  flag=2;
            else {
                if((*it).getObjType()=="cross")     flag=3;
                else    flag=1;
            }
            break;
        }
        else if((_player.getPosY()+2==(*it).getPosY())&&(_player.getPosX()>=(*it).getPosX())
                &&(_player.getPosX()<=(*it).getPosX()+(*it).getWidth()-1)&&(direction==2)){
            if((*it).canEat())  flag=2;
            else {
                if((*it).getObjType()=="cross")     flag=3;
                else    flag=1;
            }
            break;
        }
        else if((_player.getPosX()-(*it).getWidth()==(*it).getPosX())&&(_player.getPosY()+1>=(*it).getPosY())
                &&(_player.getPosY()+1<=(*it).getPosY()+(*it).getHeight()-1)&&(direction==3)){
            if((*it).canEat())  flag=2;
            else {
                if((*it).getObjType()=="cross")     flag=3;
                else    flag=1;
            }
            break;
        }
        else if((_player.getPosX()+1==(*it).getPosX())&&(_player.getPosY()+1>=(*it).getPosY())
                &&(_player.getPosY()+1<=(*it).getPosY()+(*it).getHeight()-1)&&(direction==4)){
            if((*it).canEat())  flag=2;
            else {
                if((*it).getObjType()=="cross")     flag=3;
                else    flag=1;
            }
            break;
        }
    }

    if((_player.getPosY()-1==_monster.getPosY())&&(_player.getPosX()==_monster.getPosX())
            &&(direction==1)){      flag=1;     }
    else if((_player.getPosY()+2==_monster.getPosY())&&(_player.getPosX()==_monster.getPosX())
            &&(direction==2)){      flag=1;     }
    else if((_player.getPosX()-1==_monster.getPosX())&&(_player.getPosY()+1>=_monster.getPosY())
            &&(_player.getPosY()+1<=_monster.getPosY()+1)&&(direction==3)){     flag=1;      }
    else if((_player.getPosX()+1==_monster.getPosX())&&(_player.getPosY()+1>=_monster.getPosY())
            &&(_player.getPosY()+1<=_monster.getPosY()+1)&&(direction==4)){      flag=1;    }
    if(!flag)   this->_player.move(direction, steps);
    else if(flag==2){
        static int i=0;
        this->_player.move(direction, steps);
        i+=5;
        _objs.erase(it);
    }
    else if(flag==3){
        //MW1 mw;
        //mw.die(1);
        //die();
    }
    return flag;
}

void World::save(string mapFile){
    fstream out;
    out.open(mapFile,ios::out|ios::ate);
    if(!out.is_open()) cout<<"Wrong!"<<endl;
    else{
        vector<RPGObj>::iterator it;
        for(it=this->_objs.begin();it!=this->_objs.end();it++){
            out<<(*it).getObjType()<<"\t"<<(*it).getPosX()<<"\t"<<(*it).getPosY()<<endl;
        }
        out.close();
    }
}

