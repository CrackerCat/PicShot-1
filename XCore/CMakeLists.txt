set(LIB_SHARE_NAME "XCore")

add_compile_definitions(XCORE_LIBRARY)    # 定义导入导出宏 xglobal.h

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(XCORE_FILES
        xglobal.h
        XSysInfo.h
        XSysInfo.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) # 更改库输出路径

add_library(${LIB_SHARE_NAME} SHARED ${XCORE_FILES})
#add_library(${LIB_SHARE_NAME}_static STATIC ${XCORE_FILES}) # 为生成同名称的动态库，但引用Qt动态库，故暂屏蔽
#set_target_properties(${LIB_SHARE_NAME}_static PROPERTIES OUTPUT_NAME ${LIB_SHARE_NAME})
#get_target_property(OUTPUT_VALUE ${LIB_SHARE_NAME}_static OUTPUT_NAME)
#MESSAGE(STATUS “This is the hello_static OUTPUT_NAME:”${OUTPUT_VALUE})

target_link_libraries(${LIB_SHARE_NAME}
        Qt5::Core       # 尝试 PUBLIC 达到共享传递库？
        Qt5::Gui
        Qt5::Widgets)