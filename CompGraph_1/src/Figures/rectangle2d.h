#pragma once

#include "figure2d.h"

namespace Figures
{
    //!
    //! \brief The Rectangle2D class Класс двухмерного прямоугольника
    //!
    class Rectangle2D : public Figures::Figure2D
    {
    public:
        //!
        //! \brief Rectangle2D Конструктор по умолчанию
        //!
        Rectangle2D();
        //!
        //! \brief Rectangle2D Конструктор с параметрами
        //! \param x1 Координата первой точки по X
        //! \param y1 Координата первой точки по Y
        //! \param x2 Координата второй точки по X
        //! \param y2 Координата второй точки по Y
        //!
        Rectangle2D( float x1, float y1,
                      float x2, float y2 );
        //!
        //! \brief draw Метод отрисовки фигуры
        //!
        void draw() override;
        //!
        //! \brief getCenter Возвращает центр фигуры
        //! \return Координаты центра фигуры
        //!
        QPair<float, float> getCenter() override;
    }; // Rectangle2D
} // Figures
