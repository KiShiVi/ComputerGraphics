#include "point2d.h"

namespace Figures
{
    Point2D::Point2D()
    {
        matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 } } );
    }

    Point2D::Point2D(float x, float y)
    {
        matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x, y } } );
    }
}
