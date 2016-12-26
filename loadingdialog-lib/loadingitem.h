#ifndef LOADINGITEM_H
#define LOADINGITEM_H

#include "loadingdialog_global.h"

#include <QWidget>

namespace Ui {
class LoadingItem;
}

class LOADINGDIALOGSHARED_EXPORT LoadingItem : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingItem(QWidget *parent = 0);
    ~LoadingItem();

    void setProcessName(const QString &processName);


public slots:
    void showSkip();
    void hideSkip();
    void onStarted();
    void onCompleted();

    void setPercent(int percent);

signals:
    void skip();

private slots:
    void updateText();
    void onTimer();
    void on_pushButtonSkip_clicked();

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
    Ui::LoadingItem *ui;
};

#endif // LOADINGITEM_H
