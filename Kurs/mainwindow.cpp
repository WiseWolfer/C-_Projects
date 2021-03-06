#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QLibraryInfo>
#include <QInputDialog>
#include <iostream>
#include <string>
#include <fstream>
#include <QTableWidget>

#include <QDrag>
#include <QSettings>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QLegend>
#include <QtCharts/QCategoryAxis>

///
/// Реализация класса главного окна
///

QT_CHARTS_USE_NAMESPACE

/*!
    Программу разработал:
    Сбродов Дмитрий ИЭУИС 2-4
    Акустическая система
*/

///инициализируем необходимые переменные и подключаем кнопки
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , first(0)
    , last(0)
  {
      IsOpenFile = false;
      ui->setupUi(this);
      readsettings();
      ui->tableWidget->setDragDropMode(QAbstractItemView::InternalMove);

      connect(ui->tOpen, &QAction::triggered,
              this, &MainWindow::tOpen);

      connect(ui->tCreate, &QAction::triggered,
              this, &MainWindow::tCreate);

     connect(ui->tSave, &QAction::triggered,
             this, &MainWindow::tSave);

     connect(ui->tSaveAs, &QAction::triggered,
             this, &MainWindow::tSaveAs);

      connect(ui->tExit, &QAction::triggered,
              this, &MainWindow::close);

      connect(ui->tAbout, &QAction::triggered,
              this, &MainWindow::tAbout);

      connect(ui->tDelete, &QAction::triggered,
              this, &MainWindow::tDelete);

      connect(ui->tAddNote, &QAction::triggered,
              this, &MainWindow::tAddNote);

      connect(ui->tEdit, &QAction::triggered,
              this, &MainWindow::tEdit);

      connect(ui->tClearScreen, &QAction::triggered,
              this, &MainWindow::tClearScreen);
      connect(ui->tDrawGraphic,&QAction::triggered,
              this, &MainWindow::on_tDrawGraphic);

      qApp->installTranslator(&appTranslator); // инициализируем объект перевода слов в приложении
      qApp->installTranslator(&qtTranslator); // инициализируем объект перевода слов в сообщениях qt

      qmPath = qApp->applicationDirPath() + "/translations"; //пишем в qmPath путь, где будут переводы

      ui->tableWidget->setSortingEnabled(true);
      createLanguageMenu(); //создание языкового меню

}

MainWindow::~MainWindow()
{
    delete ui;

    writesettings(); /// Запуск метода записывающего параметры окна
}
///Функция создания заголовков в таблице
void MainWindow::CreateHeaderNames()
{
    //настраиваем заголовки по размеру
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //устанавилваем число столбцов равное kol_param = 15
    ui->tableWidget->setColumnCount(kol_param);

    //Создаем сами заголовки и даем им название
    QStringList HorizontalHeader;
    HorizontalHeader.append(tr("Name of the accoustic system"));
    HorizontalHeader.append(tr("Total rated power"));
    HorizontalHeader.append(tr("Total max power"));
    HorizontalHeader.append(tr("Type of the accoustic system"));
    HorizontalHeader.append(tr("RF speakers"));
    HorizontalHeader.append(tr("Midrange_speakers"));
    HorizontalHeader.append(tr("bass speakers"));
    HorizontalHeader.append(tr("Cost"));
    HorizontalHeader.append(tr("Frequency range"));
    HorizontalHeader.append(tr("Guarantee"));
    HorizontalHeader.append(tr("Country"));
    HorizontalHeader.append(tr("Front Power"));
    HorizontalHeader.append(tr("Front max Power"));
    HorizontalHeader.append(tr("Front sensetivity"));
    HorizontalHeader.append(tr("Front impedance"));

    //добавляем в заголовки названия столбцов
    ui->tableWidget->setHorizontalHeaderLabels(HorizontalHeader);
}

///Функция вывода на экран создателя программы
void MainWindow::tAbout()
{
    //вызываем информационное окно с информацией о создаетеле программы
    QMessageBox::about(this, tr("My Program"), tr("This program was made by Dimitrii Sbrodov EUIS 2-4"));
}

///Функция для создания новой таблицы по аккустической системе
void MainWindow:: tCreate()
{
    // в filename передаем выбранный файл открытый в окне QFileDialog
    QString FILENAME = QFileDialog::getSaveFileName(this,
                                QString::fromUtf8("Choose your file to open"),
                                QDir::currentPath(),
                                "DB Files (*.db *.txt);;All Files (*.*)");

    // если будет ничего не выбранно, то просто возвращаемся в окно
    if(FILENAME=="") return;
    // переводим из qstring в строку и записываем в FileName
    FileName = FILENAME.toStdString();
    //открываем файл указанный в FILENAME
    QFile in(FILENAME);
    //открываем файл на запись
    in.open(QFile::WriteOnly);
    in.close();

    //вызов названия заголовков
    CreateHeaderNames();

    IsOpenFile = true;
    //после открытия файла блокируем
    ui->tOpen->setEnabled(!IsOpenFile);
    ui->tCreate->setEnabled(!IsOpenFile);
    ui->tSave->setEnabled(IsOpenFile);
    ui->tSaveAs->setEnabled(IsOpenFile);
    ui->tDelete->setEnabled(IsOpenFile);
    ui->tEdit->setEnabled(IsOpenFile);
    ui->tAddNote->setEnabled(IsOpenFile);
    ui->tClearScreen->setEnabled(IsOpenFile);
}
///Функция открытия файла
void MainWindow::tOpen()
{
    //создаем объект для открытия файла
    QFile file;
    do
    {
        //записываем название открываемого файла
        QString FILENAME = QFileDialog::getOpenFileName(0, tr("Choose your file to open"), "", "*.db *.txt");
        // если будет ничего не выбранно, то просто возвращаемся в окно
        if(FILENAME=="") return;
        //в файл по классу QFile передаем название открываемого файла
        file.setFileName(FILENAME);
        //конвертируем qstring в string и фиксируем в fileName
        FileName = FILENAME.toStdString();
        //открытие файла в режиме только для чтения
        file.open(QFile::ReadOnly);
        //если при проверке на открытие, мы открыли файл, на который не сработал метод FuncStrToData
        if(!checkfile())
        {
            //Создаем объект по классу QMessageBox, чтобы через него обработать исключение
            QMessageBox msgBox;
            //устанавливаем название окна
            msgBox.setWindowTitle("Ошибка");
            //устанавливаем исходный текст окна
            msgBox.setText("Выбранный файл не соответствует требуемому формату!");
            //пишем информационное сообщение(пояснителное для пользователя)
            msgBox.setInformativeText("Ок - открыть другой файл\nCancel - отменить открытие файла");
            //задаем кнопки
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            //устанавливаем иконку для окна
            msgBox.setIcon(QMessageBox::Information);
            //задаем кнопку по умолчанию
            msgBox.setDefaultButton(QMessageBox::Ok);
            //запускаем окно обработки исключения
            int res = msgBox.exec();
            //в случае, когда нажали cancel возвращаемся в Mainwindow
            if (res == QMessageBox::Cancel)
                return;
        }
    }while(!checkfile());

        last = 0;
        first = 0;
        char a [1024];
       //задаем крутящийся курсор
        QApplication::setOverrideCursor(Qt::WaitCursor);
            //пока не дошли до конца файла
            while(!file.atEnd())
            {
                //читаем по симольно
                file.readLine(a, sizeof(a));
                string str(a);
                //продолжаем читать когда идем построчно
                if(str.empty())continue;
                //выделяем память под указатель
                Data *temp = new Data;
                //вызов метода перевода
                FuncStrToData(str,temp);
                //если не первый элемент
                if(!first)
                {
                  last = temp;
                  first = temp;
                  temp->priv = 0;
                  temp->next = 0;
                 }
                //если первый жлемент
                 else
                 {
                   last->next = temp;
                   temp->priv = last;
                   temp->next = 0;
                   last = temp;
                 }
                //счетчик увеличиваем с каждой новой записью
                counter++;
            }
            file.close();
            //вызываем заголовочные файлы
            CreateHeaderNames();

            //встаем на первый элемент
          //  Data *f= first;
            Data *f = first;
            int i=0;
            //в цикле вызываем метод помещения в таблицу данных
            for( f = first; f!=0; f=f->next, i++)
            {
                Create_TableWidgetItem(f,i);
            }
            QApplication::restoreOverrideCursor();
            //сделаем неактивными пункты меню открыть и создать новый файл
            IsOpenFile = true;

            ui->tOpen->setEnabled(!IsOpenFile);
            ui->tCreate->setEnabled(!IsOpenFile);
            ui->tSave->setEnabled(IsOpenFile);
            ui->tSaveAs->setEnabled(IsOpenFile);
            ui->tDelete->setEnabled(IsOpenFile);
            ui->tEdit->setEnabled(IsOpenFile);
            ui->tAddNote->setEnabled(IsOpenFile);
            ui->tClearScreen->setEnabled(IsOpenFile);
            ui->tDrawGraphic->setEnabled(IsOpenFile);
}
///Функция записи в пустой файл записей из списка
void MainWindow::tSave()
{
    //открываем
    fstream out(FileName, ios_base::out);
    struct Data *temp;
    //через указатель на класс проходимся по циклу и записываем в поток данные из списка
    for(temp=first; temp!=0; temp=temp->next)
    {
            out<<temp->sp.getname()<<";"
                <<temp->sp.getTotal_rated_power()<<";"
                <<temp->sp.getTotal_max_power()<<";"
                <<temp->sp.getpassive()<<";"
                <<temp->sp.getSize().RF_speakers<<";"
                <<temp->sp.getSize().Midrange_speakers<<";"
                <<temp->sp.getSize().bass_speakers<<";"
                <<temp->sp.getcost()<<";"
                <<temp->sp.getfrequency_range()<<";"
                <<temp->sp.getGuarantee()<<";"
                <<temp->sp.getcountry()<<";"
                <<temp->sp.getFront_Power()<<";"
                <<temp->sp.getFront_Max_Power()<<";"
                << temp->sp.getFront_sensitivity()<<";"
                <<temp->sp.getFront_Impedance()<<";" << endl;
        }
    out.close();
}
///Функция записи в файл только с возможностью его выбора через QDialog
void MainWindow::tSaveAs()
{
    //сохраняем название файла для сохранения в FILENAME
    QString FILENAME = QFileDialog::getSaveFileName(this,
                                QString::fromUtf8("Choose file where to save to"),
                                QDir::currentPath(),
                                "DB Files (*.db *.txt);;All Files (*.*)");
    //если в названии файла пусто, то возращаемся в главное окно
    if(FILENAME=="") return;
    //конвертируем название файла в строку с qstring и перезаписываем его
    FileName = FILENAME.toStdString();
    //вызов метода сохранения файла
    tSave();
}
///Удаление записи из таблицы
void MainWindow::Delete_TableWidgetItem(int i)
{
    ui->tableWidget->removeRow(i); //удаление строки из таблицы
}
///Функция проверки файла на открытие
bool MainWindow::checkfile()
{
    //реализуем открытие выбранного файла
    QString  FILEName = QString::fromStdString(FileName);
    QFile in(FILEName);
    FileName = FILEName.toStdString();

    in.open(QFile::ReadOnly);

    char a [1024];

    Data *NewData = new Data;
//запускаем цикл while для построчного чтения и проверки на ошибки при выполнении функции funcstrtodata
    while(!in.atEnd())
    {
        in.readLine(a, sizeof(a));
        string str(a);
        if(str.empty())continue;
        try
        {
            FuncStrToData(str,NewData);     //ищем ошибку(исключение которое не будет выполненно функцией)
        }
        catch(...)
        {
            in.close();     //будет перекинута сюда и даст false
            return false;
        }
    }
    in.close();
    return true;
}

///Функция выделение места под ячейку таблицы и записи в нее данных из списка
void MainWindow::Create_TableWidgetItem(MainWindow::Data *TW, int i, bool New)
{
    //создание строк для свойств
    if(New)ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    QTableWidgetItem *QTW[kol_param];
    //выделения динамичнски места под каждую переменную из списка
    QTW[1]  = new QTableWidgetItem(QString::fromStdString(TW->sp.getname()));
    QTW[2]  = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getTotal_rated_power())));
    QTW[3]  = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getTotal_max_power())));
    QTW[4]  = new QTableWidgetItem(QString::fromStdString(TW->sp.getpassive()));
    QTW[5]  = new QTableWidgetItem(QString::fromStdString(TW->sp.getSize().Midrange_speakers));
    QTW[6]  = new QTableWidgetItem(QString::fromStdString(TW->sp.getSize().RF_speakers));
    QTW[7]  = new QTableWidgetItem(QString::fromStdString(TW->sp.getSize().bass_speakers));
    QTW[8]  = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getcost())));
    QTW[9]  = new QTableWidgetItem(QString::fromStdString(TW->sp.getfrequency_range()));
    QTW[10] = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getGuarantee())));
    QTW[11] = new QTableWidgetItem(QString::fromStdString(TW->sp.getcountry()));
    QTW[12] = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getFront_Power())));
    QTW[13] = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getFront_Max_Power())));
    QTW[14] = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getFront_sensitivity())));
    QTW[15] = new QTableWidgetItem(QString::fromStdString(to_string(TW->sp.getFront_Impedance())));

    //запись в конкретную ячейку определенных данных
    ui->tableWidget->setItem(i,0 ,QTW[1]);
    ui->tableWidget->setItem(i,1 ,QTW[2]);
    ui->tableWidget->setItem(i,2 ,QTW[3]);
    ui->tableWidget->setItem(i,3 ,QTW[4]);
    ui->tableWidget->setItem(i,4 ,QTW[5]);
    ui->tableWidget->setItem(i,5 ,QTW[6]);
    ui->tableWidget->setItem(i,6 ,QTW[7]);
    ui->tableWidget->setItem(i,7 ,QTW[8]);
    ui->tableWidget->setItem(i,8 ,QTW[9]);
    ui->tableWidget->setItem(i,9 ,QTW[10]);
    ui->tableWidget->setItem(i,10,QTW[11]);
    ui->tableWidget->setItem(i,11,QTW[12]);
    ui->tableWidget->setItem(i,12,QTW[13]);
    ui->tableWidget->setItem(i,13,QTW[14]);
    ui->tableWidget->setItem(i,14,QTW[15]);
}
///Функция создания языкового меню
void MainWindow::createLanguageMenu()
{
    // Создаём список пунктов выбора языка в динамической памяти
    languageActionGroup = new QActionGroup(this);
    // Ставим связь пунктов меню со слотом смены языка приложения
    connect(languageActionGroup, &QActionGroup::triggered,
            this, &MainWindow::switchLanguage);

    // Определяем каталог, где лежат файлы переводов "*.qm"
    QDir dir(qmPath);
    /*Получаем список файлов "*.qm" в каталоге,
     *  которые относятся
     * к нашей программе по шаблону "kurs_*.qm"*/
    QStringList fileNames =
            dir.entryList(QStringList("Kurs_*.qm"));

    /*Формируем в меню столько пунктов,
     * сколько файлов у нас, используя цикл.*/
    for (int i = 0; i < fileNames.size(); i++)
    {
       // Получаем i-ую локаль
        QString locale = fileNames[i];
        // Удаляем символы в строке сначала и по символ "_" включительно
        locale.remove(0, locale.indexOf('_') + 1);
        // Удаляем символы в строке начиная с символа точки
        locale.truncate(locale.lastIndexOf('.'));

        // Создаём временную переменную перевода для языкового пункта меню
        QTranslator translator;
        // Загружаем перевод из файла перевода "*.qm"
        translator.load(fileNames[i], qmPath);
        /*
         * Создаём имя i-ого пункта меню с названием языка путём
         * перевода в linguist заменив English на соответствующий язык
         */
        QString language = translator.translate("MainWindow",
                                                "English");
        /*
         * Создаём пункт в меню с i-ым языком по маске "&%1 %2",
         * где "&" - символ быстрого доступа к пункту меню через сочетание
         * клавиш Alt+символ_перед_которым_стоит_&;
         * "%1" - номер i-ого пункта меню по порядку.
         * "%2" - название языка, которое будет отображаться в меню.
         */
        QAction *action = new QAction(tr("&%1 %2")
                                      .arg(i + 1)
                                      .arg(language),
                                      this);
        /*
         * Задаём свойства для i-ого пункта меню.
         * Возможность держать пункт меню выбранным
         * пока пользователем не будет выбран другой пункт меню.
         */
        action->setCheckable(true);
        // Задаём внутренние данные хранимые в i-ом пункте.
        // В нашем случае это локаль вида "ru_RU"
        action->setData(locale);
        // Добавляем i-ый пункт в меню на нашей форме "mainwindow.ui"
        ui->menuLanguage->addAction(action);
        // Добавляем i-ый пункт в единую группу пунктов
        languageActionGroup->addAction(action);

        // Задаём  русский язык в качестве выбранного по умолчанию
        if (language == "Русский")
            action->setChecked(true);

    }
}

///Функция записи положения окна
void MainWindow::writesettings()
{
    QSettings settings("My Program");
   //созданиие настроек окна для записи
    settings.beginGroup("MainWindowGeometry");
   //запись размера
    settings.setValue("size",size());
    //запись позиции
    settings.setValue("position",pos());
    settings.endGroup();
}

///Функция сброса положения окна
void MainWindow::readsettings()
{
    QSettings settings("My Program");
    settings.beginGroup("MainWindowGeometry");

    resize(settings.value("size", QSize(400, 400)).toSize());    //сбрасываем размер окна
    move(settings.value("position", QPoint(200, 200)).toPoint()); //сбрасываем крайнюю левую точку
    settings.setValue("position",pos()); //устанавливам текущую позицию
    settings.endGroup();
}
///Функция смены языка
void MainWindow::switchLanguage(QAction *action)
{
    /*
     * Определяем локаль которую выбрал пользователь.
     * Например "ru_RU" для русского языка в России или
     * "en_US" для английского в США
     */
    QString locale = action->data().toString();
    // Загружаем тот перевод который выбрал пользователь
    appTranslator.load("Kurs_" + locale, qmPath);
    locale.chop(3);
    /*
     * Для переводов стандартных сообщений Qt можно запросить у системы
     * их местонахождение через вызов "QLibraryInfo::TranslationsPath"
     */
    qtTranslator.load("qt_" + locale + ".qm", QLibraryInfo::location(
                          QLibraryInfo::TranslationsPath));
    /*
     * Взываем "retranslateUi()" для обновления интерфейса приложения
     * используя загруженный из соответствующего файла "qm" язык
     */
    ui->retranslateUi(this);
}
///Функция для перевода строки из списка в число или строку и запись её в список
void MainWindow::FuncStrToData(string &str, MainWindow::Data *New)
{

    int indexNow = 0;
    int indexLast = 0;
    //создаем вектор для строчек
    vector<string> result_strochka;
    //создаем вектор для чисел
    vector<int> result_chislo;
    //сравниваем с действительными int переменными в списке и вектор sravnenie по индексам
    vector<int> sravnenie = {2, 3, 8, 10, 12, 13, 14, 15};
    //записываем длину вектора
    int length = sravnenie.size();
    //через цикл отбирем все строки и где надо переведем в число их
    for(int j=0; j<kol_param; j++)
    {
        int convert = 0;
        string vvod = "";
        indexNow = str.find(';',indexLast);
        for(int i = indexLast; i < indexNow; i++)
         {
              vvod+=str[i];
         }
        result_strochka.push_back(vvod);
        for(int z=0; z<length; z++)
        {
            if( j+1 == sravnenie[z])
             {
                 convert = stoi(vvod);
                 result_chislo.push_back(convert);
                 break;
             }
         }
         indexLast = indexNow + 1;
         indexNow = str.find(';',indexLast);
      }
    //полученные элементы вектора фиксируем в список
    New->sp.setname(result_strochka[0]);
    New->sp.setTotal_rated_power(result_chislo[0]);
    New->sp.setTotal_max_power(result_chislo[1]);
    New->sp.setpassive(result_strochka[3]);
    New->sp.setSize({result_strochka[4],result_strochka[5],result_strochka[6]});
    New->sp.setcost(result_chislo[2]);
    New->sp.setfrequency_range(result_strochka[8]);
    New->sp.setGuarantee(result_chislo[3]);
    New->sp.setcountry(result_strochka[10]);
    New->sp.setFront_Power(result_chislo[4]);
    New->sp.setlFront_Max_Power(result_chislo[5]);
    New->sp.setFront_sensitivity(result_chislo[6]);
    New->sp.setFront_Impedance(result_chislo[7]);
}
///Функция для удаления данных
void MainWindow::tDelete()
{
    bool del;
    //взываем окошко для ввода числа, чтобы пользователь смог выбрать в нем через "spinbox" нужное число для удаления
    int i = QInputDialog::getInt(this,
                                 QString::fromUtf8("Введите для удаления..."),
                                 QString::fromUtf8("Элемент:"),
                                 1, 1, counter, 1, &del) - 1;

    if (!del) return;

    Data *tdel = first;
    //после ввода указателя на удаление проходимся о списку до нужного элемента, который выбрал пользователь
    for(int j=0;j<i;j++) tdel=tdel->next;
   //кооректируем связь на следующего
    if(tdel->next)
    {
        tdel->next->priv= tdel->priv;
    }
    //если он последний
    else
    {
        last = tdel->priv;
    }
     //кооректируем связь на предыдущего
    if(tdel->priv)
    {
        tdel->priv->next=tdel->next;
    }
    //если он первый
    else
    {
        first = tdel->next;
    }
    //удаление указателя через вызов деструктора
    tdel-> ~Data();
    //уменьшение общего числа элементов на 1
    counter--;
    //удаление самой строки в tablewidget
    Delete_TableWidgetItem(i);
}
///Функция поиска элемента в таблице
void MainWindow::on_SearchLine_returnPressed()
{
    //удаление всех строк
    for(int i=ui->tableWidget->rowCount();i>=0;i--)
    {
        Delete_TableWidgetItem(i);
    }
    //ставим указатель на первый элемент
    Data *temp = first;
    int i=0;
    //если строка ввода пустая то просто строим таблицу заново вместе с данными
    if(ui->SearchLine->text().isEmpty())
    {
        for(temp=first; temp!=0; temp=temp->next, i++)
        {
            Create_TableWidgetItem(temp,i);
        }
    }
    /*в противном случае просто прохожимся через цикл до последнего элемента
      и ищем по названию и по суммарной номинальной мощности нужную позицию или позиции
    */
    else
    {
        for(temp=first; temp!=0; temp=temp->next)
        {
          if(temp->sp.getname() == ui->SearchLine->text().toStdString()|| temp->sp.getTotal_rated_power() == ui->SearchLine->text().toInt())
          {
              Create_TableWidgetItem(temp,i);
              i++;
          }
        }
    }
}
///Функция для редактирования данных, записывает в список значения из tablewidget измененные
/// После этого можно сохранить данные, и они окажутся в файле .txt или .dat
void MainWindow::tEdit()
{
    int kolvo_Row = ui->tableWidget->rowCount();
    struct Data *temp =first;
    int i = 0;
    while(i < kolvo_Row)
    {
           temp->sp.setname(ui->tableWidget->item(i,0)->text().toStdString());
           temp->sp.setTotal_rated_power(ui->tableWidget->item(i,1)->text().toInt());
           temp->sp.setTotal_max_power(ui->tableWidget->item(i,2)->text().toInt());
           temp->sp.setpassive(ui->tableWidget->item(i,3)->text().toStdString());
           temp->sp.setSize({ui->tableWidget->item(i,4)->text().toStdString(),
                               ui->tableWidget->item(i,5)->text().toStdString(),
                              ui->tableWidget->item(i,6)->text().toStdString()});
           temp->sp.setcost(ui->tableWidget->item(i,7)->text().toInt());
           temp->sp.setfrequency_range(ui->tableWidget->item(i,8)->text().toStdString());
           temp->sp.setGuarantee(ui->tableWidget->item(i,9)->text().toInt());
           temp->sp.setcountry(ui->tableWidget->item(i,10)->text().toStdString());
           temp->sp.setFront_Power(ui->tableWidget->item(i,11)->text().toInt());
           temp->sp.setlFront_Max_Power(ui->tableWidget->item(i,12)->text().toInt());
           temp->sp.setFront_sensitivity(ui->tableWidget->item(i,13)->text().toInt());
           temp->sp.setFront_Impedance(ui->tableWidget->item(i,14)->text().toInt());
           temp =temp->next;
           i++;
    }

}
///Функция добавления записи
void MainWindow::tAddNote()
{
    Dialog D;
    //запускаем диалоговое окно
    D.exec();
    //обрабатываем возврат в mainwindow
    if(D.result() == Dialog::Rejected)
        return;

    Data *tadd = new Data;
    //добавляем введенные данные в список из диалог. окна
    tadd->sp.setname(D.getname());
    tadd->sp.setTotal_rated_power(D.getTotal_rated_power());
    tadd->sp.setTotal_max_power(D.getTotal_max_power());
    tadd->sp.setpassive(D.getpassive());
    tadd->sp.setcost( D.getcost());
    tadd->sp.setfrequency_range(D.getfrequency_range());
    tadd->sp.setGuarantee(D.getGuarantee());
    tadd->sp.setcountry(D.getcountry());
    tadd->sp.setFront_Power(D.getFront_Power());
    tadd->sp.setlFront_Max_Power(D.getFront_Max_Power());
    tadd->sp.setFront_sensitivity(D.getFront_sensitivity());
    tadd->sp.setFront_Impedance(D.getFront_Impedance());
    tadd->sp.setSize({D.getSize().RF_speakers,D.getSize().Midrange_speakers,D.getSize().bass_speakers});

    if(!first)  //если пустой список
    {
        first = tadd;
        last = tadd;
        tadd->next = 0;
        tadd->priv = 0;

    }
    else //если что-то есть
    {
        last ->next = tadd;
        tadd->priv = last;
        tadd->next = 0;
        last = tadd;
    }
    //увеличиваем число записей на 1
    counter++;
    //вызываем метод построения таблицы вместе с передачей туда число столбцов
    Create_TableWidgetItem(tadd, ui->tableWidget->rowCount());
}
///Функция для очистки окна
void MainWindow::tClearScreen()
{
    IsOpenFile = true;

    Data *tclear;
    //проходимся по списку и через вызов деструктора затираем все данные из списка
    for(tclear=first; tclear!=0; tclear=tclear->next)
    {
        tclear->~Data();
    }
    //зануляем начало, конец списка и число записей
    first = 0;
    last = 0;
    counter = 0;

    for(int i=ui->tableWidget->rowCount();i>=0;i--){ //стираем строки
        Delete_TableWidgetItem(i);
    }

    for(int i=ui->tableWidget->colorCount();i>=0;i--){ //стираем столбцы
        ui->tableWidget->removeColumn(i);
    }
    //разрешаем пользователю открывать и создавать новый файл
    ui->tOpen->setEnabled(IsOpenFile);
    ui->tCreate->setEnabled(IsOpenFile);
    ui->tSave->setEnabled(!IsOpenFile);
    ui->tSaveAs->setEnabled(!IsOpenFile);
    ui->tDelete->setEnabled(!IsOpenFile);
    ui->tEdit->setEnabled(!IsOpenFile);
    ui->tAddNote->setEnabled(!IsOpenFile);
    ui->tClearScreen->setEnabled(!IsOpenFile);
}
///Функция для установки настроек окна
void MainWindow::on_AcceptSettings_triggered()
{
    //создаем объект информационного окна qt и говорим пользователю о примененных настройках
    QMessageBox msgBox;
    msgBox.setWindowTitle("Применения настроек");
    msgBox.setText("Нажмите Ок  и изменения вступят в силу");
    msgBox.setInformativeText("Ок - закрыть информационное окно");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    //устанавливаем проверку, что применился размер окна
    checkchanges =true;

}
///Функция для сброса настроек окна
void MainWindow::on_ResetSettins_triggered()
{
    //проверка на то, что пользователь применил размер окна, если нет просим его через messageBox растянуть окно
    if(checkchanges !=true)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Сначала ручками измените размер окна и примените настройки!");
        msgBox.setInformativeText("Ок - закрыть информационное окно");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    //если все хорошо, то сбрасываем настройки окна
    else{
        readsettings();
    }
}
///Функция отрисовки столбчатой диаграммы
void MainWindow::on_tDrawGraphic()
{
    //Задаем названия каждому столбцу столбчатой диаграммы
    QBarSet *set0 = new QBarSet("YAMAHA_NS-6490");
    QBarSet *set1 = new QBarSet("SONY_SS-CS5");
    QBarSet *set2 = new QBarSet("SONY_SS-CS8");
    QBarSet *set3 = new QBarSet("CANTON_Movie_365");
    QBarSet *set4 = new QBarSet("CANTON_Movie_135");
    QBarSet *set5 = new QBarSet("CANTON_Movie_165");
    QBarSet *set6 = new QBarSet("Sven_HT-201");
    QBarSet *set7 = new QBarSet("Yamaha_NS-P160");
    QBarSet *set8 = new QBarSet("Wharfedale_DX-2_5.1 HCP System");
    QBarSet *set9 = new QBarSet("Ultimate_Classic_5");
    QBarSet *set10 = new QBarSet("Vector_HX_5.0_MK2");
    QBarSet *set11 = new QBarSet("Attitude_Delta_II");
    QBarSet *set12 = new QBarSet("Vector_HX-5.0");
    QBarSet *set13 = new QBarSet("Monitor_Audio_Reference_5.0_System_Black_Oak");
    QBarSet *set14 = new QBarSet("JBL_Arena_5.0_Black");

    Data *temp = new Data;

    temp = first;
    // идем по исписку с первого элемента и берем только стоимость каждой позиции
    *set0 << temp->sp.getcost();
    temp = temp->next;
    *set1 << temp->sp.getcost();
     temp = temp->next;
    *set2 << temp->sp.getcost();
    temp = temp->next;
    *set3 << temp->sp.getcost();
     temp = temp->next;
    *set4 << temp->sp.getcost();
     temp = temp->next;
    *set5 << temp->sp.getcost();
     temp = temp->next;
    *set6 <<  temp->sp.getcost();
     temp = temp->next;
    *set7 << temp->sp.getcost();
      temp = temp->next;
    *set8 << temp->sp.getcost();
       temp = temp->next;
    *set9  << temp->sp.getcost();
       temp = temp->next;
    *set10 << temp->sp.getcost();
       temp = temp->next;
    *set11<< temp->sp.getcost();
       temp = temp->next;
    *set12 <<  temp->sp.getcost();
      temp = temp->next;
    *set13<<  temp->sp.getcost();
      temp = temp->next;
    *set14<< temp->sp.getcost();
    //добавляем к каждому столбцов стоимостное значение
       QBarSeries *series = new QBarSeries();
       series->append(set0);
       series->append(set1);
       series->append(set2);
       series->append(set3);
       series->append(set4);
       series->append(set5);
       series->append(set6);
       series->append(set7);
       series->append(set8);
       series->append(set9);
       series->append(set10);
       series->append(set11);
       series->append(set12);
       series->append(set13);
       series->append(set14);
       //на саму диаграмму добавляем столбцы
       QChart *chart = new QChart();
       chart->addSeries(series);
       //добавляем название диаграммы
       chart->setTitle("Speaker Enclosure");
       //включаем анимацию построения столбцов
       chart->setAnimationOptions(QChart::AllAnimations);

       QStringList categories;
       //пишем название оси X
       categories << "Name of the accoustic system";
       QBarCategoryAxis *axisX = new QBarCategoryAxis();
       axisX->append(categories);
       //добавляем осьX вниз диаграммы
       chart->addAxis(axisX, Qt::AlignBottom);
       //добавляем расположение столбцов по оси x
       series->attachAxis(axisX);

       QValueAxis *axisY = new QValueAxis();
       //задаем границы графика/диаграммы по OY
       axisY->setRange(0,75000);
       //ось Y располагаем слева
       chart->addAxis(axisY, Qt::AlignLeft);
       //добавляем данные по оси OY
       series->attachAxis(axisY);
       //создаем легенду, делаем ее видимой
       chart->legend()->setVisible(true);
       //располагаем легенду внизу
       chart->legend()->setAlignment(Qt::AlignBottom);

       QChartView *chartView = new QChartView(chart);
       //установка сглаживания
       chartView->setRenderHint(QPainter::Antialiasing);
       //создаем указатель на mainwindow для запуска графика в новом окне
       QMainWindow *window = new QMainWindow;
       //передаем диаграмму в окно
       window->setCentralWidget(chartView);
       //меняем размер окна
       window->resize(1200,800);
       //вызываем окно через указатель
       window->show();
}


