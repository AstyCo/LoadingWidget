#ifndef MULTITASKLOADINGWIDGET_H
#define MULTITASKLOADINGWIDGET_H

#include "htaskmanager.h"
#include "htask.h"

#include <QWidget>

namespace Ui {
class MultiTaskLoadingWidget;
}

class MultiTaskLoadingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MultiTaskLoadingWidget(QWidget *parent = 0, Qt::WindowFlags fl = 0);
    virtual ~MultiTaskLoadingWidget();

    HTaskManager *manager() const;
    void setManager(HTaskManager *manager);

private:
    void init();
    void setupUi();
protected:
    void resizeEvent(QResizeEvent *event);
signals:

private slots:
    void onTaskAdded(HTask *task);
    void onTaskRemoved(HTask *task);
private:
    Ui::MultiTaskLoadingWidget *ui;

    HTaskManager *_manager;
};

#endif // MULTITASKLOADINGWIDGET_H
