#pragma once

#include "figure3d.h"

namespace Figures
{
    //!
    //! \brief The Point3D class Класс трехмерной точки
    //!
    class Point3D : public Figures::Figure3D
    {
    public:
        //!
        //! \brief Point3D Конструктор по умолчанию
        //!
        Point3D();
        //!
        //! \brief Point3D Point2D Конструктор с параметрами
        //! \param x Координата точки по Y
        //! \param y Координата точки по X
        //! \param z Координата точки по Z
        //!
        Point3D( float x, float y, float z );
        //!
        //! \brief draw Метод отрисовки объекта
        //!
        void draw() override;
    };
}
