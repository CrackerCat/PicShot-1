//
// Created by xmuli on 2021/9/25.
//

#include "xsysinfo.h"
#include <QScreen>
#include <QApplication>
#include <QDebug>

XSysInfo::XSysInfo() {
    m_primaryScreen = QApplication::primaryScreen();
}

XSysInfo::~XSysInfo() {

}

void XSysInfo::display() {
    qDebug()<<"Physical DPI:"<<m_primaryScreen->physicalDotsPerInch()<<"  DPIX:"<<m_primaryScreen->physicalDotsPerInchX()<<"  DPIY:"<<m_primaryScreen->physicalDotsPerInchY()<<"\n"
    <<"Logical DPI:"<<m_primaryScreen->logicalDotsPerInch()<<"  DPIX:"<<m_primaryScreen->logicalDotsPerInchX()<<"  DPIY:"<<m_primaryScreen->logicalDotsPerInchY()<<"\n";
}