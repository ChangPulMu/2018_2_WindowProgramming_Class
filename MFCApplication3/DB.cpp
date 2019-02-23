// DB.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "DB.h"
#include "afxdialogex.h"
#include "projectDB.h"
#include "MFCApplication3Dlg.h"

// DB 대화 상자입니다.

IMPLEMENT_DYNAMIC(DB, CDialogEx)

DB::DB(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DB, pParent)
	, m_strTag(_T(""))
	, m_strTitle(_T(""))
	, m_strUpTime(_T(""))
	, m_strURL(_T(""))
	, m_strView(_T(""))
	, m_nSelectedItem(0)
	, m_DBNum(0)
{

}

DB::~DB()
{
}

void DB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TAG, m_strTag);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT_UPTIME, m_strUpTime);
	DDX_Text(pDX, IDC_EDIT_URL, m_strURL);
	DDX_Text(pDX, IDC_EDIT_VIEW, m_strView);
	DDX_Control(pDX, IDC_LIST_DB, m_ctrlList);
}


BEGIN_MESSAGE_MAP(DB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &DB::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &DB::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &DB::OnClickedButtonAdd)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DB, &DB::OnItemchangedListDb)
//	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_CLICK, IDC_LIST_DB, &DB::OnNMClickListDb)
END_MESSAGE_MAP()


// DB 메시지 처리기입니다.


BOOL DB::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.


	m_ctrlList.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 300);
	m_ctrlList.InsertColumn(1, _T("Upload_Time"), LVCFMT_LEFT, 80);
	m_ctrlList.InsertColumn(2, _T("View"), LVCFMT_LEFT, 70);
	m_ctrlList.InsertColumn(3, _T("Tag"), LVCFMT_LEFT, 80);
	m_ctrlList.InsertColumn(4, _T("URL"), LVCFMT_LEFT, 200);

	CprojectDB projectDB;
	if (!projectDB.Open())    // 레코드셋 열기
	{
		AfxMessageBox(_T("데이터 소스와 연결하지 못했습니다."));
	}

	int i = 0;
	while (!projectDB.IsEOF())
	{
		// 새로운 행 등록
		m_ctrlList.InsertItem(i, projectDB.m_TITLE);

		// 각 컬럼의 텍스트 설정
		m_ctrlList.SetItemText(i, 1, projectDB.m_UPLOAD_TIME);
		m_ctrlList.SetItemText(i, 2, projectDB.m_VIEW);
		m_ctrlList.SetItemText(i, 3, projectDB.m_TAG);
		m_ctrlList.SetItemText(i, 4, projectDB.m_URL);
		// 다음 레코드로 이동
		projectDB.MoveNext();
		i++;
	}
	m_DBNum = m_ctrlList.GetItemCount();
	((CMFCApplication3Dlg*)GetParent())->m_num = m_DBNum;


	CString strDBNum;
	strDBNum.Format(_T("%d"), m_DBNum);

	SetDlgItemText(IDC_EDIT_DBNUM, strDBNum);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void DB::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	pos = m_ctrlList.GetFirstSelectedItemPosition();
	int idx = m_ctrlList.GetNextSelectedItem(pos);
	CprojectDB projectDB;
	projectDB.Open();
	projectDB.Move(idx);
	projectDB.Delete();
	projectDB.Requery();
	m_ctrlList.DeleteItem(idx);
	CMFCApplication3Dlg dlg;
	dlg.m_nDataCount -= 1;

	m_DBNum = m_ctrlList.GetItemCount();
	((CMFCApplication3Dlg*)GetParent())->m_num = m_DBNum;


	CString strDBNum;
	strDBNum.Format(_T("%d"), m_DBNum);

	SetDlgItemText(IDC_EDIT_DBNUM, strDBNum);

	UpdateData(FALSE);

}


void DB::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strTitle, strURL, strTime, strView, strTag, strThumbnail;
	strTitle = m_strTitle;
	strURL = m_strURL;
	strTime = m_strUpTime;
	strView = m_strView;
	strTag = m_strTag;
	if (m_nSelectedItem >= 0)
	{
		if (!m_strTitle.IsEmpty() && !m_strURL.IsEmpty())
		{
			strTitle.Format(strTitle, m_nSelectedItem + 1);
			m_ctrlList.SetItem(m_nSelectedItem, 0, LVIF_TEXT, strTitle, 0, 0, 0, 0);
			m_ctrlList.SetItem(m_nSelectedItem, 1, LVIF_TEXT, strTime, 0, 0, 0, 0);
			m_ctrlList.SetItem(m_nSelectedItem, 2, LVIF_TEXT, strView, 0, 0, 0, 0);
			m_ctrlList.SetItem(m_nSelectedItem, 3, LVIF_TEXT, strTag, 0, 0, 0, 0);
			m_ctrlList.SetItem(m_nSelectedItem, 4, LVIF_TEXT, strURL, 0, 0, 0, 0);

			CprojectDB projectDB;
			projectDB.Open();
			projectDB.Move(m_nSelectedItem);
			projectDB.Edit();
			projectDB.m_TITLE = m_strTitle;
			projectDB.m_URL = m_strURL;

			projectDB.m_UPLOAD_TIME = m_strUpTime;
			projectDB.m_VIEW = m_strView;
			projectDB.m_TAG = m_strTag;

			projectDB.Update();
			projectDB.Requery();


			m_strTitle.Empty();
			m_strURL.Empty();
			m_strUpTime.Empty();
			m_strView.Empty();
			m_strTag.Empty();

			UpdateData(FALSE);
		}
	}
	m_DBNum = m_ctrlList.GetItemCount();
	((CMFCApplication3Dlg*)GetParent())->m_num = m_DBNum;


	CString strDBNum;
	strDBNum.Format(_T("%d"), m_DBNum);

	SetDlgItemText(IDC_EDIT_DBNUM, strDBNum);

	UpdateData(FALSE);

}


void DB::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ctrlList.GetItemCount(), tmp = 0;

	CString str;

	UpdateData(TRUE);
	if (!m_strTitle.IsEmpty() && !m_strURL.IsEmpty())
	{
		str.Format(_T("%d"), num + 1);
		m_ctrlList.InsertItem(num, m_strTitle);
		m_ctrlList.SetItem(num, 1, LVIF_TEXT, m_strUpTime, NULL, NULL, NULL, NULL);
		m_ctrlList.SetItem(num, 2, LVIF_TEXT, m_strView, NULL, NULL, NULL, NULL);
		m_ctrlList.SetItem(num, 3, LVIF_TEXT, m_strTag, NULL, NULL, NULL, NULL);
		m_ctrlList.SetItem(num, 4, LVIF_TEXT, m_strURL, NULL, NULL, NULL, NULL);
		//주석처리

		CprojectDB projectDB;
		projectDB.Open();
		if (tmp != 0)
			projectDB.MoveLast();
		projectDB.AddNew();

		projectDB.m_TITLE = m_strTitle;
		projectDB.m_URL = m_strURL;
		projectDB.m_UPLOAD_TIME = m_strUpTime;
		projectDB.m_VIEW = m_strView;
		projectDB.m_TAG = m_strTag;
		projectDB.Update();
		projectDB.Requery();


		//변경부분
		m_strTitle.Empty();
		m_strURL.Empty();
		m_strUpTime.Empty();
		m_strView.Empty();
		m_strTag.Empty();

		UpdateData(FALSE);

		tmp++;
		CMFCApplication3Dlg dlg;
		dlg.m_nDataCount += 1;
	}
	m_DBNum = m_ctrlList.GetItemCount();
	((CMFCApplication3Dlg*)GetParent())->m_num = m_DBNum;


	CString strDBNum;
	strDBNum.Format(_T("%d"), m_DBNum);

	SetDlgItemText(IDC_EDIT_DBNUM, strDBNum);

	UpdateData(FALSE);

}


void DB::OnItemchangedListDb(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;

	m_strTitle = m_ctrlList.GetItemText(m_nSelectedItem, 0);
	m_strUpTime = m_ctrlList.GetItemText(m_nSelectedItem, 1);
	m_strView = m_ctrlList.GetItemText(m_nSelectedItem, 2);
	m_strTag = m_ctrlList.GetItemText(m_nSelectedItem, 3);
	m_strURL = m_ctrlList.GetItemText(m_nSelectedItem, 4);

	UpdateData(FALSE);
	*pResult = 0;
}





void DB::OnPaint()
{
	CRect rect;
	GetClientRect(&rect);
	CPaintDC dc(this);
	CBitmap resBack;
	CBitmap *old_resBack;
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);

	resBack.LoadBitmap(IDB_BITMAP_DBBG);
	old_resBack = memDC.SelectObject(&resBack);

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	memDC.SelectObject(old_resBack);
	resBack.DeleteObject();
	memDC.DeleteDC();
}


HBRUSH DB::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	UINT nID = pWnd->GetDlgCtrlID();
	if (nID == IDC_STATIC) {
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return hbr;
}


void DB::OnNMClickListDb(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int position = pNMItemActivate->iItem;
	CMFCApplication3Dlg dlgnum;
	CprojectDB PDB;
	PDB.Open();
	((CMFCApplication3Dlg*)GetParent())->m_nCount = position;
	PDB.Move(position);
	((CMFCApplication3Dlg*) GetParent())->InsertString(PDB);
	*pResult = 0;
}
