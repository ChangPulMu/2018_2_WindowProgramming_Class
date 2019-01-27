
// 20150269_Practice2_2View.cpp : CMy20150269_Practice2_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Practice2_2.h"
#endif

#include "20150269_Practice2_2Doc.h"
#include "20150269_Practice2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice2_2View

IMPLEMENT_DYNCREATE(CMy20150269_Practice2_2View, CView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice2_2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20150269_Practice2_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20150269_Practice2_2View 생성/소멸

CMy20150269_Practice2_2View::CMy20150269_Practice2_2View()
	: m_strWindowSize(_T(""))
	, m_strOutput(_T(""))
	, m_bDrag(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20150269_Practice2_2View::~CMy20150269_Practice2_2View()
{
}

BOOL CMy20150269_Practice2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20150269_Practice2_2View 그리기

void CMy20150269_Practice2_2View::OnDraw(CDC* pDC)
{
	CMy20150269_Practice2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	// 윈도우 크기를 나타내는 문자열을 윈도우 좌측 상단(10, 10)에 출력
	pDC->TextOutW(10, 10, m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMy20150269_Practice2_2View 인쇄


void CMy20150269_Practice2_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20150269_Practice2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20150269_Practice2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20150269_Practice2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20150269_Practice2_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20150269_Practice2_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20150269_Practice2_2View 진단

#ifdef _DEBUG
void CMy20150269_Practice2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20150269_Practice2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20150269_Practice2_2Doc* CMy20150269_Practice2_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice2_2Doc)));
	return (CMy20150269_Practice2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice2_2View 메시지 처리기


void CMy20150269_Practice2_2View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 윈도우 크기가 변경될 때 윈도우 크기를 나타내는 문자열 생성
	m_strWindowSize.Format(_T("윈도우 크기는 넓이 %d, 높이 %d입니다."), cx, cy);
	// 화면 갱신
	Invalidate();
}


void CMy20150269_Practice2_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = TRUE;
	m_strOutput = _T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy20150269_Practice2_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("오른쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CMy20150269_Practice2_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("키보드를 눌렀습니다.");
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20150269_Practice2_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE)
	{
		m_strOutput = _T("마우스를 드래그하고 있습니다.");
	}
	else
	{
		m_strOutput = _T("마우스를 이동 중 입니다.");
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMy20150269_Practice2_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = FALSE;

	CView::OnLButtonUp(nFlags, point);
}
