project(babel_client)
cmake_minimum_required(VERSION 3.9)
add_definitions("-fPIC")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
find_package (Threads)

ADD_DEFINITIONS(${QT_DEFINITIONS})

include_directories(
    client/include
    server/include
)

set(UIS
    src/mainwindow.ui
)

set(CSRCS
    client/src/main.cpp
    client/src/opus.cpp
    client/src/port_audio.cpp
    client/src/tcpNetwork.cpp
    client/src/udpNetwork.cpp
    client/src/protocol.cpp
    client/src/mainwindow.cpp
    client/include/mainwindow.h
    client/include/udpNetwork.hpp
)

set(SSRCS
    server/src/main.cpp
    server/src/commande.cpp
    server/src/contacts.cpp
    server/src/instruction.cpp
    server/src/connection.cpp
    server/src/session.cpp
    server/src/server.cpp
)

include_directories(${CMAKE_INCLUDE_PATH})
add_executable(babel_client ${CSRCS})
add_executable(babel_server ${SSRCS})
target_link_libraries(babel_client PUBLIC ${CONAN_LIBS} Qt5::Core Qt5::Network Qt5::Widgets ${CMAKE_THREAD_LIBS_INIT})
set_target_properties(babel_client PROPERTIES AUTOMOC TRUE)
target_link_libraries(babel_server ${CONAN_LIBS} ${CMAKE_THREAD_LIBS_INIT})
