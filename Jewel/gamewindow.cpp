#include "gamewindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
    QWidget(parent)
  //    ui(new Ui::gameWindow)
{
    //    ui->setupUi(this);
    setWindowTitle("水果消消乐");
    setWindowOpacity(0.9);
    setFixedSize(450, 650);
    setMouseTracking(true);

    //    blank = QPixmap("");
    banana = QPixmap("://resource/banana.png");
    carambola = QPixmap("://resource/carambola.png");
    durian = QPixmap("://resource/durian.png");
    grape = QPixmap("://resource/grape.png");
    strawberry = QPixmap("://resource/strawberry.png");
    watermelon = QPixmap("://resource/watermelon.png");

    filePath = "test1.txt";

    int id = QFontDatabase::addApplicationFont("://resource/BauhausStd-Light.otf");
    QFontDatabase::applicationFontFamilies(id);

    timeText = new QLabel("Time:");
    timeText->setFont(QFont("Bauhaus Std Light", 30));
    timeText->setGeometry(325, 100, 125, 50);
    timeText->setParent(this);

    timeInfo = new QLabel("00:00:00");
    timeInfo->setFont(QFont("Bauhaus Std Light", 20));
    timeInfo->setGeometry(325, 150, 125, 50);
    timeInfo->setParent(this);

    scoreText = new QLabel("Score:");
    scoreText->setFont(QFont("Bauhaus Std Light", 30));
    scoreText->setGeometry(325, 250, 125, 50);
    scoreText->setParent(this);

    scoreInfo = new QLabel("0");
    scoreInfo->setFont(QFont("Bauhaus Std Light", 40));
    scoreInfo->setGeometry(325, 300, 150, 50);
    scoreInfo->setParent(this);

    authorInfo = new QLabel("@Jinec");
    authorInfo->setFont(QFont("Bauhaus Std Light", 20));
    authorInfo->setGeometry(325, 450, 150, 50);
    authorInfo->setParent(this);


    initGame(filePath);


}

gameWindow::~gameWindow()
{
    //    delete ui;
}

void gameWindow::initGame(string filePath)
{
    fallTimer.setInterval(25);
    connect(&fallTimer, &QTimer::timeout, this, &gameWindow::fallPic);
    drawTimer.setInterval(50);
    connect(&drawTimer, &QTimer::timeout, this, &gameWindow::drawPic);
    countTimer.setInterval(1000);
    connect(&countTimer, &QTimer::timeout, this, &gameWindow::setTime);
    countTimer.start();

    drawMode = drawPlatfrom;
    isPress = false;

    time = new QTime(0, 0, 0);
    score = 0;
    iconSize = QSize(50,50);
    iconFrame = 0;

    fileOper = new FileOper(filePath);
    platfrom = fileOper->getPlatfrom();
    jewelGame = new JewelGame(platfrom);

    platfromRows = jewelGame->platfrom->rows;
    platfromCols = jewelGame->platfrom->cols;
    platfromHeight = platfromRows * iconSize.height();
    platfromWidth = platfromCols * iconSize.width();

    qDebug()<<platfromRows<<platfromCols<<platfromHeight<<platfromWidth;

    //    gamePicLabel = new QLabel **[platfromRows];
    //    for(int i = 0; i < platfromRows; i++)
    //    {
    //        gamePicLabel[i] = new QLabel *[platfromCols];
    //    }
    //    for(int i = 0; i < platfromRows; i++)
    //    {
    //        for(int j = 0; j < platfromCols; j++)
    //        {
    //            gamePicLabel[i][j] = new QLabel();
    //            gamePicLabel[i][j]->setScaledContents(true);
    //            gamePicLabel[i][j]->setParent(this);
    //        }
    //    }
}

void gameWindow::setTime()
{
    *time = time->addSecs(1);
    timeInfo->setText(time->toString("hh:mm:ss"));
}

void gameWindow::fallPic()
{
    bool isOk = true;
    qDebug()<<"111";
    for(int i = platfromRows-1; i >= 0; i--)
    {
        for(int j = platfromCols-1; j >= 0; j--)
        {
            //            qDebug()<<jewelGame->platfrom->gameZone[i][j]->f;
            if(jewelGame->platfrom->gameZone[i][j]->f != 0)
            {
                qDebug()<<i<<j;
                isOk = false;
                jewelGame->platfrom->gameZone[i+1][j]->c = jewelGame->platfrom->gameZone[i][j]->c;
                jewelGame->platfrom->gameZone[i+1][j]->f = jewelGame->platfrom->gameZone[i][j]->f -1;
                jewelGame->platfrom->gameZone[i][j]->c = ' ';
                jewelGame->platfrom->gameZone[i][j]->f = 0;
            }
        }
    }
    repaint();

    if(isOk)
    {
        qDebug()<<"~~~~~";
        paintPlatform();
        fallTimer.stop();
        if(jewelGame->fillPlatfrom())//还需要填
        {
            fallTimer.start();
            return;
        }
        if(!jewelGame->judgeGame())//无解
        {
            QMessageBox::information(this, "哦漏！", "出现无解情况，已重置游戏界面！", QMessageBox::Ok);
            repaint();
//            jewelGame->fillPlatfrom();
//            fallTimer.start();

        }
        isPress = false;
    }
}

void gameWindow::drawPic()
{
    repaint();

}

void gameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);


    for(int i = 0; i < platfromRows; i++)
    {
        for(int j = 0; j < platfromCols; j++)
        {
            vector<Block *>::iterator findInBlocks;
            findInBlocks = std::find(removeBlocks.begin(), removeBlocks.end(), jewelGame->platfrom->gameZone[i][j]);
            if(findInBlocks != removeBlocks.end())
                continue;
            //            qDebug()<<jewelGame->platfrom->gameZone[i][j]->c;
            switch(jewelGame->platfrom->gameZone[i][j]->c)
            {
            case ' ':

                break;
            case 'B':
                painter.drawPixmap(j*iconSize.width(),i*iconSize.height(),banana,0,0,iconSize.width(),iconSize.width());
                break;
            case 'C':
                painter.drawPixmap(j*iconSize.width(),i*iconSize.height(),carambola,0,0,iconSize.width(),iconSize.width());
                break;
            case 'D':
                painter.drawPixmap(j*iconSize.width(),i*iconSize.height(),durian,0,0,iconSize.width(),iconSize.width());
                break;
            case 'G':
                painter.drawPixmap(j*iconSize.width(),i*iconSize.height(),grape,0,0,iconSize.width(),iconSize.width());
                break;
            case 'S':
                painter.drawPixmap(j*iconSize.width(),i*iconSize.height(),strawberry,0,0,iconSize.width(),iconSize.width());
                break;
            case 'W':
                painter.drawPixmap(j*iconSize.width(),i*iconSize.height(),watermelon,0,0,iconSize.width(),iconSize.width());
                break;
            }

            //            if(jewelGame->platfrom->gameZone[i][j]->c = ' ')
            //                gamePicLabel[i][j]->setVisible(false);
            //            else
            //            {
            //                gamePicLabel[i][j]->setVisible(true);
            //            }
            //            gamePicLabel[i][j]->setGeometry(j*iconSize.width(), i*iconSize.height(), iconSize.width(), iconSize.height());
            //            gamePicLabel[i][j]->show();
        }
    }

    if(drawMode == drawRemove)
    {
        for(unsigned int i = 0; i < removeBlocks.size(); i++)
        {
            switch (removeBlocks[i]->c)
            {
            case 'B':
                painter.drawPixmap(removeBlocks[i]->y*iconSize.width(),removeBlocks[i]->x*iconSize.height(),banana,iconFrame,0,iconSize.width(),iconSize.width());
                break;
            case 'C':
                painter.drawPixmap(removeBlocks[i]->y*iconSize.width(),removeBlocks[i]->x*iconSize.height(),carambola,iconFrame,0,iconSize.width(),iconSize.width());
                break;
            case 'D':
                painter.drawPixmap(removeBlocks[i]->y*iconSize.width(),removeBlocks[i]->x*iconSize.height(),durian,iconFrame,0,iconSize.width(),iconSize.width());
                break;
            case 'G':
                painter.drawPixmap(removeBlocks[i]->y*iconSize.width(),removeBlocks[i]->x*iconSize.height(),grape,iconFrame,0,iconSize.width(),iconSize.width());
                break;
            case 'S':
                painter.drawPixmap(removeBlocks[i]->y*iconSize.width(),removeBlocks[i]->x*iconSize.height(),strawberry,iconFrame,0,iconSize.width(),iconSize.width());
                break;
            case 'W':
                painter.drawPixmap(removeBlocks[i]->y*iconSize.width(),removeBlocks[i]->x*iconSize.height(),watermelon,iconFrame,0,iconSize.width(),iconSize.width());
                break;
            }
        }

        iconFrame += iconSize.width();
        //        qDebug()<<iconFrame;
        if(iconFrame == 500)
        {
            //            qDebug()<<iconFrame;
            iconFrame = 0;
            for(unsigned int i = 0; i < removeBlocks.size(); i++)
                removeBlocks[i]->c = ' ';

            drawMode = drawPlatfrom;//fall
            drawTimer.stop();
            paintPlatform();
            removeBlocks.clear();
            jewelGame->fallDown();
            fallTimer.start();
        }
    }

    //    if(drawMode == drawFall)
    //    {
    //        for(int i = 0; i < platfromRows; i++)
    //        {
    //            for(int j = 0; j < platfromCols; j++)
    //            {
    //                if(jewelGame->platfrom->gameZone[i][j]->f != 0)
    //                {
    //                    switch(jewelGame->platfrom->gameZone[i][j]->c)
    //                    {
    //                    case ' ':

    //                        break;
    //                    case 'B':
    //                        painter.drawPixmap(j*iconSize.width(),i*iconSize.height() + 50,banana,0,0,iconSize.width(),iconSize.width());
    //                        break;
    //                    case 'C':
    //                        painter.drawPixmap(j*iconSize.width(),i*iconSize.height() + 50,carambola,0,0,iconSize.width(),iconSize.width());
    //                        break;
    //                    case 'D':
    //                        painter.drawPixmap(j*iconSize.width(),i*iconSize.height()+50,durian,0,0,iconSize.width(),iconSize.width());
    //                        break;
    //                    case 'G':
    //                        painter.drawPixmap(j*iconSize.width(),i*iconSize.height()+50,grape,0,0,iconSize.width(),iconSize.width());
    //                        break;
    //                    case 'S':
    //                        painter.drawPixmap(j*iconSize.width(),i*iconSize.height()+50,strawberry,0,0,iconSize.width(),iconSize.width());
    //                        break;
    //                    case 'W':
    //                        painter.drawPixmap(j*iconSize.width(),i*iconSize.height()+50,watermelon,0,0,iconSize.width(),iconSize.width());
    //                        break;
    //                    }
    //                    jewelGame->platfrom->gameZone[i][j]->f--
    //                }
    //            }
    //        }
    //    }
}

void gameWindow::mousePressEvent(QMouseEvent *event)
{
    if(isPress)
        return;
    if(fallTimer.isActive())
        return;
    if(drawTimer.isActive())
        return;

    int posx = event->pos().x();
    int posy = event->pos().y();
    if(event->button() == Qt::LeftButton
            && posx >= 0 && posx <= platfromWidth
            && posy >= 0 && posy <= platfromHeight)
    {
        int j = posx / iconSize.width();
        int i = posy / iconSize.height();
        qDebug()<<i<<j;
        if(i >= 0 && i < platfromRows && j >= 0 && j < platfromCols)
        {
            //            jewelGame->platfrom->gameZone[i][j] = ' ';
            removeBlocks = jewelGame->removeJewel(i,j);
            if(removeBlocks.size() > 1)
            {
                isPress = true;
                score += removeBlocks.size();
                scoreInfo->setText(QString::number(score));
                qDebug()<<removeBlocks.size();
                //drawTimer.start();
                drawMode = drawRemove;
                drawTimer.start();
            }
            else
                removeBlocks.clear();
            //                repaint();
        }
    }


}


void gameWindow::paintPlatform()
{
    for(int i = 0; i < platfromRows; i++)
    {
        QString str;
        for(int j = 0; j < platfromCols; j++)
        {
            str.append(jewelGame->platfrom->gameZone[i][j]->c);
            str.append(" ");
        }
        qDebug()<<str;
    }
}
