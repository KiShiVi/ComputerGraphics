#include "mainform3.h"

MainForm3::MainForm3( QWidget * parent )
    : QWidget{ parent }
{
    initGui();
}

void MainForm3::initGui()
{
    setFixedSize( 1000, 520 );

    openGlWidget = new OpenGLForm3D();
    openGlWidget->setFixedSize(500, 500);

    openGlWidget->addFigure( new Figures::BilinearPlane3D() );

    connect( this, SIGNAL( coordsChanched( QList<QList<float>>, Figures::Figure3D * ) ),
             openGlWidget, SLOT( setCoords( QList<QList<float>>, Figures::Figure3D * ) ) );
    connect( this, SIGNAL( XAngleChanched( float, Figures::Figure3D * ) ),
             openGlWidget, SLOT( rotateViaOX( float, Figures::Figure3D * ) ) );
    connect( this, SIGNAL( YAngleChanched( float, Figures::Figure3D * ) ),
             openGlWidget, SLOT( rotateViaOY( float, Figures::Figure3D * ) ) );
    connect( this, SIGNAL( ZAngleChanched( float, Figures::Figure3D * ) ),
             openGlWidget, SLOT( rotateViaOZ( float, Figures::Figure3D * ) ) );

    QHBoxLayout * mainLayout    = new QHBoxLayout();

    QGroupBox   * coordsGB        = new QGroupBox();
    QGroupBox   * slidersGB       = new QGroupBox();

    coordsGB->setTitle( "Координаты" );
    slidersGB->setTitle( "Поворот" );

    QVBoxLayout * coordsLayout    = new QVBoxLayout();
    QVBoxLayout * slidersLayout   = new QVBoxLayout();

    for ( int i = 0; i < 4; ++i )
    {
        QHBoxLayout * localCoordsLayout = new QHBoxLayout();
        listOfCoords.append( QList<QSpinBox *>
                             {
                                 new QSpinBox(),
                                 new QSpinBox(),
                                 new QSpinBox()
                             } );
        for ( int j = 0; j < 3; ++j )
        {
            listOfCoords[i][j]->setRange( -100, 100 );
            listOfCoords[i][j]->setValue( 0 );
            localCoordsLayout->addWidget( listOfCoords[i][j] );
            connect( listOfCoords[i][j], SIGNAL( valueChanged( int ) ), this, SLOT( onCoordsChanched() ) );
        }
        coordsLayout->addLayout( localCoordsLayout );
    }

    for ( int i = 0; i < 3; ++i )
    {
        listOfAngles.append( new QSlider( Qt::Orientation::Horizontal ) );
        slidersLayout->addWidget( listOfAngles[i] );
        listOfAngles[i]->setRange( -179, 180 );
        listOfAngles[i]->setValue( 0 );
    }

    connect( listOfAngles[0], SIGNAL( valueChanged( int ) ), this, SLOT( onXAngleChanched() ) );
    connect( listOfAngles[1], SIGNAL( valueChanged( int ) ), this, SLOT( onYAngleChanched() ) );
    connect( listOfAngles[2], SIGNAL( valueChanged( int ) ), this, SLOT( onZAngleChanched() ) );

    coordsGB->setLayout( coordsLayout );
    slidersGB->setLayout( slidersLayout );

    QVBoxLayout * toolsLayout    = new QVBoxLayout();
    toolsLayout->addWidget( coordsGB );
    toolsLayout->addWidget( slidersGB );

    mainLayout->addWidget( openGlWidget );
    mainLayout->addLayout( toolsLayout );

    setLayout( mainLayout );
}

void MainForm3::onCoordsChanched()
{
    emit coordsChanched( QList<QList<float>> {
                          { ( float )( listOfCoords[0][0]->value() ),
                            ( float )( listOfCoords[0][1]->value() ),
                            ( float )( listOfCoords[0][2]->value() ) },
                          { ( float )( listOfCoords[1][0]->value() ),
                            ( float )( listOfCoords[1][1]->value() ),
                            ( float )( listOfCoords[1][2]->value() ) },
                          { ( float )( listOfCoords[2][0]->value() ),
                            ( float )( listOfCoords[2][1]->value() ),
                            ( float )( listOfCoords[2][2]->value() ) },
                          { ( float )( listOfCoords[3][0]->value() ),
                            ( float )( listOfCoords[3][1]->value() ),
                            ( float )( listOfCoords[3][2]->value() ) }
                                               }, nullptr );
}

void MainForm3::onXAngleChanched()
{
    static int prevValue = 0;
    if ( listOfAngles[0]->value() > prevValue )
        emit XAngleChanched( 0.1, nullptr );
    else if ( listOfAngles[0]->value() < prevValue )
        emit XAngleChanched( -0.1, nullptr );
    prevValue = listOfAngles[0]->value();
}

void MainForm3::onYAngleChanched()
{
    static int prevValue = 0;
    if ( listOfAngles[1]->value() > prevValue )
        emit YAngleChanched( 0.1, nullptr );
    else if ( listOfAngles[1]->value() < prevValue )
        emit YAngleChanched( -0.1, nullptr );
    prevValue = listOfAngles[1]->value();
}

void MainForm3::onZAngleChanched()
{
    static int prevValue = 0;
    if ( listOfAngles[2]->value() > prevValue )
        emit ZAngleChanched( 0.1, nullptr );
    else if ( listOfAngles[2]->value() < prevValue )
        emit ZAngleChanched( -0.1, nullptr );
    prevValue = listOfAngles[2]->value();
}
