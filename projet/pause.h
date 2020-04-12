#include <QtWidgets>

class Pause : public QWidget {
	Q_OBJECT

public:
	Pause(QWidget *parent=nullptr);

private slots:
	void reprendre();
	void instructions();
	void rejouer();
	void quitter();
	
private:
	void createMenu();
	QPushButton *reprendreP;
	QPushButton *instructionsP;
	QPushButton *rejouerP;
	QPushButton *quitterP;
	QPlainTextEdit *fenetreTexte;
};
