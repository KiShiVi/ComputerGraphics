#pragma once

#include "figure2d.h"

namespace Figures
{
    //!
    //! \brief The Point2D class Класс двухмерной точки
    //!
    class Point2D : public Figures::Figure2D
    {
    public:
        //!
        //! \brief Point2D Конструктор по умолчанию
        //!
        Point2D();
        //!
        //! \brief Point2D Конструктор с параметрами
        //! \param x Координата точки по X
        //! \param y Координата точки по Y
        //!
        Point2D( float x, float y );
        //!
        //! \brief draw Метод отрисовки объекта
        //!
        void draw() override;
    }; // Point2D
} // Figures
