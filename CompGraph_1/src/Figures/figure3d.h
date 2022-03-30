#pragma once

#include <Matrix>
#include <QOpenGLWidget>

namespace Figures
{
    //!
    //! \brief The Figure3D class Базовый класс для трехмерных фигур
    //!
    class Figure3D
    {
    public:
        //!
        //! \brief Figure3D Конструктор
        //!
        explicit Figure3D();
        //!
        //! \brief draw Виртуальный метод, который определяют в себе дочерние классы
        //!
        virtual void draw();
        //!
        //! \brief rotateViaX Виртуальный метод поворота фигуры относительно оси X
        //! \param angle Угол
        //!
        virtual void rotateViaX( float angle );
        //!
        //! \brief rotateViaY Виртуальный метод поворота фигуры относительно оси Y
        //! \param angle Угол
        //!
        virtual void rotateViaY( float angle );
        //!
        //! \brief rotateViaZ Виртуальный метод поворота фигуры относительно оси Z
        //! \param angle Угол
        //!
        virtual void rotateViaZ( float angle );
        //!
        //! \brief m_matrix Матрица с координатами
        //!
        MathLogic::Matrix * m_matrix;
    };
}

