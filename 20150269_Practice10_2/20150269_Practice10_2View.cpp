
// 20150269_Practice10_2View.cpp : CMy20150269_Practice10_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Practice10_2.h"
#endif

#include "20150269_Practice10_2Doc.h"
#include "20150269_Practice10_2View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice10_2View

IMPLEMENT_DYNCREATE(CMy20150269_Practice10_2View, CView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice10_2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20150269_Practice10_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20150269_Practice10_2View 생성/소멸

CMy20150269_Practice10_2View::CMy20150269_Practice10_2View()
	: m_ptFollow(0)
	, m_nCount(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20150269_Practice10_2View::~CMy20150269_Practice10_2View()
{
}

BOOL CMy20150269_Practice10_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20150269_Practice10_2View 그리기

void CMy20150269_Practice10_2View::OnDraw(CDC* pDC)
{
	CMy20150269_Practice10_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	if (m_nCount < 5)					// m_nCount가 5 이하일 때 출력
	{
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 10, pDoc->m_strDept);
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 30, pDoc->m_strName);
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 50, pDoc->m_strSex);
		pDC->TextOut(m_ptFollow.x + 10, m_ptFollow.y + 70, pDoc->m_strHobby);
	}

	for (int i = 0; i < m_nCount; i++)			// 출력된 내용을 저장된 위치에 다섯 번까지만 복사
	{
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 10, pDoc->m_strDept);
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 30, pDoc->m_strName);
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 50, pDoc->m_strSex);
		pDC->TextOut(m_ptFixate[i].x + 10, m_ptFixate[i].y + 70, pDoc->m_strHobby);
	}
}


// CMy20150269_Practice10_2View 인쇄


void CMy20150269_Practice10_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20150269_Practice10_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20150269_Practice10_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20150269_Practice10_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20150269_Practice10_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20150269_Practice10_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20150269_Practice10_2View 진단

#ifdef _DEBUG
void CMy20150269_Practice10_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20150269_Practice10_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20150269_Practice10_2Doc* CMy20150269_Practice10_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice10_2Doc)));
	return (CMy20150269_Practice10_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice10_2View 메시지 처리기


void CMy20150269_Practice10_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptFollow = point;					// 현재 마우스 위치 저장
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CMy20150269_Practice10_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20150269_Practice10_2Doc* pDoc = (CMy20150269_Practice10_2Doc*)pFrame->GetActiveDocument();

	if (!pDoc->m_strName.IsEmpty())
	{
		if (m_nCount < 5)
		{
			m_ptFixate[m_nCount] = point;		// 마우스가 눌렸을 때 위치 저장
			m_nCount++;
		}
		else
		{
			AfxMessageBox(_T("글자는 다섯 번 까지만 출력할 수 있습니다."));
		}
	}
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy20150269_Practice10_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20150269_Practice10_2Doc* pDoc = (CMy20150269_Practice10_2Doc*)pFrame->GetActiveDocument();

	if (!pDoc->m_strName.IsEmpty())
	{
		if (m_nCount > 0)
			m_nCount--;
		else
			if (AfxMessageBox(_T("출력 내용을 삭제하겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
			{
				pDoc->m_strName.Empty();
				pDoc->m_strDept.Empty();
				pDoc->m_strSex.Empty();
				pDoc->m_strHobby.Empty();
			}
	}
	else
		MessageBox(_T("삭제할 내용이 없습니다."));
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}
