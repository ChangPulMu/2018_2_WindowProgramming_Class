
// 20150269_Practice3_1View.cpp : CMy20150269_Practice3_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Practice3_1.h"
#endif

#include "20150269_Practice3_1Doc.h"
#include "20150269_Practice3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice3_1View

IMPLEMENT_DYNCREATE(CMy20150269_Practice3_1View, CView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice3_1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMy20150269_Practice3_1View 생성/소멸

CMy20150269_Practice3_1View::CMy20150269_Practice3_1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20150269_Practice3_1View::~CMy20150269_Practice3_1View()
{
}

BOOL CMy20150269_Practice3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20150269_Practice3_1View 그리기

void CMy20150269_Practice3_1View::OnDraw(CDC* /*pDC*/)
{
	CMy20150269_Practice3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy20150269_Practice3_1View 인쇄

BOOL CMy20150269_Practice3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20150269_Practice3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20150269_Practice3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy20150269_Practice3_1View 진단

#ifdef _DEBUG
void CMy20150269_Practice3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20150269_Practice3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20150269_Practice3_1Doc* CMy20150269_Practice3_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice3_1Doc)));
	return (CMy20150269_Practice3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice3_1View 메시지 처리기


int CMy20150269_Practice3_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	/// 윈도우가 생성될 때 메시지 박스 출력
	AfxMessageBox(_T("윈도우가 생성되었습니다."), MB_OKCANCEL | MB_ICONINFORMATION);

	return 0;
}


void CMy20150269_Practice3_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 왼쪽 마우스를 더블 클릭할 때 메시지 박스 출력
	AfxMessageBox(_T("왼쪽 마우스를 더블클릭 했습니까?"), MB_YESNO | MB_ICONQUESTION);

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy20150269_Practice3_1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 윈도우가 종료될 때 메시지 박스 출력
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_YESNO | MB_ICONWARNING);
}
