#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H

#include "loadingdialog_global.h"

#include <QDialog>
#include <QThread>
#include <QStack>
#include <QDebug>


namespace Ui {
class LoadingDialog;
}

class LOADINGDIALOGSHARED_EXPORT LoadingDialog : public QDialog
{
    Q_OBJECT
public:
    enum VisualWidget
    {
        widgetSpinner,
        widgetProgressBar
    };

    enum PlayMode{
        modeUnlimitted,
        modeDefinite
    };

    explicit LoadingDialog(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~LoadingDialog();

    void setVisualWidget(LoadingDialog::VisualWidget which); ///< Выбор режима отображения: Полоса загрузки, или Спиннер
    void setUnlimittedMode();
    void setDefiniteMode();
    void setPlayMode(LoadingDialog::PlayMode playMode);



protected:
    void resizeEvent(QResizeEvent *);

public slots:
    void show();

    void setProcess(int proc); ///< От 0 до 100
    void setProcessName(const QString &str); ///< Имя процесса
    void setDescription(const QString &str); ///< Описание

private:
    void init();
    void initSpinner();
    void initProgressBar();
    void moveToParentCenter();

private:
    Ui::LoadingDialog *ui;

    VisualWidget m_visualWidget;
};

#endif // LOADINGDIALOG_H
