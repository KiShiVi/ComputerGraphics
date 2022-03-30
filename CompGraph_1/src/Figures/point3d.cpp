#include "point3d.h"

namespace Figures
{
    Point3D::Point3D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0, 0 } } );
    }

    Point3D::Point3D(float x, float y, float z)
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x, y, z } } );
    }

    void Point3D::draw()
    {
        glPointSize(5);
        glBegin(GL_POINTS);
            glColor3f( 1, 0, 0 ); glVertex3f( m_matrix->valueOf( 0, 0 ),
                                              m_matrix->valueOf( 0, 1 ),
                                              m_matrix->valueOf( 0, 2 ) );
        glEnd();
    }
}
