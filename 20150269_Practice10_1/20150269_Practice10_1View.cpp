
// 20150269_Practice10_1View.cpp : CMy20150269_Practice10_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Practice10_1.h"
#endif

#include "20150269_Practice10_1Doc.h"
#include "20150269_Practice10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice10_1View

IMPLEMENT_DYNCREATE(CMy20150269_Practice10_1View, CFormView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice10_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CMy20150269_Practice10_1View::OnClickedButtonOutput)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CMy20150269_Practice10_1View::OnClickedButtonColor)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CMy20150269_Practice10_1View::OnClickedButtonReset)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT_RED, &CMy20150269_Practice10_1View::OnChangeEditRed)
	ON_EN_CHANGE(IDC_EDIT_GREEN, &CMy20150269_Practice10_1View::OnChangeEditGreen)
	ON_EN_CHANGE(IDC_EDIT_BLUE, &CMy20150269_Practice10_1View::OnChangeEditBlue)
	ON_EN_CHANGE(IDC_EDIT_TEXT, &CMy20150269_Practice10_1View::OnChangeEditText)
END_MESSAGE_MAP()

// CMy20150269_Practice10_1View 생성/소멸

CMy20150269_Practice10_1View::CMy20150269_Practice10_1View()
	: CFormView(IDD_MY20150269_PRACTICE10_1_FORM)
	, m_strText(_T(""))
	, m_nRed(0)
	, m_nGreen(0)
	, m_nBlue(0)
	, m_nX(0)
	, m_nY(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_colorText = RGB(0, 0, 0);
	m_nX = 30;
	m_nY = 270;		// 대화상자의 크기와 배치된 컨트롤에 따라 변경될 수 있다.
}

CMy20150269_Practice10_1View::~CMy20150269_Practice10_1View()
{
}

void CMy20150269_Practice10_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDV_MinMaxInt(pDX, m_nRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDV_MinMaxInt(pDX, m_nGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDV_MinMaxInt(pDX, m_nBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT_X, m_nX);
	DDX_Text(pDX, IDC_EDIT_Y, m_nY);
	DDX_Control(pDX, IDC_SLIDER_Y, m_sliderY);
	DDX_Control(pDX, IDC_SLIDER_X, m_sliderX);
}

BOOL CMy20150269_Practice10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy20150269_Practice10_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_sliderX.SetRange(20, 300);			// 범위는 대화상자의 크기와 컨트롤의 배치에 따라
	m_sliderY.SetRange(260, 500);
	m_sliderX.SetPos(30);
	m_sliderY.SetPos(270);
}

void CMy20150269_Practice10_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20150269_Practice10_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20150269_Practice10_1View 진단

#ifdef _DEBUG
void CMy20150269_Practice10_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20150269_Practice10_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20150269_Practice10_1Doc* CMy20150269_Practice10_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice10_1Doc)));
	return (CMy20150269_Practice10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice10_1View 메시지 처리기


void CMy20150269_Practice10_1View::OnClickedButtonOutput()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);		// 입력된 색상을 문자 색상으로 저장
	// 잘못된 색상일 경우 에러메세지를 보낸다.
	if (m_nRed > 255 || m_nRed < 0 || m_nGreen > 255 || m_nGreen < 0 || m_nBlue > 255 || m_nBlue < 0)
	{
		AfxMessageBox(_T("잘못된 색상입니다."));
	}
	else
	{
		Invalidate();
	}
}


void CMy20150269_Practice10_1View::OnClickedButtonColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 색상 다이얼로그를 띄운다.
	CColorDialog colorDlg;
	if (colorDlg.DoModal() == IDOK)
	{
		m_colorText = colorDlg.GetColor();
	}
	// 색상을 나타내는 RGB EditBox에 각 색의 RGB값을 넣어준다.
	m_nRed = GetRValue(m_colorText);
	m_nGreen = GetGValue(m_colorText);
	m_nBlue = GetBValue(m_colorText);

	UpdateData(FALSE);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20150269_Practice10_1View::OnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strText.Empty();
	m_nRed = 0;
	m_nGreen = 0;
	m_nBlue = 0;
	m_nX = 30;
	m_nY = 270;
	m_sliderX.SetPos(30);
	m_sliderY.SetPos(270);
	UpdateData(FALSE);
	Invalidate();
	GetDocument()->OnNewDocument();
}


void CMy20150269_Practice10_1View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nX = m_sliderX.GetPos();
	int nY = m_sliderY.GetPos();

	if (pScrollBar->GetSafeHwnd() == m_sliderX.m_hWnd)
		m_nX = nX;
	else if (pScrollBar->GetSafeHwnd() == m_sliderY.m_hWnd)
		m_nY = nY;
	else
		return;

	UpdateData(FALSE);
	Invalidate();

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy20150269_Practice10_1View::OnChangeEditRed()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20150269_Practice10_1View::OnChangeEditGreen()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20150269_Practice10_1View::OnChangeEditBlue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20150269_Practice10_1View::OnChangeEditText()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	GetDocument()->SetModifiedFlag();
}


void CMy20150269_Practice10_1View::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	pDC->SetTextColor(m_colorText);
	pDC->TextOut(m_nX, m_nY, m_strText);
	m_sliderX.SetPos(m_nX);
	m_sliderY.SetPos(m_nY);
}
