QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airport.cpp \
    circle.cpp \
    continent.cpp \
    controller.cpp \
    controllermenu.cpp \
    country.cpp \
    customitem.cpp \
    disease.cpp \
    diseasebar.cpp \
    infobar.cpp \
    main.cpp \
    mainwindow.cpp \
    menubar.cpp \
    myrectangle.cpp \
    mytext.cpp \
    picture.cpp \
    plague.cpp \
    plane.cpp \
    progress.cpp \
    rebuild.cpp \
    update.cpp \
    view.cpp \
    viewmenu.cpp

HEADERS += \
    airport.h \
    circle.h \
    continent.h \
    controller.h \
    controllermenu.h \
    country.h \
    customitem.h \
    disease.h \
    diseasebar.h \
    infobar.h \
    mainwindow.h \
    menubar.h \
    myrectangle.h \
    mytext.h \
    picture.h \
    plague.h \
    plane.h \
    progress.h \
    rebuild.h \
    update.h \
    view.h \
    viewmenu.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    countries.qrc \
    diseases.qrc \
    icons.qrc \
    json.qrc
