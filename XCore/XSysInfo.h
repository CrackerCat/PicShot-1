//
// Created by xmuli on 2021/9/25.
//

#ifndef PICSHOT_XSYSINFO_H
#define PICSHOT_XSYSINFO_H

#include "x_global.h"
#include <QVector>

QT_BEGIN_NAMESPACE
class QScreen;
QT_END_NAMESPACE

class Q_DECL_EXPORT XSysInfo
{
public:
    XSysInfo();
    ~XSysInfo();
    void display();

private:
//    QVector<QScreen *> m_screens;
    QScreen * m_primaryScreen;
};

//Q_DECL_EXPORT int add(int a, int b)
//{
//    return  a +b;
//}


#endif //PICSHOT_XSYSINFO_H
