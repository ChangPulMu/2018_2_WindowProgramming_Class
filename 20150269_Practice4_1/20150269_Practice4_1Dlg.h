
// 20150269_Practice4_1Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMy20150269_Practice4_1Dlg 대화 상자
class CMy20150269_Practice4_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20150269_Practice4_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20150269_PRACTICE4_1_DIALOG };
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
	afx_msg void OnBnClickedCheck2();
//	CString m_strEdit;
//	CListBox m_listBox;
//	CComboBox m_cbListItem;
	void UpdateComboBox();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	bool m_bChecked[2];
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedCheck2();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonDelete();
	CString m_strEdit;
	CListBox m_listBox;
	CComboBox m_cbListItem;
};
