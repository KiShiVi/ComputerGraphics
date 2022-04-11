#pragma once

#include "figure2d.h"

namespace Figures
{
    //!
    //! \brief The Line2D class Класс двухмерного отрезка
    //!
    class Line2D: public Figure2D
    {
    public:
        //!
        //! \brief Line2D Конструктор по умолчанию
        //!
        Line2D();
        //!
        //! \brief Line2D Конструктор с параметрами
        //! \param x1 Координата первой точки по X
        //! \param y1 Координата первой точки по Y
        //! \param x2 Координата второй точки по X
        //! \param y2 Координата второй точки по Y
        //! \param color Цвет отрезка
        //!
        Line2D( float x1, float y1, float x2, float y2, int color = 0 );
        //!
        //! \brief draw Метод отрисовки объекта
        //!
        void draw() override;
    private:
        //!
        //! \brief color Цвет
        //!
        int color;
    }; // Line2D
} // Figures
