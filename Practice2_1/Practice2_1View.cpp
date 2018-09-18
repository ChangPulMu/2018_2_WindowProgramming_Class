
// Practice2_1View.cpp : CPractice2_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice2_1.h"
#endif

#include "Practice2_1Doc.h"
#include "Practice2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice2_1View

IMPLEMENT_DYNCREATE(CPractice2_1View, CView)

BEGIN_MESSAGE_MAP(CPractice2_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice2_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPractice2_1View ����/�Ҹ�

CPractice2_1View::CPractice2_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPractice2_1View::~CPractice2_1View()
{
}

BOOL CPractice2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice2_1View �׸���

void CPractice2_1View::OnDraw(CDC* /*pDC*/)
{
	CPractice2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CPractice2_1View �μ�


void CPractice2_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice2_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice2_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice2_1View ����

#ifdef _DEBUG
void CPractice2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice2_1Doc* CPractice2_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice2_1Doc)));
	return (CPractice2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice2_1View �޽��� ó����
