#pragma once
#include "afxwin.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

class CHobbyCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CHobbyCtrl)

public:
	CHobbyCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHobbyCtrl();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listHobby;
	CComboBox m_cbSex;
	CString m_strName;
	virtual BOOL OnInitDialog();
};
