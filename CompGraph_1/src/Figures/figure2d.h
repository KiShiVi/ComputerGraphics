#pragma once

#include "../matrix.h"

#include <QOpenGLWidget>

namespace Figures
{
    //!
    //! \brief The Figure2D class Базовый класс для двухмерных фигур
    //!
    class Figure2D
    {

    public:
        //!
        //! \brief Figure2D Конструктор по умолчанию
        //!
        explicit Figure2D();
        //!
        //! \brief draw Виртуальный метод, который определяют в себе дочерние классы
        //!
        virtual void draw();
        //!
        //! \brief matrix Матрица с координатами
        //!
        MathLogic::Matrix * matrix;
    }; // Figure2D
} // Figures
