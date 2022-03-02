#pragma once

#include "../matrix.h"

#include <QOpenGLWidget>

namespace Figures
{
    class Figure2D
    {

    public:
        explicit Figure2D();
        MathLogic::Matrix * matrix;
        virtual void draw();
    };
}
