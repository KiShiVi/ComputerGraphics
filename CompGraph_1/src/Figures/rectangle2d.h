#pragma once

#include "figure2d.h"

namespace Figures
{
    class Rectangle2D : public Figures::Figure2D
    {
    public:
        Rectangle2D();
        Rectangle2D( float x1, float y1,
                      float x2, float y2 );
        void draw() override;
    };
}
