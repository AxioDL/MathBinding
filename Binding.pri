INCLUDEPATH += $$PWD

!contains(DEFINS, ZE_MATH_BINDING):DEFINES += ZE_MATH_BINDING

HEADERS += \
    $$PWD/GenericVectorOperations.hpp \
    $$PWD/ASVector.hpp

SOURCES += \
    $$PWD/ASVector.cpp
