cmake_minimum_required(VERSION 3.6)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
    main.cpp Parser.hpp LangVars.hpp Tokenizer.hpp Command.hpp Integer.hpp String.hpp cmds/Mov.hpp cmds/Define.hpp Variables.hpp cmds/Output.hpp CPPSource.hpp Goto.hpp cmds/Maths.hpp cmds/StringOps.hpp cmds/EqualsInt.hpp Gotos.hpp StringCheck.hpp cmds/EqualsString.hpp)

add_executable(ny6 ${SOURCE_FILES})