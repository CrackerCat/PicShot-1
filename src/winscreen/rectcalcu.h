//
// Created by xmuli on 2021/9/29.
//

#ifndef PICSHOT_RECTCALCU_H
#define PICSHOT_RECTCALCU_H

#include "../xglobal.h"
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>

QT_BEGIN_NAMESPACE
class QRect;
class QPoint;
QT_END_NAMESPACE

namespace XC {

// TODO 2021.11.09 后优化为 emun class、或写进 class 里面定，而非此全局形式(那就需要重载 qDebug() 的 << 函数了，输出类)
enum ScreenStatus {                                  // ------------（矩形区域）------------
	Auto,     // 自动检测
	Custom,   // 手动拖曳

	Left,
	Right,
	Top,
	Bottom,
	TopLeft,
	TopRight,
	BottomLeft,
	BottomRight,

	Width = Left | Right,                    // 左、右
	Height = Top | Bottom,                   // 上、下
	Edge = Width | Height,                   // 任意一边（左、右、上、下）
	TLAndBR = TopLeft | BottomRight,         // 斜对角（左上、右下）
	TRAndBL = TopRight | BottomLeft,         // 斜对角（右上、左下）
	Corner = TLAndBR | TRAndBL,              // 斜任意一斜角（左上、右下、右上、左下）
	Frame = Edge | Corner,                   // 矩形任意一边或一斜角（左、右、上、下；左上、右下、右上、左下）         

	// 基础的几种状态
	WaitBase,                                // 基础的等待状态（未有，和已有矩形局域）
	SelectBase,                              // 基础的选中状态
	MoveBase,                                // 基础的移动状态
	DrawBase,                                // 基础的绘画状态    
	StretchBase,                             // 基础的拉伸状态

	Waiting,                                 // 等待 状态（未有，和已有矩形局域）
	Selecting,                               // 选中状态
	Moveing,                                 // 移动状态
	Drawing,                                 // 绘画状态    
	Stretching,                              // 拉伸状态

    UnknowCursorType                         // 未知
};
Q_DECLARE_FLAGS(CursorTypes, ScreenStatus)     // 枚举 CursorType 生成宏 CursorTypes
Q_DECLARE_OPERATORS_FOR_FLAGS(CursorTypes)   // 重载宏 CursorType 的 |() 函数

enum CursorArea {
    CursorCrossLeft = 0x00000000,
    CursorCrossTop = 0x00000001,
    CursorCrossRight = 0x00000002,
    CursorCrossBottom = 0x00000004,
    CursorCrossHorizontal = CursorCrossLeft | CursorCrossRight,
    CursorCrossVertical = CursorCrossTop | CursorCrossBottom,
    CursorCrossBorder = CursorCrossHorizontal | CursorCrossVertical,

    CursorCrossTopLeft = 0x00000010,
    CursorCrossTopRight = 0x00000020,
    CursorCrossBottomLeft = 0x00000040,
    CursorCrossBottomRight = 0x00000080,
    CursorCrossTL2BR = CursorCrossTopLeft | CursorCrossBottomRight,
    CursorCrossTR2BL = CursorCrossTopRight | CursorCrossBottomLeft,
    CursorCrossCorner = CursorCrossTL2BR | CursorCrossTR2BL,
    CursorCross = CursorCrossBorder | CursorCrossCorner,

    CursorOutSize = 0x00000100,
    CursorInner = 0x00000200,

    UnknowCursorArea
};
Q_DECLARE_FLAGS(CursorAreas, CursorArea)
//Q_DECLARE_OPERATORS_FOR_FLAGS(CursorAreas)

}

// ** 方便使用枚举 **
using namespace XC;

// 矩形计算
class RectCalcu
{
public:
	RectCalcu();
	~RectCalcu();

	QRect& getSelRect();
	QRect getOuterSelRect(QRect& rect, int interval = HAIF_INTERVAL);
	QRect getInnerSelRect(QRect& rect, int interval = HAIF_INTERVAL);
	int getMoveWidth();
	int getMoveHeight();
	int getModifyWidth();
	int getModifyHeight();
	void clear();
	void setClear(bool clear);
	bool isClear();
    const CursorArea getCursorArea(QPoint pos, bool details = false);

    static QRect getRect(QPoint pos1, QPoint pos2);
	QRect getRect(QRect rect, int px, CursorArea area);
	QRect& limitBound(QRect& rt, QRect rtDesktop = QApplication::desktop()->rect());

private:
	QRect& setSelRect(QPoint pos1, QPoint pos2);
	
public:
	QPoint m_startPos;
	QPoint m_EndPos;
	QPoint m_moveStartPos;
	QPoint m_moveEndPos;
	QPoint m_modifyStartPos;
	QPoint m_modifyEndPos;
    ScreenStatus m_cursorType = ScreenStatus::UnknowCursorType;     // 程序状态（对应此时鼠标的操作类型）

private:
	QRect m_rtSel;
	bool m_bClear;  // 当前清理状态
};

#endif //PICSHOT_RECTCALCU_H
