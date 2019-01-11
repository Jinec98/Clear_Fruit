#include "block.h"

Block::Block()
{

}

Block::Block(int x, int y, char c)
{
    this->x = x;
    this->y = y;
    this->c = c;
    f = 0;
}

Block::Block(const Block &b)
{
    this->x = b.x;
    this->y = b.y;
    this->c = b.c;
    this->f = b.f;
}

bool Block::operator==(const Block &b)
{
    return x == b.x && y == b.y && c == b.c && f == b.f;
}
