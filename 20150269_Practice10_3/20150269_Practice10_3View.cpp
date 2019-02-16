
// 20150269_Practice10_3View.cpp : CMy20150269_Practice10_3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Practice10_3.h"
#endif

#include "20150269_Practice10_3Doc.h"
#include "20150269_Practice10_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice10_3View

IMPLEMENT_DYNCREATE(CMy20150269_Practice10_3View, CFormView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice10_3View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMy20150269_Practice10_3View::OnClickedButtonSave)
END_MESSAGE_MAP()

// CMy20150269_Practice10_3View 생성/소멸

CMy20150269_Practice10_3View::CMy20150269_Practice10_3View()
	: CFormView(IDD_MY20150269_PRACTICE10_3_FORM)
	, m_strInput(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20150269_Practice10_3View::~CMy20150269_Practice10_3View()
{
}

void CMy20150269_Practice10_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
}

BOOL CMy20150269_Practice10_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy20150269_Practice10_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMy20150269_Practice10_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20150269_Practice10_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20150269_Practice10_3View 진단

#ifdef _DEBUG
void CMy20150269_Practice10_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20150269_Practice10_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20150269_Practice10_3Doc* CMy20150269_Practice10_3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice10_3Doc)));
	return (CMy20150269_Practice10_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice10_3View 메시지 처리기


void CMy20150269_Practice10_3View::OnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMy20150269_Practice10_3Doc* pDoc = GetDocument();

	UpdateData(TRUE);
	pDoc->m_strSaveInput = m_strInput;
}
