QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    client_room.cpp \
    computer.cpp \
    computer_four.cpp \
    computer_six.cpp \
    computer_three.cpp \
    computer_two.cpp \
    four.cpp \
    game_four.cpp \
    game_six.cpp \
    game_three.cpp \
    game_two.cpp \
    lianji_one.cpp \
    lianjie_two.cpp \
    liuren.cpp \
    main.cpp \
    mainwindow.cpp \
    networkdata.cpp \
    networkserver.cpp \
    networksocket.cpp \
    one.cpp \
    pawn.cpp \
    ranklist.cpp \
    sanren.cpp \
    serve.cpp \
    siren.cpp \
    three.cpp \
    two.cpp

HEADERS += \
    client.h \
    client_room.h \
    computer.h \
    computer_four.h \
    computer_six.h \
    computer_three.h \
    computer_two.h \
    four.h \
    game_four.h \
    game_six.h \
    game_three.h \
    game_two.h \
    lianji_one.h \
    lianjie_two.h \
    liuren.h \
    mainwindow.h \
    networkdata.h \
    networkserver.h \
    networksocket.h \
    one.h \
    pawn.h \
    ranklist.h \
    sanren.h \
    serve.h \
    siren.h \
    three.h \
    two.h

FORMS += \
    client.ui \
    client_room.ui \
    computer.ui \
    computer_four.ui \
    computer_six.ui \
    computer_three.ui \
    computer_two.ui \
    four.ui \
    game_four.ui \
    game_six.ui \
    game_three.ui \
    game_two.ui \
    lianji_one.ui \
    lianjie_two.ui \
    liuren.ui \
    mainwindow.ui \
    one.ui \
    ranklist.ui \
    sanren.ui \
    serve.ui \
    siren.ui \
    three.ui \
    two.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc
