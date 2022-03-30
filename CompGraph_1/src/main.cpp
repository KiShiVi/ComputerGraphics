#include "mainform.h"
#include "mainform2.h"
#include "mainform3.h"
#include "matrix.h"

#include "openglform3d.h"
#include <QWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //MainForm w1;
    //MainForm2 w2;
    //w1.show();
    //w2.show();

    //QWidget wgt;
    //OpenGLForm3D * glForm = new OpenGLForm3D( & wgt );
    //glForm->setFixedSize(500, 500);
    //wgt.show();

    MainForm3 w3;
    w3.show();

    return app.exec();
}
