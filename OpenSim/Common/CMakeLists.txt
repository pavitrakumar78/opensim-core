
file(GLOB INCLUDES *.h gcvspl.h)
file(GLOB SOURCES *.cpp gcvspl.c)

if(NOT WITH_BTK)
    file(GLOB C3D_HEADER *C3DFileAdapter.h)
    file(GLOB C3D_SOURCE *C3DFileAdapter.cpp)
    list(REMOVE_ITEM INCLUDES ${C3D_HEADER})
    list(REMOVE_ITEM SOURCES  ${C3D_SOURCE})
    unset(BTK_LIBRARIES)
endif()

OpenSimAddLibrary(
    KIT Common
    AUTHORS "Clay_Anderson-Ayman_Habib-Peter_Loan"
    # Clients of osimCommon need not link to BTK.
    LINKLIBS PUBLIC ${Simbody_LIBRARIES} PRIVATE ${BTK_LIBRARIES}
    INCLUDES ${INCLUDES}
    SOURCES ${SOURCES}
    TESTDIRS "Test"
    )

if(WIN32)
    add_dependencies(osimCommon Simbody_CONFIG_check)
endif()
  
