#include "openglform2d.h"

//#include <QOpenGLFunctions_1_0>

OpenGLForm2D::OpenGLForm2D(QWidget *parent)
    : QOpenGLWidget(parent)
{
    figures.append( new Figures::CoordinateAxes() );
}

void OpenGLForm2D::clearAll()
{
    figures.clear();
}

void OpenGLForm2D::clear()
{
    figures.clear();
    figures.append( new Figures::CoordinateAxes() );
}

Figures::Figure2D & OpenGLForm2D::getByIndex(const int index)
{
    return * figures[index];
}

int OpenGLForm2D::size()
{
    return figures.size();
}

void OpenGLForm2D::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
}

void OpenGLForm2D::resizeGL( int w, int h )
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho( -1, 1, -1, 1, -1, 1 );
}

void OpenGLForm2D::paintGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    draw();
}

void OpenGLForm2D::draw()
{
    foreach(Figures::Figure2D * figure, figures){
        figure->draw();
    }
}

void OpenGLForm2D::onClear()
{
    clear();
    paintGL();
    update();
}

void OpenGLForm2D::addFigure( Figures::Figure2D * figure )
{
    figures.append( figure );
    paintGL();
    update();
}

void OpenGLForm2D::changeFigureScale( Figures::Figure2D & figure, float scale )
{
    figure.scaling(scale);
    paintGL();
    update();
}



