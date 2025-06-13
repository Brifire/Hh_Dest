include("/home/art/Hh_Dest/build/Desktop_Qt_6_9_0-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Hh_Dest-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/art/Hh_Dest/build/Desktop_Qt_6_9_0-Debug/Hh_Dest
    GENERATE_QT_CONF
)
