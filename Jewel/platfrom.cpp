#include "platfrom.h"

Platfrom::Platfrom()
{

}

Platfrom::Platfrom(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
}

void Platfrom::setGameZone(int rows, int cols)
{
    gameZone.resize(rows);
    for(unsigned int i = 0; i < gameZone.size(); i++)
    {
        gameZone[i].resize(cols);
    }
}
