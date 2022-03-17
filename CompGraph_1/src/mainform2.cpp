#include "mainform2.h"

MainForm2::MainForm2( QWidget * parent )
    : QWidget{ parent }
{
    initGui();
}

void MainForm2::initGui()
{
    setFixedSize( 1000, 520 );
    openGlWidget = new OpenGLForm();
    openGlWidget->setFixedSize(500, 500);

    QHBoxLayout * mainLayout            = new QHBoxLayout();

    QGroupBox   * createFigureGB        = new QGroupBox();

    QVBoxLayout * createFigureLayout    = new QVBoxLayout();

    createFigureGB->setTitle( "Создание кривой Безье" );

    createFigureLayout->addWidget( new QLabel( "Координаты точек кривой:" ) );

    QHBoxLayout * btnLay    = new QHBoxLayout();
    QPushButton * btnMinus  = new QPushButton( "-" );
    QPushButton * btnPlus   = new QPushButton( "+" );

    connect( btnMinus,  SIGNAL( clicked() ), this, SLOT( onMinusClicked() ) );
    connect( btnPlus,   SIGNAL( clicked() ), this, SLOT( onPlusClicked() ) );

    btnLay->addWidget( btnMinus );
    btnLay->addWidget( btnPlus );
    btnLay->addStretch(1);

    createFigureLayout->addLayout( btnLay );

    listOfPoints.append( QPair<QLineEdit *, QLineEdit *>( new QLineEdit(), new QLineEdit() ) );
    listOfPoints.append( QPair<QLineEdit *, QLineEdit *>( new QLineEdit(), new QLineEdit() ) );
    listOfPoints.append( QPair<QLineEdit *, QLineEdit *>( new QLineEdit(), new QLineEdit() ) );

    inWidgets    = new QVBoxLayout();

    for ( int i = 0; i < listOfPoints.count(); ++i )
    {
        QHBoxLayout * onePointLayout    = new QHBoxLayout();
        onePointLayout->addWidget( listOfPoints[i].first );
        onePointLayout->addWidget( listOfPoints[i].second );
        inWidgets->addLayout(onePointLayout);
    }

    createFigureLayout->addLayout( inWidgets );

    QPushButton * applyBtn = new QPushButton( "Применить" );
    connect( applyBtn, SIGNAL( clicked() ), this, SLOT( onDrawClicked() ) );

    createFigureLayout->addStretch(1);
    createFigureLayout->addWidget( applyBtn );

    createFigureGB->setLayout( createFigureLayout );

    mainLayout->addWidget( openGlWidget );
    mainLayout->addWidget( createFigureGB );

    connect( this, SIGNAL( draw( Figures::Figure2D * ) ), openGlWidget, SLOT( addFigure( Figures::Figure2D * ) ) );

    setLayout( mainLayout );
}

void MainForm2::onDrawClicked()
{
    QList<QPair<float, float>> sendList;
    for ( int i = 0; i < listOfPoints.count(); ++i )
    {
        sendList.append( QPair<float, float>(listOfPoints[i].first->text().toFloat(),
                                             listOfPoints[i].second->text().toFloat() ) );
    }

    openGlWidget->onClear();

    emit draw( new Figures::Spline2D( sendList ) );
}

void MainForm2::onPlusClicked()
{
    if ( listOfPoints.size() > 15 )
        return;
    listOfPoints.append( QPair<QLineEdit *, QLineEdit *>( new QLineEdit(), new QLineEdit() ) );
    QHBoxLayout * onePointLayout    = new QHBoxLayout();
    onePointLayout->addWidget( listOfPoints[listOfPoints.size() - 1].first );
    onePointLayout->addWidget( listOfPoints[listOfPoints.size() - 1].second );
    inWidgets->addLayout( onePointLayout );
}

void MainForm2::onMinusClicked()
{
    if ( listOfPoints.size() < 4 )
        return;
    //listOfPoints.append( QPair<QLineEdit *, QLineEdit *>( new QLineEdit(), new QLineEdit() ) );
    inWidgets->removeWidget( listOfPoints[listOfPoints.size() - 1].first );
    inWidgets->removeWidget( listOfPoints[listOfPoints.size() - 1].second );
    delete listOfPoints[listOfPoints.size() - 1].first;
    delete listOfPoints[listOfPoints.size() - 1].second;
    listOfPoints.removeLast();
}
