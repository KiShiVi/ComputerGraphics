#pragma once

#include <OpenGLFormLib>
#include <FiguresLib>

#include <QWidget>
#include <QSlider>

//!
//! \brief The MainForm5 class Основная форма 5ой и 6ой лаб
//!
class MainForm5 : public QWidget
{
    Q_OBJECT
public:
    //!
    //! \brief MainForm5 Конструктор
    //! \param parent Родительский виджет
    //!
    explicit MainForm5( QWidget * parent = nullptr );
signals:
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
    //!
    //! \brief lightChanged Сигнал изменения интенсивности свечения
    //! \param value значение интенсивности свечения
    //!
    void lightChanged( int value );

private:
    //!
    //! \brief initGui Инициализация GUI
    //!
    void initGui();

private slots:
    void onXAngleChanched();
    void onYAngleChanched();
    void onZAngleChanched();
    void onLightChanged( int value );

private:
    //!
    //! \brief listOfAngles Указатели на виджеты смены угла поворота куба
    //!
    QList<QSlider *> listOfAngles;
    //!
    //! \brief openGlWidget Указатель на OpenGL форму
    //!
    OpenGLForm3D  * openGlWidget;
};

