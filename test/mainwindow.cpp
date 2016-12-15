#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myclass.h"
#include "htaskextension.h"
#include "multitaskloadingwidget.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralWidget->layout()->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonMultipleLoadingWidget_clicked()
{
    static MyClass myClass1, myClass2;

    static HTaskManager manager(HTaskManager::sync);

    manager.addTask(new HTask(  makeCaller(&myClass1,&MyClass::hardComputationFunction,0,10),
                                makeBreaker(&myClass1,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 10")));
    manager.addTask(new HTask(  makeCaller(&myClass2,&MyClass::hardComputationFunction,0,20),
                                QString::fromUtf8("От 0 до 20")));
    manager.addTask(new HTask(  makeCaller(&myClass1,&MyClass::hardComputationFunction,0,10),
                                makeBreaker(&myClass1,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 10")));

    MultiTaskLoadingWidget *dlg = new MultiTaskLoadingWidget(&manager,
                                                             QString::fromUtf8("Тестовая установка"),
                                                             QString::fromUtf8("Это окно отображает работу loadingdialog-lib")
                                                             ,this);
    dlg->show();
    manager.run();
//    dlg->close(); // not needed
}

void MainWindow::on_pushButtonLoadingDialog_clicked()
{
    MyClass myClass1;
    LoadingDialog dlg(this);
    dlg.setProcessName(QString::fromUtf8("Тест LoadingDialog"));
    runAndWait(&dlg, &myClass1, &MyClass::hardComputationFunction,0,100);
}
