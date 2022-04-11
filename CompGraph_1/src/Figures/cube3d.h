#pragma once

#include "figure3d.h"
#include "../graphictools.h"

namespace Figures
{
    //!
    //! \brief The Cube3D class Класс куба
    //!
    class Cube3D : public Figures::Figure3D
    {
    public:
        //!
        //! \brief Cube3D Конструктор по умолчанию
        //!
        Cube3D();
        //!
        //! \brief Cube3D Конструктор с параметрами
        //! \param coords Начальная и конечная точки куба
        //!
        Cube3D( QPair<QList<float>, QList<float>> coords);
        //!
        //! \brief draw Метод отрисовки фигуры
        //!
        void draw() override;
        //!
        //! \brief rotateViaX Поврот плоскости относительно оси X
        //! \param angle Угол
        //!
        void rotateViaX( float angle ) override;
        //!
        //! \brief rotateViaY Поврот плоскости относительно оси Y
        //! \param angle Угол
        //!
        void rotateViaY( float angle ) override;
        //!
        //! \brief rotateViaZ Поврот плоскости относительно оси Z
        //! \param angle Угол
        //!
        void rotateViaZ( float angle ) override;
    private:
        //!
        //! \brief findAngleOfFacetAndPoint Поиск угла между плоскостью и точкой (вектором от точки до куба)
        //! \param point Точка
        //! \param facet Плоскость
        //! \param reverseNormal Реверс результа (нормали некоторых плоскостей инвертируются)
        //! \return Косинус угла
        //!
        float findAngleOfFacetAndPoint( QList<float> point, QList<QList<float>> facet, bool reverseNormal );
        //!
        //! \brief drawFacet Нарисовать грань
        //! \param pointOfFacet Координаты грани
        //! \param color Цвет
        //!
        void drawFacet( QList<QList<float>> pointOfFacet, QList<float> color );
        //!
        //! \brief isVisibleFacet Метод, определяющий видимость грани
        //! \param pointOfFacet Координаты грани
        //! \return true - если грань видна; false - если нет
        //!
        bool isVisibleFacet( QList<QList<float>> pointOfFacet );
        //!
        //! \brief checkPointsOnVision Метод, определяющий видимость вершин
        //!
        void checkPointsOnVision();
        //!
        //! \brief invisiblePoints Список невидимых вершин
        //!
        QList<QList<float>> invisiblePoints;
    };
}
