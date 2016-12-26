#include "loadingdialog.h"
#include "ui_loadingdialog.h"

#include <QDebug>
#include <QTime>
#include <QKeyEvent>
#include <QThread>

LoadingDialog::LoadingDialog(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent,f),
    ui(new Ui::LoadingDialog)
{
    init();
}

LoadingDialog::~LoadingDialog()
{
    delete ui;
}

void LoadingDialog::setVisualWidget(LoadingDialog::VisualWidget which)
{
    m_visualWidget = which;
    switch(which)
    {
    case widgetProgressBar:
        ui->progressBar->show();
        ui->spinner->hide();

        setAttribute(Qt::WA_NoSystemBackground, false);
        setAttribute(Qt::WA_TranslucentBackground, false);
        resize(300,100);

        setWindowFlags( Qt::SubWindow | Qt::Dialog | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
        moveToParentCenter();

        break;
    case widgetSpinner:
        ui->progressBar->hide();
        ui->spinner->show();


        setWindowFlags( Qt::SubWindow | Qt::Dialog | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
        resize(300,150);
        moveToParentCenter();

        ui->spinner->setCenterOnlyH(true);
        ui->spinner->setDisableParentWhenSpinning(false);

        break;
    default:
        Q_ASSERT_X(false,"setVisualWidget","no such widget");
        return;
    }
}


void LoadingDialog::init()
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setVisualWidget(widgetSpinner);
    setAttribute(Qt::WA_DeleteOnClose, true);

    initSpinner();
    initProgressBar();
}

void LoadingDialog::initSpinner()
{
    ui->spinner->setRoundness(70.0);
    ui->spinner->setMinimumTrailOpacity(15.0);
    ui->spinner->setTrailFadePercentage(70.0);
    ui->spinner->setNumberOfLines(12);
    ui->spinner->setLineLength(10);
    ui->spinner->setLineWidth(5);
    ui->spinner->setInnerRadius(10);
    ui->spinner->setRevolutionsPerSecond(1);

    ui->spinner->start(); // gets the show on the road!


}

void LoadingDialog::initProgressBar()
{
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}

void LoadingDialog::moveToParentCenter()
{
    if(parentWidget()!= NULL)
    {
        const QPoint global = parentWidget()->mapToGlobal(parentWidget()->rect().center());
        move(global.x() - width() / 2, global.y() - height() / 2);
    }
}


void LoadingDialog::setUnlimittedMode()
{
    ui->spinner->setMode(WaitingSpinnerWidget::UnlimittedMode);
    ui->progressBar->setMaximum(0);
    ui->progressBar->setValue(-1);
}

void LoadingDialog::setDefiniteMode()
{
    ui->spinner->setMode(WaitingSpinnerWidget::DefiniteMode);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}

void LoadingDialog::setPlayMode(LoadingDialog::PlayMode playMode)
{
    switch(playMode){
    case modeUnlimitted:
        setUnlimittedMode();
        break;
    case modeDefinite:
        setDefiniteMode();
        break;
    default:
        return;
    }
}

//bool LoadingDialog::close()
//{
//    if(LoadingDialogSingleton::loadingDialog()==this)
//    {
//        LoadingDialogSingleton::clearFeatures();
//    }
//    return QDialog::close();
//}

void LoadingDialog::resizeEvent(QResizeEvent *e)
{
    QDialog::resizeEvent(e);
    moveToParentCenter();
    ui->spinner->updatePosition();
    update();
}

void LoadingDialog::show()
{
    QDialog::show();
    switch(m_visualWidget)
    {
    case widgetProgressBar:
        ui->spinner->hide();
        break;
    case widgetSpinner:
        ui->progressBar->hide();
        break;
    default:
        Q_ASSERT(false);
        return;
    }
}

void LoadingDialog::setProcess(int proc)
{
    ui->spinner->setProcess(proc);
    ui->progressBar->setValue(proc);
    update();
    QApplication::instance()->processEvents();
}

void LoadingDialog::setProcessName(const QString &str)
{
    setWindowTitle(str);
}

void LoadingDialog::setDescription(const QString &str)
{
    ui->labelProcessName->setText(str);
}
