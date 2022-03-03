#pragma once

#include "figure2d.h"

namespace Figures
{
    //!
    //! \brief The CoordinateAxes class Класс координатных осей.
    //!
    class CoordinateAxes : public Figures::Figure2D
    {
    public:
        //!
        //! \brief CoordinateAxes Конструктор по умолчанию
        //!
        CoordinateAxes();
        //!
        //! \brief draw Метод отрисовки объекта
        //!
        void draw() override;
     private:
        //!
        //! \brief scale Масштаб осей
        //!
        float scale;
    };
}
