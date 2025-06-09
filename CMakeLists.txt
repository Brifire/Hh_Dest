cmake_minimum_required(VERSION 3.19)
project(Hh_Dest LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network Charts)

qt_standard_project_setup()

qt_add_executable(Hh_Dest
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Hh_Search/hh_search.h Hh_Search/hh_search.cpp
    Hh_Search/hh_pars.h Hh_Search/hh_pars.cpp
    Hh_Settings/settingsmanager.h Hh_Settings/settingsmanager.cpp

    Custom_Message_Box/custommessagebox.h Custom_Message_Box/custommessagebox.cpp
    Hh_Downloading_Menu/downloadingmenu.h Hh_Downloading_Menu/downloadingmenu.cpp Hh_Downloading_Menu/downloadingmenu.ui
    Hh_Pars_JSON/hhparsjson.h Hh_Pars_JSON/hhparsjson.cpp
    Hh_Data_Structures/datastructures.h Hh_Data_Structures/datastructures.cpp

    Hh_Search/downloadjsondata.h
    Hh_Search/downloadvacanciesid.h Hh_Search/downloadvacanciesid.cpp
    Tabs_Filler/tabskillsfiller.h Tabs_Filler/tabskillsfiller.cpp
    Tabs_Filler/abstracttabfiller.h
    Tabs_Filler/tabextendedskillsfiller.h Tabs_Filler/tabextendedskillsfiller.cpp
    Tabs_Filler/tabextendedmodel.h Tabs_Filler/tabextendedmodel.cpp
    Hh_Data_Structures/datainsert.h Hh_Data_Structures/datainsert.cpp
    Model_Data_Provider/abstractmodeldataprovider.h
    Model_Data_Provider/vacancydataprovider.h Model_Data_Provider/vacancydataprovider.cpp
    Model_Data_Provider/abstractprocessingstrategy.h
    Model_Data_Provider/abstactrowdata.h
    Model_Data_Provider/jobinfosecondtab.h Model_Data_Provider/jobinfosecondtab.cpp



)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Hh_Dest
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
        Qt6::Charts
)
find_package(Qt6 REQUIRED COMPONENTS Charts)

include(GNUInstallDirs)

install(TARGETS Hh_Dest
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Hh_Dest
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
add_compile_definitions(DEBUG_MACRO)
endif()
install(SCRIPT ${deploy_script})
