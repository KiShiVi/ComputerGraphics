#include "point2d.h"

namespace Figures
{
    Point2D::Point2D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 } } );
    }

    Point2D::Point2D(float x, float y)
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x, y } } );
    }

    void Point2D::draw()
    {
        glPointSize(5);
        glBegin(GL_POINTS);
            glColor3f( 1, 0, 0 ); glVertex2f( m_matrix->valueOf( 0, 0 ) , m_matrix->valueOf( 0, 1 ) );
        glEnd();
    }
}
