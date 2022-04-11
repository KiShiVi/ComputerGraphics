#include "openglform3d.h"

OpenGLForm3D::OpenGLForm3D( QWidget * parent )
    : QOpenGLWidget(parent)
{
    //!@todo Добавление координатных осей
    //figures.append( new Figures::CoordinateAxes() );
    lightPoint = new Figures::Point3D(-0.4, 0.4, 0.4);
}

void OpenGLForm3D::clearAll()
{
    figures.clear();
}

void OpenGLForm3D::clear()
{
    figures.clear();
    //!@todo Добавление координатных осей
    //figures.append( new Figures::CoordinateAxes() );
}

void OpenGLForm3D::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
}

void OpenGLForm3D::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho( -1, 1, -1, 1, -1, 1 );
}

void OpenGLForm3D::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    draw();
}

void OpenGLForm3D::draw()
{
    foreach(Figures::Figure3D * figure, figures){
        figure->draw();
    }
    lightPoint->draw();
}

void OpenGLForm3D::onClear()
{
    clear();
    paintGL();
    update();
}

void OpenGLForm3D::addFigure( Figures::Figure3D * figure )
{
    figures.append( figure );
    paintGL();
    update();
}

void OpenGLForm3D::setCoords( QList<QList<float> > coords, Figures::Figure3D * figure )
{
    Figures::Figure3D * localFigure;
    if ( figures.isEmpty() )
        return;
    if ( figure == nullptr )
        localFigure = figures[0];
    else
        localFigure = figure;

    if ( localFigure->m_matrix->getDimension().first != coords.size()
         || localFigure->m_matrix->getDimension().second != coords[0].size() )
        throw std::invalid_argument( "illegal setCoords in OpenGLForm3D" );
    *(localFigure->m_matrix) = MathLogic::Matrix( coords ) / 100;
    paintGL();
    update();
}

void OpenGLForm3D::rotateViaOX( float angle, Figures::Figure3D * figure )
{
    Figures::Figure3D * localFigure;
    if ( figures.isEmpty() )
        return;
    if ( figure == nullptr )
        localFigure = figures[0];
    else
        localFigure = figure;
    localFigure->rotateViaX( angle );
    paintGL();
    update();
}

void OpenGLForm3D::rotateViaOY( float angle, Figures::Figure3D * figure )
{
    Figures::Figure3D * localFigure;
    if ( figures.isEmpty() )
        return;
    if ( figure == nullptr )
        localFigure = figures[0];
    else
        localFigure = figure;
    localFigure->rotateViaY( angle );
    paintGL();
    update();
}

void OpenGLForm3D::rotateViaOZ( float angle, Figures::Figure3D * figure )
{
    Figures::Figure3D * localFigure;
    if ( figures.isEmpty() )
        return;
    if ( figure == nullptr )
        localFigure = figures[0];
    else
        localFigure = figure;
    localFigure->rotateViaZ( angle );
    paintGL();
    update();
}

void OpenGLForm3D::onLightChanged(int value)
{
    figures[0]->lightingIntensity = (float)value / 100;
    paintGL();
    update();
}
