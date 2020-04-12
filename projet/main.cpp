#include "fenetrejeu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetreJeu w;
    w.show();
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    return a.exec();
}
