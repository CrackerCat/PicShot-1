//
// Created by xmuli on 2021/9/21.
//

#include "XSysInfo.h"
#include <QDebug>

void XSysInfo::display() {
    qDebug()<<"Physical DPI:"<<physicalDotsPerInch()<<"  DPIX:"<<physicalDotsPerInchX()<<"  DPIY:"<<physicalDotsPerInchY()<<"\n"
    <<"Logical DPI:"<<logicalDotsPerInch()<<"  DPIX:"<<logicalDotsPerInchX()<<"  DPIY:"<<logicalDotsPerInchY()<<"\n";
}
