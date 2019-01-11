#ifndef JEWELGAME_H
#define JEWELGAME_H

#include "gamewindow.h"

using namespace std;

class Block;
class Platfrom;
class JewelGame
{
public:
    JewelGame();
    JewelGame(Platfrom *platfrom);

    Platfrom *platfrom;
    vector<Block *> removeJewel(int x, int y);
    vector<Block *> up_down(int x, int y);
    vector<Block *> left_right(int x, int y);
    vector<Block *> leftup_rightdown(int x, int y);
    vector<Block *> leftdown_rightup(int x, int y);
    void fallDown();
    void search_down(int x, int y);
    bool judgeGame();
    bool judgeSolution();
    bool fillPlatfrom();
};

#endif // JEWELGAME_H
