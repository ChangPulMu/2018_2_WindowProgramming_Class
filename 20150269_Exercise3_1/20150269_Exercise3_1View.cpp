
// 20150269_Exercise3_1View.cpp : CMy20150269_Exercise3_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Exercise3_1.h"
#endif

#include "20150269_Exercise3_1Doc.h"
#include "20150269_Exercise3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Exercise3_1View

IMPLEMENT_DYNCREATE(CMy20150269_Exercise3_1View, CView)

BEGIN_MESSAGE_MAP(CMy20150269_Exercise3_1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20150269_Exercise3_1View 생성/소멸

CMy20150269_Exercise3_1View::CMy20150269_Exercise3_1View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_strStopWatchRun(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20150269_Exercise3_1View::~CMy20150269_Exercise3_1View()
{
}

BOOL CMy20150269_Exercise3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20150269_Exercise3_1View 그리기

void CMy20150269_Exercise3_1View::OnDraw(CDC* pDC)
{
	CMy20150269_Exercise3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CFont big_font;											// 폰트 값 설정
	big_font.CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("굴림체"));

	CRect rect;												
	GetClientRect(&rect);									// 화면 크기 얻어오기

	CClientDC dc(this);										// 새로운 디바이스 컨텍스트를 생성
	dc.SelectObject(big_font);								// 그 디바이스 컨텍스트에 폰트 등록
	dc.DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);		// 스톱워치를 화면상에 출력

	for (int i = 0, y_adder = 0; i <= m_nCount; i++)		// 기록 값을 10,10 위치부터 y값을 20씩 늘려가며 차례대로 출력
	{
		pDC->TextOut(10, 10 + y_adder, m_strRecord[i]);
		y_adder += 20;
	}
}


// CMy20150269_Exercise3_1View 인쇄

BOOL CMy20150269_Exercise3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20150269_Exercise3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20150269_Exercise3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy20150269_Exercise3_1View 진단

#ifdef _DEBUG
void CMy20150269_Exercise3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20150269_Exercise3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20150269_Exercise3_1Doc* CMy20150269_Exercise3_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Exercise3_1Doc)));
	return (CMy20150269_Exercise3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Exercise3_1View 메시지 처리기


void CMy20150269_Exercise3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_strStopWatchRun == false)				// 타이머가 멈춰있을 때
	{
		SetTimer(0, 10, NULL);
		m_strStopWatchRun = true;				// 타이머를 동작시킨다.
	}
	else										// 타이머가 동작중일 때
	{
		KillTimer(0);
		m_strStopWatchRun = false;				// 타이머를 멈춘다.
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy20150269_Exercise3_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_nMSec++;							// SetTimer로 인해 1/100초 호출마다 밀리세컨드 값을 1씩 올린다.
	if (m_nMSec == 100)					// 밀리세컨드가 100이 넘어가면 세컨드 값으로 치환
	{
		m_nSecond++;
		m_nMSec = 0;
		if (m_nSecond == 60)			// 세컨드가 60이 넘어가면 미닛 값으로 치환
		{
			m_nMinute++;
			m_nSecond = 0;
		}
	}
	m_strStopWatch.Format(_T("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);			// 타이머 형식
	
	Invalidate();						// Ondraw() 호출

	CView::OnTimer(nIDEvent);
}


void CMy20150269_Exercise3_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_SPACE)										// 스페이스 바가 눌렸을 때
	{
		if (m_strStopWatchRun == true)							// 스톱워치가 작동중이면
		{
			m_nCount++;											// m_strRecord의 인덱스 값을 하나 올리고
			if (m_nCount >= 40)									// m_strRecord의 인자들이 40개가 넘으면 초기화
			{
				m_nCount = 0;
				for (int i = 0; i < 40; i++)
				{
					m_strRecord[i] = "";
				}
			}
			m_strRecord[m_nCount] = m_strStopWatch;				// 스톱워치 값을 기록에 하나 저장
		}

		Invalidate();											// Ondraw() 호출
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20150269_Exercise3_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_strStopWatchRun == false)				// 스톱워치가 멈춰있을 때
	{
		if (AfxMessageBox(_T("초기화 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)			// 초기화
		{
			m_nCount = 0;
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
		}
	}
	else										// 스톱워치가 작동중일 때
	{
		AfxMessageBox(_T("작동 중에는 스톱워치를 초기화시킬수 없습니다."), MB_ICONWARNING);			// 초기화 불가
	}

	CView::OnRButtonDown(nFlags, point);
}
