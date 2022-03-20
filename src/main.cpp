﻿#include <QApplication>
#include <QDir>
#include <QPushButton>
#include <QDebug>
#include <QtGlobal>
#include <QObject>
#include "screen/screenshot.h"
#include "screen/winsetting.h"

// test
//#include <QHotkey>
#include "./screen/winresetbtn.h"
#include "./screen/tray.h"
#include "widget/xroundwidget.h"

//#include "./wininfo/wininfo_win.h"
#include <iostream>

#include "core/xlog/xlog.h"
int main(int argc, char *argv[])
{


    // getAllTopWinRect();

    // TODO 2021-10-08 高分屏适配的许多尝试: QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);
    //a.loadTranslator(QList<QLocale>() << QLocale::system());
    //a.setOrganizationName("XMuli");
    //a.setApplicationName("PicShot");
    //a.setApplicationVersion("0.1");
    //a.setQuitOnLastWindowClosed(false);
    //a.setAttribute(Qt::AA_UseHighDpiPixmaps);

    /* 枚举窗口的所有进程 */
    //获取屏幕上所有的顶层窗口,每发现一个窗口就调用回调函数一次

    // 截图、显示主界面；若点击右上角，则整程序关闭; 如同执行了 close、destroy 一类函数
    Tray* tary = new Tray();
	QApplication::setQuitOnLastWindowClosed(false);

    return QApplication::exec();
}
