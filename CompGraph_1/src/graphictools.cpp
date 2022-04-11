#include "graphictools.h"

float GraphicTools::findLineLen3D( QList<float> p1, QList<float> p2 )
{
    return sqrt( pow( p1[0] - p2[0], 2) + pow( p1[1] - p2[1], 2) + pow( p1[2] - p2[2], 2) );
}

GraphicTools::GraphicTools()
{

}
