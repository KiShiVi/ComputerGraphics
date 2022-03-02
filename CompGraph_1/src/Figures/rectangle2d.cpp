#include "rectangle2d.h"

namespace Figures
{
    Rectangle2D::Rectangle2D()
    {
        matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 },
                                                                   { 0, 0 },
                                                                   { 0, 0 },
                                                                   { 0, 0 } } );
    }

    Rectangle2D::Rectangle2D(float x1, float y1, float x2, float y2 )
    {
        matrix = new MathLogic::Matrix( QVector<QVector<float> > { { x1, y1 },
                                                                   { x2, y1 },
                                                                   { x2, y2 },
                                                                   { x1, y2 } } );
    }

    void Rectangle2D::draw()
    {
        glBegin(GL_LINE_STRIP);
            glColor3f( 0, 0, 0 ); glVertex2f( matrix->valueOf( 0, 0 ) , matrix->valueOf( 0, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( matrix->valueOf( 1, 0 ) , matrix->valueOf( 1, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( matrix->valueOf( 2, 0 ) , matrix->valueOf( 2, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( matrix->valueOf( 3, 0 ) , matrix->valueOf( 3, 1 ) );
            glColor3f( 0, 0, 0 ); glVertex2f( matrix->valueOf( 0, 0 ) , matrix->valueOf( 0, 1 ) );
        glEnd();
    }
}
