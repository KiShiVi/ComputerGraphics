#include "coordinateaxes.h"

namespace Figures
{
    CoordinateAxes::CoordinateAxes()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 },
                                                                     { 0, 0 } } );
        scale = 1;
    }

    void CoordinateAxes::draw()
    {
        glBegin(GL_LINES);
            { // Перекрестие
                glColor3f( 0, 0, 1 ); glVertex2f( -1, 0 );
                glColor3f( 0, 0, 1 ); glVertex2f( 1, 0 );

                glColor3f( 0, 0, 1 ); glVertex2f( 0, -1 );
                glColor3f( 0, 0, 1 ); glVertex2f( 0, 1 );
            }
            { // Верхняя стрелка
                glColor3f( 0, 0, 1 ); glVertex2f( 0, 1 );
                glColor3f( 0, 0, 1 ); glVertex2f( -0.02, 0.9 );

                glColor3f( 0, 0, 1 ); glVertex2f( 0, 1 );
                glColor3f( 0, 0, 1 ); glVertex2f( 0.02, 0.9 );
            }
            { // Правая стрелка
                glColor3f( 0, 0, 1 ); glVertex2f( 1, 0 );
                glColor3f( 0, 0, 1 ); glVertex2f( 0.9, 0.02 );

                glColor3f( 0, 0, 1 ); glVertex2f( 1, 0 );
                glColor3f( 0, 0, 1 ); glVertex2f( 0.9, -0.02 );
            }
            { // Горизонтальные метки
                for (int i = -8; i < 9; ++i)
                {
                    // Если будем меня масштаб, надо будет уходить от 0.1
                    glColor3f( 0, 0, 1 ); glVertex2f( i * 0.1, -0.01 );
                    glColor3f( 0, 0, 1 ); glVertex2f( i * 0.1, 0.01 );
                }
            }
            { // Вертикальные метки
                for (int i = -8; i < 9; ++i)
                {
                    // Если будем меня масштаб, надо будет уходить от 0.1
                    glColor3f( 0, 0, 1 ); glVertex2f( -0.01, i * 0.1 );
                    glColor3f( 0, 0, 1 ); glVertex2f( 0.01, i * 0.1 );
                }
            }
        glEnd();
    }
}
