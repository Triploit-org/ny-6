cmake_minimum_required(VERSION 3.6)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
    main.cpp objects/Parser.hpp LangVars.hpp objects/Tokenizer.hpp objects/Command.hpp objects/Integer.hpp objects/String.hpp cmds/Mov.hpp cmds/Define.hpp Variables.hpp cmds/Output.hpp CPPSource.hpp objects/Goto.hpp cmds/Maths.hpp cmds/StringOps.hpp cmds/EqualsInt.hpp Gotos.hpp StringCheck.hpp cmds/EqualsString.hpp cmds/Input.hpp cmds/IfDefInc.hpp PraeVars.hpp objects/PVariable.hpp objects/Scope.hpp Error.hpp objects/RealGoto.h cmds/FileSystem.h)

add_executable(ny6 ${SOURCE_FILES})