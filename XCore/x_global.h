//
// Created by xmuli on 2021/9/25.
//

#ifndef PICSHOT_X_GLOBAL_H
#define PICSHOT_X_GLOBAL_H

#include <QtGlobal>

#if defined(XCORE_LIBRARY)
#   define XCORE_EXPORT Q_DECL_EXPORT
#else
#   define XCORE_EXPORT Q_DECL_IMPORT
#endif

#endif //PICSHOT_X_GLOBAL_H
