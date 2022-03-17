#include "mainform.h"
#include "mainform2.h"
#include "matrix.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //MainForm w;
    MainForm2 w;
    w.show();

    return app.exec();
}
