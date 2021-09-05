#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

#include "speaker_enclosure.hpp"
#include "dialog.hpp"
#include <QtGui>
#include <QtCore>
#include <cmath>

///
///В нем находятся основные методы и переменные по работе с главным окном
///
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE



class QActionGroup;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    ///конструктор главного окна
    explicit MainWindow(QWidget *parent = 0);

    ///деструктор главного окна
    ~MainWindow();

    ///
    /// \brief Создание заголовков файлов
    ///
    void CreateHeaderNames();

private slots:

    /// Слот (метод) переключает язык программы
    void switchLanguage(QAction *action);

    /// Cлот для вызова меню о программе
    void tAbout();

    /// Слот для создания нового файла
    void tCreate();

    ///Слот для открытия файла
    void tOpen();

    ///Слот для сохранения файла
    void tSave();

    ///Слот с выбором места для сохранения
    void tSaveAs();

    ///Слот удаления записи
    void tDelete();

    ///Слот поиска элемента
    void on_SearchLine_returnPressed();

    ///Слот для редактирования записи
    void tEdit();

    ///Слот для добавления записи
    void tAddNote();

    ///Слот для очистки экрана
    void tClearScreen();

    ///Слот для применения настроек окна
    void on_AcceptSettings_triggered();

   ///Слот для сброса настроек окна
    void on_ResetSettins_triggered();

    ///Слот для рисования графика
    void on_tDrawGraphic();

///Структура со списоком

public:
    struct Data
    {
        ///объект класса аккустической системы
        speaker_enclosure sp;

        ///указатель на следующего
        Data* next;

        ///указатель на предыдущего
        Data* priv;
    };

private:

    /// указатель на главное окно
    Ui::MainWindow *ui;

    ///переменная с названием файла
    string FileName;

    ///переменная проверки на открытие
    bool IsOpenFile;

    ///указатель на первый элемент списка
    Data *first;

    ///указатель на последний элемент списка
    Data *last;

    /// переменная количества свойств объекта
    const int kol_param = 15;

    ///переменная, показывающая число записей
    int counter = 0;

    ///метод перевода строки в число
    void FuncStrToData(string &str, Data *New);

    ///метод создания ячеек под данные в таблице
    void Create_TableWidgetItem(Data *TW, int i, bool New = true);

    ///метод удаления строки из таблицы
    void Delete_TableWidgetItem(int i);

    ///метод проверки файла на открытие
    bool checkfile();

    ///переменная проверки изменений
    bool checkchanges;

    ////Создадим два объекта управляющих переводом текстов в нашем приложении.

    ///Первый для слов из нашего приложения "app"
    QTranslator appTranslator;

    ///Второй для слов из стандартных сообщений Qt (различные диалоговые окна)
    QTranslator qtTranslator;

    /// Список доступных переводов в меню будет формироваться динамически
    QActionGroup *languageActionGroup;

    /// Переменная где будет храниться путь к файлам перевода "*.qm"
    QString qmPath;

    /// Метод для создания языкового меню
    void createLanguageMenu();

    /// Метод для записи настроек окна
    void writesettings();

    ///Метод для сброса настроек окна
    void readsettings();

};
#endif // MAINWINDOW_H
