#pragma once

#include "../matrix.h"

#include <QVector>

namespace Figures
{
    class Point2D
    {
    public:
        Point2D();
        Point2D( float x, float y );
    private:
        MathLogic::Matrix * matrix;
    };
}
