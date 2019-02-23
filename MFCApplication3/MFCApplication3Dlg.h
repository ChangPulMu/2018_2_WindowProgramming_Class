
// MFCApplication3Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "DB.h"
#include "projectDB.h"
#include "MFCApplication3.h"

// CMFCApplication3Dlg ��ȭ ����
class CMFCApplication3Dlg : public CDHtmlDialog
{
// �����Դϴ�.
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG, IDH = IDR_HTML_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

	//OnButtonLoad(IHTMLElement *);


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	CButton ctl_btnTrans;

	HRESULT CMFCApplication3Dlg::OnButtonLoad(IHTMLElement* /*pElement*/);
	bool m_bOpenMyDB;
	DB m_dlgMyDataBase;
	HRESULT CMFCApplication3Dlg::OnButtonSearch(IHTMLElement* /*pElement*/);
	HRESULT CMFCApplication3Dlg::OnButtonPrev(IHTMLElement* /*pElement*/);
	HRESULT CMFCApplication3Dlg::OnButtonNext(IHTMLElement* /*pElement*/);
	void CallHtml();
	void CallRealHtml(CString h_str);
	CString m_strMainText;
	CString m_strVideoInfo;
	int m_nCount;
	int m_nMax;
	int m_bReservationTime;
	CString m_prevURL;
	CString m_null;
	int m_nDataCount;
	int m_nDBCount;
	CString m_strYtbUrl;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void InsertString(CprojectDB &projectDB);
//	afx_msg void OnNcPaint();
//	afx_msg void OnNcPaint();
	int m_nStopCount;
	virtual BOOL DestroyWindow();
	int m_num;
};
