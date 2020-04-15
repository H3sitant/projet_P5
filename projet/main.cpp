#include "FenetrePrincipale.h"
#include "menu.h"

#include <QApplication>
#include <QMainWindow>

//D�marrage de l'application

int main(int argc, char *argv[])
{
	srand(time(NULL)); //initialise le random
    QApplication a(argc, argv);
	a.setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0) } QPushButton:hover{background-color: rgba(255, 255, 255, 50) } QWidget{ color: white; font-size: 30px; font-style: bold; qproperty-alignment: AlignCenter;font-family: Teletactile; } QProgressBar{ border-radius: 5 px; background-color: rgba(255,255,255,40);}  ");
	QFontDatabase::addApplicationFont(":police/Teletactile.ttf");

	FenetrePrincipale fenetre;
	fenetre.setWindowTitle("Fat UNICORN");
	fenetre.setWindowIcon(QIcon(":images/Modele_Burger.png"));
	fenetre.show();

	QPixmap bkgnd(":/images/Fond_Menu.png");
	bkgnd = bkgnd.scaled(fenetre.size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	a.setPalette(palette);
	

	
    return a.exec();
}
