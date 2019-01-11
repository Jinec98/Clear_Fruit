#ifndef PLATFROM_H
#define PLATFROM_H

#include "gamewindow.h"

using namespace std;

class Block;
class Platfrom
{
public:
    Platfrom();
    Platfrom(int rows, int cols);

    int rows;
    int cols;
    vector<vector<Block *> >gameZone;

    void setGameZone(int rows, int cols);
};

#endif // PLATFROM_H
