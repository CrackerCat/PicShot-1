set(LIB_SHARE_NAME "XCore")

set(SYSINFO_FILES
        XSysInfo.h
        XSysInfo.cpp)

add_library(${LIB_SHARE_NAME} SHARED ${SYSINFO_FILES})