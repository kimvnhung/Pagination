#include <qapplication.h>

#include "mainwindow.h"
#include "paginationtest.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // PaginationTest w;
    // w.show();

    return a.exec();
}
