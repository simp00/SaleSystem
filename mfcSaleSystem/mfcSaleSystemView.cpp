
// mfcSaleSystemView.cpp : CmfcSaleSystemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmfcSaleSystemView ����/����

CmfcSaleSystemView::CmfcSaleSystemView()
{
	// TODO: �ڴ˴���ӹ������

}

CmfcSaleSystemView::~CmfcSaleSystemView()
{
}

BOOL CmfcSaleSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmfcSaleSystemView ����

void CmfcSaleSystemView::OnDraw(CDC* /*pDC*/)
{
	CmfcSaleSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmfcSaleSystemView ��ӡ

BOOL CmfcSaleSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmfcSaleSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmfcSaleSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CmfcSaleSystemView ���

#ifdef _DEBUG
void CmfcSaleSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcSaleSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcSaleSystemDoc* CmfcSaleSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcSaleSystemDoc)));
	return (CmfcSaleSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcSaleSystemView ��Ϣ�������
