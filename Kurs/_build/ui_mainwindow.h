/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *tOpen;
    QAction *tExit;
    QAction *tAbout;
    QAction *tCreate;
    QAction *tSave;
    QAction *tSaveAs;
    QAction *tDelete;
    QAction *tEdit;
    QAction *tAddNote;
    QAction *tClearScreen;
    QAction *tDrawGraphic;
    QAction *AcceptSettings;
    QAction *ResetSettins;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *SearchLine;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_Edit;
    QMenu *menu_Settings;
    QMenu *menu_About;
    QMenu *menuLanguage;
    QMenu *menu_Graphics;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(913, 599);
        tOpen = new QAction(MainWindow);
        tOpen->setObjectName(QString::fromUtf8("tOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        tOpen->setIcon(icon);
        tExit = new QAction(MainWindow);
        tExit->setObjectName(QString::fromUtf8("tExit"));
        tAbout = new QAction(MainWindow);
        tAbout->setObjectName(QString::fromUtf8("tAbout"));
        tCreate = new QAction(MainWindow);
        tCreate->setObjectName(QString::fromUtf8("tCreate"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        tCreate->setIcon(icon1);
        tSave = new QAction(MainWindow);
        tSave->setObjectName(QString::fromUtf8("tSave"));
        tSave->setCheckable(false);
        tSave->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        tSave->setIcon(icon2);
        tSaveAs = new QAction(MainWindow);
        tSaveAs->setObjectName(QString::fromUtf8("tSaveAs"));
        tSaveAs->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/-save-as-file-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tSaveAs->setIcon(icon3);
        tDelete = new QAction(MainWindow);
        tDelete->setObjectName(QString::fromUtf8("tDelete"));
        tDelete->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/rubbish_bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        tDelete->setIcon(icon4);
        tEdit = new QAction(MainWindow);
        tEdit->setObjectName(QString::fromUtf8("tEdit"));
        tEdit->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tEdit->setIcon(icon5);
        tAddNote = new QAction(MainWindow);
        tAddNote->setObjectName(QString::fromUtf8("tAddNote"));
        tAddNote->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/addNote.png"), QSize(), QIcon::Normal, QIcon::Off);
        tAddNote->setIcon(icon6);
        tClearScreen = new QAction(MainWindow);
        tClearScreen->setObjectName(QString::fromUtf8("tClearScreen"));
        tClearScreen->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/clear.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tClearScreen->setIcon(icon7);
        tDrawGraphic = new QAction(MainWindow);
        tDrawGraphic->setObjectName(QString::fromUtf8("tDrawGraphic"));
        tDrawGraphic->setEnabled(false);
        AcceptSettings = new QAction(MainWindow);
        AcceptSettings->setObjectName(QString::fromUtf8("AcceptSettings"));
        ResetSettins = new QAction(MainWindow);
        ResetSettins->setObjectName(QString::fromUtf8("ResetSettins"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        SearchLine = new QLineEdit(centralwidget);
        SearchLine->setObjectName(QString::fromUtf8("SearchLine"));

        formLayout->setWidget(0, QFormLayout::FieldRole, SearchLine);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, tableWidget);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 913, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Settings = new QMenu(menubar);
        menu_Settings->setObjectName(QString::fromUtf8("menu_Settings"));
        menu_About = new QMenu(menubar);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menu_Graphics = new QMenu(menubar);
        menu_Graphics->setObjectName(QString::fromUtf8("menu_Graphics"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_Settings->menuAction());
        menubar->addAction(menu_About->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menubar->addAction(menu_Graphics->menuAction());
        menu->addAction(tCreate);
        menu->addAction(tOpen);
        menu->addAction(tSave);
        menu->addSeparator();
        menu->addAction(tSaveAs);
        menu->addSeparator();
        menu->addAction(tExit);
        menu_Edit->addAction(tClearScreen);
        menu_Edit->addAction(tAddNote);
        menu_Edit->addAction(tEdit);
        menu_Edit->addAction(tDelete);
        menu_Settings->addAction(AcceptSettings);
        menu_Settings->addAction(ResetSettins);
        menu_About->addAction(tAbout);
        menu_Graphics->addAction(tDrawGraphic);
        toolBar->addAction(tCreate);
        toolBar->addAction(tOpen);
        toolBar->addAction(tSave);
        toolBar->addSeparator();
        toolBar->addAction(tDelete);
        toolBar->addAction(tClearScreen);
        toolBar->addSeparator();
        toolBar->addAction(tAddNote);
        toolBar->addAction(tEdit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tOpen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        tOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        tExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(shortcut)
        tExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        tAbout->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        tCreate->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        tCreate->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        tSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        tSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        tSaveAs->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        tDelete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        tDelete->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        tEdit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        tEdit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        tAddNote->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
#if QT_CONFIG(shortcut)
        tAddNote->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        tClearScreen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\215\320\272\321\200\320\260\320\275", nullptr));
        tDrawGraphic->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        AcceptSettings->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\320\267\320\274\320\265\321\200 \320\276\320\272\320\275\320\260", nullptr));
        ResetSettins->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \320\276\320\272\320\275\320\260 \320\275\320\260 \321\201\321\202\320\260\321\200\321\213\320\265  \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_Edit->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        menu_Settings->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        menu_About->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "\320\257\320\267\321\213\320\272\320\270", nullptr));
        menu_Graphics->setTitle(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
