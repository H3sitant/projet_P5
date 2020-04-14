######################################################################
# Automatically generated by qmake (3.1) Thu Apr 9 14:29:45 2020
######################################################################

TEMPLATE = vcapp
TARGET = projet
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += burger.h \
FenetrePrincipale.h \
           Condiment.h \
           fenetrejeu.h \
           panneaucentral.h \
           panneaudroite.h \
           panneaugauche.h \
           Personnage.h \
           Powerup.h \
		   menu.h \
		   pause.h \
		   instructions.h\
		   MenuFinPartie.h
		   
		   
FORMS += fenetrejeu.ui
SOURCES += burger.cpp \
           condiment.cpp \
		   FenetrePrincipale.cpp \
           fenetrejeu.cpp \
           main.cpp \
           panneaucentral.cpp \
           panneaudroite.cpp \
           panneaugauche.cpp \
           Personnage.cpp \
           Powerup.cpp \
		   Menu.cpp \
		   Pause.cpp\
		   Instructions.cpp\
		   MenuFinPartie.cpp
		   

QT += widgets

RESOURCES += \
    ressources.qrc
