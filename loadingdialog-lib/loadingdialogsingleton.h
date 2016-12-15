/*
 * Obsolete
 *
 */

#ifndef LOADINGDIALOGSINGLETON_H
#define LOADINGDIALOGSINGLETON_H

#include "loadingdialog_global.h"
#include "loadingdialog.h"

#include <QPointer>
#include <QWidget>


class LOADINGDIALOGSHARED_EXPORT LoadingDialogSingleton
{
public:
    static LoadingDialogSingleton& instance(){
        static LoadingDialogSingleton s;
        return s;
    }

    static void setActiveWindow(QPointer<QWidget> newActiveWindow);

    static QWidget *activeWindow();

    static LoadingDialog* loadingDialog();
    static void setLoadingDialog(const QPointer<LoadingDialog> &loadingDialog);

    static void setVisualWidget(LoadingDialog::VisualWidget which); ///< Выбор режима отображения: Полоса загрузки, или Спиннер
    static void setUnlimittedMode();
    static void setDefiniteMode();
    static void setProcess(int proc); ///< От 0 до 100
    static void setProcessName(const QString &str); ///< Имя процесса


private:
    static void setFeatures();
    static void clearFeatures();

private:
    QPointer<QWidget> m_activeWindow;
    QPointer<LoadingDialog> m_loadingDialog;

    LoadingDialog::PlayMode m_pm;
    LoadingDialog::VisualWidget m_vw;
    QString m_processName;



private:
    LoadingDialogSingleton() {}
    ~LoadingDialogSingleton() {}

    LoadingDialogSingleton(LoadingDialogSingleton const&);
    LoadingDialogSingleton& operator= (LoadingDialogSingleton const&);
    friend class LoadingDialog;
};

#endif // LOADINGDIALOGSINGLETON_H
