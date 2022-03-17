#pragma once

#include "figure2d.h"
#include "line2d.h"
#include "point2d.h"
#include <QList>
#include <QPair>

namespace Figures
{
    //!
    //! \brief COUNT_OF_LINES_IN_SPLINE_FRAGMENT Константа, задающая кол-во отрезков в одной секции кривой.
    //! Чем больше число - тем больше вычислений, но чётче картинка
    //!
    const int COUNT_OF_LINES_IN_SPLINE_FRAGMENT = 100;
    //!
    //! \brief The Spline2D class Класс кривой Безье
    //!
    class Spline2D : public Figures::Figure2D
    {
    public:
        //!
        //! \brief Spline2D Конструктор по умолчанию
        //!
        Spline2D();
        //!
        //! \brief Spline2D Конструктор с параметрами
        //! \param listOfPoint Список точек кривой Безье
        //!
        Spline2D( QList<QPair<float, float>> listOfPoint );
        //!
        //! \brief draw Метод отрисовки фигуры
        //!
        void draw() override;
    private:
        //!
        //! \brief lerp Метод вычисления точки на отрезке в пропорции t
        //! \param point1 Начальная точка отрезка
        //! \param point2 Конечная точка отрезка
        //! \param t Пропорция (0.00; 1.00)
        //! \return Пара (x, y)
        //!
        QPair<float, float> lerp( QPair<float, float> point1, QPair<float, float> point2, float t);
        //!
        //! \brief findNewBeziersLayer Находит новый слой точек отрезков криой Безье
        //! \param list Список изначальных точек
        //! \param t Пропорция (0.00; 1.00)
        //! \details Изначально в первый раз в метод подаём тупо лист из заданных точек
        //! \return Новый список точек
        //!
        QList<QPair<float, float>> findNewBeziersLayer( QList<QPair<float, float>> list, float t );
    };
}
