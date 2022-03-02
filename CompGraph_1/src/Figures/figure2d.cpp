#include "figure2d.h"

namespace Figures
{
    Figure2D::Figure2D()
    {

    }

    void Figure2D::draw()
    {
        throw std::invalid_argument( "Draw method not overridden" );
    }
}
