
// 20150269_Practice9_1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "20150269_Practice9_1.h"
#include "20150269_Practice9_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy20150269_Practice9_1Dlg 대화 상자



CMy20150269_Practice9_1Dlg::CMy20150269_Practice9_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20150269_PRACTICE9_1_DIALOG, pParent)
	, m_nCount(0)
	, m_nSelectedCard(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20150269_Practice9_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_BACKGND, m_cbtnBackgnd);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_TEXT, m_cbtnText);
	DDX_Control(pDX, IDC_MFCFONTCOMBO_TEXT, m_fcbText);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_CARD, m_pgCardInfo);
	DDX_Control(pDX, IDC_MFCVSLISTBOX_CARDLIST, m_listNameCard);
}

BEGIN_MESSAGE_MAP(CMy20150269_Practice9_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_REGISTERED_MESSAGE(AFX_WM_PROPERTY_CHANGED, OnPropertyChanged)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON_BACKGND, &CMy20150269_Practice9_1Dlg::OnClickedMfccolorbuttonBackgnd)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON_TEXT, &CMy20150269_Practice9_1Dlg::OnClickedMfccolorbuttonText)
	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO_TEXT, &CMy20150269_Practice9_1Dlg::OnSelchangeMfcfontcomboText)
END_MESSAGE_MAP()


// CMy20150269_Practice9_1Dlg 메시지 처리기

BOOL CMy20150269_Practice9_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// Color 버튼을 초기화 한다.
	m_cbtnBackgnd.SetColor(RGB(255, 255, 255));
	m_cbtnText.SetColor(RGB(0, 0, 0));

	// Font Combo 박스를 초기화 한다.
	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);
	m_fcbText.SelectFont(lf.lfFaceName);

	// 명함 리스트 박스를 초기화 한다.
	m_listNameCard.SetWindowText(_T("NameCard"));

	// 명함 Property Grid를 초기화 한다.
	InitializePropGrid(NameCard());		// 빈 명함으로 초기화

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy20150269_Practice9_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy20150269_Practice9_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy20150269_Practice9_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20150269_Practice9_1Dlg::AddNameCard(CString strName)
{
	NameCard card;
	card.strName = strName;

	m_pNameCards[m_nCount++] = card;
	DrawNameCard(card);
	InitializePropGrid(card);
}


void CMy20150269_Practice9_1Dlg::SelectNameCard(int nIndex)
{
	m_nSelectedCard = nIndex;
	DrawNameCard(m_pNameCards[nIndex]);
	InitializePropGrid(m_pNameCards[nIndex]);
}


void CMy20150269_Practice9_1Dlg::DeleteNameCard(int nIndex)
{
	if (nIndex != (m_nCount - 1))
		memcpy(&m_pNameCards[nIndex], &m_pNameCards[nIndex + 1], sizeof(NameCard)*(m_nCount - nIndex + 1));
	m_nCount--;
}


void CMy20150269_Practice9_1Dlg::InitializePropGrid(NameCard card)
{
	HDITEM item;
	item.cxy = 110;
	item.mask = HDI_WIDTH;
	m_pgCardInfo.GetHeaderCtrl().SetItem(0, &item);

	m_pgCardInfo.RemoveAll();
	m_pgCardInfo.EnableHeaderCtrl(FALSE);
	m_pgCardInfo.SetVSDotNetLook();
	m_pgCardInfo.EnableDescriptionArea();

	// 1. 개인 신상 정보
	CMFCPropertyGridProperty* pGroupInfo = new CMFCPropertyGridProperty(_T("Information"));

	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Company"), card.strCompany, _T("회사이름을 입력하세오."), 0));

	CMFCPropertyGridProperty* pTitle = new CMFCPropertyGridProperty(_T("Title"), card.strTitle, _T("직책을 선택하세요."), 1);

	pTitle->AddOption(_T("대표이사"));
	pTitle->AddOption(_T("부장"));
	pTitle->AddOption(_T("과장"));
	pTitle->AddOption(_T("대리"));
	pTitle->AddOption(_T("사원"));
	pTitle->AllowEdit(FALSE);

	pGroupInfo->AddSubItem(pTitle);
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Name"), card.strName, _T("이름을 입력하세요."), 2));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Telephone"), card.strTelephone, _T("전화번호를 입력하세요."), 3));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Mobile"), card.strMobile, _T("핸드폰 번호를 입력하세요."), 4));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("EMail"), card.strEMail, _T("메일주소를 입력하세요."), 5));

	m_pgCardInfo.AddProperty(pGroupInfo);

	m_pgCardInfo.UpdateData(FALSE);
}


void CMy20150269_Practice9_1Dlg::DrawNameCard(NameCard card)
{
	CRect rc;
	CFont font, *pOldFont;
	CDC* pDC = GetDlgItem(IDC_STATIC_NAMECARD)->GetDC();
	GetDlgItem(IDC_STATIC_NAMECARD)->GetClientRect(&rc);

	// 배경
	pDC->FillSolidRect(&rc, m_cbtnBackgnd.GetColor());
	pDC->SetBkColor(m_cbtnBackgnd.GetColor());

	LOGFONT lf;
	CMFCFontInfo* pInfo = m_fcbText.GetSelFont();
	afxGlobalData.fontRegular.GetLogFont(&lf);

	lf.lfCharSet = pInfo->m_nCharSet;
	lf.lfPitchAndFamily = pInfo->m_nPitchAndFamily;
	lstrcpyn(lf.lfFaceName, pInfo->m_strName, LF_FACESIZE);
	lf.lfHeight = 50;

	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(m_cbtnText.GetColor());

	pDC->TextOut(15, 15, card.strCompany);		// 회사 이름

	CRect rcTitle(rc);
	rcTitle.right = rc.CenterPoint().x;
	pDC->DrawText(card.strTitle, &rcTitle, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

	CRect rcName(rc);
	rcName.left = rc.CenterPoint().x;
	pDC->DrawText(card.strName, &rcName, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	font.DeleteObject();

	lf.lfCharSet = pInfo->m_nCharSet;
	lf.lfPitchAndFamily = pInfo->m_nPitchAndFamily;
	lstrcpyn(lf.lfFaceName, pInfo->m_strName, LF_FACESIZE);
	lf.lfHeight = 15;

	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(m_cbtnText.GetColor());

	CString str;
	CRect rcMail(rc);

	rcMail.right = rcMail.right - 6;
	rcMail.bottom = rcMail.bottom - 6;
	str.Format(_T("전자메일 : %s"), card.strEMail);
	int nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("개인전화 : %s"), card.strMobile);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("대표전화 : %s"), card.strTelephone);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	font.DeleteObject();
}

LRESULT CMy20150269_Practice9_1Dlg::OnPropertyChanged(WPARAM wParam, LPARAM lParam)
{
	// wParam - control id, lParam - a pointer to property that changed
	CMFCPropertyGridProperty* pProperty = (CMFCPropertyGridProperty*)lParam;

	switch (pProperty->GetData())
	{
	case 0 :
		m_pNameCards[m_nSelectedCard].strCompany = pProperty->GetValue();
		break;
	case 1:
		m_pNameCards[m_nSelectedCard].strTitle = pProperty->GetValue();
		break;
	case 2:
		m_pNameCards[m_nSelectedCard].strName = pProperty->GetValue();
		break;
	case 3:
		m_pNameCards[m_nSelectedCard].strTelephone = pProperty->GetValue();
		break;
	case 4:
		m_pNameCards[m_nSelectedCard].strMobile = pProperty->GetValue();
		break;
	case 5:
		m_pNameCards[m_nSelectedCard].strEMail = pProperty->GetValue();
		break;
	}
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
	return 0L;
}


void CMy20150269_Practice9_1Dlg::OnClickedMfccolorbuttonBackgnd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CMy20150269_Practice9_1Dlg::OnClickedMfccolorbuttonText()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CMy20150269_Practice9_1Dlg::OnSelchangeMfcfontcomboText()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}
