#include "mainform4.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QPushButton>

#include <ctime>

MainForm4::MainForm4( QWidget * parent )
    : QWidget{ parent }
{
    initGui();

    srand( time( 0 ) );
    generateLines( 10 );
    onChangedRectangleCoords();
}

void MainForm4::initGui()
{
    setFixedSize( 1000, 520 );

    openGlWidget = new OpenGLForm2D();
    openGlWidget->setFixedSize(500, 500);

    QVBoxLayout * createRecLayout    = new QVBoxLayout();

    for ( int i = 0; i < 4; ++i )
    {
        coordsList.append( new QSpinBox() );
        coordsList[i]->setRange( -100, 100 );
        coordsList[i]->setValue( 0 );
        connect( coordsList[i], SIGNAL( valueChanged( int ) ), this, SLOT( onChangedRectangleCoords() ) );
    }

    QHBoxLayout * firstPointLayout = new QHBoxLayout();

    firstPointLayout->addWidget( new QLabel( "X: " ) );
    firstPointLayout->addWidget( coordsList[0] );
    firstPointLayout->addStretch( 1 );
    firstPointLayout->addWidget( new QLabel( "Y: " ) );
    firstPointLayout->addWidget( coordsList[1] );
    firstPointLayout->addStretch( 1 );

    QHBoxLayout * secondPointLayout = new QHBoxLayout();

    secondPointLayout->addWidget( new QLabel( "X: " ) );
    secondPointLayout->addWidget( coordsList[2] );
    secondPointLayout->addStretch( 1 );
    secondPointLayout->addWidget( new QLabel( "Y: " ) );
    secondPointLayout->addWidget( coordsList[3] );
    secondPointLayout->addStretch( 1 );

    createRecLayout->addWidget( new QLabel( "Первая точка прямоугольника" ) );
    createRecLayout->addLayout( firstPointLayout );
    createRecLayout->addWidget( new QLabel( "Первая точка прямоугольника" ) );
    createRecLayout->addLayout( secondPointLayout );

    QGroupBox * createRecGB = new QGroupBox();
    createRecGB->setTitle( "Задание прямоугольника" );
    createRecGB->setLayout( createRecLayout );

    QVBoxLayout * lineGeneratorLayout    = new QVBoxLayout();
    QSlider * countOfLinesSlider = new QSlider( Qt::Orientation::Horizontal );
    countOfLinesSlider->setRange( 1, 100 );
    countOfLinesSlider->setValue( 10 );

    connect( countOfLinesSlider, SIGNAL( valueChanged( int ) ), this, SLOT( onChangedCountOfLines( int ) ) );

    QPushButton * fillLinesPushButton = new QPushButton( "Подсветить линии" );
    connect( fillLinesPushButton, SIGNAL( clicked() ), this, SLOT( calculateLinesStates() ) );

    lineGeneratorLayout->addWidget( countOfLinesSlider  );
    lineGeneratorLayout->addStretch( 1 );
    lineGeneratorLayout->addWidget( fillLinesPushButton );

    QGroupBox * lineGeneratorGB = new QGroupBox();
    lineGeneratorGB->setTitle( "Генерация отрезков" );
    lineGeneratorGB->setLayout( lineGeneratorLayout );

    QVBoxLayout * mainToolLayout = new QVBoxLayout();

    mainToolLayout->addWidget( createRecGB );
    mainToolLayout->addWidget( lineGeneratorGB );

    QHBoxLayout * mainLayout  = new QHBoxLayout();
    mainLayout->addWidget( openGlWidget );
    mainLayout->addLayout( mainToolLayout );

    setLayout( mainLayout );
}

void MainForm4::generateLines( int countOfLines )
{
    for ( int i = 0; i < countOfLines; ++i )
        coordsOfLinesList.append( QPair<QPair<QPair<float, float>, QPair<float, float>>, int>(
                                      QPair<QPair<float, float>, QPair<float, float>>(
                                      QPair<float, float>( 1 + ( rand() % 200 ) - 100, 1 + ( rand() % 200 ) - 100 ),
                                      QPair<float, float>( 1 + ( rand() % 200 ) - 100, 1 + ( rand() % 200 ) - 100 ) ),
                                      LINE_BLACK )
                                  );
}

QPair<float, float> MainForm4::lerp(QPair<float, float> point1, QPair<float, float> point2, float t)
{
    return QPair<float, float>( ( point2.first - point1.first ) * t + point1.first,
                                ( point2.second - point1.second ) * t + point1.second );
}


void MainForm4::onChangedRectangleCoords()
{
    openGlWidget->clear();
    openGlWidget->addFigure( new Figures::Rectangle2D( ( float )( coordsList[0]->value() ) / 100,
                                                       ( float )( coordsList[1]->value() ) / 100,
                                                       ( float )( coordsList[2]->value() ) / 100,
                                                       ( float )( coordsList[3]->value() ) / 100 ) );
    for ( int i = 0; i < coordsOfLinesList.count(); ++i )
        openGlWidget->addFigure( new Figures::Line2D( ( float )( coordsOfLinesList[i].first.first.first ) / 100,
                                                      ( float )( coordsOfLinesList[i].first.first.second ) / 100,
                                                      ( float )( coordsOfLinesList[i].first.second.first ) / 100,
                                                      ( float )( coordsOfLinesList[i].first.second.second ) / 100,
                                                      coordsOfLinesList[i].second ) );
}

void MainForm4::onChangedCountOfLines( int countOfLines )
{
    coordsOfLinesList.clear();
    generateLines( countOfLines );
    onChangedRectangleCoords();
}

void MainForm4::calculateLinesStates()
{
    bool flag = false;
    for ( int i = 0; i < coordsOfLinesList.count(); ++i )
    {
        flag = false;
        // Проверяем, лежит ли отрезок полностью в области
        float minLineX = qMin( coordsOfLinesList[i].first.first.first, coordsOfLinesList[i].first.second.first );
        float maxLineX = qMax( coordsOfLinesList[i].first.first.first, coordsOfLinesList[i].first.second.first );
        float minLineY = qMin( coordsOfLinesList[i].first.first.second, coordsOfLinesList[i].first.second.second );
        float maxLineY = qMax( coordsOfLinesList[i].first.first.second, coordsOfLinesList[i].first.second.second );

        float minRecX = qMin( coordsList[0]->value(), coordsList[2]->value() );
        float maxRecX = qMax( coordsList[0]->value(), coordsList[2]->value() );
        float minRecY = qMin( coordsList[1]->value(), coordsList[3]->value() );
        float maxRecY = qMax( coordsList[1]->value(), coordsList[3]->value() );

        if ( ( minLineX >= minRecX && minLineX <= maxRecX
             && maxLineX >= minRecX && maxLineX <= maxRecX )
             && ( minLineY >= minRecY && minLineY <= maxRecY
             && maxLineY >= minRecY && maxLineY <= maxRecY ) )
        {
            coordsOfLinesList[i].second = LINE_GREEN;
            continue;
        }

        // Проверяем, лежит ли отрезок в области хотя бы частично

        for( int j = 0; j < 1000; ++j )
        {
            QPair<float, float> lerpResult = lerp( coordsOfLinesList[i].first.first,
                                                   coordsOfLinesList[i].first.second,
                                                   (float)j / 1000 );
            if ( lerpResult.first >= minRecX && lerpResult.first <= maxRecX
                 && lerpResult.second >= minRecY && lerpResult.second <= maxRecY)
            {
                coordsOfLinesList[i].second = LINE_YELLOW;
                flag = true;
                break;
            }
        }

        if (flag)
            continue;

        coordsOfLinesList[i].second = LINE_RED;
    }
    onChangedRectangleCoords();
}
