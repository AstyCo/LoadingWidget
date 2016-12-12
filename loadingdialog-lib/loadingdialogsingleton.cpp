#include "loadingdialogsingleton.h"
#include "loadingdialog.h"

void LoadingDialogSingleton::setActiveWindow(QPointer<QWidget> newActiveWindow){
    instance().m_activeWindow=newActiveWindow;
}

QWidget *LoadingDialogSingleton::activeWindow(){
    return instance().m_activeWindow.data();
}

LoadingDialog *LoadingDialogSingleton::loadingDialog(){
    return instance().m_loadingDialog.data();
}

void LoadingDialogSingleton::setLoadingDialog(const QPointer<LoadingDialog> &loadingDialog){
    instance().m_loadingDialog = loadingDialog;

    setFeatures();
}

void LoadingDialogSingleton::setVisualWidget(LoadingDialog::VisualWidget which)
{
    instance().m_vw = which;
    if(!instance().m_loadingDialog.isNull())
        instance().m_loadingDialog->setVisualWidget(instance().m_vw);
}

void LoadingDialogSingleton::setUnlimittedMode()
{
    instance().m_pm = LoadingDialog::modeUnlimitted;
    if(!instance().m_loadingDialog.isNull())
        instance().m_loadingDialog->setUnlimittedMode();
}

void LoadingDialogSingleton::setDefiniteMode()
{
    instance().m_pm = LoadingDialog::modeDefinite;
    if(!instance().m_loadingDialog.isNull())
        instance().m_loadingDialog->setDefiniteMode();
}

void LoadingDialogSingleton::setProcess(int proc)
{
    if(!instance().m_loadingDialog.isNull())
        instance().m_loadingDialog->setProcess(proc);
}

void LoadingDialogSingleton::setProcessName(const QString &str)
{
    instance().m_processName=str;
    if(!instance().m_loadingDialog.isNull())
        instance().m_loadingDialog->setProcessName(instance().m_processName);
}

void LoadingDialogSingleton::setFeatures()
{
    if(!instance().m_loadingDialog.isNull())
    {
        if(instance().m_pm==LoadingDialog::modeUnlimitted)
            instance().m_loadingDialog->setUnlimittedMode();
        else
            instance().m_loadingDialog->setDefiniteMode();

        if(!instance().m_processName.isEmpty())
            instance().m_loadingDialog->setProcessName(instance().m_processName);

        instance().m_loadingDialog->setVisualWidget(instance().m_vw);
    }
}

void LoadingDialogSingleton::clearFeatures()
{
    instance().m_vw = LoadingDialog::widgetSpinner;
    instance().m_pm = LoadingDialog::modeUnlimitted;
    instance().m_processName = QString();
}
