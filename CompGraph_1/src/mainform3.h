#pragma once

#include <OpenGLFormLib>
#include <FiguresLib>

#include <QAbstractSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>

//!
//! \brief The MainForm3 class Основная форма приложения 3 лабораторной работы
//!
class MainForm3 : public QWidget
{
    Q_OBJECT
public:
    //!
    //! \brief MainForm3 Конструктор
    //! \param parent Родительский виджет
    //!
    explicit MainForm3( QWidget *parent = nullptr );

signals:
    //!
    //! \brief coordsChanched Сигнал для смены координат фигуры
    //! \param coords Новые координаты
    //! \param figure фигура
    //!
    void coordsChanched( QList<QList<float>> coords, Figures::Figure3D * figure);
    //!
    //! \brief XAngleChanched Сигнал для поворота фигуры относительно оси X
    //! \param angle Угол
    //! \param figure Фигура
    //!
    void XAngleChanched( float angle, Figures::Figure3D * figure );
    //!
    //! \brief YAngleChanched Сигнал для поворота фигуры относительно оси Y
    //! \param angle Угол
    //! \param figure Фигура
    //!
    void YAngleChanched( float angle, Figures::Figure3D * figure );
    //!
    //! \brief ZAngleChanched Сигнал для поворота фигуры относительно оси Z
    //! \param angle Угол
    //! \param figure Фигура
    //!
    void ZAngleChanched( float angle, Figures::Figure3D * figure );

private:
    //!
    //! \brief initGui Инициализация GUI
    //!
    void initGui();

private slots:
    void onCoordsChanched();
    void onXAngleChanched();
    void onYAngleChanched();
    void onZAngleChanched();

private:
    //!
    //! \brief listOfPoints Список на QSpinBox каждой из точек на форме
    //!
    QList<QList<QSpinBox *> > listOfCoords;
    //!
    //! \brief listOfAngles Список на QSlider каждой из поворотных осей на форме
    //!
    QList<QSlider *> listOfAngles;
    //!
    //! \brief openGlWidget Указатель на OpenGL форму
    //!
    OpenGLForm3D  * openGlWidget;
};
