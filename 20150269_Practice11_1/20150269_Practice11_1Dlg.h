
// 20150269_Practice11_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMy20150269_Practice11_1Dlg ��ȭ ����
class CMy20150269_Practice11_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20150269_Practice11_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20150269_PRACTICE11_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nYear;
	CSpinButtonCtrl m_spinYear;
	CComboBox m_cbMonth;
	int m_nMonth;
	afx_msg void OnSelchangeComboMonth();
	afx_msg void OnDeltaposSpinYear(NMHDR *pNMHDR, LRESULT *pResult);
};
