#ifndef FILEOPER_H
#define FILEOPER_H

#include "gamewindow.h"

using namespace std;

class Platfrom;
class FileOper
{
public:
    FileOper();
    FileOper(string fileName);

    string fileName;
    Platfrom *platfrom;

//    void openFile();
//    void writeFile();
    Platfrom* getPlatfrom();
    void writePlatfrom();
};

#endif // FILEOPER_H
