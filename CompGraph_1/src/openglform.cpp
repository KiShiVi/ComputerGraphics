#include "openglform.h"

//#include <QOpenGLFunctions_1_0>

OpenGLForm::OpenGLForm(QWidget *parent)
    : QOpenGLWidget(parent)
{
    figures.append( new Figures::CoordinateAxes() );
}

void OpenGLForm::clearAll()
{
    figures.clear();
}

void OpenGLForm::clear()
{
    figures.clear();
    figures.append( new Figures::CoordinateAxes() );
}

Figures::Figure2D & OpenGLForm::getByIndex(const int index)
{
    return * figures[index];
}

void OpenGLForm::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
}

void OpenGLForm::resizeGL( int w, int h )
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho( -1, 1, -1, 1, -1, 1 );
}

void OpenGLForm::paintGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    draw();
}

void OpenGLForm::draw()
{
    foreach(Figures::Figure2D * figure, figures){
        figure->draw();
    }
}

void OpenGLForm::onClear()
{
    clear();
    paintGL();
    update();
}

void OpenGLForm::addFigure( Figures::Figure2D * figure )
{
    figures.append( figure );
    paintGL();
    update();
}

void OpenGLForm::changeFigureScale( Figures::Figure2D & figure, float scale )
{
    figure.scaling(scale);
    paintGL();
    update();
}



