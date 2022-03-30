QT       += core gui openglwidgets \
    widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Figures/bilinearplane3d.cpp \
    src/Figures/coordinateaxes.cpp \
    src/Figures/figure2d.cpp \
    src/Figures/figure3d.cpp \
    src/Figures/line2d.cpp \
    src/Figures/line3d.cpp \
    src/Figures/point2d.cpp \
    src/Figures/point3d.cpp \
    src/Figures/rectangle2d.cpp \
    src/Figures/spline2d.cpp \
    src/main.cpp \
    src/mainform.cpp \
    src/mainform2.cpp \
    src/mainform3.cpp \
    src/matrix.cpp \
    src/openglform2d.cpp \
    src/openglform3d.cpp

HEADERS += \
    src/Figures/bilinearplane3d.h \
    src/Figures/coordinateaxes.h \
    src/Figures/figure2d.h \
    src/Figures/figure3d.h \
    src/Figures/line2d.h \
    src/Figures/line3d.h \
    src/Figures/point2d.h \
    src/Figures/point3d.h \
    src/Figures/rectangle2d.h \
    src/Figures/spline2d.h \
    src/mainform.h \
    src/mainform2.h \
    src/mainform3.h \
    src/matrix.h \
    src/openglform2d.h \
    src/openglform3d.h

LIBS += -lglu32 -lopengl32

INCLUDEPATH += $$PWD/../includes

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
