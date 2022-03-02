#include "mainwindow.h"
#include "matrix.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
//    Matrix m(5, 5);
//    qDebug() << m.getDimension();
//    qDebug() << "\n" << m;
//    m.valueOf( 2, 3 ) = 1.0f;
//    qDebug() << "\n" << m;

//    Matrix m2(2, 2);
//    m2.valueOf( 0, 0 ) = 1.0f;

//    Matrix m3(2, 2);
//    m2.valueOf( 1, 1 ) = 1.0f;

//    m = m2 + m3;

//    qDebug() << "\n\n" << m;

    MathLogic::Matrix a( QVector<QVector<float> > { { 1, 2 },
                                               { 3, 4 } } );

    MathLogic::Matrix b( QVector<QVector<float> > { { 4, 3 },
                                               { 2, 1 } } );
    qDebug() << (a * b - a) * 2;

    return app.exec();
}
