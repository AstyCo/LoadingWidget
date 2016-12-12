#ifndef LOADINGDIALOGITEM_H
#define LOADINGDIALOGITEM_H

#include <QWidget>

namespace Ui {
class LoadingDialogItem;
}

class LoadingDialogItem : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingDialogItem(QWidget *parent = 0);
    ~LoadingDialogItem();

private:
    Ui::LoadingDialogItem *ui;
};

#endif // LOADINGDIALOGITEM_H
