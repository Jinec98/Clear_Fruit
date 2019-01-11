#include "jewelgame.h"

JewelGame::JewelGame()
{

}

JewelGame::JewelGame(Platfrom *platfrom)
{
    this->platfrom = platfrom;
    srand((unsigned)time(NULL));
}

vector<Block *> JewelGame::removeJewel(int x, int y)
{
    vector<Block *> blocks, blocks1, blocks2, blocks3, blocks4;
    blocks.push_back(platfrom->gameZone[x][y]);
    blocks1 = up_down(x, y);
    blocks2 = left_right(x, y);
    blocks3 = leftup_rightdown(x, y);
    blocks4= leftdown_rightup(x, y);
    //    if(blocks1.size() >= 2 || blocks2.size() >= 2 || blocks3.size() >= 2 || blocks4.size() >= 2)
    //        platfrom->gameZone[x][y]->c = ' ';
    if(blocks1.size() >= 2)
        blocks.insert(blocks.end(),blocks1.begin(),blocks1.end());
    if(blocks2.size() >= 2)
        blocks.insert(blocks.end(),blocks2.begin(),blocks2.end());
    if(blocks3.size() >= 2)
        blocks.insert(blocks.end(),blocks3.begin(),blocks3.end());
    if(blocks4.size() >= 2)
        blocks.insert(blocks.end(),blocks4.begin(),blocks4.end());
    return blocks;
}

vector<Block *> JewelGame::up_down(int x, int y)
{
    Block *thisBlock = platfrom->gameZone[x][y];
    vector<Block *> canRemove;
    int cnt = 0;
    int dx[2] = {-1, 1};
    int dy[2] = {0, 0};

    for(int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
        {
            Block *nextBlock = platfrom->gameZone[nx][ny];
            while(nextBlock->c == thisBlock->c)
            {
                canRemove.push_back(nextBlock);
                cnt++;
                nx += dx[i];
                ny += dy[i];
                if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
                    nextBlock = platfrom->gameZone[nx][ny];
                else
                    break;
            }
        }
    }

    //    if(cnt >= 2)
    //    {
    //        for(unsigned int i = 0; i < canRemove.size(); i++)
    //        {
    //            canRemove[i]->c = ' ';
    //        }
    //    }

    return canRemove;
    //    return cnt;
}

vector<Block *> JewelGame::left_right(int x, int y)
{
    Block *thisBlock = platfrom->gameZone[x][y];
    vector<Block *> canRemove;
    int cnt = 0;
    int dx[2] = {0, 0};
    int dy[2] = {-1, 1};

    for(int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
        {
            Block *nextBlock = platfrom->gameZone[nx][ny];
            while(nextBlock->c == thisBlock->c)
            {
                canRemove.push_back(nextBlock);
                cnt++;
                nx += dx[i];
                ny += dy[i];
                if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
                    nextBlock = platfrom->gameZone[nx][ny];
                else
                    break;
            }
        }
    }

    //    if(cnt >= 2)
    //    {
    //        for(unsigned int i = 0; i < canRemove.size(); i++)
    //        {
    //            canRemove[i]->c = ' ';
    //        }
    //    }

    return canRemove;
    //    return cnt;
}

vector<Block *> JewelGame::leftup_rightdown(int x, int y)
{
    Block *thisBlock = platfrom->gameZone[x][y];
    vector<Block *> canRemove;
    int cnt = 0;
    int dx[2] = {-1, 1};
    int dy[2] = {-1, 1};

    for(int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
        {
            Block *nextBlock = platfrom->gameZone[nx][ny];
            while(nextBlock->c == thisBlock->c)
            {
                canRemove.push_back(nextBlock);
                cnt++;
                nx += dx[i];
                ny += dy[i];
                if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
                    nextBlock = platfrom->gameZone[nx][ny];
                else
                    break;
            }
        }
    }

    //    if(cnt >= 2)
    //    {
    //        for(unsigned int i = 0; i < canRemove.size(); i++)
    //        {
    //            canRemove[i]->c = ' ';
    //        }
    //    }

    return canRemove;
    //    return cnt;
}

vector<Block *> JewelGame::leftdown_rightup(int x, int y)
{
    Block *thisBlock = platfrom->gameZone[x][y];
    vector<Block *> canRemove;
    int cnt = 0;
    int dx[2] = {-1, 1};
    int dy[2] = {1, -1};

    for(int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
        {
            Block *nextBlock = platfrom->gameZone[nx][ny];
            while(nextBlock->c == thisBlock->c)
            {
                canRemove.push_back(nextBlock);
                cnt++;
                nx += dx[i];
                ny += dy[i];
                if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
                    nextBlock = platfrom->gameZone[nx][ny];
                else
                    break;
            }
        }
    }

    //    if(cnt >= 2)
    //    {
    //        for(unsigned int i = 0; i < canRemove.size(); i++)
    //        {
    //            canRemove[i]->c = ' ';
    //        }
    //    }

    return canRemove;
    //    return cnt;
}

void JewelGame::fallDown()
{
    for(int i = platfrom->rows-1 ; i >= 0; i--)
    {
        for(int j = platfrom->cols-1; j >=0; j--)
        {
            search_down(i,j);
        }
    }
}

void JewelGame::search_down(int x, int y)
{
    Block *thisBlock = platfrom->gameZone[x][y];

    int nx = x+1;
    int ny = y;

    if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
    {
        Block *nextBlock = platfrom->gameZone[nx][ny];
        while(1)
        {
            //            nextBlock->c = thisBlock->c;
            //            thisBlock->c = ' ';
            //            thisBlock = nextBlock;
            if(nextBlock->c == ' ')
                thisBlock->f++;
            nx += 1;
            if(nx >= 0 && nx < platfrom->rows && ny >= 0 && ny < platfrom->cols)
                nextBlock = platfrom->gameZone[nx][ny];
            else
                break;
        }
    }
}

bool JewelGame::judgeGame()
{
    if(judgeSolution())
        return true;
    else
    {
        for(int i = 0 ; i < platfrom->rows; i++)
        {
            for(int j = 0; j < platfrom->cols; j++)
            {
                int type = rand()%6;
                switch (type)
                {
                case 0:
                    platfrom->gameZone[i][j]->c = 'B';
                    break;
                case 1:
                    platfrom->gameZone[i][j]->c = 'C';
                    break;
                case 2:
                    platfrom->gameZone[i][j]->c = 'D';
                    break;
                case 3:
                    platfrom->gameZone[i][j]->c = 'S';
                    break;
                case 4:
                    platfrom->gameZone[i][j]->c = 'G';
                    break;
                case 5:
                    platfrom->gameZone[i][j]->c = 'W';
                    break;
                }
            }
        }
    }
    return false;
}

bool JewelGame::judgeSolution()
{
    for(int i = 0; i < platfrom->rows; i++)
    {
        for(int j = 0; j < platfrom->cols; j++)
        {
            if(removeJewel(i,j).size() > 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool JewelGame::fillPlatfrom()
{
    bool hasBlocks = false;

        for(int i = 0; i < platfrom->cols; i++)
        {
            if(platfrom->gameZone[0][i]->c != ' ')
                continue;
            hasBlocks = true;
            int type = rand()%6;
            switch (type)
            {
            case 0:
                platfrom->gameZone[0][i]->c = 'B';
                break;
            case 1:
                platfrom->gameZone[0][i]->c = 'C';
                break;
            case 2:
                platfrom->gameZone[0][i]->c = 'D';
                break;
            case 3:
                platfrom->gameZone[0][i]->c = 'S';
                break;
            case 4:
                platfrom->gameZone[0][i]->c = 'G';
                break;
            case 5:
                platfrom->gameZone[0][i]->c = 'W';
                break;
            }
        }

    if(hasBlocks)
        fallDown();
    return hasBlocks;
}
