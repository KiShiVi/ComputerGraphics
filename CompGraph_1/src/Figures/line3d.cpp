#include "line3d.h"

namespace Figures
{
    Line3D::Line3D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0, 0 },
                                                                     { 0, 0, 0 } } );
    }

    Line3D::Line3D(float x1, float y1, float z1, float x2, float y2, float z2)
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x1, y1, z1 },
                                                                     { x2, y2, z2 } } );
    }

    void Line3D::draw()
    {
        glBegin(GL_LINES);
            glColor3f( 0, 0, 0 ); glVertex3f( m_matrix->valueOf( 0, 0 ),
                                              m_matrix->valueOf( 0, 1 ),
                                              m_matrix->valueOf( 0, 2 ) );

            glColor3f( 0, 0, 0 ); glVertex3f( m_matrix->valueOf( 1, 0 ),
                                              m_matrix->valueOf( 1, 1 ),
                                              m_matrix->valueOf( 1, 2 ) );
        glEnd();
    }
}
