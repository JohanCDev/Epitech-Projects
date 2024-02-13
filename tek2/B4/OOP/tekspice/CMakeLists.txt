cmake_minimum_required (VERSION 3.12)
project(NANOTEKSPICE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

function (set_flags target)
    #Set C++11
    target_compile_features(${target}
        PUBLIC
        cxx_std_11
    )
    set_target_properties(${target}
        PROPERTIES
        CXX_EXTENSIONS OFF
    )

    #Set flags
    if(MSVC)
        target_compile_options(${target}
            PRIVATE
            /W4
            #/WX
        )
    else()
        target_compile_options(${target}
            PRIVATE
            -Wall
            -Wextra
            -pedantic
            -Wshadow
            -Wpointer-arith
            -g
            -Og
        )
    endif()
endfunction(set_flags)

#Directories
set(SRCROOT ${PROJECT_SOURCE_DIR}/sources)
set(CIRCUITROOT ${SRCROOT}/Circuit)
set(COMPONENTROOT ${SRCROOT}/Component)
set(BASICROOT ${COMPONENTROOT}/Basic)
set(FACTORYROOT ${SRCROOT}/Factory)
set(PARSERROOT ${SRCROOT}/Parser)
set(PARSERERRORROOT ${PARSERROOT}/Error)
set(CIRCUITROOT ${SRCROOT}/Circuit)
set(LOOPROOT ${SRCROOT}/Loop)
set(COMPOROOT ${SRCROOT}/Component)
set(GATESROOT ${COMPOROOT}/Gates)
set(BASECOMPOROOT ${COMPOROOT}/Base)
set(SPECCOMPOROOT ${COMPOROOT}/Specific)

include_directories(
    ${CIRCUITROOT}
    ${COMPOROOT}
    ${BASECOMPOROOT}
    ${GATESROOT}
    ${PARSERROTT}
    ${PARSERERRORROOT}
    ${LOOPROOT}
    ${FACTORYROOT}
)

# Root Directory
set(SRC
    ${CIRCUITROOT}/Circuit.cpp
    ${COMPONENTROOT}/AComponent.cpp
	${SRCROOT}/main.cpp
    ${PARSERROOT}/AParser.cpp
    ${PARSERROOT}/AParser.hpp
    ${PARSERROOT}/IParser.hpp
    ${PARSERROOT}/NTSParser.cpp
    ${PARSERROOT}/NTSParser.hpp
    ${PARSERERRORROOT}/NTSError.hpp
    ${PARSERERRORROOT}/ParserError.hpp
    ${FACTORYROOT}/Factory.cpp
    ${CIRCUITROOT}/Circuit.cpp
    ${CIRCUITROOT}/Circuit.hpp
    ${LOOPROOT}/Loop.cpp
    ${COMPOROOT}/AComponent.cpp
    ${COMPOROOT}/AComponent.hpp
    ${COMPOROOT}/IComponent.hpp
    ${COMPOROOT}/ComponentList.hpp
    ${BASECOMPOROOT}/Input.cpp
    ${BASECOMPOROOT}/Input.hpp
    ${BASECOMPOROOT}/Output.cpp
    ${BASECOMPOROOT}/Output.hpp
    ${BASECOMPOROOT}/TruePin.cpp
    ${BASECOMPOROOT}/TruePin.hpp
    ${BASECOMPOROOT}/FalsePin.cpp
    ${BASECOMPOROOT}/FalsePin.hpp
    ${BASECOMPOROOT}/Electrical.cpp
    ${BASECOMPOROOT}/Electrical.cpp
    ${GATESROOT}/AndGates.cpp
    ${GATESROOT}/AndGates.hpp
    ${GATESROOT}/NorGates.cpp
    ${GATESROOT}/NorGates.hpp
    ${GATESROOT}/NandGates.cpp
    ${GATESROOT}/NandGates.hpp
    ${GATESROOT}/XorGates.cpp
    ${GATESROOT}/XorGates.hpp
    ${GATESROOT}/OrGates.cpp
    ${GATESROOT}/OrGates.hpp
    ${GATESROOT}/InverterGates.cpp
    ${GATESROOT}/InverterGates.hpp
    ${SPECCOMPOROOT}/component4001.cpp
    ${SPECCOMPOROOT}/component4001.hpp
    ${SPECCOMPOROOT}/component4011.cpp
    ${SPECCOMPOROOT}/component4011.hpp
    ${SPECCOMPOROOT}/component4030.cpp
    ${SPECCOMPOROOT}/component4030.hpp
    ${SPECCOMPOROOT}/component4071.cpp
    ${SPECCOMPOROOT}/component4071.hpp
    ${SPECCOMPOROOT}/component4081.cpp
    ${SPECCOMPOROOT}/component4081.hpp
    ${SPECCOMPOROOT}/component4069.cpp
    ${SPECCOMPOROOT}/component4069.hpp
)

add_executable (nanotekspice ${SRC})
set_flags(nanotekspice )

install(TARGETS nanotekspice
    RUNTIME
    DESTINATION ${PROJECT_INSTALL_DIR})
