#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "player.h"
#include <QLabel>
class World
{
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    int handlePlayerMove(int direction, int steps);
        //假定只有一个玩家
    void monstermove(int steps);
    void showfruit(QPainter * painter);
    void save(string);
private:
    vector<RPGObj> _objs;
    Player _player;
    Player _monster;
};

#endif // WORLD_H
