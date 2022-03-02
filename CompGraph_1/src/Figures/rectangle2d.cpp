#include "rectangle2d.h"

namespace Figures
{
    Rectangle2D::Rectangle2D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 },
                                                                   { 0, 0 },
                                                                   { 0, 0 },
                                                                   { 0, 0 } } );
    }

    Rectangle2D::Rectangle2D(float x1, float y1, float x2, float y2 )
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x1, y1 },
                                                                   { x2, y1 },
                                                                   { x2, y2 },
                                                                   { x1, y2 } } );
    }

    void Rectangle2D::draw()
    {
        glBegin(GL_LINE_STRIP);
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 0, 0 ) , m_matrix->valueOf( 0, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 1, 0 ) , m_matrix->valueOf( 1, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 2, 0 ) , m_matrix->valueOf( 2, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 3, 0 ) , m_matrix->valueOf( 3, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( m_matrix->valueOf( 0, 0 ) , m_matrix->valueOf( 0, 1 ) );
            glEnd();
    }

    QPair<float, float> Rectangle2D::getCenter()
    {
        return QPair<float, float>( ( m_matrix->valueOf( 1, 0 ) + m_matrix->valueOf( 0, 0 ) ) / 2,
                                      ( m_matrix->valueOf( 0, 1 ) + m_matrix->valueOf( 2, 1 ) ) / 2 );
    }
}
