#include <QApplication>
#include <QPushButton>
#include <QLibrary>
#include <QDebug>
#include <QMessageBox>
#include <windows.h>

#include "./XCore/xsysinfo.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();


//    HINSTANCE handle = LoadLibrary("./lib_out/my_dll.dll");
    QLibrary lib("XCore.dll");
    if (!lib.isLoaded())
        qDebug()<<"can't load XCore libary";
//
//    XSysInfo info;
////    info.display();
//
//    if (!lib.isLoaded())
//        qDebug()<<"can't load XCore libary 22";


//    XSysInfo info;
//    info.display();

QLibrary myLib("XCore");

if (myLib.isLoaded())
    QMessageBox::information(nullptr,"信息","DelphiDLL.DLL 1");
typedef int (*FunDef)(int); //函数原定定义
FunDef myTriple = (FunDef) myLib.resolve("triple"); //解析DLL中的函数
int V=myTriple(13); //调用函数
if (myLib.isLoaded())
    QMessageBox::information(nullptr,"info" + QString::number(V) ,"DelphiDLL.DLL  2");

    return QApplication::exec();
}
