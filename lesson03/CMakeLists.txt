project(client_lesson03)
cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake ${CMAKE_MODULE_PATH})

find_package(UaOpenSSL)
find_package(UaLibXml2)

include(MessageUtils)
include(InstallPDBFiles)
include(InstallIfNewer)
include(ConfigureCompiler)
include(ConfigureUaStack)
include(ConfigureCppSdk)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

display_project_header()

####################################### Different Configurations ########################################

# Build with shared stack
if (BUILD_SHARED_STACK OR BUILD_SHARED_LIBS)
    add_definitions(-D_UA_STACK_USE_DLL)
endif ()

if (NOT UASTACK_SUPPORT_ENC_OBJ_EXTENSIONS)
    message(FATAL_ERROR "It is not allowed to to build the application without UASTACK_SUPPORT_ENC_OBJ_EXTENSIONS")
endif ()

# configure Dll/Lib
if (BUILD_SHARED_LIBS)
    add_definitions(-D_UA_BASE_USE_DLL)
    if (UASTACK_WITH_OPENSSL)
        add_definitions(-D_UA_PKI_USE_DLL)
    endif ()
    if (UASDK_WITH_XMLPARSER)
        add_definitions(-D_XML_PARSER_USE_DLL)
    endif ()
    add_definitions(-D_UA_CLIENT_USE_DLL)
endif ()

file(GLOB LESSON_03_H    "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

####################################### Include Paths ########################################

if (UASTACK_WITH_OPENSSL)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif ()
include_directories(${UASTACK_INCLUDE})
include_directories(${UABASE_INCLUDE})
include_directories(${UAPKI_INCLUDE})
include_directories(${UACLIENT_INCLUDE})

# LINKER PATHS
if (NOT TARGET uastack)
    link_directories(${UA_LIB_DIR})
endif ()

####################################### Different Platforms ########################################

####################################### Create executable ###################################

install_if_newer("${CMAKE_CURRENT_SOURCE_DIR}/../sampleconfig.ini" "${CMAKE_INSTALL_PREFIX}/bin/sampleconfig.ini")
list(APPEND LESSON_CONFIG ../sampleconfig.ini)
source_group("Config" FILES ${LESSON_CONFIG})

add_executable(${PROJECT_NAME} ${LESSON_03_H} ${LESSON_CONFIG}
    client_cpp_sdk_tutorial.cpp
    sampleclient.cpp
    samplesubscription.cpp
    configuration.cpp
    ../../utilities/shutdown.cpp
    )

####################################### Link Library ########################################

target_link_libraries(${PROJECT_NAME}
                      ${UACLIENT_LIBRARY}
                      ${UAPKI_LIBRARY}
                      ${UABASE_LIBRARY})
if (UASDK_WITH_XMLPARSER)
    target_link_libraries(${PROJECT_NAME} ${UAXML_LIBRARY})
endif ()
target_link_libraries(${PROJECT_NAME} ${UASTACK_LIBRARY})
if (UASDK_WITH_XMLPARSER)
    target_link_libraries(${PROJECT_NAME} ${LIBXML2_LIBRARIES})
endif ()
if (UASTACK_WITH_OPENSSL)
    target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES})
endif ()
target_link_libraries(${PROJECT_NAME} ${SYSTEM_LIBS})

####################################### configure debug postfix #############################

# configure debug postfix
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}" FOLDER Examples/ClientGettingStarted ${WCELINKERFLAGS})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

if (UASTACK_WITH_OPENSSL)
    install_openssl_crypto_library()
    if (UASTACK_WITH_HTTPS)
        install_openssl_ssl_library()
    endif ()
endif ()
if (UASDK_WITH_XMLPARSER)
    install_libxml2_library()
endif ()

install_pdb_files()

include(VSSetDebugConfig)
vs_set_debug_config(TARGET ${PROJECT_NAME}
                    INSTALL_DIR_EXECUTABLE
                    WORKING_DIR "${CMAKE_INSTALL_PREFIX}/bin")
