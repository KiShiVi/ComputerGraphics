#pragma once

#include <OpenGLFormLib>
#include <FiguresLib>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>

//!
//! \brief The MainForm class Основная форма приложения первой лабораторной работы
//!
class MainForm : public QWidget
{
    Q_OBJECT
public:
    //!
    //! \brief MainForm Конструктор
    //! \param parent Родительский виджет
    //!
    explicit MainForm ( QWidget * parent = nullptr );

signals:
    //!
    //! \brief clearSignal Сигнал, испускаемый для очистки поля (кроме координатных осей)
    //!
    void clearSignal();
    //!
    //! \brief addFigureSignal Сигнал, испускаемый для добавления новой фигуры (прямоугольника)
    //! \param figure Ссылка на новую фигуру
    //!
    void addFigureSignal( Figures::Figure2D * figure );
    //!
    //! \brief changeFigureScaleSignal Сигнал, испускаемый для изменения масштаба текущей фигуры
    //! \param figure Фигура
    //! \param scale Новый масштаб
    //!
    void changeFigureScaleSignal( Figures::Figure2D & figure, float scale );

private:
    //!
    //! \brief initGui Инициализация пользовательского интерфейса
    //!
    void initGui();

private slots:
    //!
    //! \brief onClearButtonClicked Обработка нажатия кнопки "Очистить"
    //!
    void onClearButtonClicked();
    //!
    //! \brief onAddFigureButtonClicked Обработка нажатия кнопки "Добавить прямоугольник"
    //!
    void onAddFigureButtonClicked();
    //!
    //! \brief onChangeFigureScaleButtonClicked Обработка нажатия кнопки "Изменить размер"
    //!
    void onChangeFigureScaleButtonClicked();

private:
    QLineEdit * x1_le;              //!< Ссылка на QLineEdit координаты X первой точки прямоугольника
    QLineEdit * x2_le;              //!< Ссылка на QLineEdit координаты Y первой точки прямоугольника
    QLineEdit * y1_le;              //!< Ссылка на QLineEdit координаты X второй точки прямоугольника
    QLineEdit * y2_le;              //!< Ссылка на QLineEdit координаты Y второй точки прямоугольника
    QLineEdit * n_le;               //!< Ссылка на QLineEdit номера изменяемой фигуры
    QLineEdit * scale_le;           //!< Ссылка на QLineEdit нового масштаба фигуры
    OpenGLForm  * openGlWidget;     //!< Ссылка на форму OpenGL
}; // MainForm
