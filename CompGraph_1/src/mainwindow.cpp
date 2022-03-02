#include "mainwindow.h"

//#include <QOpenGLFunctions_1_0>

MainWindow::MainWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
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
    glOrtho( 0, 100, 100, 0, -1, 1 );
}

void MainWindow::paintGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    draw();
}

void MainWindow::draw()
{
    glBegin(GL_LINES);
        glColor3f( 0, 0, 0 ); glVertex2f( 0, 50 );
        glColor3f( 0, 0, 0 ); glVertex2f( 100, 50 );

        glColor3f( 0, 0, 0 ); glVertex2f( 50, 0 );
        glColor3f( 0, 0, 0 ); glVertex2f( 50, 100 );
    glEnd();
}



