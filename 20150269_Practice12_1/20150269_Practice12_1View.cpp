
// 20150269_Practice12_1View.cpp : CMy20150269_Practice12_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20150269_Practice12_1.h"
#endif

#include "20150269_Practice12_1Doc.h"
#include "20150269_Practice12_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice12_1View

IMPLEMENT_DYNCREATE(CMy20150269_Practice12_1View, CFormView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice12_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FIRST_RECORD, &CMy20150269_Practice12_1View::OnFirstRecord)
	ON_COMMAND(ID_PREV_RECORD, &CMy20150269_Practice12_1View::OnPrevRecord)
	ON_COMMAND(ID_NEXT_RECORD, &CMy20150269_Practice12_1View::OnNextRecord)
	ON_COMMAND(ID_LAST_RECORD, &CMy20150269_Practice12_1View::OnLastRecord)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMy20150269_Practice12_1View::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CMy20150269_Practice12_1View::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy20150269_Practice12_1View::OnClickedButtonDelete)
	ON_CBN_SELCHANGE(IDC_COMBO_SEEKBY, &CMy20150269_Practice12_1View::OnSelchangeComboSeekby)
	ON_BN_CLICKED(IDC_BUTTON_SEEK, &CMy20150269_Practice12_1View::OnClickedButtonSeek)
END_MESSAGE_MAP()

// CMy20150269_Practice12_1View 생성/소멸

CMy20150269_Practice12_1View::CMy20150269_Practice12_1View()
	: CFormView(IDD_MY20150269_PRACTICE12_1_FORM)
	, m_strMajor(_T(""))
	, m_strBook(_T(""))
	, m_strHakbun(_T(""))
	, m_strCheckOut(_T(""))
	, m_strName(_T(""))
	, m_strReturn(_T(""))
	, m_bMoveRecord(false)
	, m_nTotal(0)
	, m_nMoveCount(0)
	, m_nAddMode(0)
	, m_nSelectedItem(0)
	, m_strSeekText(_T(""))
	, m_nSeekMode(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_nAddMode = ADD_READY;
	m_nSeekMode = SEEK_READY;
}

CMy20150269_Practice12_1View::~CMy20150269_Practice12_1View()
{
}

void CMy20150269_Practice12_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_BOOK, m_strBook);
	DDX_Text(pDX, IDC_EDIT_HAKBUN, m_strHakbun);
	DDX_Text(pDX, IDC_EDIT_CHECKOUT, m_strCheckOut);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_RETURN, m_strReturn);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strSeekText);
}

BOOL CMy20150269_Practice12_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy20150269_Practice12_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CString strQuery;
	strQuery.Format(_T("SELECT * FROM card"));
	m_command.Close();
	if (m_dbSet.Query(strQuery, &m_command))
	{
		// 전체 레코드 숫자 구하기
		m_nTotal = 0;
		while (m_command.MoveNext() == S_OK)
		{
			m_nTotal++;
		}
		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
		m_bMoveRecord = true;
	}
}

void CMy20150269_Practice12_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20150269_Practice12_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20150269_Practice12_1View 진단

#ifdef _DEBUG
void CMy20150269_Practice12_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20150269_Practice12_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20150269_Practice12_1Doc* CMy20150269_Practice12_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice12_1Doc)));
	return (CMy20150269_Practice12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice12_1View 메시지 처리기


void CMy20150269_Practice12_1View::OnFirstRecord()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_nSeekMode == SEEK_READY)					// 검색중이 아닐 때
	{
		CString strQuery;
		strQuery.Format(_T("SELECT * FROM card"));
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			// 전체 레코드 숫자 구하기
			m_nTotal = 0;
			while (m_command.MoveNext() == S_OK)
			{
				m_nTotal++;
			}
			m_nMoveCount = 1;
			GetDataFromDb(MOVE_FIRST_RECORD);
		}
	}
	else if (m_nSeekMode == SEEK_FREE)					// 검색 중일 때
	{
		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
	}
	m_bMoveRecord = true;
	UpdateData(FALSE);
}


void CMy20150269_Practice12_1View::OnPrevRecord()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!m_bMoveRecord)
	{
		return;
	}
	else
	{
		if (m_nMoveCount == 1)
		{
			return;
		}
		m_nMoveCount--;
		GetDataFromDb(MOVE_PREV_RECORD);
	}
	UpdateData(FALSE);
}


void CMy20150269_Practice12_1View::OnNextRecord()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!m_bMoveRecord)
	{
		return;
	}
	else
	{
		if (m_nMoveCount == m_nTotal)
		{
			return;
		}
		m_nMoveCount++;
		GetDataFromDb(MOVE_NEXT_RECORD);
	}
	UpdateData(FALSE);
}


void CMy20150269_Practice12_1View::OnLastRecord()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_nSeekMode == SEEK_READY)					// 검색중이 아닐 때
	{
		CString strQuery;
		strQuery.Format(_T("SELECT * FROM card"));
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			// 전체 레코드 숫자 구하기
			m_nTotal = 0;
			while (m_command.MoveNext() == S_OK)
			{
				m_nTotal++;
			}
			m_nMoveCount = m_nTotal;
			GetDataFromDb(MOVE_LAST_RECORD);
		}
	}
	else if (m_nSeekMode == SEEK_FREE)					// 검색 중일 때
	{
		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
	}
	m_bMoveRecord = true;
	UpdateData(FALSE);
}


void CMy20150269_Practice12_1View::GetDataFromDb(int nMoveRecord)
{
	switch (nMoveRecord)
	{
	case MOVE_FIRST_RECORD:
		m_command.MoveFirst();
		break;
	case MOVE_PREV_RECORD:
		m_command.MovePrev();
		break;
	case MOVE_NEXT_RECORD:
		m_command.MoveNext();
		break;
	case MOVE_LAST_RECORD:
		m_command.MoveLast();
		break;
	}
	m_strMajor = m_command.GetString(2);
	m_strHakbun = m_command.GetString(3);
	m_strName = m_command.GetString(4);
	m_strBook = m_command.GetString(5);
	m_strCheckOut = m_command.GetString(6);
	m_strReturn = m_command.GetString(7);

	UpdateData(FALSE);
}


void CMy20150269_Practice12_1View::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nAddMode == ADD_READY)	// Edit 박스 초기화
	{
		m_strMajor.Empty();
		m_strHakbun.Empty();
		m_strName.Empty();
		m_strBook.Empty();
		m_strCheckOut.Empty();
		m_strReturn.Empty();

		UpdateData(FALSE);

		(GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("추가 완료"));
		m_nAddMode = ADD_OK;
	}
	else if (m_nAddMode == ADD_OK)		// 레코드 추가
	{
		UpdateData(TRUE);
		CString strQuery;
		strQuery.Format(_T("INSERT INTO card(major, hakbun, sname, booktitle, checkout, returnday) VALUES('%s','%s','%s','%s','%s','%s');"), m_strMajor, m_strHakbun, m_strName, m_strBook, m_strCheckOut, m_strReturn);
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			AfxMessageBox(_T("추가되었습니다."));
		}
		(GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("추가"));
		m_nAddMode = ADD_READY;

		OnFirstRecord();				// 처음 레코드로 이동
	}
}


void CMy20150269_Practice12_1View::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 레코드 수정
	UpdateData(TRUE);
	CString strQuery;
	strQuery.Format(_T("UPDATE card SET major='%s', hakbun='%s', sname='%s', booktitle='%s', checkout='%s', returnday='%s', WHERE major='%s'"), m_strMajor, m_strHakbun, m_strName, m_strBook, m_strCheckOut, m_strReturn, m_command.GetString(2));
	m_command.Close();
	if (m_dbSet.Query(strQuery, &m_command))
	{
		AfxMessageBox(_T("수정되었습니다."));
		OnFirstRecord();				// 처음 레코드로 이동
	}
}


void CMy20150269_Practice12_1View::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 레코드 삭제
	UpdateData(TRUE);
	CString strQuery;
	strQuery.Format(_T("DELETE * FROM card WHERE major='%s' AND hakbun='%s' AND sname='%s' AND booktitle='%s' AND checkout='%s' AND returnday='%s'"), m_strMajor, m_strHakbun, m_strName, m_strBook, m_strCheckOut, m_strReturn);
	m_command.Close();
	if (m_dbSet.Query(strQuery, &m_command))
	{
		AfxMessageBox(_T("삭제되었습니다."));
		OnFirstRecord();				// 처음 레코드로 이동
	}
}


void CMy20150269_Practice12_1View::OnSelchangeComboSeekby()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = ((CComboBox *)GetDlgItem(IDC_COMBO_SEEKBY))->GetCurSel();
}


void CMy20150269_Practice12_1View::OnClickedButtonSeek()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_nSeekMode == SEEK_READY)		// 검색 시작
	{
		CString strQuery;
		switch (m_nSelectedItem)			// 검색 옵션에 따라
		{
		case 0:
			strQuery.Format(_T("SELECT * FROM card WHERE hakbun = '%s'"), m_strSeekText);
			break;
		case 1:
			strQuery.Format(_T("SELECT * FROM card WHERE sname = '%s'"), m_strSeekText);
			break;
		case 2:
			strQuery.Format(_T("SELECT * FROM card WHERE major = '%s'"), m_strSeekText);
			break;
		case 3:
			strQuery.Format(_T("SELECT * FROM card WHERE booktitle = '%s'"), m_strSeekText);
			break;
		}
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			// 전체 레코드 개수 계산
			while (m_command.MoveNext() == S_OK)
			{
				m_nTotal++;
			}
			AfxMessageBox(_T("검색되었습니다."));
			GetDataFromDb(MOVE_FIRST_RECORD);
		}
		GetDlgItem(IDC_BUTTON_SEEK)->SetWindowText(_T("검색해제"));
		m_nSeekMode = SEEK_FREE;
	}
	else if (m_nSeekMode == SEEK_FREE)			// 검색종료
	{
		m_strSeekText.Empty();
		GetDlgItem(IDC_BUTTON_SEEK)->SetWindowText(_T("검색"));
		m_nSeekMode = SEEK_READY;

		OnFirstRecord();						// 처음 레코드로 이동
	}
	UpdateData(FALSE);
}
