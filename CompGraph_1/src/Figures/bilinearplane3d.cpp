#include "bilinearplane3d.h"

namespace Figures
{
    BilinearPlane3D::BilinearPlane3D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0, 0 },
                                                                     { 0, 0, 0 },
                                                                     { 0, 0, 0 },
                                                                     { 0, 0, 0 } } );
    }

    BilinearPlane3D::BilinearPlane3D( QList<QList<float> > listOfPoint )
    {
        if ( listOfPoint.size() != 4 )
            throw std::invalid_argument( "illegal matrix BilinearPlane3D" );
        m_matrix = new MathLogic::Matrix( 4, 3 );
        for ( int i = 0; i < 4; ++i )
        {
            if ( listOfPoint[i].size() != 3 )
                throw std::invalid_argument( "illegal matrix BilinearPlane3D" );
            m_matrix->valueOf( i, 0 ) = listOfPoint[i][0];
            m_matrix->valueOf( i, 1 ) = listOfPoint[i][1];
            m_matrix->valueOf( i, 2 ) = listOfPoint[i][2];
        }
    }

    void BilinearPlane3D::draw()
    {
        //!@todo Нормальная отрисовка поверхности
        for ( int i = 0; i < 4; ++i )
        {
            Figures::Point3D p( m_matrix->valueOf( i, 0 ), m_matrix->valueOf( i, 1 ), m_matrix->valueOf( i, 2 ) );
            p.draw();
        }

        glBegin(GL_LINE_STRIP);
        for ( int i = 0; i < 5; ++i )
        {
            glColor3f( 1, 0, 0 ); glVertex3f( m_matrix->valueOf( i % 4, 0 ),
                                              m_matrix->valueOf( i % 4, 1 ),
                                              m_matrix->valueOf( i % 4, 2 ) );
        }
        glEnd();

        for ( int i = 0; i < 5; ++i )
        {
            glBegin(GL_LINE_STRIP);
            glColor3f( 1, 0, 0 ); glVertex3f( lerp(QList<float>{m_matrix->valueOf( 0, 0 ), m_matrix->valueOf( 0, 1 ), m_matrix->valueOf( 0, 2 )},
                                                   QList<float>{m_matrix->valueOf( 1, 0 ), m_matrix->valueOf( 1, 1 ), m_matrix->valueOf( 1, 2 )},
                                                   (float)i * 0.2)[0],
                                              lerp(QList<float>{m_matrix->valueOf( 0, 0 ), m_matrix->valueOf( 0, 1 ), m_matrix->valueOf( 0, 2 )},
                                                   QList<float>{m_matrix->valueOf( 1, 0 ), m_matrix->valueOf( 1, 1 ), m_matrix->valueOf( 1, 2 )},
                                                   (float)i * 0.2)[1],
                                              lerp(QList<float>{m_matrix->valueOf( 0, 0 ), m_matrix->valueOf( 0, 1 ), m_matrix->valueOf( 0, 2 )},
                                                   QList<float>{m_matrix->valueOf( 1, 0 ), m_matrix->valueOf( 1, 1 ), m_matrix->valueOf( 1, 2 )},
                                                   (float)i * 0.2)[2] );
            glColor3f( 1, 0, 0 ); glVertex3f( lerp(QList<float>{m_matrix->valueOf( 3, 0 ), m_matrix->valueOf( 3, 1 ), m_matrix->valueOf( 3, 2 )},
                                                   QList<float>{m_matrix->valueOf( 2, 0 ), m_matrix->valueOf( 2, 1 ), m_matrix->valueOf( 2, 2 )},
                                                   (float)i * 0.2)[0],
                                              lerp(QList<float>{m_matrix->valueOf( 3, 0 ), m_matrix->valueOf( 3, 1 ), m_matrix->valueOf( 3, 2 )},
                                                   QList<float>{m_matrix->valueOf( 2, 0 ), m_matrix->valueOf( 2, 1 ), m_matrix->valueOf( 2, 2 )},
                                                   (float)i * 0.2)[1],
                                              lerp(QList<float>{m_matrix->valueOf( 3, 0 ), m_matrix->valueOf( 3, 1 ), m_matrix->valueOf( 3, 2 )},
                                                   QList<float>{m_matrix->valueOf( 2, 0 ), m_matrix->valueOf( 2, 1 ), m_matrix->valueOf( 2, 2 )},
                                                   (float)i * 0.2)[2] );
            glEnd();
        }
    }

    void BilinearPlane3D::rotateViaX( float angle )
    {
        MathLogic::Matrix matrixOX ( QList<QList<float>> {
                                                             { 1, 0, 0 },
                                                             { 0, qCos( angle ), qSin( angle ) },
                                                             { 0, -qSin( angle ), qCos( angle ) }
                                                         } );
        * m_matrix = ( * m_matrix ) * matrixOX;
    }

    void BilinearPlane3D::rotateViaY( float angle )
    {
        MathLogic::Matrix matrixOY ( QList<QList<float>> {
                                                             { qCos( angle ), 0, -qSin( angle ) },
                                                             { 0, 1, 0 },
                                                             { qSin( angle ), 0, qCos( angle ) }
                                                         } );
        * m_matrix = ( * m_matrix ) * matrixOY;
    }

    void BilinearPlane3D::rotateViaZ( float angle )
    {
        MathLogic::Matrix matrixOZ ( QList<QList<float>> {
                                                             { qCos( angle ), qSin( angle ), 0 },
                                                             { -qSin( angle ), qCos( angle ), 0 },
                                                             { 0, 0, 1 }
                                                         } );
        * m_matrix = ( * m_matrix ) * matrixOZ;
    }

    QList<float> BilinearPlane3D::lerp(QList<float> point1, QList<float> point2, float t)
    {
        return QList<float>{  ( point2[0] - point1[0] ) * t + point1[0] ,
                              ( point2[1] - point1[1] ) * t + point1[1] ,
                              ( point2[2] - point1[2] ) * t + point1[2] };
    }
}
