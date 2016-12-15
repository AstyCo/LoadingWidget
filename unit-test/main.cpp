#include "myclass.h"
#include "htaskextension.h"
#include "multitaskloadingwidget.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClass w;

    HTaskManager manager;

    manager.addTask(new HTask(makeCaller(&w,&MyClass::hardComputationFunction,0,10000)));

    MultiTaskLoadingWidget *dlg = new MultiTaskLoadingWidget();
    dlg->show();
    dlg->setManager(&manager);
    manager.run();
    dlg->close();

    return a.exec();
}
