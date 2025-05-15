cmake_minimum_required(VERSION 3.16)

project(gestao VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

set(PROJECT_HEADERS
    src/ui/GraphNode.h
    src/ui/GraphView.h
    src/ui/window.h
    src/ui/mainwindow.ui
    src/ui/mainwindow.h
)

set(PROJECT_SOURCES
    src/ui/GraphNode.cpp
    src/ui/GraphView.cpp
    src/ui/mainwindow.cpp
    src/ui/window.cpp
)

qt_add_executable(gestao
    src/main.cpp
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)
target_link_libraries(gestao PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(gestao PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS gestao
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
