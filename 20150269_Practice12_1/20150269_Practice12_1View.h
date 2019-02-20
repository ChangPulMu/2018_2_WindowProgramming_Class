
// 20150269_Practice12_1View.h : CMy20150269_Practice12_1View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "DataSet.h"

#define MOVE_FIRST_RECORD	1
#define MOVE_PREV_RECORD	2
#define MOVE_NEXT_RECORD	3
#define MOVE_LAST_RECORD	4
#define ADD_READY			5
#define ADD_OK				6
#define SEEK_READY			7
#define SEEK_FREE			8

class CMy20150269_Practice12_1View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy20150269_Practice12_1View();
	DECLARE_DYNCREATE(CMy20150269_Practice12_1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY20150269_PRACTICE12_1_FORM };
#endif

// 특성입니다.
public:
	CMy20150269_Practice12_1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMy20150269_Practice12_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strMajor;
	CString m_strBook;
	CString m_strHakbun;
	CString m_strCheckOut;
	CString m_strName;
	CString m_strReturn;
	CDataSet m_dbSet;
	DbCommand m_command;
	bool m_bMoveRecord;
	int m_nTotal;
	int m_nMoveCount;
	afx_msg void OnFirstRecord();
	afx_msg void OnPrevRecord();
	afx_msg void OnNextRecord();
	afx_msg void OnLastRecord();
	void GetDataFromDb(int nMoveRecord);
	afx_msg void OnClickedButtonAdd();
	int m_nAddMode;
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnSelchangeComboSeekby();
	int m_nSelectedItem;
	CString m_strSeekText;
	afx_msg void OnClickedButtonSeek();
	int m_nSeekMode;
};

#ifndef _DEBUG  // 20150269_Practice12_1View.cpp의 디버그 버전
inline CMy20150269_Practice12_1Doc* CMy20150269_Practice12_1View::GetDocument() const
   { return reinterpret_cast<CMy20150269_Practice12_1Doc*>(m_pDocument); }
#endif

