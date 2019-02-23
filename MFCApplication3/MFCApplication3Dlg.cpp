
// MFCApplication3Dlg.cpp : ���� ����
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


// CMFCApplication3Dlg ��ȭ ����


BEGIN_DHTML_EVENT_MAP(CMFCApplication3Dlg)

	DHTML_EVENT_ONCLICK(_T("ButtonSearch"), OnButtonSearch)
	DHTML_EVENT_ONCLICK(_T("ButtonLoad"), OnButtonLoad)
	DHTML_EVENT_ONCLICK(_T("ButtonPrev"), OnButtonPrev)
	DHTML_EVENT_ONCLICK(_T("ButtonNext"), OnButtonNext)


END_DHTML_EVENT_MAP()


CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(IDD_MFCAPPLICATION3_DIALOG, IDR_HTML_MFCAPPLICATION3_DIALOG, pParent)
	, m_bOpenMyDB(false)
	, m_strMainText(_T("�˻����� DataBase���� ���ÿ�"))
	, m_strVideoInfo(_T("���Ǵ��б� ���� ���� - �ǾƳ� ����\n2016-06-12\n��ȸ�� 2,711ȸ\n"))
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


// CMFCApplication3Dlg �޽��� ó����

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CComboBox* Combo_Temp = (CComboBox*)GetDlgItem(IDC_COMBO2);
	Combo_Temp->SetCurSel(0);
	Combo_Temp->MoveWindow(680, 400, 90, 200);

	CprojectDB PDB;
	PDB.Open();
	m_nCount = PDB.m_ID;
	m_nMax = PDB.m_ID;
	m_nDataCount += PDB.m_ID;

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	switch (nCtlColor) {
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
		break;
	}
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
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
void CMFCApplication3Dlg::CallHtml()			// �ʱ� YouTube HTML ���� ����
{
	UpdateData(TRUE);		// ��Ʈ�ѿ��� ��� ������ �� �޾ƿ���

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
		pHttpFile = (CHttpFile*)session.OpenURL(strUrl);		// URL ����
	}

	catch (CInternetException* e) {			// ���� ó��
		CString strError;

		e->GetErrorMessage(strError.GetBuffer(1024), 1024);
		_tprintf(_T("%s\n"), strError);

		e->Delete();
		strError.ReleaseBuffer();
	}



	if (pHttpFile != NULL) {

		// �� �پ� �о ��ġ��
		while (pHttpFile->ReadString(strTemp))
		{
			// �� ������ ���ڵ��� UTF-8�̹Ƿ� �����ڵ�� ����
			strIf1 = CA2W((LPCSTR)strTemp.GetBuffer(), CP_UTF8);

			if ((strIf1.Find(_T("lockup-thumbnail")) != -1) && num < num_key) {		// ������ ������ URL�� ���� �ʵ�
				strIf2 = strIf1;

				tmp = strIf2.Find(_T("href="));			// URL ��õ� �ʵ� ã��
				ftmp = tmp + 6;

				while (strIf2.GetAt(ftmp) != '\"') {		// strHtml �迭�� ������ ������ URL �޾ƿ���
					strHtml[num] += strIf2.GetAt(ftmp);
					ftmp++;
				}

			//	AfxMessageBox(_T("������ ã��!"));

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
						CallRealHtml(strHtml[num]);			// ������ ������ URL HTML ������ ����
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

		session.Close();		// ��ü �Ҹ�
		pHttpFile->Close();
		delete pHttpFile;
	}

	else {				// URL�� �о���� ����
		_tprintf(_T("pFile is NULL.\n"));
	}
}


void CMFCApplication3Dlg::CallRealHtml(CString h_str)			// ������ ������ URL�� HTML ���� ����
{
	CInternetSession session;
	CHttpFile* pHttpFile = NULL;
	CString strHtml[1000];
	CString strTemp;
	CString strIf1, strIf2;
	int tmp, ftmp, num = 0;

	CString strUrl = _T("https://www.youtube.com") + h_str;			// ������ URL�� HTML ������ ����

	try
	{
		pHttpFile = (CHttpFile*)session.OpenURL(strUrl);		// URL ����
	}
	catch (CInternetException* e) {			// ���� ó��
		CString strError;

		e->GetErrorMessage(strError.GetBuffer(1024), 1024);
		_tprintf(_T("%s\n"), strError);

		e->Delete();
		strError.ReleaseBuffer();
	}



	if (pHttpFile != NULL) {

		// �� �پ� �о ��ġ��
		while (pHttpFile->ReadString(strTemp))
		{
			// �� ������ ���ڵ��� UTF-8�̹Ƿ� �����ڵ�� ����
			strIf1 = CA2W((LPCSTR)strTemp.GetBuffer(), CP_UTF8);

			if (strIf1.Find(_T("content=")) != -1) {			// HTML �������� �޾ƿ� �� �ִ� Content �ʵ�

				tmp = strIf1.Find(_T("content="));
				ftmp = tmp + 9;

				while ((strIf1.GetAt(ftmp) != '\"')&&(m_nStopCount<100)) {		// ������ �������� strHtml �迭�� ���� ����
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
		m_dlgMyDataBase.m_strTitle = strHtml[0];		// Edit Control ���� ������ �� ����
														//m_strTmp = strHtml[1];
		m_dlgMyDataBase.m_strTag = strHtml[2];			// Tag �� ����
		m_dlgMyDataBase.m_strURL = _T("https://www.youtube.com") + h_str;			// URL �� ����	
		//m_dlgMyDataBase.m_strThumbnail = strHtml[7];	// ����� �� ����
														//m_strTmp += strHtml[17];
														//m_strTmp += strHtml[20];
														//m_strTmp += strHtml[21];
		for (int i = 31; i < 100; i++)
		{

			if (strHtml[i].Find(_T("AD,AE,AF")) != -1)
			{
				m_dlgMyDataBase.m_strView = strHtml[i + 1];			// ��ȸ�� �� ����
				m_dlgMyDataBase.m_strUpTime = strHtml[i + 2];			// �ð� �� ����
																	//m_strTmp += strHtml[i + 3];

				break;
			}
		}

		m_dlgMyDataBase.UpdateData(FALSE);			// Dialog ������Ʈ

		_tprintf(_T("%s\n\n"), strHtml);

		m_dlgMyDataBase.OnClickedButtonAdd();		// �߰� ��ư �۵��ǵ��� ����

		session.Close();		// ��ü �Ҹ�
		pHttpFile->Close();
		delete pHttpFile;
	}

	else {				// URL�� �о���� ����
		AfxMessageBox(_T("pFile is NULL."));
		_tprintf(_T("pFile is NULL.\n"));
	}
}

void CMFCApplication3Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDHtmlDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
		strTmp.Format(_T("%d��"), nTmp);
	}
	else if (nTmp >= 10000) {
		nTmp /= 10000;
		strTmp.Format(_T("%d��"), nTmp);
	}

	m_strVideoInfo.Format(_T("%s\n%s\n%s\n%s"), strTmp2.Left(50),
		projectDB.m_UPLOAD_TIME.Left(10), _T("��ȸ�� ") + strTmp + _T(" ȸ"), projectDB.m_TAG.Left(30) + _T("..."));

	UpdateData(false);
}



BOOL CMFCApplication3Dlg::DestroyWindow()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
