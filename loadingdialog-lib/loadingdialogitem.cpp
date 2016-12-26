#include "loadingdialogitem.h"
#include "ui_loadingdialogitem.h"

#include <QTimer>

LoadingDialogItem::LoadingDialogItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingDialogItem)
{
    init();
}

LoadingDialogItem::~LoadingDialogItem()
{
    delete ui;
}

void LoadingDialogItem::setProcessName(const QString &processName)
{
    _processName=processName;
    updateText();
}

void LoadingDialogItem::showSkip()
{
    ui->pushButtonSkip->show();
}

void LoadingDialogItem::hideSkip()
{
    ui->pushButtonSkip->hide();
}


void LoadingDialogItem::onStarted()
{
    _evaluate = true;
    startTimer();
    showStarted();
}

void LoadingDialogItem::onCompleted()
{
    _evaluate = false;
    killTimer();
    showCompleted();
}

void LoadingDialogItem::setPercent(int percent)
{
    if(percent<0 || percent>100)
        qWarning(qPrintable(
                     QString("LoadingDialogItem::setPercent:: in range [0..100], but given %1")
                     .arg(QString::number(percent))));
    _percent=percent;
    updateText();
}

void LoadingDialogItem::showStarted()
{
    ui->labelText->setStyleSheet(labelStylesheet(true));
    updateText();
}

void LoadingDialogItem::showCompleted()
{
    ui->labelText->setStyleSheet(labelStylesheet(false));
    ui->stackedWidget->setCurrentWidget(ui->pageCheck);
    _dots = 0;
    updateText();
}

void LoadingDialogItem::init()
{
    ui->setupUi(this);

    _timer = NULL;
    _dots = 0;
    _percent = -1;
    _processName = QString::fromUtf8("Безымянный");
    _evaluate = false;
    ui->labelText->setStyleSheet(labelStylesheet(false));

    updateText();
    ui->stackedWidget->setCurrentWidget(ui->pageEmpty);
//    const int height = 24;
//    setMaximumHeight(height);
//    setMinimumHeight(height);
}

void LoadingDialogItem::startTimer()
{
    if(_timer)
        killTimer();

    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    _timer->start(400);
}

void LoadingDialogItem::killTimer()
{
    if(_timer == NULL)
        return;

    _timer->disconnect(this);
    _timer->deleteLater();
    _timer = NULL;
}

void LoadingDialogItem::updateText()
{
    QString text = _processName;
    if(_evaluate){
        if(_percent >= 0)
            text.append(QString(" (%1\%)").arg(QString::number(_percent)));
        text.append(" " + currentDots());
    }
    ui->labelText->setText(text);
//    ui->labelText->setText(_processName + ( _evaluate ?
//                                                (QString(" (%1\%) %2").arg(QString::number(_percent)).arg(currentDots()))
//                                                :QString()));
}

void LoadingDialogItem::onTimer()
{
    _dots++;
    updateText();
}

QString LoadingDialogItem::currentDots() const
{
    QString res;
    for(int i = 0; i < _dots%3 + 1; ++i){
        res.append('.');
    }
    return res;
}

QString LoadingDialogItem::labelStylesheet(bool enable) const
{
    if(enable)
        return "font-weight: bold; color: black";
    else
        return "font-weight: normal; color: gray";
}

void LoadingDialogItem::on_pushButtonSkip_clicked()
{
    ui->pushButtonSkip->setText(QString::fromUtf8("Не выполнять"));
    ui->pushButtonSkip->setEnabled(false);
    emit skip();
}
