#pragma once

#include <FiguresLib>
#include <Matrix>
#include <QList>
#include <QPair>

#include <QOpenGLWidget>

//!
//! \brief The OpenGLForm class Форма OpenGL для отрисовки объектов
//!
class OpenGLForm2D : public QOpenGLWidget
{
    Q_OBJECT

public:
    //!
    //! \brief OpenGLForm Конструктор
    //! \param parent Родительский виджет
    //!
    OpenGLForm2D( QWidget * parent = nullptr );
    //!
    //! \brief clearAll Очистить поле, включая координатные оси
    //!
    void clearAll();
    //!
    //! \brief clear Очистить поле, кроме координатных осей
    //!
    void clear();
    //!
    //! \brief getByIndex Возвращает ссылку на фигуру по её индексу в figures
    //! \param index Индекс
    //! \return Ссылка на фигуру
    //!
    Figures::Figure2D & getByIndex( const int index );
    //!
    //! \brief size Возвращает кол-во активных фигур
    //! \return Кол-во фигур
    //!
    int size();

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
    void addFigure( Figures::Figure2D * figure );
    //!
    //! \brief changeFigureScale Слот для смены масштаба фигуры
    //! \param figure Ссылка на фигуру
    //! \param scale Новый масштаб
    //!
    void changeFigureScale( Figures::Figure2D & figure, float scale );

private:
    //!
    //! \brief figures Контейнер для хранения всех фигур на форме
    //!
    QVector<Figures::Figure2D * > figures;
}; // OpenGLForm
