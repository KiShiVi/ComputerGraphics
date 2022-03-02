#pragma once

#include "figure2d.h"

namespace Figures
{
    class Point2D : public Figures::Figure2D
    {
    public:
        Point2D();
        Point2D( float x, float y );
        void draw() override;
    };
}
