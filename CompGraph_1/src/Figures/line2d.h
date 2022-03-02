#pragma once

#include "figure2d.h"

namespace Figures
{
    class Line2D: public Figure2D
    {
    public:
        Line2D();
        Line2D( float x1, float y1, float x2, float y2 );
        void draw() override;
    };
}
