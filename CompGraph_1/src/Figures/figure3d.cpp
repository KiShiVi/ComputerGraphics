#include "figure3d.h"

namespace Figures
{
    Figure3D::Figure3D()
    {

    }
    void Figure3D::draw()
    {
        throw std::invalid_argument( "Draw method not overridden" );
    }

    void Figure3D::rotateViaX( float angle )
    {
        Q_UNUSED( angle );
        throw std::invalid_argument( "rotateViaX method not overridden" );
    }

    void Figure3D::rotateViaY( float angle )
    {
        Q_UNUSED( angle );
        throw std::invalid_argument( "rotateViaY method not overridden" );
    }

    void Figure3D::rotateViaZ( float angle )
    {
        Q_UNUSED( angle );
        throw std::invalid_argument( "rotateViaZ method not overridden" );
    }
}
