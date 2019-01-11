#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QMessageBox>
#include <QIcon>
#include <QLabel>
#include <QFontDatabase>

#include <string>
#include <vector>
#include <fstream>
#include <time.h>

#include "block.h"
#include "platfrom.h"
#include "fileoper.h"
#include "jewelgame.h"

using namespace std;

//namespace Ui {
//class gameWindow;
//}

class Block;
class Platfrom;
class FileOper;
class JewelGame;

const int drawRemove = 1;
const int drawFall = 2;
const int drawPlatfrom = 3;

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();

    int platfromRows;
    int platfromCols;
    int platfromHeight;
    int platfromWidth;
    QSize iconSize;
    int iconFrame;

//    QPixmap blank;
    QPixmap durian;
    QPixmap carambola;
    QPixmap grape;
    QPixmap banana;
    QPixmap strawberry;
    QPixmap watermelon;

    QLabel *scoreText;
    QLabel *scoreInfo;
    QLabel *authorInfo;
    QLabel *timeText;
    QLabel *timeInfo;


    string filePath;
    FileOper *fileOper;
    Platfrom *platfrom;
    JewelGame *jewelGame;
    vector<Block *> removeBlocks;

    QTimer fallTimer;
    QTimer drawTimer;
    QTimer countTimer;

    QTime *time;

    bool isPress;
    int drawMode;
    int score;


    void initGame(string filePath);

    void paintPlatform();

protected:
    void paintEvent(QPaintEvent *event);
//	void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
//	void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void fallPic();
    void drawPic();
    void setTime();

private:
//    Ui::gameWindow *ui;
};

#endif // GAMEWINDOW_H
