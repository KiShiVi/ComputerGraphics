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
//! \brief The MainForm2 class Основная форма приложения второй лабораторной работы
//!
class MainForm2 : public QWidget
{
    Q_OBJECT
public:
    //!
    //! \brief MainForm2 Конструктор
    //! \param parent Родительский виджет
    //!
    explicit MainForm2( QWidget * parent = nullptr );

signals:
    //!
    //! \brief draw Сигнал, который отсылается в OpenGLForm для отрисовки кривой
    //! \param figure Кривая Безье
    //!
    void draw( Figures::Figure2D * figure );

private:
    //!
    //! \brief initGui Инициализация GUI
    //!
    void initGui();

private slots:
    //!
    //! \brief onDrawClicked Слот для обработки нажатия на кнопку "Принять"
    //!
    void onDrawClicked();
    //!
    //! \brief onPlusClicked Слот для обработки нажатия на кнопку "+"
    //!
    void onPlusClicked();
    //!
    //! \brief onMinusClicked Слот для обработки нажатия на кнопку "-"
    //!
    void onMinusClicked();

private:
    //!
    //! \brief listOfPoints Список на QLineEdit каждой из точек на форме
    //!
    QList<QPair<QLineEdit *, QLineEdit *>> listOfPoints;
    //!
    //! \brief openGlWidget Указатель на OpenGL форму
    //!
    OpenGLForm  * openGlWidget;
    //!
    //! \brief inWidgets Указатель на слой с QLineEdit (для изменения при увелечении/уменьшении кол-ва полей)
    //!
    QVBoxLayout * inWidgets;

};

