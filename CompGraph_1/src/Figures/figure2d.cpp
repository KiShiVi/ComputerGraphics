#include "figure2d.h"

namespace Figures
{
    Figure2D::Figure2D()
    {

    }

    void Figure2D::draw()
    {
        throw std::invalid_argument( "Draw method not overridden" );
    }

    QPair<float, float> Figure2D::getCenter()
    {
        throw std::invalid_argument( "getCenter method not overridden" );
    }

    void Figure2D::scaling(float scaleValue)
    {
        MathLogic::Matrix scaleMatrix( m_matrix->getDimension().second, m_matrix->getDimension().second );
        for (int i = 0; i < m_matrix->getDimension().second; ++i)
            scaleMatrix.valueOf( i, i ) = scaleValue;

        QPair<float, float> offCenter( getCenter() );

        MathLogic::Matrix normalizingMatrix( m_matrix->getDimension().first, m_matrix->getDimension().second );
        for (int i = 0; i < m_matrix->getDimension().first; ++i)
        {
            normalizingMatrix.valueOf( i, 0 ) = offCenter.first;
            normalizingMatrix.valueOf( i, 1 ) = offCenter.second;
        }
        * m_matrix = * m_matrix - normalizingMatrix;
        * m_matrix = * m_matrix * scaleMatrix;
        * m_matrix = * m_matrix + normalizingMatrix;
    }
}
