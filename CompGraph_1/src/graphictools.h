#pragma once

#include <QList>

//!
//! \brief The GraphicTools class Класс статических методов-инструментов
//!
class GraphicTools
{
public:
    //!
    //! \brief findLineLen3D Найти длину длину отрезка
    //! \param firstPoint Первая точка отрезка
    //! \param secondPoint Вторая точка отрезка
    //! \return Длина отрезка
    //!
    static float findLineLen3D( QList<float> firstPoint, QList<float> secondPoint );

private:
    //!
    //! \brief GraphicTools Приватный конструктор
    //!
    GraphicTools();
};
