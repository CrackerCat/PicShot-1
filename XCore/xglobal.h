//
// Created by xmuli on 2021/9/24.
//

#ifndef PICSHOT_XGLOBAL_H
#define PICSHOT_XGLOBAL_H

#include <QtGlobal>
//#include <QtCore/QtGlobal>

#if defined(XCORE_LIBRARY)
    #define XCORE_EXPORT Q_DECL_EXPORT
#else
    #define XCORE_EXPORT Q_DECL_IMPORT
#endif

#endif //PICSHOT_XGLOBAL_H
