
// mfcSaleSystemView.cpp : CmfcSaleSystemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mfcSaleSystem.h"
#endif

#include "mfcSaleSystemDoc.h"
#include "mfcSaleSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcSaleSystemView

IMPLEMENT_DYNCREATE(CmfcSaleSystemView, CView)

BEGIN_MESSAGE_MAP(CmfcSaleSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmfcSaleSystemView 构造/析构

CmfcSaleSystemView::CmfcSaleSystemView()
{
	// TODO: 在此处添加构造代码

}

CmfcSaleSystemView::~CmfcSaleSystemView()
{
}

BOOL CmfcSaleSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmfcSaleSystemView 绘制

void CmfcSaleSystemView::OnDraw(CDC* /*pDC*/)
{
	CmfcSaleSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CmfcSaleSystemView 打印

BOOL CmfcSaleSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmfcSaleSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmfcSaleSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmfcSaleSystemView 诊断

#ifdef _DEBUG
void CmfcSaleSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcSaleSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcSaleSystemDoc* CmfcSaleSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcSaleSystemDoc)));
	return (CmfcSaleSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcSaleSystemView 消息处理程序
