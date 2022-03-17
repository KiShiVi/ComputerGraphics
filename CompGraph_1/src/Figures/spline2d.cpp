#include "spline2d.h"

namespace Figures {
    Spline2D::Spline2D()
    {
        m_matrix = new MathLogic::Matrix( QVector<QVector<float> > { { 0, 0 } } );
    }

    Spline2D::Spline2D( QList<QPair<float, float> > listOfPoint )
    {
        m_matrix = new MathLogic::Matrix( listOfPoint.size(), 2 );
        for ( int i = 0; i < listOfPoint.size(); ++i )
        {
            m_matrix->valueOf( i, 0 ) = listOfPoint[i].first;
            m_matrix->valueOf( i, 1 ) = listOfPoint[i].second;
        }
    }

    QPair<float, float> Spline2D::lerp( QPair<float, float> point1, QPair<float, float> point2, float t )
    {
        return QPair<float, float>( ( point2.first - point1.first ) * t + point1.first,
                                    ( point2.second - point1.second ) * t + point1.second );
    }

    QList<QPair<float, float> > Spline2D::findNewBeziersLayer( QList<QPair<float, float> > list, float t )
    {
        QList<QPair<float, float> > resultList;
        for ( int i = 1; i < list.size(); ++i )
        {
            resultList.append( lerp( list[i - 1], list[i], t ) );
        }
        return resultList;
    }

    void Spline2D::draw()
    {
        if ( m_matrix->getDimension().first <= 1 )
            return;
        else
        {
            QList<QPair<float, float> > beziersList;
            for ( int i = 0; i < m_matrix->getDimension().first; ++i )
            {
                beziersList.append( QPair<float, float>( m_matrix->valueOf( i, 0 ), m_matrix->valueOf( i, 1 ) ) );

                Figures::Point2D p( m_matrix->valueOf( i, 0 ), m_matrix->valueOf( i, 1 ) );
                p.draw();
            }


            // Здесь крутим t, чтобы прорисовывать кривую дальше и дальше
            glBegin(GL_LINE_STRIP);
            for ( int t = 1; t < COUNT_OF_LINES_IN_SPLINE_FRAGMENT; ++t )
            {
                QList<QPair<float, float> > tmpBeziersList = beziersList;
                // А здесь крутимся столько раз - какая степень у кривой - 1, вычисляя новые слои
                for ( int i = 0; i < m_matrix->getDimension().first - 1; ++i )
                {
                    tmpBeziersList = findNewBeziersLayer( tmpBeziersList, (float)t / COUNT_OF_LINES_IN_SPLINE_FRAGMENT );
                }
                glColor3f( 0, 0, 0 ); glVertex2f( tmpBeziersList[0].first, tmpBeziersList[0].second );
            }
            glEnd();
        }
    }
}
