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

    void Point2D::draw()
    {
        glBegin(GL_POINT);
            glColor3f( 0, 0, 0 ); glVertex2f( matrix->valueOf( 0, 0 ) , matrix->valueOf( 0, 1 ) );
        glEnd();
    }
}
