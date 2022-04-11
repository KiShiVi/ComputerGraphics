#include "cube3d.h"
#include <QtMath>

namespace Figures
{
    Cube3D::Cube3D()
    {

    }

    Figures::Cube3D::Cube3D(QPair<QList<float>, QList<float>> coords)
    {
        m_matrix = new MathLogic::Matrix( 8, 3 );

        // Первая вершина
        m_matrix->valueOf( 0, 0 ) = coords.first[0];
        m_matrix->valueOf( 0, 1 ) = coords.first[1];
        m_matrix->valueOf( 0, 2 ) = coords.first[2];

        // Вторая вершина
        m_matrix->valueOf( 1, 0 ) = coords.second[0];
        m_matrix->valueOf( 1, 1 ) = coords.first[1];
        m_matrix->valueOf( 1, 2 ) = coords.first[2];

        // Третья вершина
        m_matrix->valueOf( 2, 0 ) = coords.second[0];
        m_matrix->valueOf( 2, 1 ) = coords.first[1];
        m_matrix->valueOf( 2, 2 ) = coords.second[2];

        // Четвертая вершина
        m_matrix->valueOf( 3, 0 ) = coords.first[0];
        m_matrix->valueOf( 3, 1 ) = coords.first[1];
        m_matrix->valueOf( 3, 2 ) = coords.second[2];

        // Пятая вершина
        m_matrix->valueOf( 4, 0 ) = coords.first[0];
        m_matrix->valueOf( 4, 1 ) = coords.second[1];
        m_matrix->valueOf( 4, 2 ) = coords.first[2];

        // Шестая вершина
        m_matrix->valueOf( 5, 0 ) = coords.second[0];
        m_matrix->valueOf( 5, 1 ) = coords.second[1];
        m_matrix->valueOf( 5, 2 ) = coords.first[2];

        // Седьмая вершина
        m_matrix->valueOf( 6, 0 ) = coords.second[0];
        m_matrix->valueOf( 6, 1 ) = coords.second[1];
        m_matrix->valueOf( 6, 2 ) = coords.second[2];

        // Восьмая вершина
        m_matrix->valueOf( 7, 0 ) = coords.first[0];
        m_matrix->valueOf( 7, 1 ) = coords.second[1];
        m_matrix->valueOf( 7, 2 ) = coords.second[2];
    }

    void Cube3D::draw()
    {
        QList<float> lightColor{ -0.4, 0.4, 0.4 };
        checkPointsOnVision();

        // Проверяем первую грань на видимость

        QList<QList<float>> tmpListFacet = QList<QList<float>>{ m_matrix->getListRow( 0 ),
                                                                m_matrix->getListRow( 1 ),
                                                                m_matrix->getListRow( 2 ),
                                                                m_matrix->getListRow( 3 ) };

        float cosOfSide = findAngleOfFacetAndPoint( lightColor, tmpListFacet, 1 );
        if ( isVisibleFacet( tmpListFacet ) )
             drawFacet( tmpListFacet, QList<float>{ 1 * cosOfSide, 0 * cosOfSide, 0 * cosOfSide } );

         // Проверяем вторую грань на видимость

         tmpListFacet = QList<QList<float>>{ m_matrix->getListRow( 1 ),
                                             m_matrix->getListRow( 5 ),
                                             m_matrix->getListRow( 6 ),
                                             m_matrix->getListRow( 2 ) };

         cosOfSide = findAngleOfFacetAndPoint( lightColor, tmpListFacet, 1 );
         if ( isVisibleFacet( tmpListFacet ) )
              drawFacet( tmpListFacet, QList<float>{ 0 * cosOfSide, 1 * cosOfSide, 0 * cosOfSide } );

         // Проверяем третью грань на видимость

         tmpListFacet = QList<QList<float>>{ m_matrix->getListRow( 0 ),
                                             m_matrix->getListRow( 1 ),
                                             m_matrix->getListRow( 5 ),
                                             m_matrix->getListRow( 4 ) };

         cosOfSide = findAngleOfFacetAndPoint( lightColor, tmpListFacet, 0 );
         if ( isVisibleFacet( tmpListFacet ) )
              drawFacet( tmpListFacet, QList<float>{ 0 * cosOfSide, 0 * cosOfSide, 1 * cosOfSide } );

         // Проверяем четвертую грань на видимость

         tmpListFacet = QList<QList<float>>{ m_matrix->getListRow( 0 ),
                                             m_matrix->getListRow( 3 ),
                                             m_matrix->getListRow( 7 ),
                                             m_matrix->getListRow( 4 ) };

         cosOfSide = findAngleOfFacetAndPoint( lightColor, tmpListFacet, 1 );
         if ( isVisibleFacet( tmpListFacet ) )
              drawFacet( tmpListFacet, QList<float>{ 1 * cosOfSide, 1 * cosOfSide, 0 * cosOfSide } );

         // Проверяем пятую грань на видимость

         tmpListFacet = QList<QList<float>>{ m_matrix->getListRow( 2 ),
                                             m_matrix->getListRow( 3 ),
                                             m_matrix->getListRow( 7 ),
                                             m_matrix->getListRow( 6 ) };

         cosOfSide = findAngleOfFacetAndPoint( lightColor, tmpListFacet, 0 );
         if ( isVisibleFacet( tmpListFacet ) )
              drawFacet( tmpListFacet, QList<float>{ 0 * cosOfSide, 1 * cosOfSide, 1 * cosOfSide } );

         // Проверяем шестую грань на видимость

         tmpListFacet = QList<QList<float>>{ m_matrix->getListRow( 4 ),
                                             m_matrix->getListRow( 5 ),
                                             m_matrix->getListRow( 6 ),
                                             m_matrix->getListRow( 7 ) };

         cosOfSide = findAngleOfFacetAndPoint( lightColor, tmpListFacet, 0 );
         if ( isVisibleFacet( tmpListFacet ) )
             drawFacet( tmpListFacet, QList<float>{ 1 * cosOfSide, 0 * cosOfSide, 1 * cosOfSide } );
    }

    void Cube3D::rotateViaX(float angle)
    {
        MathLogic::Matrix matrixOX ( QList<QList<float>> {
                                                             { 1, 0, 0 },
                                                             { 0, qCos( angle ), qSin( angle ) },
                                                             { 0, -qSin( angle ), qCos( angle ) }
                                                         } );
        * m_matrix = ( * m_matrix ) * matrixOX;
    }

    void Cube3D::rotateViaY(float angle)
    {
        MathLogic::Matrix matrixOY ( QList<QList<float>> {
                                                             { qCos( angle ), 0, -qSin( angle ) },
                                                             { 0, 1, 0 },
                                                             { qSin( angle ), 0, qCos( angle ) }
                                                         } );
        * m_matrix = ( * m_matrix ) * matrixOY;
    }

    void Cube3D::rotateViaZ(float angle)
    {
        MathLogic::Matrix matrixOZ ( QList<QList<float>> {
                                                             { qCos( angle ), qSin( angle ), 0 },
                                                             { -qSin( angle ), qCos( angle ), 0 },
                                                             { 0, 0, 1 }
                                                         } );
        * m_matrix = ( * m_matrix ) * matrixOZ;
    }

    float Cube3D::findAngleOfFacetAndPoint(QList<float> point, QList<QList<float> > facet, bool reverseNormal )
    {
        QList<float> side1 { facet[0][0] - facet[1][0], facet[0][1] - facet[1][1], facet[0][2] - facet[1][2] };
        QList<float> side2 { facet[0][0] - facet[2][0], facet[0][1] - facet[2][1], facet[0][2] - facet[2][2] };

        QList<float> normalVector { side1[1] * side2[2] - side1[2] * side2[1],
                                    side1[2] * side2[0] - side1[0] * side2[2],
                                    side1[0] * side2[1] - side1[1] * side2[0] };

        // Заменить нули на центр куба, если нужно будет менять координаты куба
        QList<float> lightLine = QList<float>{ 0 - point[0], 0 - point[1], 0 - point[2] };

        float result = ( normalVector[0] * lightLine[0] + normalVector[1] * lightLine[1] + normalVector[2] * lightLine[2] )
                / ( sqrt( pow( normalVector[0], 2 ) + pow( normalVector[1], 2 ) + pow( normalVector[2], 2 ) )
                * sqrt( pow( lightLine[0], 2 ) + pow( lightLine[1], 2 ) + pow( lightLine[2], 2 ) ) );
        if ( reverseNormal )
            return ( result < 0 ? 0 : result ) > 1 ? 1 : -result;
        else
            return ( result < 0 ? 0 : result ) > 1 ? 1 : result;

    }

    void Cube3D::drawFacet( QList<QList<float> > pointOfFacet, QList<float> color )
    {
        glColor3f(color[0], color[1], color[2]);
            glBegin(GL_TRIANGLES);
            glVertex3f( pointOfFacet[0][0], pointOfFacet[0][1], pointOfFacet[0][2] );
            glVertex3f( pointOfFacet[1][0], pointOfFacet[1][1], pointOfFacet[1][2] );
            glVertex3f( pointOfFacet[2][0], pointOfFacet[2][1], pointOfFacet[2][2] );

            glVertex3f( pointOfFacet[0][0], pointOfFacet[0][1], pointOfFacet[0][2] );
            glVertex3f( pointOfFacet[3][0], pointOfFacet[3][1], pointOfFacet[3][2] );
            glVertex3f( pointOfFacet[2][0], pointOfFacet[2][1], pointOfFacet[2][2] );
        glEnd();
    }

    bool Cube3D::isVisibleFacet( QList<QList<float> > pointOfFacet )
    {
        if ( !invisiblePoints.contains( pointOfFacet[0] )
             && !invisiblePoints.contains( pointOfFacet[1] )
             && !invisiblePoints.contains( pointOfFacet[2] )
             && !invisiblePoints.contains( pointOfFacet[3] ) )
        {
            return true;
        }
        return false;
    }


    void Cube3D::checkPointsOnVision()
    {
        invisiblePoints.clear();
        QList<float> observationPoint{ 0, 0, 2 };
        invisiblePoints.append( QList<float>{ m_matrix->valueOf( 0, 0 ),
                                              m_matrix->valueOf( 0, 1 ),
                                              m_matrix->valueOf( 0, 2 ) } );
        for ( int i = 0; i < 8; ++i )
        {
            float len = GraphicTools::findLineLen3D( observationPoint, QList<float>{ m_matrix->valueOf( i, 0 ),
                                                                                     m_matrix->valueOf( i, 1 ),
                                                                                     m_matrix->valueOf( i, 2 )} );
            if ( len > GraphicTools::findLineLen3D( observationPoint, invisiblePoints[0] ) )
            {
                invisiblePoints.clear();
                invisiblePoints.append( QList<float>{ m_matrix->valueOf( i, 0 ),
                                                      m_matrix->valueOf( i, 1 ),
                                                      m_matrix->valueOf( i, 2 )} );
            }
            else if ( len == GraphicTools::findLineLen3D( observationPoint, invisiblePoints[0] ) )
            {
                invisiblePoints.append( QList<float>{ m_matrix->valueOf( i, 0 ),
                                                      m_matrix->valueOf( i, 1 ),
                                                      m_matrix->valueOf( i, 2 )} );
            }
            else
                continue;
        }
    }
}
