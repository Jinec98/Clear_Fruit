#include "fileoper.h"

FileOper::FileOper()
{

}

FileOper::FileOper(string fileName)
{
    this->fileName = fileName;
    platfrom = new Platfrom();
}

Platfrom* FileOper::getPlatfrom()
{
    ifstream fileOpen(fileName.c_str());
    fileOpen >> platfrom->rows >> platfrom->cols;
    fileOpen.get();

    platfrom->setGameZone(platfrom->rows, platfrom->cols);

    int rows = 0;
    while(!fileOpen.eof())
    {
        string str;
        getline(fileOpen, str);
        int len = str.length();
        for(int i = 0; i < len; i++)
        {
            platfrom->gameZone[rows][i] = new Block(rows, i, str[i]);
        }
//        cout<<str<<endl;
        rows++;
    }

    fileOpen.close();
    return platfrom;
}

void FileOper::writePlatfrom()
{
    ofstream fileWrite(fileName.c_str());

    string *str = new string[platfrom->rows];
    for(int i = 0; i < platfrom->rows; i++)
    {
        for(int j = 0; j < platfrom->cols; j++)
            str[i] += platfrom->gameZone[i][j]->c;
        str[i] += '\n';
    }

    fileWrite << platfrom->rows << " " << platfrom->cols <<"\n";
    for(int i = 0; i < platfrom->rows; i++)
        fileWrite << str[i];

    fileWrite.close();
}
