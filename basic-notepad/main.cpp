#include<QApplication>
#include "mainwindow.h"
#include<QSplashScreen>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    QSplashScreen* splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.jpg"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    MainWindow* win=new MainWindow;
    win->show();
    splash->finish(win);
    delete splash;
    return app.exec();
}
