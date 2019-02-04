
// 20150269_Exercise4_1Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMy20150269_Exercise4_1Dlg 대화 상자
class CMy20150269_Exercise4_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20150269_Exercise4_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20150269_EXERCISE4_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listLeft;
	CListBox m_listRight;
	CComboBox m_cbMove;
	CString m_strResult;
//	afx_msg void OnSelchangeComboMove();
	afx_msg void OnSelchangeComboMove();
	afx_msg void OnClickedButtonPurchase();
};
