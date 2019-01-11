#ifndef BLOCK_H
#define BLOCK_H

#include "gamewindow.h"

class Block
{
public:
    Block();
    Block(int x, int y, char c);
    Block(const Block &b);
    bool operator== (const Block &b);

    int x;
    int y;
    int f;
    char c;
};

#endif // BLOCK_H
