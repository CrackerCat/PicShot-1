//
// Created by xmuli on 2021/9/21.
//

#ifndef PICSHOT_XSYSINFO_H
#define PICSHOT_XSYSINFO_H

#include "xglobal.h"
#include <QScreen>

class Q_DECL_EXPORT XSysInfo : public QScreen
{
public:
    void display();
};

#endif //PICSHOT_XSYSINFO_H
