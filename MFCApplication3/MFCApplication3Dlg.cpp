
// MFCApplication3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "projectDB.h"
#include "DB.h"
#include <afxinet.h>
#include <atlconv.h>

#define RELATION_VALUE 0
#define FAMOUS_VALUE 1
#define NEW_VALUE 2
#define RESERVATION_30 3
#define RESERVATION_60 4

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3Dlg 대화 상자


BEGIN_DHTML_EVENT_MAP(CMFCApplication3Dlg)

	DHTML_EVENT_ONCLICK(_T("ButtonSearch"), OnButtonSearch)
	DHTML_EVENT_ONCLICK(_T("ButtonLoad"), OnButtonLoad)
	DHTML_EVENT_ONCLICK(_T("ButtonPrev"), OnButtonPrev)
	DHTML_EVENT_ONCLICK(_T("ButtonNext"), OnButtonNext)


END_DHTML_EVENT_MAP()


CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(IDD_MFCAPPLICATION3_DIALOG, IDR_HTML_MFCAPPLICATION3_DIALOG, pParent)
	, m_bOpenMyDB(false)
	, m_strMainText(_T("검색전에 DataBase부터 여시오"))
	, m_strVideoInfo(_T("숭실대학교 교가 영상 - 피아노 버전\n2016-06-12\n조회수 2,711회\n"))
	, m_nCount(0)
	, m_nMax(0)
	, m_bReservationTime(0)
	, m_prevURL(_T(""))
	, m_null(_T(""))
	, m_nDataCount(0)
	, m_nDBCount(0)
	, m_strYtbUrl(_T("https://www.youtube.com/embed/rM6AGrgujrs"))
	, m_nStopCount(0)
	, m_num(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_DHtml_ElementText(pDX, _T("MainText"), DISPID_A_VALUE, m_strMainText);
	DDX_DHtml_ElementText(pDX, _T("VideoInfo"), DISPID_A_VALUE, m_strVideoInfo);
	DDX_DHtml_Frame_Src(pDX, _T("YtbUrl"), m_strYtbUrl);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDHtmlDialog)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
//	ON_WM_NCPAINT()
//ON_WM_NCPAINT()
END_MESSAGE_MAP()


// CMFCApplication3Dlg 메시지 처리기

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CComboBox* Combo_Temp = (CComboBox*)GetDlgItem(IDC_COMBO2);
	Combo_Temp->SetCurSel(0);
	Combo_Temp->MoveWindow(680, 400, 90, 200);

	CprojectDB PDB;
	PDB.Open();
	m_nCount = PDB.m_ID;
	m_nMax = PDB.m_ID;
	m_nDataCount += PDB.m_ID;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication3Dlg::OnPaint()
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
		CDHtmlDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CMFCApplication3Dlg::OnButtonSearch(IHTMLElement* /*pElement*/)
{
	
	CallHtml();
	int num;
	CString str;
	CprojectDB projectDB;
	
	projectDB.Open();
	projectDB.MoveLast();
	
	m_nDBCount = 0;

	InsertString(projectDB);

	

	return S_OK;
}

HRESULT CMFCApplication3Dlg::OnButtonLoad(IHTMLElement* /*pElement*/)
{
	if (m_bOpenMyDB == false)
	{
		m_dlgMyDataBase.Create(IDD_DIALOG_DB, this);

		CRect rectMain, rectDB;
		GetWindowRect(&rectMain);

		m_dlgMyDataBase.GetWindowRect(&rectDB);
		m_dlgMyDataBase.MoveWindow(rectMain.right, rectMain.top, rectDB.Width(), rectDB.Height());

		m_dlgMyDataBase.ShowWindow(SW_SHOW);
		m_bOpenMyDB = true;
	}
	else
	{
		m_dlgMyDataBase.ShowWindow(SW_HIDE);
		m_dlgMyDataBase.DestroyWindow();
		m_bOpenMyDB = false;
	}

	return S_OK;
}


HBRUSH CMFCApplication3Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDHtmlDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch (nCtlColor) {
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
		break;
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}

HRESULT CMFCApplication3Dlg::OnButtonPrev(IHTMLElement* /*pElement*/)
{
	if (m_nCount > 0) {
		m_nCount -= 1;
	}
	if (m_nCount == 0) {
		m_nCount = m_nMax;
	}
	else
	{

	}

	CprojectDB projectDB;
	projectDB.Open();

	projectDB.Move(m_nCount);

	InsertString(projectDB);
	UpdateData(false);

	return S_OK;
	
}

HRESULT CMFCApplication3Dlg::OnButtonNext(IHTMLElement* /*pElement*/)
{
	CprojectDB projectDB;
	projectDB.Open();
	if (m_nCount < m_nMax) {
		m_nCount = m_nCount + 1;

		projectDB.Move(m_nCount);
		InsertString(projectDB);
		UpdateData(false);

	}
	if (m_nCount == m_nMax) {
		projectDB.MoveFirst();
		m_nCount = 0;
		InsertString(projectDB);
		UpdateData(false);
	}
	return S_OK;
}
void CMFCApplication3Dlg::CallHtml()			// 초기 YouTube HTML 문서 연결
{
	UpdateData(TRUE);		// 컨트롤에서 멤버 변수로 값 받아오기

	CInternetSession session;
	CHttpFile* pHttpFile = NULL;
	CString strHtml[100];
	CString strTemp;
	CString strIf1, strIf2;
	int tmp, ftmp, num = 0;

	//CString strUTF8 = CW2A((LPWSTR)(LPCWSTR)m_strSearch.GetBuffer(), CP_UTF8);

	CString strSearchTmp = m_strMainText;
	int spacebar = m_strMainText.Find(_T(" "));
	int findtmp = 0;
	CString strUTF8, strUTF8_1;
	while (strSearchTmp.GetAt(findtmp) != NULL)
	{
		strUTF8_1 = _T("");
		while ((strSearchTmp.GetAt(findtmp) != ' ') && (strSearchTmp.GetAt(findtmp) != NULL))
		{
			strUTF8_1 += strSearchTmp.GetAt(findtmp);
			findtmp++;
		}
		if (strSearchTmp.GetAt(findtmp) == NULL)
			strUTF8 += strUTF8_1;
		else
		{
			strUTF8 += strUTF8_1 + '+';
			findtmp++;
		}
	}

	

	CString strUrl;

	CComboBox * Combo_Tmp = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int cursel = Combo_Tmp->GetCurSel();

	if (m_nCount == 0)
	{
		switch (cursel)
		{
		case RELATION_VALUE:
			strUrl = _T("https://www.youtube.com/results?sp=CAA%253D&search_query=") + strUTF8;
			m_nDataCount += 10;
			break;
		case FAMOUS_VALUE:
			strUrl = _T("https://www.youtube.com/results?sp=CAM%253D&search_query=") + strUTF8;
			m_nDataCount += 10;
			break;
		case NEW_VALUE:
			strUrl = _T("https://www.youtube.com/results?sp=CAI%253D&search_query=") + strUTF8;
			m_nDataCount += 10;
			break;
		case RESERVATION_30:
			SetTimer(0, 60000, NULL);
			m_nCount = 1;
			m_bReservationTime = 1;
			m_nDataCount += 1;
			break;
		case RESERVATION_60:
			SetTimer(0, 60000, NULL);
			m_nCount = 1;
			m_bReservationTime = 2;
			m_nDataCount += 1;
			break;
		}
	}
	else
	{
		strUrl = _T("https://www.youtube.com/results?sp=CAI%253D&search_query=") + strUTF8;
		m_nCount++;

		if ((m_bReservationTime == 1) && (m_nCount == 31))
		{
			m_nCount = 0;
			m_bReservationTime = 0;
		}

		if ((m_bReservationTime == 2) && (m_nCount == 61))
		{
			m_nCount = 0;
			m_bReservationTime = 0;
		}
	}

	int num_key;

	if (m_bReservationTime == 0)
		num_key = 10;
	else
		num_key = 1;


	


	try
	{
		pHttpFile = (CHttpFile*)session.OpenURL(strUrl);		// URL 열기
	}

	catch (CInternetException* e) {			// 예외 처리
		CString strError;

		e->GetErrorMessage(strError.GetBuffer(1024), 1024);
		_tprintf(_T("%s\n"), strError);

		e->Delete();
		strError.ReleaseBuffer();
	}



	if (pHttpFile != NULL) {

		// 한 줄씩 읽어서 합치기
		while (pHttpFile->ReadString(strTemp))
		{
			// 웹 페이지 인코딩이 UTF-8이므로 유니코드로 변경
			strIf1 = CA2W((LPCSTR)strTemp.GetBuffer(), CP_UTF8);

			if ((strIf1.Find(_T("lockup-thumbnail")) != -1) && num < num_key) {		// 각각의 동영상 URL을 갖는 필드
				strIf2 = strIf1;

				tmp = strIf2.Find(_T("href="));			// URL 명시된 필드 찾기
				ftmp = tmp + 6;

				while (strIf2.GetAt(ftmp) != '\"') {		// strHtml 배열에 각각의 동영상 URL 받아오기
					strHtml[num] += strIf2.GetAt(ftmp);
					ftmp++;
				}

			//	AfxMessageBox(_T("동영상 찾음!"));

				if (m_nCount == 2)
				{
					m_prevURL = strHtml[num];
					m_nDataCount++;
				}
				else if (strHtml[num] == m_prevURL)
					break;
				else if ((m_nCount > 2) && (strHtml[num] != m_prevURL))
				{
					m_prevURL = strHtml[num];
					m_nDataCount++;
				}

				if ((strHtml[num].Find(_T("/user/")) == -1))
				{
					if ((strHtml[num].Find(_T("/channel/")) == -1))
					{
						CallRealHtml(strHtml[num]);			// 각각의 동영상 URL HTML 문서로 연결
						strHtml[num] = _T("");
						num++;
					}
				}

				strHtml[num] = _T("");
			}

			strTemp.ReleaseBuffer();
		}


		UpdateData(FALSE);

		_tprintf(_T("%s\n\n"), strHtml);

		session.Close();		// 객체 소멸
		pHttpFile->Close();
		delete pHttpFile;
	}

	else {				// URL을 읽어오지 못함
		_tprintf(_T("pFile is NULL.\n"));
	}
}


void CMFCApplication3Dlg::CallRealHtml(CString h_str)			// 각각의 동영상 URL의 HTML 문서 연결
{
	CInternetSession session;
	CHttpFile* pHttpFile = NULL;
	CString strHtml[1000];
	CString strTemp;
	CString strIf1, strIf2;
	int tmp, ftmp, num = 0;

	CString strUrl = _T("https://www.youtube.com") + h_str;			// 동영상 URL의 HTML 문서로 연결

	try
	{
		pHttpFile = (CHttpFile*)session.OpenURL(strUrl);		// URL 열기
	}
	catch (CInternetException* e) {			// 예외 처리
		CString strError;

		e->GetErrorMessage(strError.GetBuffer(1024), 1024);
		_tprintf(_T("%s\n"), strError);

		e->Delete();
		strError.ReleaseBuffer();
	}



	if (pHttpFile != NULL) {

		// 한 줄씩 읽어서 합치기
		while (pHttpFile->ReadString(strTemp))
		{
			// 웹 페이지 인코딩이 UTF-8이므로 유니코드로 변경
			strIf1 = CA2W((LPCSTR)strTemp.GetBuffer(), CP_UTF8);

			if (strIf1.Find(_T("content=")) != -1) {			// HTML 문서에서 받아올 수 있는 Content 필드

				tmp = strIf1.Find(_T("content="));
				ftmp = tmp + 9;

				while ((strIf1.GetAt(ftmp) != '\"')&&(m_nStopCount<100)) {		// 각각의 콘텐츠를 strHtml 배열에 값을 저장
					strHtml[num] += strIf1.GetAt(ftmp);
					ftmp++;
					m_nStopCount++;
				}
				m_nStopCount = 0;
				//AfxMessageBox(strHtml[num]);
				num++;
			}

			strTemp.ReleaseBuffer();
		}

		/*m_strSearch = strHtml[0];
		UpdateData(FALSE);*/
		m_dlgMyDataBase.m_strTitle = strHtml[0];		// Edit Control 제목 변수에 값 설정
														//m_strTmp = strHtml[1];
		m_dlgMyDataBase.m_strTag = strHtml[2];			// Tag 값 설정
		m_dlgMyDataBase.m_strURL = _T("https://www.youtube.com") + h_str;			// URL 값 설정	
		//m_dlgMyDataBase.m_strThumbnail = strHtml[7];	// 썸네일 값 설정
														//m_strTmp += strHtml[17];
														//m_strTmp += strHtml[20];
														//m_strTmp += strHtml[21];
		for (int i = 31; i < 100; i++)
		{

			if (strHtml[i].Find(_T("AD,AE,AF")) != -1)
			{
				m_dlgMyDataBase.m_strView = strHtml[i + 1];			// 조회수 값 설정
				m_dlgMyDataBase.m_strUpTime = strHtml[i + 2];			// 시간 값 설정
																	//m_strTmp += strHtml[i + 3];

				break;
			}
		}

		m_dlgMyDataBase.UpdateData(FALSE);			// Dialog 업데이트

		_tprintf(_T("%s\n\n"), strHtml);

		m_dlgMyDataBase.OnClickedButtonAdd();		// 추가 버튼 작동되도록 설정

		session.Close();		// 객체 소멸
		pHttpFile->Close();
		delete pHttpFile;
	}

	else {				// URL을 읽어오지 못함
		AfxMessageBox(_T("pFile is NULL."));
		_tprintf(_T("pFile is NULL.\n"));
	}
}

void CMFCApplication3Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDHtmlDialog::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_BG);
	BITMAP *bitinfo = new BITMAP;
	bitmap.GetBitmap(bitinfo);
	CRect rt(NULL, NULL, bitinfo->bmWidth, bitinfo->bmHeight);
	CMFCApplication3Dlg* pDlgWnd = this;
	if (pDlgWnd->GetSafeHwnd())
	{
		pDlgWnd->MoveWindow(rt);
	}
	delete bitinfo;
}


void CMFCApplication3Dlg::InsertString(CprojectDB &projectDB)
{
	m_strYtbUrl = projectDB.m_URL;
	m_strYtbUrl = m_strYtbUrl.Mid(32, m_strYtbUrl.GetLength() - 32);
	m_strYtbUrl = _T("https://www.youtube.com/embed/") + m_strYtbUrl;
	CString strTmp = projectDB.m_VIEW;

	CString strTmp2 = projectDB.m_TITLE;
	while (strTmp2.Find(_T("&#39;")) != -1) {
		int sidx = strTmp2.Find(_T("&#39;"));
		strTmp2 = strTmp2.Left(sidx) + "\'" + strTmp2.Mid(sidx + 5, strTmp2.GetLength());
	}


	int nTmp = _tstoi(strTmp);
	if (nTmp >= 100000000) {
		nTmp /= 100000000;
		strTmp.Format(_T("%d억"), nTmp);
	}
	else if (nTmp >= 10000) {
		nTmp /= 10000;
		strTmp.Format(_T("%d만"), nTmp);
	}

	m_strVideoInfo.Format(_T("%s\n%s\n%s\n%s"), strTmp2.Left(50),
		projectDB.m_UPLOAD_TIME.Left(10), _T("조회수 ") + strTmp + _T(" 회"), projectDB.m_TAG.Left(30) + _T("..."));

	UpdateData(false);
}



BOOL CMFCApplication3Dlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CprojectDB db;
	db.Open();
	if (db.m_TITLE != m_null) {
		db.MoveFirst();
		db.Edit();
		db.m_ID = m_num;
		db.Update();
	}
	db.Close();

	return CDHtmlDialog::DestroyWindow();
}
