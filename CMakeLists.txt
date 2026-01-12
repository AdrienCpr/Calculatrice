cmake_minimum_required(VERSION 3.16)

project(ProjetCalculatriceIHM VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Charts)

set(TS_FILES ProjetCalculatriceIHM_fr_FR.ts)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        include/mainwindow.h
        src/mainwindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProjetCalculatriceIHM
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/Addition.cpp src/Constante.cpp src/Division.cpp src/Expression.cpp src/Multiplication.cpp src/OperateurBinaire.cpp src/Soustraction.cpp src/TableDesSymboles.cpp src/Variable.cpp
        include/Addition.h include/Constante.h include/Division.h include/Expression.h include/Multiplication.h include/OperateurBinaire.h include/Soustraction.h include/TableDesSymboles.h include/Variable.h
        include/OperateurUnaire.h include/OperateurUnaire.h
        src/OperateurUnaire.cpp
        include/Carre.h
        src/Carre.cpp
        include/Oppose.h
        include/RacineCarree.h
        include/Inverse.h
        include/ValeurAbsolue.h
        include/LogNeperien.h
        src/Oppose.cpp
        src/RacineCarree.cpp
        src/Inverse.cpp
        src/ValeurAbsolue.cpp
        src/LogNeperien.cpp
        include/Puissance.h
        src/Puissance.cpp
        include/ExpressionManager.h
        include/TestsRunner.h
        src/TestsRunner.cpp
        include/expressionmodel.h
        include/graph2ddialog.h
        src/graph2ddialog.cpp
        include/expressionModel.h
        include/expressionModel.h
        include/ExpressionModel.h
        include/ExpressionModel.h
        include/graph2DDialog.h
        include/Graph2dDialog.h
        src/Graph2dDialog.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ProjetCalculatriceIHM APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(ProjetCalculatriceIHM SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ProjetCalculatriceIHM
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(ProjetCalculatriceIHM PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Charts
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ProjetCalculatriceIHM)
endif()
set_target_properties(ProjetCalculatriceIHM PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
# Les applis. WIN32 n'ont pas accés au terminal. Commenter la ligne suivante permet d'avoir la sortie standard c++ (cout) dans le terminal.
#    WIN32_EXECUTABLE TRUE
)

include_directories(include)

include(GNUInstallDirs)
install(TARGETS ProjetCalculatriceIHM
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ProjetCalculatriceIHM)
endif()
