#ifndef MULTITASKLOADINGWIDGET_H
#define MULTITASKLOADINGWIDGET_H

#include "loadingdialog_global.h"
#include "htaskmanager.h"
#include "htask.h"
#include "loadingdialogitem.h"

#include <QPointer>
#include <QHash>
#include <QWidget>

namespace Ui {
class MultiTaskLoadingWidget;
}

class LOADINGDIALOGSHARED_EXPORT MultiTaskLoadingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MultiTaskLoadingWidget(HTaskManager *manager, const QString &title,const QString &description,
                                    QWidget *parent = 0, Qt::WindowFlags fl = 0);
    explicit MultiTaskLoadingWidget(HTaskManager *manager, const QString &title,
                                    QWidget *parent = 0, Qt::WindowFlags fl = 0);
    explicit MultiTaskLoadingWidget(HTaskManager *manager, QWidget *parent = 0, Qt::WindowFlags fl = 0);
    virtual ~MultiTaskLoadingWidget();

    void setDescription(const QString &text);

protected:
    void resizeEvent(QResizeEvent *event);
signals:

private slots:
    void onStarted();
    void onFinished();
    void addTask(HTask *task);
    void removeTask(HTask *task);
    void onTaskStarted(HTask *task);
    void onTaskFinished(HTask *task);

    void on_pushButtonCancel_clicked();

private:
    QPointer<HTaskManager> manager() const;
    void setManager(HTaskManager *manager);
    void moveToParentCenter();
    void init();
    void setupUi();

    void removeManagerDepends();
    void initManager();
private:
    Ui::MultiTaskLoadingWidget *ui;
    QPointer<HTaskManager> _manager;
    QHash<HTask *, LoadingDialogItem *> _qhashTasks;
};

#endif // MULTITASKLOADINGWIDGET_H
