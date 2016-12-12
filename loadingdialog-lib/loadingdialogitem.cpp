#include "loadingdialogitem.h"
#include "ui_loadingdialogitem.h"

LoadingDialogItem::LoadingDialogItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingDialogItem)
{
    ui->setupUi(this);
}

LoadingDialogItem::~LoadingDialogItem()
{
    delete ui;
}
