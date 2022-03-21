#include "mainform.h"
#include "mainform2.h"
#include "matrix.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //MainForm w1;
    MainForm2 w2;
    //w1.show();
    w2.show();

    return app.exec();
}
