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
    MyClass myClass1, myClass2;

    HTaskManager manager;

    manager.addTask(new HTask(  makeCaller(&myClass1,&MyClass::hardComputationFunction,0,100),
                                makeBreaker(&myClass1,&MyClass::cancelComputations),
                                QString::fromUtf8("От 0 до 100")));
    manager.addTask(new HTask(  makeCaller(&myClass2,&MyClass::hardComputationFunction,0,20),
                                QString::fromUtf8("От 0 до 20")));

    MultiTaskLoadingWidget *dlg = new MultiTaskLoadingWidget(QString::fromUtf8("Тестовая установка"),
                                                             QString::fromUtf8("Это окно отображает работу loadingdialog-lib")
                                                             ,this);
    dlg->show();
    dlg->setManager(&manager);
    manager.run();
    dlg->close();
}

void MainWindow::on_pushButtonLoadingDialog_clicked()
{
    MyClass myClass1;
    LoadingDialog dlg(this);
    dlg.setProcessName(QString::fromUtf8("Тест LoadingDialog"));
    runAndWait(&dlg, &myClass1, &MyClass::hardComputationFunction,0,100);
}
