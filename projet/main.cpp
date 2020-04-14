#include "FenetrePrincipale.h"
#include "menu.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
	srand(time(NULL)); //initialise le random
    QApplication a(argc, argv);
	a.setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0) } QPushButton:hover{background-color: rgba(255, 255, 255, 50) } QWidget{color: white; font-size: 20px; font-style: bold; qproperty-alignment: AlignCenter;font-family: Teletactile; }");
	QFontDatabase::addApplicationFont(":police/Teletactile.ttf");

	FenetrePrincipale fenetre;

	QPixmap bkgnd(":/images/Fond_Menu.png");
	bkgnd = bkgnd.scaled(fenetre.size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	a.setPalette(palette);

	

	fenetre.show();
	//QMainWindow window;
	//window.setCentralWidget(fenetre);
    //w.show();
//	Menu *menu = new Menu();;
	//menu->setMinimumSize(500, 500);
	//window.setCentralWidget(menu);
	//window.show();
	
    return a.exec();
}
