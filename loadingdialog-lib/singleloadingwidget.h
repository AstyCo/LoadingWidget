#ifndef SINGLELOADINGWIDGET_H
#define SINGLELOADINGWIDGET_H

#include "htask.h"
#include "htaskmanager.h"
#include "loadingdialog.h"

#include <QWidget>
#include <QPointer>

class SingleLoadingWidget : public LoadingDialog
{
    Q_OBJECT
public:
    SingleLoadingWidget(
            HTask *task,
            HTaskManager *manager,
            const QString &title = QString::fromUtf8("Подождите, пожалуйста..."),
            const QString &description = QString(),
            LoadingDialog::PlayMode playMode=LoadingDialog::modeUnlimitted,
            QWidget *parent = 0);
    ~SingleLoadingWidget(){}

signals:
    void cancel();
public slots:
    void setTask(HTask *task);
private slots:
    void onTaskStarted();
    void onTaskFinished();

private:
    void init();
    void setManager(const QPointer<HTaskManager> &manager);
private:
    QPointer<HTask> _task;
    QPointer<HTaskManager> _manager;
};



#endif // SINGLELOADINGWIDGET_H
