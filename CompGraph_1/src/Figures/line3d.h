#pragma once

#include "figure3d.h"

namespace Figures
{
    //!
    //! \brief The Line3D class Класс трехмерного отрезка
    //!
    class Line3D : public Figures::Figure3D
    {
    public:
        //!
        //! \brief Line3D Конструктор по умолчанию
        //!
        Line3D();
        //!
        //! \brief Line3D Конструктор с параметрами
        //! \param x1 Координата первой точки по Y
        //! \param y1 Координата первой точки по X
        //! \param z1 Координата первой точки по Z
        //! \param x2 Координата второй точки по Y
        //! \param y2 Координата второй точки по X
        //! \param z2 Координата второй точки по Z
        //!
        Line3D( float x1, float y1, float z1,
                float x2, float y2, float z2 );
        //!
        //! \brief draw Метод отрисовки объекта
        //!
        void draw() override;
    };
}

