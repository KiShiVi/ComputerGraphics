QT       += core gui openglwidgets \
    widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Figures/coordinateaxes.cpp \
    src/Figures/figure2d.cpp \
    src/Figures/line2d.cpp \
    src/Figures/point2d.cpp \
    src/Figures/rectangle2d.cpp \
    src/main.cpp \
    src/mainform.cpp \
    src/matrix.cpp \
    src/openglform.cpp

HEADERS += \
    src/Figures/coordinateaxes.h \
    src/Figures/figure2d.h \
    src/Figures/line2d.h \
    src/Figures/point2d.h \
    src/Figures/rectangle2d.h \
    src/mainform.h \
    src/matrix.h \
    src/openglform.h

LIBS += -lglu32 -lopengl32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
