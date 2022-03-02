#include "mainwindow.h"
#include "matrix.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    MathLogic::Matrix a( QVector<QVector<float> > { { 1, 2 },
                                               { 3, 4 } } );

    MathLogic::Matrix b( QVector<QVector<float> > { { 4, 3 },
                                               { 2, 1 } } );
    qDebug() << (a * b - a) * 2;

    return app.exec();
}
