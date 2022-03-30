#pragma once

#include "figure3d.h"
#include "point3d.h"
#include "line3d.h"

#include <Matrix>
#include <QtMath>

namespace Figures
{
    //!
    //! \brief The BilinearPlane3D class Класс плоскости
    //!
    class BilinearPlane3D : public Figures::Figure3D
    {
    public:
        //!
        //! \brief BilinearPlane3D Конструктор по умолчанию
        //!
        BilinearPlane3D();
        //!
        //! \brief BilinearPlane3D Конструктор с параметрами
        //! \param listOfPoint Матрица конечных точек плоскости
        //!
        BilinearPlane3D( QList<QList<float> > listOfPoint );
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
        //! \brief lerp Метод вычисления точки на отрезке в пропорции t
        //! \param point1 Начальная точка отрезка
        //! \param point2 Конечная точка отрезка
        //! \param t Пропорция (0.00; 1.00)
        //! \return Тройка (x, y, z)
        //!
        QList<float> lerp( QList<float> point1, QList<float> point2, float t);
    };
}
