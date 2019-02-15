// LeftViewDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "20150269_Practice10_2.h"
#include "LeftViewDlg.h"

#include "MainFrm.h"
#include "20150269_Practice10_2Doc.h"


// CLeftViewDlg

IMPLEMENT_DYNCREATE(CLeftViewDlg, CFormView)

CLeftViewDlg::CLeftViewDlg()
	: CFormView(IDD_FORMVIEW)
	, m_strDept(_T(""))
	, m_strName(_T(""))
	, m_nSex(0)
{

}

CLeftViewDlg::~CLeftViewDlg()
{
}

void CLeftViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(CLeftViewDlg, CFormView)
	ON_COMMAND(IDC_RADIO_MALE, &CLeftViewDlg::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CLeftViewDlg::OnRadioFemale)
	ON_BN_CLICKED(IDC_CHECK_READING, &CLeftViewDlg::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CLeftViewDlg::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CLeftViewDlg::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CLeftViewDlg::OnClickedButtonOk)
END_MESSAGE_MAP()


// CLeftViewDlg 진단입니다.

#ifdef _DEBUG
void CLeftViewDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftViewDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftViewDlg 메시지 처리기입니다.


void CLeftViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CComboBox*)GetDlgItem(IDC_COMBO_DEPT))->SetCurSel(2);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);
	m_nSex = 0;
	m_bHobby[0] = m_bHobby[1] = m_bHobby[2] = FALSE;
}


void CLeftViewDlg::OnRadioMale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSex = 0;
}


void CLeftViewDlg::OnRadioFemale()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nSex = 1;
}


void CLeftViewDlg::OnClickedCheckReading()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bHobby[0] = !m_bHobby[0];
}


void CLeftViewDlg::OnClickedCheckSports()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bHobby[1] = !m_bHobby[1];
}


void CLeftViewDlg::OnClickedCheckFishing()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bHobby[2] = !m_bHobby[2];
}


void CLeftViewDlg::OnClickedButtonOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20150269_Practice10_2Doc* pDoc = (CMy20150269_Practice10_2Doc*)pFrame->GetActiveDocument();

	pDoc->m_strHobby.Empty();

	if (m_strName.IsEmpty())
	{
		AfxMessageBox(_T("이름을 입력하세오."));
	}
	else
	{
		pDoc->m_strDept = m_strDept;
		pDoc->m_strName = m_strName;
		if (m_nSex == 0)
			pDoc->m_strSex = _T("남자");
		else
			pDoc->m_strSex = _T("여자");
		if (m_bHobby[0])
			pDoc->m_strHobby += _T("독서");
		if (m_bHobby[1])
			pDoc->m_strHobby += _T("운동");
		if (m_bHobby[2])
			pDoc->m_strHobby += _T("낚시");
	}
	UpdateData(FALSE);
}
