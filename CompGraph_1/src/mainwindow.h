#pragma once

#include <QOpenGLWidget>
#include "Figures/figure2d.h"
#include "Figures/line2d.h"
#include "Figures/rectangle2d.h"
#include "matrix.h"


class MainWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    MainWindow( QWidget * parent = nullptr );

private:
    void initializeGL() override;
    void resizeGL( int w, int h ) override;
    void paintGL() override;
    void draw();

    QVector<Figures::Figure2D * > figures;
}; // MainWindow
