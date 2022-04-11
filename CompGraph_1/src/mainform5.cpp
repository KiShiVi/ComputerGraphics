#include "mainform5.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

MainForm5::MainForm5( QWidget * parent )
    : QWidget{ parent }
{
    initGui();

    openGlWidget->addFigure( new Figures::Cube3D( QPair<QList<float>, QList<float>>{ QList<float>{ -0.3, -0.3, -0.3 },
                                                                                     QList<float>{ 0.3, 0.3, 0.3 } } ) );
}

void MainForm5::initGui()
{
    setFixedSize( 1000, 520 );
    openGlWidget = new OpenGLForm3D();
    openGlWidget->setFixedSize(500, 500);

    connect( this, SIGNAL( XAngleChanched( float, Figures::Figure3D * ) ),
             openGlWidget, SLOT( rotateViaOX( float, Figures::Figure3D * ) ) );
    connect( this, SIGNAL( YAngleChanched( float, Figures::Figure3D * ) ),
             openGlWidget, SLOT( rotateViaOY( float, Figures::Figure3D * ) ) );
    connect( this, SIGNAL( ZAngleChanched( float, Figures::Figure3D * ) ),
             openGlWidget, SLOT( rotateViaOZ( float, Figures::Figure3D * ) ) );
    connect( this, SIGNAL( lightChanged( int ) ),
             openGlWidget, SLOT( onLightChanged( int ) ) );

    QHBoxLayout * mainLayout    = new QHBoxLayout();
    QGroupBox   * slidersGB     = new QGroupBox();
    slidersGB->setTitle( "Инструменты" );

    QVBoxLayout * slidersLayout = new QVBoxLayout();

    for ( int i = 0; i < 3; ++i )
    {
        listOfAngles.append( new QSlider( Qt::Orientation::Horizontal ) );
        slidersLayout->addWidget( listOfAngles[i] );
        listOfAngles[i]->setRange( -179, 180 );
        listOfAngles[i]->setValue( 0 );
    }

    QSlider * lightSlider = new QSlider( Qt::Orientation::Horizontal );
    slidersLayout->addWidget( lightSlider );
    lightSlider->setRange( 0, 100 );
    lightSlider->setValue( 100 );

    connect( listOfAngles[0], SIGNAL( valueChanged( int ) ), this, SLOT( onXAngleChanched() ) );
    connect( listOfAngles[1], SIGNAL( valueChanged( int ) ), this, SLOT( onYAngleChanched() ) );
    connect( listOfAngles[2], SIGNAL( valueChanged( int ) ), this, SLOT( onZAngleChanched() ) );
    connect( lightSlider, SIGNAL( valueChanged( int ) ), this, SLOT( onLightChanged( int ) ) );

    slidersGB->setLayout( slidersLayout );

    mainLayout->addWidget( openGlWidget );
    mainLayout->addWidget( slidersGB );

    setLayout( mainLayout );
}

void MainForm5::onXAngleChanched()
{
    static int prevValue = 0;
    if ( listOfAngles[0]->value() > prevValue )
        emit XAngleChanched( 0.1, nullptr );
    else if ( listOfAngles[0]->value() < prevValue )
        emit XAngleChanched( -0.1, nullptr );
    prevValue = listOfAngles[0]->value();
}

void MainForm5::onYAngleChanched()
{
    static int prevValue = 0;
    if ( listOfAngles[1]->value() > prevValue )
        emit YAngleChanched( 0.1, nullptr );
    else if ( listOfAngles[1]->value() < prevValue )
        emit YAngleChanched( -0.1, nullptr );
    prevValue = listOfAngles[1]->value();
}

void MainForm5::onZAngleChanched()
{
    static int prevValue = 0;
    if ( listOfAngles[2]->value() > prevValue )
        emit ZAngleChanched( 0.1, nullptr );
    else if ( listOfAngles[2]->value() < prevValue )
        emit ZAngleChanched( -0.1, nullptr );
    prevValue = listOfAngles[2]->value();
}

void MainForm5::onLightChanged( int value )
{
    emit lightChanged( value );
}
