#include "mainwindow.h"

//#include <QOpenGLFunctions_1_0>

MainWindow::MainWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
    figures.append( new Figures::Line2D( -1, -1,
                                          1, 1 ) );
    figures.append( new Figures::Line2D( -1, 1,
                                          1, -1 ) );
    figures.append( new Figures::Rectangle2D ( -0.5, -0.2,
                                               -0.1, -0.5 ) );
    figures.append( new Figures::Rectangle2D ( -0.5, -0.2,
                                               -0.1, -0.5 ) );
    figures[3]->scaling(2);

    figures.append( new Figures::Rectangle2D ( -0.5, -0.2,
                                               -0.1, -0.5 ) );

    figures[4]->scaling(0.5);
}

void MainWindow::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
}

void MainWindow::resizeGL( int w, int h )
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho( -1, 1, -1, 1, -1, 1 );
}

void MainWindow::paintGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    draw();
}

void MainWindow::draw()
{
    foreach(Figures::Figure2D * figure, figures){
        figure->draw();
    }
}



