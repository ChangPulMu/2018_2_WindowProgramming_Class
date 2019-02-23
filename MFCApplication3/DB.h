#pragma once
#include "afxcmn.h"


// DB 대화 상자입니다.

class DB : public CDialogEx
{
	DECLARE_DYNAMIC(DB)

public:
	DB(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DB();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strTag;
	CString m_strTitle;
	CString m_strUpTime;
	CString m_strURL;
	CString m_strView;
	virtual BOOL OnInitDialog();
	CListCtrl m_ctrlList;
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnItemchangedListDb(NMHDR *pNMHDR, LRESULT *pResult);
	int m_nSelectedItem;
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int m_DBNum;
	afx_msg void OnNMClickListDb(NMHDR *pNMHDR, LRESULT *pResult);
};
