#include "line2d.h"

namespace Figures
{
    Line2D::Line2D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 },
                                                                   { 0, 0 } } );
    }

    Line2D::Line2D(float x1, float y1, float x2, float y2)
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x1, y1 },
                                                                   { x2, y2 } } );
    }

    void Line2D::draw()
    {
        glBegin(GL_LINES);
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 0, 0 ) , m_matrix->valueOf( 0, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 1, 0 ) , m_matrix->valueOf( 1, 1 ) );
        glEnd();
    }
}
