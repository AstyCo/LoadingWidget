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

    void setProcessName(const QString &processName);

public slots:
    void onStarted();
    void onCompleted();

    void setPercent(int percent);

private slots:
    void updateText();
    void onTimer();
private:
    void showStarted();
    void showCompleted();
    void init();
    void startTimer();
    void killTimer();
    QString currentDots() const;
    QString labelStylesheet(bool enable) const;

    QString _processName;
    short _percent;
    short _dots;
    QTimer *_timer;
    bool _evaluate;

private:
    Ui::LoadingDialogItem *ui;
};

#endif // LOADINGDIALOGITEM_H
