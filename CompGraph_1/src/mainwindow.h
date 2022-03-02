#pragma once

#include <QOpenGLWidget>


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
};
