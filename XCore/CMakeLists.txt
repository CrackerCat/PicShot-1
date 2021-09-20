set(LIB_SHARE_NAME "XCore")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(XCORE_FILES
        XSysInfo.h
        XSysInfo.cpp)

add_library(${LIB_SHARE_NAME} SHARED ${XCORE_FILES})

target_link_libraries(${LIB_SHARE_NAME}
        Qt5::Core       # 尝试 PUBLIC 达到共享传递库？
        Qt5::Gui
        Qt5::Widgets)