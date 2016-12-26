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
    MyClass myClass1, myClass2, myClass3;
    HTaskManager manager(
                this,
                QString::fromUtf8("Тестовая установка"),
                QString::fromUtf8("Это окно отображает работу loadingdialog-lib"),
                HTaskManager::sync);

    manager.addTask(new HTask(  makeCaller(&myClass1,&MyClass::hardComputationFunction,0,30),
                                makeBreaker(&myClass1,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 30")));
    manager.addTask(new HTask(  makeCaller(&myClass2,&MyClass::hardComputationFunction,0,40),
                                QString::fromUtf8("От 0 до 40")));
    manager.addTask(new HTask(  makeCaller(&myClass3,&MyClass::hardComputationFunction,0,20),
                                makeBreaker(&myClass3,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 20")));

    manager.run();
}

void MainWindow::on_pushButtonLoadingDialog_clicked()
{
    MyClass myClass1;
    LoadingDialog dlg(this);
    dlg.setProcessName(QString::fromUtf8("Тест LoadingDialog"));
    runAndWait(&dlg, &myClass1, &MyClass::hardComputationFunction,0,50);
}

void MainWindow::on_pushButton_2_clicked()
{
    MyClass myClass1,
            myClass2,
            myClass3,
            myClass4,
            myClass5,
            myClass6,
            myClass7,
            myClass8,
            myClass9;
    HTaskManager manager(
                this,
                QString::fromUtf8("Тестовая установка"),
                QString::fromUtf8("Это окно отображает работу loadingdialog-lib"),
                HTaskManager::async);

    manager.addTask(new HTask(  makeCaller(&myClass1,&MyClass::hardComputationFunction,0,20),
                                makeBreaker(&myClass1,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 20")));
    manager.addTask(new HTask(  makeCaller(&myClass2,&MyClass::hardComputationFunction,0,40),
                                QString::fromUtf8("От 0 до 40")));
    manager.addTask(new HTask(  makeCaller(&myClass3,&MyClass::hardComputationFunction,0,30),
                                makeBreaker(&myClass3,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 30")));
    manager.addTask(new HTask(  makeCaller(&myClass4,&MyClass::hardComputationFunction,0,15),
                                makeBreaker(&myClass4,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 15")));
    manager.addTask(new HTask(  makeCaller(&myClass5,&MyClass::hardComputationFunction,0,25),
                                QString::fromUtf8("От 0 до 25")));
    manager.addTask(new HTask(  makeCaller(&myClass6,&MyClass::hardComputationFunction,0,100),
                                makeBreaker(&myClass6,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 100")));
    manager.addTask(new HTask(  makeCaller(&myClass7,&MyClass::hardComputationFunction,0,45),
                                makeBreaker(&myClass7,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 45")));
    manager.addTask(new HTask(  makeCaller(&myClass8,&MyClass::hardComputationFunction,0,70),
                                QString::fromUtf8("От 0 до 70")));
    manager.addTask(new HTask(  makeCaller(&myClass9,&MyClass::hardComputationFunction,0,65),
                                makeBreaker(&myClass9,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 65")));

    manager.run();
}

void MainWindow::on_pushButton_clicked()
{
    MyClass myClass1;
    HTaskManager manager(
                new HTask(  makeCaller(&myClass1,&MyClass::hardComputationFunction,0,2000),
                                                makeBreaker(&myClass1,&MyClass::cancelComputations),
                                                QString::fromUtf8("От 0 до 2000")),
                this,
                QString::fromUtf8("Тестовая установка"),
                QString::fromUtf8("Это окно отображает работу loadingdialog-lib"),
                HTaskManager::async);

    manager.run();
}
