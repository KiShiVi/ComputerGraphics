#pragma once

#include <FiguresLib>
#include <OpenGLFormLib>
#include <QSpinBox>
#include <QWidget>

//!
//! \brief The MainForm4 class Основная форма приложения 4 лабораторной работы
//!
class MainForm4 : public QWidget
{
    Q_OBJECT
public:
    //!
    //! \brief MainForm4 Конструктор
    //! \param parent Родительский виджет
    //!
    explicit MainForm4( QWidget * parent = nullptr );
private:
    //!
    //! \brief initGui Инициализация GUI
    //!
    void initGui();
    //!
    //! \brief generateLines Генерация случайных отрезков
    //! \param countOfLines Кол-во отрезков
    //!
    void generateLines( int countOfLines );
    //!
    //! \brief lerp Метод вычисления точки на отрезке в пропорции t
    //! \param point1 Начальная точка отрезка
    //! \param point2 Конечная точка отрезка
    //! \param t Пропорция (0.00; 1.00)
    //! \return Пара (x, y)
    //!
    QPair<float, float> lerp( QPair<float, float> point1, QPair<float, float> point2, float t);

private slots:
    //!
    //! \brief onChangedRectangleCoords Слот на изменение координат прямоугольника
    //!
    void onChangedRectangleCoords();
    //!
    //! \brief onChangedCountOfLines Слот на изменение кол-ва генерируемых линий
    //! \param countOfLines Кол-во линий
    //!
    void onChangedCountOfLines( int countOfLines );
    //!
    //! \brief calculateLinesStates Слот на вычисление "типа" линии (в области/не в области/частично в области)
    //!
    void calculateLinesStates();
private:
    //!
    //! \brief coordsOfLinesList Координаты отрезков и их состояния
    //!
    QList<QPair<QPair<QPair<float, float>, QPair<float, float>>, int>> coordsOfLinesList;
    //!
    //! \brief coordsList Координаты области
    //!
    QList<QSpinBox *> coordsList;
    //!
    //! \brief openGlWidget Указатель на OpenGL форму
    //!
    OpenGLForm2D  * openGlWidget;
};
