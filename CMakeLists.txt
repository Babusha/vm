cmake_minimum_required(VERSION 2.8)
project(vm)
find_package( Boost 1.48 REQUIRED )
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )
SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
    SET (CMAKE_CXX_FLAGS                "-Wall")
    SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
    SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
    SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
    SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
     
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall -g -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable")
     
set(SRC_LIST    src/Assembler.cpp
                src/Assembler.hpp
                src/Bytecode.cpp
                src/Bytecode.hpp
                src/Byte.hpp
                src/Exceptions.hpp
                src/File.cpp
                src/File.hpp
                src/Main.cpp
                src/Stack.cpp
                src/Stack.hpp
                src/Machine.cpp
                src/Machine.hpp
                src/Registers.cpp
                src/Registers.hpp
                src/Hexdump.cpp
                src/Hexdump.hpp
                src/Opcodes.hpp
                src/Colors.hpp
                src/Heap.cpp
                src/Heap.hpp
                src/Object.cpp
                src/Object.hpp
                src/GarbageCollector.cpp
                src/GarbageCollector.hpp
                src/Assign.cpp
                src/Ctor.cpp
                src/Dynamic.cpp
                src/Iterator.cpp
                src/Relational.cpp
                src/Types.cpp
                src/dynamic/Dynamic.hpp
                src/dynamic/exception.hpp
                src/dynamic/var.hpp
                src/MachineCalls.cpp
                src/MachineCalls.hpp
)
     
add_executable(${PROJECT_NAME} ${SRC_LIST})

