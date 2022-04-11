#include "mainform.h"
#include "mainform2.h"
#include "mainform3.h"
#include "mainform4.h"
#include "mainform5.h"

#include "openglform3d.h"
#include <QWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    MainForm w1;
//    MainForm2 w2;
//    w1.show();
//    w2.show();

//    MainForm3 w3;
//    w3.show();

//    MainForm4 w4;
//    w4.show();

    MainForm5 w5;
    w5.show();

    return app.exec();
}
