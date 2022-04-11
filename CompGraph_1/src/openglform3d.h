#pragma once

#include <FiguresLib>
#include <Matrix>
#include <QList>
#include <QPair>

#include <QOpenGLWidget>

//!
//! \brief The OpenGLForm3D class Форма OpenGL для отрисовки трехмерных объектов
//!
class OpenGLForm3D : public QOpenGLWidget
{
    Q_OBJECT
public:
    //!
    //! \brief OpenGLForm3D Конструктор
    //! \param parent Родительский виджет
    //!
    OpenGLForm3D( QWidget * parent = nullptr );
    //!
    //! \brief clearAll Очистить поле, включая координатные оси
    //!
    void clearAll();
    //!
    //! \brief clear Очистить поле, кроме координатных осей
    //!
    void clear();

private:
    //!
    //! \brief initializeGL Перегрузка встроенного метода OpenGL для инициализации формы
    //!
    void initializeGL() override;
    //!
    //! \brief resizeGL Перегрузка встроенного метода OpenGL для смены размеров виджета
    //! \param w Ширини
    //! \param h Высота
    //!
    void resizeGL( int w, int h ) override;
    //!
    //! \brief paintGL Перегрузка встроенного метода OpenGL для отрисовки объектов на форме
    //!
    void paintGL() override;
    //!
    //! \brief draw Прорисовка объектов
    //!
    void draw();

public slots:
    //!
    //! \brief onClear Слот для очищения формы
    //!
    void onClear();
    //!
    //! \brief addFigure Слот для добавления новой фигуры
    //! \param figure Ссылка на новую фигуру
    //!
    void addFigure( Figures::Figure3D * figure );
    //!
    //! \brief setCoords Установка координат фигуры
    //! \param coords Координаты
    //! \param figure Ссылка на фигуру
    //!
    void setCoords( QList<QList<float>> coords, Figures::Figure3D * figure = nullptr );
    //!
    //! \brief rotateViaOX Поворот фигуры относительно оси X
    //! \param angle Угол
    //! \param figure Фигура
    //!
    void rotateViaOX( float angle, Figures::Figure3D * figure = nullptr );
    //!
    //! \brief rotateViaOY Поворот фигуры относительно оси Y
    //! \param angle Угол
    //! \param figure Фигура
    //!
    void rotateViaOY( float angle, Figures::Figure3D * figure = nullptr );
    //!
    //! \brief rotateViaOZ Поворот фигуры относительно оси Z
    //! \param angle Угол
    //! \param figure Фигура
    //!
    void rotateViaOZ( float angle, Figures::Figure3D * figure = nullptr );

private:
    //!
    //! \brief figures Контейнер для хранения всех фигур на форме
    //!
    QVector<Figures::Figure3D * > figures;
    Figures::Point3D * lightPoint;
};
