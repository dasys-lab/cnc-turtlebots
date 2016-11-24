#include <QApplication>
#include "../../include/wumpus_simulator/WumpusSimulator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
