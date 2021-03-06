//
// Created by XMuli <xmulitech@gmail.com> on 2021/11/09.
//
#ifndef XDRAW_H
#define XDRAW_H

#include <QObject>
#include <QPen>
#include <QRect>
#include <QFont>
#include <QPainterPath>

namespace XC {
	//enum ScrnStatus {
	//	// 基础的几种状态
	//	SS_WaitBase,                                // 基础的等待状态（未有，和已有矩形局域）
	//	SS_SelectBase,                              // 基础的选中状态
	//	SS_MoveBase,                                // 基础的移动状态
	//	SS_DrawBase,                                // 基础的绘画状态    
	//	SS_StretchBase,                             // 基础的拉伸状态
	//};

	//enum ScreenStatus {                                  // ------------（矩形区域）------------
	//	Auto,     // 自动检测
	//	Custom,   // 手动拖曳

	//	Left,
	//	Right,
	//	Top,
	//	Bottom,
	//	TopLeft,
	//	TopRight,
	//	BottomLeft,
	//	BottomRight,

	//	Width = Left | Right,                    // 左、右
	//	Height = Top | Bottom,                   // 上、下
	//	Edge = Width | Height,                   // 任意一边（左、右、上、下）
	//	TLAndBR = TopLeft | BottomRight,         // 斜对角（左上、右下）
	//	TRAndBL = TopRight | BottomLeft,         // 斜对角（右上、左下）
	//	Corner = TLAndBR | TRAndBL,              // 斜任意一斜角（左上、右下、右上、左下）
	//	Frame = Edge | Corner,                   // 矩形任意一边或一斜角（左、右、上、下；左上、右下、右上、左下）         

	//	UnknowCursorType                         // 未知
	//};
	//Q_DECLARE_FLAGS(CursorTypes, ScreenStatus)     // 枚举 ScrnType 生成宏 CursorTypes
	//	Q_DECLARE_OPERATORS_FOR_FLAGS(CursorTypes)   // 重载宏 ScrnType 的 |() 函数



	// C++11 新增带作用域的枚举，用 enum class  或enum struct（两者等价）声明。
	// https://blog.csdn.net/luckysym/article/details/1666114
	enum class DrawState {
		Draw,
		Move,
		Delete,
		Wateing,
		Unknow
	};

	enum class DrawShape {
		Rectangles,
		Ellipses,
		Brush,
		Arrows,
		Text,
		Mosaics,
		NoDraw
	};

	enum class LineEnds {
		EmptyToEmpty,
		EmptyToRecesedArrow,
		DotToRecesedArrow,
		EmptyToArrow,
		DotToArrow,
		EmptyToDot,
		DotToEmpty,
		DotToDot,
		RecesedArrowToRecesedArrow,
		ArrowToArrow
	};
}

using namespace XC;


//Rectangles,
//Ellipses,
//Arrows,
//Lines,
//Texts,
//Mosaics,
//NoDraw

struct  XDrawStep
{   // 公共元素 ------------------
	QPoint pos1;                             // 起点
	QPoint pos2;                             // 终点
	QRect rt;                                // 初始绘画位置
    DrawShape shape = DrawShape::NoDraw;     // 绘画形状
	bool bFill = false;                      // 绘画类型
	int index = -1;                          // 序号，亦 z 轴，越大越顶层
	static int g_index;

	QPen pen = QPen(Qt::red);
	int penWidth = 2;                         // 画笔宽度
	QBrush brush = QBrush(Qt::NoBrush);       // 画刷
	int brushWidth = 1;                       // 画刷宽度
	int transparency = 1;                     // 透明度

	// Rectangles ----------------

	// Ellipses ------------------
    int rX = 58;                              // 短长轴
    int rY = 58;                              // 竖长轴
	
	// Arrows || Brush(Customized path) ---
	LineEnds lineEnds = LineEnds::EmptyToEmpty;
	Qt::PenStyle lineDashes = Qt::SolidLine;
	QVector<QPoint> custPath;                 // 手绘路径

	// Texts ---------------------
	bool bDisplay = false;                       // true 准备显示，显示；false 显示结束，隐藏起来
	bool bTextComplete = true;                // 文字编辑完成
	QPoint editPos;                           // 显示控件
    QString text = "==Test Text==";
	QFont font = QFont();
	int fontSize = 16;

	// Mosaic ---------------------
	int mscPx = 3; // 马赛克默认模糊块

	void clear();
};

class DrawHelper : public QObject
{
    Q_OBJECT
public:
    explicit DrawHelper(QObject* parent = nullptr);
    virtual ~DrawHelper();

    void drawRect(QPainter& pa, QRect rt, QPen pen = QPen(Qt::red), int width = 2, QBrush brush = QBrush(Qt::NoBrush));
    bool drawStep();
    bool saveDrawStep(QVector<XDrawStep *>& steps);
    bool revoke();
    bool revoke(XDrawStep* step);

public:
    XDrawStep m_step;
    QVector<XDrawStep> m_vDrawStep;
};

//QDebug operator<<(QDebug myDebug, const XDrawStep& step)
//{
//    myDebug << step.rt << step.shape;
//    return myDebug;
//}

#endif // XDRAW_H
