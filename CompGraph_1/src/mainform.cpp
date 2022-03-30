#include "mainform.h"

MainForm::MainForm( QWidget * parent )
    : QWidget{ parent }
{
    initGui();
}

void MainForm::initGui()
{
    x1_le       = new QLineEdit();
    x2_le       = new QLineEdit();
    y1_le       = new QLineEdit();
    y2_le       = new QLineEdit();
    n_le        = new QLineEdit();
    scale_le    = new QLineEdit();


    setFixedSize( 1000, 520 );
    openGlWidget = new OpenGLForm2D( );
    openGlWidget->setFixedSize(500, 500);

    QHBoxLayout * mainLayout            = new QHBoxLayout();
    QVBoxLayout * toolsLayout           = new QVBoxLayout();

    QGroupBox   * createFigureGB        = new QGroupBox();
    QVBoxLayout * createFigureLayout    = new QVBoxLayout();

    createFigureGB->setTitle( "Создание прямоугольника" );

    createFigureLayout->addWidget( new QLabel( "Координаты прямоугольника:" ) );
    createFigureLayout->addWidget( new QLabel( "Первая точка - X:" ) );
    createFigureLayout->addWidget( x1_le );
    createFigureLayout->addWidget( new QLabel( "Первая точка - Y:" ) );
    createFigureLayout->addWidget( y1_le );
    createFigureLayout->addWidget( new QLabel( "Вторая точка - X:" ) );
    createFigureLayout->addWidget( x2_le );
    createFigureLayout->addWidget( new QLabel( "Вторая точка - Y:" ) );
    createFigureLayout->addWidget( y2_le );
    QPushButton * createRec = new QPushButton( "Создать прямоугольник" );
    createFigureLayout->addWidget( createRec );
    connect( createRec, SIGNAL( clicked() ), this, SLOT( onAddFigureButtonClicked() ) );

    createFigureGB->setLayout(createFigureLayout);


    QGroupBox   * changeScaleFigureGB        = new QGroupBox();
    QVBoxLayout * changeScaleFigureLayout    = new QVBoxLayout();

    changeScaleFigureGB->setTitle( "Изменить масштаб фигуры" );

    changeScaleFigureLayout->addWidget( new QLabel( "Номер фигуры (от 0):" ) );
    changeScaleFigureLayout->addWidget( n_le );
    changeScaleFigureLayout->addWidget( new QLabel( "Новый масштаб:" ) );
    changeScaleFigureLayout->addWidget( scale_le );
    QPushButton * changeScaleBut = new QPushButton( "Изменить масштаб" );
    changeScaleFigureLayout->addWidget( changeScaleBut );
    connect( changeScaleBut, SIGNAL( clicked() ), this, SLOT( onChangeFigureScaleButtonClicked() ) );

    changeScaleFigureGB->setLayout(changeScaleFigureLayout);

    toolsLayout->addWidget(createFigureGB);
    toolsLayout->addWidget(changeScaleFigureGB);

    QPushButton * clearButton = new QPushButton( "Очистить" );
    connect( clearButton, SIGNAL( clicked() ), this, SLOT( onClearButtonClicked() ) );
    toolsLayout->addWidget(clearButton);

    mainLayout->addWidget( openGlWidget );
    mainLayout->addLayout( toolsLayout );

    connect(this, SIGNAL( addFigureSignal( Figures::Figure2D * ) ),
                         openGlWidget, SLOT( addFigure( Figures::Figure2D * ) ) );

    connect(this, SIGNAL( changeFigureScaleSignal( Figures::Figure2D &, float ) ),
                         openGlWidget, SLOT( changeFigureScale( Figures::Figure2D &, float ) ) );

    connect(this, SIGNAL( clearSignal() ),
                         openGlWidget, SLOT( onClear() ) );


    setLayout( mainLayout );
}

void MainForm::onClearButtonClicked()
{
    emit clearSignal();
}

void MainForm::onAddFigureButtonClicked()
{
    emit addFigureSignal( new Figures::Rectangle2D( x1_le->text().toFloat(), y1_le->text().toFloat(),
                                                       x2_le->text().toFloat(), y2_le->text().toFloat() ) );
}

void MainForm::onChangeFigureScaleButtonClicked()
{
    if ( n_le->text().toInt() >= 1 && n_le->text().toInt() < openGlWidget->size() )
        emit changeFigureScaleSignal( openGlWidget->getByIndex( n_le->text().toInt() ), scale_le->text().toFloat() );
}
